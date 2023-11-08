#!/bin/bash
################## vsomeip generator ##################
#delete "src-gen-carinfo" folder if it exists
if [ -d "src-gen-carinfo" ]; then
    rm -rf src-gen-carinfo
fi
#run generator
/home/seame02/generator/core-generator/commonapi-core-generator-linux-x86_64 -sk ./fidl/carinfo.fidl -d ./src-gen-carinfo/core
/home/seame02/generator/someip-generator/commonapi-someip-generator-linux-x86_64  ./fidl/carinfo.fdepl -d ./src-gen-carinfo/someip

################## NOTE ##################
# This needs to be run before running Build.sh
# Unfornauteley, the generator does not run on the target system (Raspberry Pi). 
# Therefore, the teams laptop is used.
# Paths on Genenrator needs to be modified regarding the used machine.