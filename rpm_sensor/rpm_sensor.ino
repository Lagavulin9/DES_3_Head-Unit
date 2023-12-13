#include <can-serial.h>
#include <mcp2515_can.h>
#include <mcp2515_can_dfs.h>
#include <mcp2518fd_can.h>
#include <mcp2518fd_can_dfs.h>
#include <mcp_can.h>

// Declare the global variables
const int PayloadLen = sizeof(unsigned long);
const int PulseIntPin= 3;
const int CanHatCSPin = 9;
const byte PulsesPerRevolution = 20;
const byte numReadings = 20;
const unsigned long CANID = 0x100;
const unsigned long ZeroTimeout = 100000; //Microseconds
volatile unsigned long PeriodBetweenPulses = ZeroTimeout + 1000;
volatile unsigned long PeriodAverage = ZeroTimeout + 1000;
volatile unsigned long LastTimeWeMeasured;
unsigned long PeriodSum;
unsigned long LastTimeCycleMeasure = LastTimeWeMeasured;
unsigned long CurrentMicros = micros();
unsigned long readings[numReadings];
unsigned long readIndex;
unsigned int PulseCounter = 1;
unsigned int AmountOfReadings = 1;
unsigned int ZeroDebouncingExtra;

mcp2515_can CAN(CanHatCSPin);

void setup() {
  // put your setup code here, to run once:
  // Initialize CAN-HAT module
  CAN.begin(CAN_500KBPS);

  // Attach sensor interrupt
  attachInterrupt(digitalPinToInterrupt(PulseIntPin), pulseEvent, RISING);

  //Serial.begin(9600);
}

void loop() {
  const unsigned long period = 100; // in milliseconds
  static unsigned long lastMillis = 0;
  unsigned long currentMillis;

  currentMillis = millis();
  if (currentMillis - lastMillis > period) {
    lastMillis = currentMillis;
    canSend();
  }
}

void canSend() {
  unsigned long RPM = calculateRpm();

  byte Payload[PayloadLen];
  memcpy(Payload, &RPM, sizeof(unsigned long));
  CAN.sendMsgBuf(CANID, 0, PayloadLen, Payload);
}

void pulseEvent() {
  // Calculate the period between pulses and update the LastTimeWeMeasured variable
  PeriodBetweenPulses = micros() - LastTimeWeMeasured;
  LastTimeWeMeasured = micros();

  // If the pulse counter is greater than or equal to the amount of readings, calculate the average period
  if (PulseCounter >= AmountOfReadings)  {
    PeriodAverage = PeriodSum / AmountOfReadings;
    PulseCounter = 1;
    PeriodSum = PeriodBetweenPulses;

    // Remap the amount of readings based on the period between pulses
    int RemapedAmountOfReadings = map(PeriodBetweenPulses, 40000, 5000, 1, 10);
    RemapedAmountOfReadings = constrain(RemapedAmountOfReadings, 1, 10);
    AmountOfReadings = RemapedAmountOfReadings;
  } else {
    PulseCounter++;
    PeriodSum = PeriodSum + PeriodBetweenPulses;
  }
}

unsigned long calculateRpm(){
  unsigned long RPM, FrequencyRaw, total, average, TimeInterval, TimeOut;

  LastTimeCycleMeasure = LastTimeWeMeasured;
  CurrentMicros = micros();
  if (CurrentMicros < LastTimeCycleMeasure) {
    LastTimeCycleMeasure = CurrentMicros;
  }

  FrequencyRaw = 10000000000 / PeriodAverage;
  TimeInterval = CurrentMicros - LastTimeCycleMeasure;
  TimeOut = ZeroTimeout - ZeroDebouncingExtra;

  if (PeriodBetweenPulses > TimeOut || TimeInterval > TimeOut) {
    FrequencyRaw = 0;  // Set frequency as 0.
    ZeroDebouncingExtra = 2000;
  } else {
    ZeroDebouncingExtra = 0;
  }

  // RoundPerMicrosecond = FrequencyRaw / PulsesPerRevolution;
  RPM = ((FrequencyRaw / PulsesPerRevolution) * 60) / 10000;

  total = total - readings[readIndex];
  readings[readIndex] = RPM;
  total = total + readings[readIndex];
  readIndex = readIndex + 1;

  if (readIndex >= numReadings) {
    readIndex = 0;
  }

  average = total / numReadings;

  //Serial.print("RPM: ");
  //Serial.println(RPM);
  return average;
}