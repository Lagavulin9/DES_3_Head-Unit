# run someip genrator
/home/seame02/Desktop/commonapi_core_generator/commonapi-core-generator-linux-x86_64 -sk ./fidl/car_control.fidl -d ./src-gen-car_control
/home/seame02/Desktop/commonapi_someip_generator/commonapi-someip-generator-linux-x86_64  ./fidl/car_control.fdepl -d ./src-gen-car_control

# build 
cd build
cmake -DUSE_INSTALLED_COMMONAPI=OFF .. 
make 