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
struct SetPartialOrder
{
    string compareSets( vector <int> a, vector <int> b );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    SetPartialOrder ___test;
    vector <int> _a = {1, 2, 3, 5, 8};
    vector <int> _b = {8, 5, 1, 3, 2};
    string expected_result = "EQUAL";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.compareSets( _a, _b ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    SetPartialOrder ___test;
    vector <int> _a = {2, 3, 5, 7};
    vector <int> _b = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    string expected_result = "LESS";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.compareSets( _a, _b ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    SetPartialOrder ___test;
    vector <int> _a = {2, 4, 6, 8, 10, 12, 14, 16};
    vector <int> _b = {2, 4, 8, 16};
    string expected_result = "GREATER";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.compareSets( _a, _b ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    SetPartialOrder ___test;
    vector <int> _a = {42, 23, 17};
    vector <int> _b = {15, 23, 31};
    string expected_result = "INCOMPARABLE";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.compareSets( _a, _b ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    SetPartialOrder ___test;
    vector <int> _a = {1, 2, 3, 5, 8};
    vector <int> _b = {8, 5, 1, 3, 2};
    string expected_result = "EQUAL";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.compareSets( _a, _b ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
string SetPartialOrder::compareSets( vector <int> a, vector <int> b )
{
    sort( a.begin(), a.end() );
    sort( b.begin(), b.end() );
    vi c;
    if (a == b)
        return "EQUAL";
    set_intersection( a.begin(), a.end(), b.begin(), b.end(), back_inserter( c ) );
    if (c.size() == a.size())
        return "LESS";
    if (c.size() == b.size())
        return "GREATER";
    return "INCOMPARABLE";
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve TEST SetPartialOrder
    return RUN_ALL_TESTS();
}
// END CUT HERE
