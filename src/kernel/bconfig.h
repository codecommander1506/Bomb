#ifndef BCONFIG_H
#define BCONFIG_H

#include <QtCore/qglobal.h>

#define BOMB_VERSION_MAJOR 
#define BOMB_VERSION_MINOR 
#define BOMB_VERSION_PATCH 
#define BOMB_VERSION_STR ".."
#define BOMB_VERSION_CHECK(major, minor, patch) QT_VERSION_CHECK(major, minor, patch)
#define BOMB_VERSION BOMB_VERSION_CHECK(BOMB_VERSION_MAJOR, BOMB_VERSION_MINOR, BOMB_VERSION_PATCH)

#endif // BCONFIG_H
