################## build ##################
cd .. 
#delete "build" folder if it exists
if [ -d "build" ]; then
    rm -rf build
fi
mkdir build
cd build 
# set CommonAPI configuration file 
touch commonapi.ini
echo -e "[default]\nbinding=someip\n\n[logging]\nconsole=true\nfile=./mylog.log\ndlt=true\nlevel=verbose" > commonapi.ini
cmake -DUSE_INSTALLED_COMMONAPI=ON .. 
make -j $(nproc)
#sudo make install