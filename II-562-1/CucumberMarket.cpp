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
struct CucumberMarket
{
    string check( vector <int> price, int budget, int k );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    CucumberMarket ___test;
    vector <int> _price = {1000,1,10,100};
    int _budget = 1110;
    int _k = 3;
    string expected_result = "YES";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.check( _price, _budget, _k ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    CucumberMarket ___test;
    vector <int> _price = {1000,1,10,100};
    int _budget = 1109;
    int _k = 3;
    string expected_result = "NO";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.check( _price, _budget, _k ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    CucumberMarket ___test;
    vector <int> _price = {33,4};
    int _budget = 33;
    int _k = 1;
    string expected_result = "YES";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.check( _price, _budget, _k ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    CucumberMarket ___test;
    vector <int> _price = {1,1,1,1,1,1};
    int _budget = 2;
    int _k = 4;
    string expected_result = "NO";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.check( _price, _budget, _k ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test4 )
{
    CucumberMarket ___test;
    vector <int> _price = {1000,1000,1000,1000,1000,1000,1000,1000,1000};
    int _budget = 10000;
    int _k = 9;
    string expected_result = "YES";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.check( _price, _budget, _k ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    CucumberMarket ___test;
    vector <int> _price = {1000,1,10,100};
    int _budget = 1110;
    int _k = 3;
    string expected_result = "YES";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.check( _price, _budget, _k ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
string CucumberMarket::check( vector <int> price, int budget, int k )
{
    sort( price.begin(), price.end(), greater<int>() );
    if (accumulate( price.begin(), price.begin() + k, 0 ) <= budget)
        return "YES";
    return "NO";
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve TEST CucumberMarket
    return RUN_ALL_TESTS();
}
// END CUT HERE
