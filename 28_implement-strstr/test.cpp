/*
mkdir build
cmake ..
make
./runTests
*/

#include <gtest/gtest.h>
extern "C" {
extern int strStr(char * haystack, char * needle);
}
TEST(SquareRootTest, test1) { 
    ASSERT_EQ(2, strStr("hello", "ll"));
    ASSERT_EQ(0, strStr("hello", ""));
    ASSERT_EQ(-1, strStr("aaaaa", "bba"));
    ASSERT_EQ(4, strStr("mississippi", "issip"));
}
