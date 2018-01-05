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
struct FilipTheFrog
{
    int countReachableIslands( vector <int> positions, int L );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    FilipTheFrog ___test;
    vector <int> _positions = {4, 7, 1, 3, 5};
    int _L = 1;
    int expected_result = 3;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.countReachableIslands( _positions, _L ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    FilipTheFrog ___test;
    vector <int> _positions = {100, 101, 103, 105, 107};
    int _L = 2;
    int expected_result = 5;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.countReachableIslands( _positions, _L ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    FilipTheFrog ___test;
    vector <int> _positions = {17, 10, 22, 14, 6, 1, 2, 3};
    int _L = 4;
    int expected_result = 7;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.countReachableIslands( _positions, _L ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    FilipTheFrog ___test;
    vector <int> _positions = {0};
    int _L = 1000;
    int expected_result = 1;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.countReachableIslands( _positions, _L ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    FilipTheFrog ___test;
    vector <int> _positions = {4, 7, 1, 3, 5};
    int _L = 1;
    int expected_result = 3;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.countReachableIslands( _positions, _L ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
int FilipTheFrog::countReachableIslands( vector <int> positions, int L )
{
    int result = 1;
    int start = positions[0];
    vector<char> M( 1001 );
    for (int p : positions)
        M[p] = 1;
    int x = start - 1;
    int k = 1;
    while (x >= 0 && k <= L)
    {
        if (M[x])
        {
            k = 0;
            ++result;
        }
        --x;
        ++k;
    }
    k = 1; x = start + 1;
    while (x <= 1000 && k <= L)
    {
        if (M[x])
        {
            k = 0;
            ++result;
        }
        ++x;
        ++k;
    }
    return result;
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve TEST FilipTheFrog
    return RUN_ALL_TESTS();
}
// END CUT HERE
