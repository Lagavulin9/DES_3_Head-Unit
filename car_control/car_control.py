from piracer.vehicles import PiRacerStandard
from piracer.gamepads import ShanWanGamepad

# define class car
class car:
    def __init__(self) -> None:
        self._shanwan_gamepad  = ShanWanGamepad()
        self._piracer          = PiRacerStandard()
        self.throttle          = None
        self.steering          = None
        self.indicator         = None
        self.gear              = None

    def read_gamepad(self):
        self._set_gear_selection()
        self._set_throttle()
        self._set_steering()
        self._set_indicator()

    def _set_gear_selection(self):
        gamepad_input = self._shanwan_gamepad.read_data()
        drive      = gamepad_input.button_a
        park       = gamepad_input.button_b
        reverse    = gamepad_input.button_y
        neutral    = gamepad_input.button_x
        if drive:
            self.gear = "D"
        elif park:
            self.gear = "P"
        elif reverse:
            self.gear = "R"
        elif neutral:
            self.gear = "N"

    def _set_throttle(self):
        gamepad_input = self._shanwan_gamepad.read_data()
        max_throttle = 0.3
        if self.gear == "D":
            self.throttle = gamepad_input.analog_stick_right.y * max_throttle
        elif self.gear == "R":
            self.throttle = (gamepad_input.analog_stick_right.y * max_throttle) * ( -1)
        else:
            self.throttle = 0.0

    def _set_steering(self):
        gamepad_input = self._shanwan_gamepad.read_data()
        self.steering = gamepad_input.analog_stick_left.x
    
    def _set_indicator(self):
        gamepad_input = self._shanwan_gamepad.read_data()
        left_indicator  = gamepad_input.button_l1
        right_indicator = gamepad_input.button_r1
        if left_indicator:
            self.indicator = "L"
        elif right_indicator:
            self.indicator = "R"
        else:
            self.indicator = None

def main(): 
    car = car()
    while True:
        car.read_gamepad()
        print("Throttle: {0:.2f}, Steering: {1:.2f}".format(car.throttle, car.steering))
        print("Indicator: {0}, Gear: {1}".format(car.indicator, car.gear))


# def main(): 
#     shanwan_gamepad = ShanWanGamepad()
#     piracer = PiRacerStandard()

#     while True:
#         gamepad_input = shanwan_gamepad.read_data()

#         throttle        = gamepad_input.analog_stick_right.y
#         steering        = gamepad_input.analog_stick_left.x
#         left_indicator  = gamepad_input.button_l1
#         right_indicator = gamepad_input.button_r1
#         gear_drive      = gamepad_input.button_a
#         gear_park       = gamepad_input.button_b
#         gear_reverse    = gamepad_input.button_y
#         gear_neutral    = gamepad_input.button_x

#         piracer.set_throttle_percent(throttle * 0.3)
#         piracer.set_steering_percent(steering)

#         print("Throttle: {0:.2f}, Steering: {1:.2f}".format(throttle, steering))
#         print("Left Indicator: {0}, Right Indicator: {1}".format(left_indicator,right_indicator))
#         print("Drive: {0}, Neutral: {1}, Park: {2}, Reverse: {3}".format(gear_drive,gear_neutral,gear_park,gear_reverse))


if __name__ == '__main__':
    main()