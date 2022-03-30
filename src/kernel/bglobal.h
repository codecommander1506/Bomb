#ifndef BGLOBAL_H
#define BGLOBAL_H

#include <Bomb/bconfig.h>

#ifdef QT_DEBUG
#   include <QtCore/qdebug.h>
#endif

#ifdef BOMB_SHARED
#   ifdef BOMB_BUILD
#       define BOMB_EXPORT Q_DECL_EXPORT
#   else
#       define BOMB_EXPORT Q_DECL_IMPORT
#   endif
#else
#   define BOMB_EXPORT
#endif

#define B_DECLARE_PRIVATE(Class) friend class Class##Private;
#define B_DECLARE_PUBLIC(Class) friend class Class;

#define B_D(Class) Class##Private *d = static_cast<Class##Private *>(qGetPtrHelper(this->d))
#define B_Q(Class) Class *q = static_cast<Class *>(this->q)

#endif // BGLOBAL_H
