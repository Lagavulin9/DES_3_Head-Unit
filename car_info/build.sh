# sets the PYTHONPATH environment - determine where to look for modules and packages - only valid for current shell
export PYTHONPATH="$PWD":"$PWD"/piracer
# delte old build
if [ -d "build" ]; then
    rm -rf build
fi
# create new build
mkdir build
cd build
cmake ..
make
cd ..