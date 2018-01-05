// BEGIN CUT HERE
#include "precompiled.h"
/*
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <list>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
using namespace std;
// BEGIN CUT HERE
*/
// END CUT HERE
struct LuckyCounter
{
    int countLuckyMoments( vector <string> moments );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    LuckyCounter ___test;
    vector <string> _moments = {"12:21", "11:10"};
    int expected_result = 1;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.countLuckyMoments( _moments ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    LuckyCounter ___test;
    vector <string> _moments = {"00:00", "00:59", "23:00"};
    int expected_result = 1;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.countLuckyMoments( _moments ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    LuckyCounter ___test;
    vector <string> _moments = {"12:34"};
    int expected_result = 0;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.countLuckyMoments( _moments ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    LuckyCounter ___test;
    vector <string> _moments = {"12:11", "22:22", "00:01", "03:30", "15:15", "16:00"};
    int expected_result = 3;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.countLuckyMoments( _moments ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    LuckyCounter ___test;
    vector <string> _moments = {"12:21", "11:10"};
    int expected_result = 1;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.countLuckyMoments( _moments ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
int LuckyCounter::countLuckyMoments( vector <string> moments )
{
    int result{};
    for (const string& s : moments)
    {
        vector<char> X( 256 );
        for (char c : s)
            ++X[c];
        int flag = 1;
        for (char c = '0'; c <= '9'; ++c)
            if (X[c] % 2 == 1)
                flag = 0;
        result += flag;
    }
    return result;
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve: TEST, LuckyCounter
    return RUN_ALL_TESTS();
}
// END CUT HERE
