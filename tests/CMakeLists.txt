enable_testing()

add_executable(bomb_test main.cpp)

target_link_libraries(bomb_test bomb Qt5::Test GTest::gtest)

add_subdirectory(kernel)
