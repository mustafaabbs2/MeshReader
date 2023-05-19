cmake_minimum_required(VERSION 3.5)

project(MeshReader LANGUAGES CXX) 
message("Configuring MeshReader..")

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 17)

set(CPP_SOURCES
    main.cpp
)

# Add executable target
add_executable(MeshReader 
${CPP_SOURCES}
)

# Add include directories
target_include_directories(MeshReader PRIVATE 
include/
$ENV{HOOPS_3DF_PREFIX}/Dev_Tools/hoops_3dgs/source
)

# Set the runtime library path
if (WIN32)
    set(CMAKE_INSTALL_RPATH "$ENV{HOOPS_3DF_PREFIX}/bin/nt_x64_vc11d")
endif()

message(${CMAKE_INSTALL_RPATH})

# Link against the HOOPS/3dGS static libraries
target_link_libraries(MeshReader
    $ENV{HOOPS_3DF_PREFIX}/Dev_Tools/hoops_3dgs/lib/nt_x64_vc11/hoops.lib
)