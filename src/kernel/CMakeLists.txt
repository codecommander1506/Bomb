configure_file(bconfig.h.in ${CMAKE_CURRENT_SOURCE_DIR}/bconfig.h)

set(HEADERS
    bconfig.h bglobal.h
    bbomb.h
    bbombcomponent.h
    babstractexplosive.h bexplosive.h
    babstracttimer.h
)

set(SOURCES
    bbombexplosive.cpp bbombtimer.cpp bbombdetonator.cpp bbomb.cpp
    bbombcomponent.cpp
    babstractexplosive.cpp bexplosive.cpp
    babstracttimer.cpp
)

bomb_generate_nested_headers(${HEADERS})

target_sources(bomb PRIVATE ${SOURCES})
