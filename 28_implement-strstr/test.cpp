/*
mkdir build
cmake ..
make
./runTests
*/

#include <gtest/gtest.h>
#include "main3.c"

TEST(SquareRootTest, test1) { 
//    ASSERT_EQ(2, strStr("hello", "ll"));
//    ASSERT_EQ(0, strStr("hello", ""));
//    ASSERT_EQ(-1, strStr("aaaaa", "bba"));
    ASSERT_EQ(4, strStr("mississippi", "issip"));
}
 
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}