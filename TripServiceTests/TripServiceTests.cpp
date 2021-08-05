// TripServiceTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TripService/User.h"
#include "../TripService/TripService.h"
#include "../TripService/UserNotLoggedInException.h"

using namespace testing;
TEST(TripServiceTests, Foo)
{
	ASSERT_EQ(0, 1);
}

int main(int argc, char** argv)
{
	InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}