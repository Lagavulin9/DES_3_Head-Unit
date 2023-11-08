from vehicles import PiRacerStandard
from time import sleep

class Car:
    def __init__(self) -> None:
        self._piracer               = PiRacerStandard()
        self.voltage: float         = None
        self.current: float         = None 
        self.battery_level: int      = None 
        self.power_consumtion: float = None 
        self._numcells              = 3

    def get_voltage(self):
        return self.voltage
    
    def get_current(self):
        return self.current
    
    def get_battery_level(self):
        return self.battery_level
    
    def get_power_consumtion(self):
        return self.power_consumtion

    def update_battery_info(self):
        self.voltage    = round(abs(self._piracer.get_battery_voltage()), 3)   # in V
        self.current    = round(abs(self._piracer.get_battery_current()), 3)   # in mA
        self.power_consumtion  = round(abs(self.voltage * self.current / 1000), 3) # in W  
        x = self.voltage / self._numcells
        y = -691.919 * x**3 + 7991.667 * x**2 - 30541.295 * x + 38661.5          # approximation of battery level in % (third degree, approximation)
        self.battery_level = min(max(round(y, 3), 0), 100) # in % (make sure that battery level is between 0 and 100)

# def main(): 
#     car = Car()
#     while True:
#         car.update_battery_info()
#         print("Voltage: ", car.get_voltage())
#         print("Current: ", car.get_current())
#         print("Battery level: ", car.get_battery_level())
#         print("Power consumption: ", car.get_power_consumtion())
#         sleep(1)

# if __name__ == '__main__':
#     main()