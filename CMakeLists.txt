cmake_minimum_required(VERSION 3.16)
project(BuilderPanic LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SFML 2.5 COMPONENTS graphics window audio system REQUIRED)

set(GAME_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Building-PanicHD)

add_executable(builder-panic
    ${GAME_DIR}/animation.cpp
    ${GAME_DIR}/assets.cpp
    ${GAME_DIR}/coin.cpp
    ${GAME_DIR}/enemy.cpp
    ${GAME_DIR}/entity.cpp
    ${GAME_DIR}/game.cpp
    ${GAME_DIR}/gameobject.cpp
    ${GAME_DIR}/hero.cpp
    ${GAME_DIR}/main.cpp
    ${GAME_DIR}/menu.cpp
    ${GAME_DIR}/object.cpp
    ${GAME_DIR}/objectmanager.cpp
    ${GAME_DIR}/player.cpp
    ${GAME_DIR}/scena.cpp
    ${GAME_DIR}/smartenemy.cpp
)

target_include_directories(builder-panic PRIVATE ${GAME_DIR})
target_link_libraries(builder-panic PRIVATE sfml-graphics sfml-window sfml-audio sfml-system)
target_compile_options(builder-panic PRIVATE -Wall -Wextra)

# SFML unpacked outside the default linker path still runs without LD_LIBRARY_PATH.
if(UNIX AND NOT APPLE)
    foreach(prop IN ITEMS IMPORTED_LOCATION IMPORTED_LOCATION_RELEASE IMPORTED_LOCATION_NONE IMPORTED_LOCATION_NOCONFIG)
        get_target_property(_sfml_loc sfml-system "${prop}")
        if(_sfml_loc AND NOT _sfml_loc MATCHES "NOTFOUND$")
            get_filename_component(_sfml_dir "${_sfml_loc}" DIRECTORY)
            set_target_properties(builder-panic PROPERTIES
                BUILD_RPATH "${_sfml_dir}"
                INSTALL_RPATH "${_sfml_dir}")
            break()
        endif()
    endforeach()
endif()
