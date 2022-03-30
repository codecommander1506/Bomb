macro(bomb_generate_nested_headers)
    foreach(header ${ARGN})
        file(RELATIVE_PATH path ${Bomb_SOURCE_DIR}/include/Bomb ${CMAKE_CURRENT_SOURCE_DIR}/${header})
        file(WRITE ${Bomb_SOURCE_DIR}/include/Bomb/${header} "#include \"${path}\"")
    endforeach()

    install(FILES ${ARGN} DESTINATION include/Bomb)
endmacro()
