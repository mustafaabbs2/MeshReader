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


set(glfw3_DIR ${CMAKE_SOURCE_DIR}/cmake)
set(opengl_system_DIR ${CMAKE_SOURCE_DIR}/cmake)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
set(glu_DIR ${CMAKE_SOURCE_DIR}/cmake)


#temp....
set(glfw_PACKAGE_FOLDER_RELEASE "C:/Users/mbhotvaw/.conan2/p/glfw6cc6ce20f8f46/p")
set(GLFW_INCLUDE_DIRS "${glfw_PACKAGE_FOLDER_RELEASE}/include")


find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

# Add include directories
target_include_directories(MeshReader PRIVATE 
include/
$ENV{HOOPS_3DF_PREFIX}/Dev_Tools/hoops_3dgs/source
${GLFW_INCLUDE_DIRS} 
${GLEW_INCLUDE_DIRS}
)

if(FALSE)
    message("${GLFW_INCLUDE_DIRS}")
    message("${GLEW_INCLUDE_DIRS}")
    message("${GLFW_LIBRARIES}")
    message("${GLEW_LIBRARIES}")
endif()

# Set the runtime library path
if (WIN32)
    set(CMAKE_INSTALL_RPATH "$ENV{HOOPS_3DF_PREFIX}/bin/nt_x64_vc11d")
endif()

# Link against the HOOPS/3dGS static libraries
target_link_libraries(MeshReader
    $ENV{HOOPS_3DF_PREFIX}/Dev_Tools/hoops_3dgs/lib/nt_x64_vc11/hoops.lib
    glfw
    ${GLEW_LIBRARIES}
)