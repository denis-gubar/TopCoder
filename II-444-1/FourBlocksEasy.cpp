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
struct FourBlocksEasy
{
    int maxScore( vector <string> grid );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    FourBlocksEasy ___test;
    vector <string> _grid = {".....1..1..",
 "..1.....1.."};
    int expected_result = 70;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.maxScore( _grid ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    FourBlocksEasy ___test;
    vector <string> _grid = {"....................",
 "...................."}
;
    int expected_result = 160;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.maxScore( _grid ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    FourBlocksEasy ___test;
    vector <string> _grid = {".1.........11.........",
 "..1.1......11........."}
;
    int expected_result = 128;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.maxScore( _grid ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    FourBlocksEasy ___test;
    vector <string> _grid = {"......1.....1...1.",
 ".................."};
    int expected_result = 108;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.maxScore( _grid ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    FourBlocksEasy ___test;
    vector <string> _grid = {".....1..1..",
 "..1.....1.."};
    int expected_result = 70;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.maxScore( _grid ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
int FourBlocksEasy::maxScore( vector <string> grid )
{
    int result{};
    for(int i = 0; i < grid.size(); ++i)
        for (int j = 0; j < grid[0].size(); ++j)
        {
            if (i + 1 < grid.size() && j + 1 < grid[0].size() && grid[i][j] == '.' && grid[i + 1][j] == '.' && grid[i][j + 1] == '.' && grid[i + 1][j + 1] == '.')
            {
                grid[i][j] = grid[i + 1][j] = grid[i][j + 1] = grid[i + 1][j + 1] = '0';
                result += 16;
            }
            else
                result += grid[i][j] != '0';
        }
    return result;
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve: TEST, FourBlocksEasy
    return RUN_ALL_TESTS();
}
// END CUT HERE
