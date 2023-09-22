# Get path of this directory
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Check if the virtual environment exists
VENV_NAME="venv"
if [ ! -d "$SCRIPT_DIR/$VENV_NAME" ]; then
    echo "Creating a new virtual environment..."
    python3 -m venv "$SCRIPT_DIR/$VENV_NAME"
fi

# Activate the virtual environment
source "$SCRIPT_DIR/$VENV_NAME/bin/activate"

# Install dependencies
echo "Installing python dependencies." 
REQUIREMENTS_FILE="$SCRIPT_DIR/requirements.txt"
while read -r line; do
    if pip show "$line" >/dev/null; then
        echo "Package: '$line' is already installed. "
    else
        echo "Installing: '$line'."
        pip install "$line" 	
    fi
done < "$REQUIREMENTS_FILE"
echo "Done."

# Run the program
python "$SCRIPT_DIR/car_control.py" "$@"


