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
struct LittleElephantAndBooks
{
    int getNumber( vector <int> pages, int number );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    LittleElephantAndBooks ___test;
    vector <int> _pages = {1, 2};
    int _number = 1;
    int expected_result = 2;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getNumber( _pages, _number ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    LittleElephantAndBooks ___test;
    vector <int> _pages = {74, 7, 4, 47, 44};
    int _number = 3;
    int expected_result = 58;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getNumber( _pages, _number ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    LittleElephantAndBooks ___test;
    vector <int> _pages = {3, 1, 9, 7, 2, 8, 6, 4, 5};
    int _number = 7;
    int expected_result = 29;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getNumber( _pages, _number ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    LittleElephantAndBooks ___test;
    vector <int> _pages = {74, 86, 32, 13, 100, 67, 77};
    int _number = 2;
    int expected_result = 80;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getNumber( _pages, _number ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    LittleElephantAndBooks ___test;
    vector <int> _pages = {1, 2};
    int _number = 1;
    int expected_result = 2;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getNumber( _pages, _number ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
int LittleElephantAndBooks::getNumber( vector <int> pages, int number )
{
    sort( pages.begin(), pages.end() );
    return accumulate( pages.begin(), pages.begin() + number + 1, 0 ) - pages[number - 1];
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve TEST LittleElephantAndBooks
    return RUN_ALL_TESTS();
}
// END CUT HERE
