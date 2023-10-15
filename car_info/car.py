from vehicles import PiRacerStandard

class Car:
    def __init__(self) -> None:
        self._piracer        = PiRacerStandard()
        self.voltage         = None
        self.current         = None
        self.batterylevel    = None
        self.powerconsumtion = None
        self._numcells       = 3

    def get_voltage(self):
        return str(self.voltage)
    
    def get_current(self):
        return str(self.current)
    
    def get_batterylevel(self):
        return str(self.batterylevel)
    
    def get_powerconsumtion(self):
        return str(self.powerconsumtion)

    def update_batteryinfo(self):
        self.battery_voltage    = round(abs(self._piracer.get_battery_voltage()), 3)   # in V
        self.battery_current    = round(abs(self._piracer.get_battery_current()), 3)   # in mA
        self.power_consumption  = round(abs(self.battery_voltage * self.battery_current / 1000), 3) # in W  
        x = self.battery_voltage / self._numcells
        y = -691.919 * x**3 + 7991.667 * x**2 - 30541.295 * x + 38661.5          # approximation of battery level in % (third degree, approximation)
        self.battery_level = min(max(round(y, 3), 0), 100) # in % (make sure that battery level is between 0 and 100)

# def main(): 
#     car = Car()
#     while True:
#         car.read_gamepad()
#         print("Throttle: {0:.2f}, Steering: {1:.2f}, Indicator: {2}, Gear: {3}".format(car.throttle, car.steering, car.indicator, car.gear))

# if __name__ == '__main__':
#     main()