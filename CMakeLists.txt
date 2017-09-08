cmake_minimum_required(VERSION 2.8)
PROJECT(OBJ_GLVIEWER)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)
find_package(Qt5OpenGL)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

find_package(JPEG REQUIRED)

SET(SRC_DIRS src)
SET(GLM_INCLUDE_DIRS src/glm-0.3/glm)

SET(ADDITIONAL_SOURCES ${GLM_INCLUDE_DIRS}/glm.c ${GLM_INCLUDE_DIRS}/glmimg.c ${GLM_INCLUDE_DIRS}/glmimg_devil.c ${GLM_INCLUDE_DIRS}/glmimg_jpg.c ${GLM_INCLUDE_DIRS}/glmimg_png.c ${GLM_INCLUDE_DIRS}/glmimg_sdl.c ${GLM_INCLUDE_DIRS}/glmimg_sim.c ${GLM_INCLUDE_DIRS}/glm_util.c)
include_directories(${JPEG_INCLUDE_DIR} ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})



add_executable(objmodel_viewer ${SRC_DIRS}/gl_obj_test.cpp ${SRC_DIRS}/widget.cpp ${SRC_DIRS}/window.cpp ${ADDITIONAL_SOURCES})
qt5_use_modules(objmodel_viewer Widgets OpenGL)
target_link_libraries(objmodel_viewer ${JPEG_LIBRARY} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
