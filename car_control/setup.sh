
################# ptyhon setup #################
# # Get path of this directory
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# # Check if the virtual environment exists
# VENV_NAME="venv"
# if [ ! -d "$SCRIPT_DIR/$VENV_NAME" ]; then
#     echo "Creating a new virtual environment..."
#     python3 -m venv "$SCRIPT_DIR/$VENV_NAME"
# fi

# # Activate the virtual environment
# source "$SCRIPT_DIR/$VENV_NAME/bin/activate"

# # Install dependencies
# echo "Installing piracer dependencies."
# pip install piracer-py

# # Set permissions
# chmod 755 "$SCRIPT_DIR/car_control.py"
# chmod 755 "$SCRIPT_DIR/piracer/"

##set pythonpath temporarily for pybind
# export PYTHONPATH="$PWD":"$PWD"/piracer

################## C++only ##################

# run someip genrator
/home/seame02/Desktop/commonapi_core_generator/commonapi-core-generator-linux-x86_64 -sk ./fidl/car_control.fidl -d ./src-gen-car_control
/home/seame02/Desktop/commonapi_someip_generator/commonapi-someip-generator-linux-x86_64  ./fidl/car_control.fdepl -d ./src-gen-car_control

# build service and Client executable
mkdir build
#if build is not empty, then delete all files in build
if [ "$(ls -A build)" ]; then
    rm build/*
fi

#mkdir build
cd build
cmake -DUSE_INSTALLED_COMMONAPI=OFF .. 
make 