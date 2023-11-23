# set up CAN
sudo ip link set can0 up type can bitrate 500000
sudo ip link set can1 up type can bitrate 500000
# run code
../build/Can_Receiver