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
typedef vector<int> vi;
struct CyclesInPermutations
{
    int maxCycle( vector <int> board );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    CyclesInPermutations ___test;
    vector <int> _board = {3,2,4,1,6,5};
    int expected_result = 3;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.maxCycle( _board ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    CyclesInPermutations ___test;
    vector <int> _board = {1,2,3,4,5,6};
    int expected_result = 1;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.maxCycle( _board ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    CyclesInPermutations ___test;
    vector <int> _board = {5,1,2,3,4};
    int expected_result = 5;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.maxCycle( _board ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    CyclesInPermutations ___test;
    vector <int> _board = {5,7,14,6,16,10,8,17,11,12,18,3,4,13,2,15,9,1,20,19};
    int expected_result = 11;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.maxCycle( _board ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    CyclesInPermutations ___test;
    vector <int> _board = {3,2,4,1,6,5};
    int expected_result = 3;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.maxCycle( _board ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
int CyclesInPermutations::maxCycle( vector <int> board )
{
    vi results;
    for (int start = 0; start < board.size(); ++start)
    {
        int current = 1;
        int x = board[start] - 1;
        while (x != start)
        {
            ++current;
            x = board[x] - 1;
        }
        results.push_back( current );
    }
    return *max_element(results.begin(), results.end());
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve: TEST, CyclesInPermutations
    return RUN_ALL_TESTS();
}
// END CUT HERE
