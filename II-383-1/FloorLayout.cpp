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
struct FloorLayout
{
    int countBoards( vector <string> layout );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    FloorLayout ___test;
    vector <string> _layout = {"----"
,"----"
,"----"
,"----"};
    int expected_result = 4;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.countBoards( _layout ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    FloorLayout ___test;
    vector <string> _layout = {"-||--||--"
,"--||--||-"
,"|--||--||"
,"||--||--|"
,"-||--||--"
,"--||--||-"};
    int expected_result = 31;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.countBoards( _layout ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    FloorLayout ___test;
    vector <string> _layout = {"--------"
,"|------|"
,"||----||"
,"|||--|||"
,"||----||"
,"|------|"
,"--------"};
    int expected_result = 13;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.countBoards( _layout ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    FloorLayout ___test;
    vector <string> _layout = {"||-||-|||-"
,"||--||||||"
,"-|-|||||||"
,"-|-||-||-|"
,"||--|-||||"
,"||||||-||-"
,"|-||||||||"
,"||||||||||"
,"||---|--||"
,"-||-||||||"};
    int expected_result = 41;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.countBoards( _layout ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test4 )
{
    FloorLayout ___test;
    vector <string> _layout = {"-||--|"
,"||||||"
,"|||-|-"
,"-||||-"
,"||||-|"
,"||-||-"};
    int expected_result = 19;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.countBoards( _layout ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    FloorLayout ___test;
    vector <string> _layout = {"----"
,"----"
,"----"
,"----"};
    int expected_result = 4;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.countBoards( _layout ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
int FloorLayout::countBoards( vector <string> layout )
{
    int result{};
    for( int i = 0; i < layout.size(); ++i )
        for (int j = 0; j < layout[0].size(); ++j)
        {
            int x = i, y = j;
            int current = 0;
            while (x < layout.size() && layout[x][y] == '|')
            {
                layout[x][y] = '.';
                ++x;
                current = 1;
            }
            x = i, y = j;
            while (y < layout[0].size() && layout[x][y] == '-')
            {
                layout[x][y] = '.';
                ++y;
                current = 1;
            }
            result += current;
        }
    return result;
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve: TEST, FloorLayout
    return RUN_ALL_TESTS();
}
// END CUT HERE
