from piracer.vehicles import PiRacerStandard
from piracer.gamepads import ShanWanGamepad

def main(): 
    shanwan_gamepad = ShanWanGamepad()
    piracer = PiRacerStandard()

    while True:
        gamepad_input = shanwan_gamepad.read_data()
        button_states = list(shanwan_gamepad.button_states.values()) 

        throttle        = gamepad_input.analog_stick_right.y
        steering        = gamepad_input.analog_stick_left.x
        left_indicator  = gamepad_input.button_l1
        right_indicator = gamepad_input.button_r1
        gear_drive      = gamepad_input.button_a
        gear_park       = gamepad_input.button_b
        gear_reverse    = gamepad_input.button_y
        gear_neutral    = gamepad_input.button_x

        piracer.set_throttle_percent(throttle * 0.3)
        piracer.set_steering_percent(steering)

        print(button_states)


        # print("Throttle: {0:.2f}, Steering: {1:.2f}".format(throttle, steering))
        print("Left Indicator: {0}, Right Indicator: {1}".format(left_indicator,right_indicator))
        print("Drive: {0}, Neutral: {1}, Park: {2}, Reverse: {3}".format(gear_drive,gear_neutral,gear_park,gear_reverse))

if __name__ == '__main__':
    main()