option(Bomb_BUILD_STATIC OFF)

if (Bomb_BUILD_STATIC)
    set(Bomb_BUILD_TYPE STATIC)
else()
    set(Bomb_BUILD_TYPE SHARED)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(bomb ${Bomb_BUILD_TYPE})

target_include_directories(bomb PUBLIC ${Bomb_SOURCE_DIR}/include)

target_link_libraries(bomb PUBLIC Qt5::Network)

target_compile_definitions(bomb PUBLIC BOMB_LIB BOMB_${Bomb_BUILD_TYPE} PRIVATE BOMB_BUILD)