#include "bexplosivetest.h"

#include <QtTest/qsignalspy.h>

TEST_F(BExplosiveTest, c4Test)
{
    ASSERT_EQ(explosive.explosiveName(), "C4");
}

TEST_F(BExplosiveTest, explosionTest)
{
    {
        QSignalSpy spy(&explosive, &BExplosive::explosionOcccured);
        explosive.explode();
        ASSERT_EQ(spy.size(), 1);
    }

    {
        QSignalSpy spy(&explosive, &BAbstractExplosive::exploded);
        explosive.explode();
        ASSERT_EQ(spy.size(), 1);
    }
}
