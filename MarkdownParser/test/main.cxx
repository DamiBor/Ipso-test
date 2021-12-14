#include <gtest/gtest.h>
#include "MDParserContainerTest.hh"

using ::testing::InitGoogleTest;
using ::testing::UnitTest;

int main(int argc, char **argv)
{
    // Init google test
    InitGoogleTest(&argc, argv);

    // Run all tests
    const int result = RUN_ALL_TESTS();
    return result;
}
