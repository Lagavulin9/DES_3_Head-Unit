from piracer.vehicles import PiRacerStandard
from piracer.gamepads import ShanWanGamepad

class Car:
    def __init__(self) -> None:
        self._shanwan_gamepad  = ShanWanGamepad()
        self._piracer          = PiRacerStandard()
        self._gamepad_input    = None
        self.throttle          = None
        self.max_throttle      = 0.3
        self.steering          = None
        self.max_steering      = 1.0
        self.indicator         = None
        self.gear              = "P"

    def read_gamepad(self):
        self._gamepad_input = self._shanwan_gamepad.read_data()
        self._set_gear_selection()
        self._set_throttle()
        self._set_steering()
        self._set_indicator()

    def _set_gear_selection(self):
        drive      = self._gamepad_input.button_a
        park       = self._gamepad_input.button_b
        reverse    = self._gamepad_input.button_y
        neutral    = self._gamepad_input.button_x
        if drive:
            self.gear = "D"
        elif park:
            self.gear = "P"
        elif reverse:
            self.gear = "R"
        elif neutral:
            self.gear = "N"

    def _set_throttle(self):
        if (self.gear == "D") & (self._gamepad_input.analog_stick_right.y > 0.0):
            self.throttle = self._gamepad_input.analog_stick_right.y * self.max_throttle
        elif (self.gear == "R") & (self._gamepad_input.analog_stick_right.y < 0.0):
            self.throttle = self._gamepad_input.analog_stick_right.y * self.max_throttle
        else:
            self.throttle = 0.0
        self._piracer.set_throttle_percent(self.throttle)

    def _set_steering(self):
        self.steering = self._gamepad_input.analog_stick_left.x * self.max_steering
        self._piracer.set_steering_percent(self.steering)
    
    def _set_indicator(self):
        left_indicator  = self._gamepad_input.button_l1
        right_indicator = self._gamepad_input.button_r1
        if left_indicator:
            self.indicator = "L"
        elif right_indicator:
            self.indicator = "R"
        else:
            self.indicator = None

def main(): 
    car = Car()
    while True:
        car.read_gamepad()
        print("Throttle: {0:.2f}, Steering: {1:.2f}, Indicator: {2}, Gear: {3}".format(car.throttle, car.steering, car.indicator, car.gear))

if __name__ == '__main__':
    main()