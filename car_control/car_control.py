from piracer.vehicles import PiRacerStandard
from piracer.gamepads import ShanWanGamepad

def main(): 
    shanwan_gamepad = ShanWanGamepad()
    piracer = PiRacerStandard()

    while True:
        gamepad_input = shanwan_gamepad.read_data()
        button_states = list(shanwan_gamepad.button_states.values()) #workaround

        throttle = gamepad_input.analog_stick_right.y
        steering = gamepad_input.analog_stick_left.x
        #left_indicator = gamepad_input.button_l1 # doesn't work, workaround:
        left_indicator = button_states[6]       # L1
        right_indicator = button_states[7]      # R1
        gear_drive = button_states[0]           # A
        gear_park = button_states[1]            # B
        gear_reverse = button_states[4]         # Y
        gear_neutral = button_states[3]         # X

        piracer.set_throttle_percent(throttle * 0.3)
        piracer.set_steering_percent(steering)

        print("Throttle: {0:.2f}, Steering: {1:.2f}".format(throttle, steering))
        print("Left Indicator: {0}, Right Indicator: {1}".format(left_indicator,right_indicator))
        print("Drive: {0}, Neutral: {1}, Park: {2}, Reverse: {3}".format(gear_drive,gear_neutral,gear_park,gear_reverse))

if __name__ == '__main__':
    main()