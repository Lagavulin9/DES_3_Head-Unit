cmake_minimum_required(VERSION 2.8)

project(PiRacer)

# Externals
add_subdirectory(external/googletest/)

# Libs
add_subdirectory(libs/example_lib/)

# Apos
add_subdirectory(apps/example_app)

# Unit-Test
add_subdirectory(unit_tests/)