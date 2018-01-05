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
struct ContestWinner
{
    int getWinner( vector <int> events );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    ContestWinner ___test;
    vector <int> _events = {4,7,4,1};
    int expected_result = 4;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getWinner( _events ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    ContestWinner ___test;
    vector <int> _events = {10,20,30,40,50};
    int expected_result = 10;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getWinner( _events ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    ContestWinner ___test;
    vector <int> _events = {123,123,456,456,456,123};
    int expected_result = 456;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getWinner( _events ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    ContestWinner ___test;
    vector <int> _events = {1,2,2,3,3,3,4,4,4,4};
    int expected_result = 4;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getWinner( _events ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    ContestWinner ___test;
    vector <int> _events = {4,7,4,1};
    int expected_result = 4;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getWinner( _events ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
int ContestWinner::getWinner( vector <int> events )
{
    set<int> S;
    reverse( events.begin(), events.end() );
    for (int e : events)
        S.insert( e );
    return *max_element( S.begin(), S.end(), [&]( int a, int b ) -> bool
                         {
                             int x = count( events.begin(), events.end(), a );
                             int y = count( events.begin(), events.end(), b );
                             if (x < y)
                                 return true;
                             if (x > y)
                                 return false;
                             x = distance( events.begin(), find( events.begin(), events.end(), a ) );
                             y = distance( events.begin(), find( events.begin(), events.end(), b ) );
                             return x < y;
                         } );
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve TEST ContestWinner
    return RUN_ALL_TESTS();
}
// END CUT HERE
