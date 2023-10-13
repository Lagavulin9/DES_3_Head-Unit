################# Pythononly #################
# # Get path of this directory
# SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

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

################## C++only ##################
# Get path of this directory
# delete content of build folder
mkdir build
#if build is not empty, then delete all files in build
if [ "$(ls -A build)" ]; then
    rm build/*
fi

cd build
cmake ..
make
cd ..

