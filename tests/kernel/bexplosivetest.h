#ifndef BEXPLOSIVETEST_H
#define BEXPLOSIVETEST_H

#include <Bomb/bbomb.h>
#include <Bomb/bexplosive.h>

#include <gtest/gtest.h>

class BExplosiveTest : public testing::Test
{
public:
    BExplosiveTest() :
        explosive(&bomb)
    {}

    ~BExplosiveTest()
    {}

    virtual void SetUp()
    {bomb.arm();}

    virtual void TearDown()
    {bomb.setArmed(false);}

    BBomb bomb;
    BExplosive explosive;
};

#endif // BEXPLOSIVETEST_H
