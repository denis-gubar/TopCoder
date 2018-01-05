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
struct CostOfDancing
{
    int minimum( int K, vector <int> danceCost );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    CostOfDancing ___test;
    int _K = 2;
    vector <int> _danceCost = {1, 5, 3, 4};
    int expected_result = 4;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.minimum( _K, _danceCost ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    CostOfDancing ___test;
    int _K = 3;
    vector <int> _danceCost = {1, 5, 4};
    int expected_result = 10;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.minimum( _K, _danceCost ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    CostOfDancing ___test;
    int _K = 1;
    vector <int> _danceCost = {2, 2, 4, 5, 3};
    int expected_result = 2;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.minimum( _K, _danceCost ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    CostOfDancing ___test;
    int _K = 39;
    vector <int> _danceCost = {973, 793, 722, 573, 521, 568, 845, 674, 595, 310, 284, 794, 913, 93, 129, 758, 108, 433, 181, 163, 96, 932,
 703, 989, 884, 420, 615, 991, 364, 657, 421, 336, 801, 142, 908, 321, 709, 752, 346, 656, 413, 629, 801};
    int expected_result = 20431;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.minimum( _K, _danceCost ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    CostOfDancing ___test;
    int _K = 2;
    vector <int> _danceCost = {1, 5, 3, 4};
    int expected_result = 4;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.minimum( _K, _danceCost ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
int CostOfDancing::minimum( int K, vector <int> danceCost )
{
    sort( danceCost.begin(), danceCost.end() );
    return accumulate(danceCost.begin(), danceCost.begin() + K, 0);
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve TEST CostOfDancing
    return RUN_ALL_TESTS();
}
// END CUT HERE
