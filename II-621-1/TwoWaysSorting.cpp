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
struct TwoWaysSorting
{
    string sortingMethod( vector <string> stringList );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    TwoWaysSorting ___test;
    vector <string> _stringList = {"a", "aa", "bbb"};
    string expected_result = "both";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.sortingMethod( _stringList ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    TwoWaysSorting ___test;
    vector <string> _stringList = {"c", "bb", "aaa"};
    string expected_result = "lengths";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.sortingMethod( _stringList ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    TwoWaysSorting ___test;
    vector <string> _stringList = {"etdfgfh", "aio"};
    string expected_result = "none";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.sortingMethod( _stringList ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    TwoWaysSorting ___test;
    vector <string> _stringList = {"aaa", "z"};
    string expected_result = "lexicographically";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.sortingMethod( _stringList ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test4 )
{
    TwoWaysSorting ___test;
    vector <string> _stringList = {"z"};
    string expected_result = "both";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.sortingMethod( _stringList ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test5 )
{
    TwoWaysSorting ___test;
    vector <string> _stringList = {"abcdef", "bcdef", "cdef", "def", "ef", "f", "topcoder"};
    string expected_result = "lexicographically";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.sortingMethod( _stringList ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    TwoWaysSorting ___test;
    vector <string> _stringList = {"a", "aa", "bbb"};
    string expected_result = "both";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.sortingMethod( _stringList ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
string TwoWaysSorting::sortingMethod( vector <string> stringList )
{
    bool isSorted = is_sorted( stringList.begin(), stringList.end() );
    bool isSorted2 = is_sorted( stringList.begin(), stringList.end(), []( const string& a, const string b ) -> bool
                                {
                                    return a.size() < b.size();
                                } );
    if (isSorted && isSorted2)
        return "both";
    if (isSorted)
        return "lexicographically";
    if (isSorted2)
        return "lengths";
    return "none";
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve TEST TwoWaysSorting
    return RUN_ALL_TESTS();
}
// END CUT HERE
