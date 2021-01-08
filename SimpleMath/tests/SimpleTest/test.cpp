#include <iostream>
#include "gtest/gtest.h"

namespace
{
	TEST(SampleTest, Simple)
	{
		EXPECT_EQ(1, 1);
	}
}

int main()
{
	::testing::InitGoogleTest();
	RUN_ALL_TESTS();
}