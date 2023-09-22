from piracer.vehicles import PiRacerStandard
from piracer.gamepads import ShanWanGamepad

def main(): 
    shanwan_gamepad = ShanWanGamepad()
    piracer = PiRacerStandard()

    while True:
        gamepad_input = shanwan_gamepad.read_data()

        throttle = gamepad_input.analog_stick_right.y * 0.5
        steering = gamepad_input.analog_stick_left.x

        piracer.set_throttle_percent(throttle)
        piracer.set_steering_percent(steering)

if __name__ == '__main__':
    main()