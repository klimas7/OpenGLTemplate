cmake_minimum_required(VERSION 3.3)
project(OpenGLTemplate)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp Canvas.cpp Canvas.h Point.cpp Point.h Points.cpp Points.h)
add_executable(OpenGLTemplate ${SOURCE_FILES})

#########################################################
# FIND GLUT
#########################################################
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)
#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

########################################################
# Linking & stuff
#########################################################

# create the program "test"
target_link_libraries(OpenGLTemplate ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )