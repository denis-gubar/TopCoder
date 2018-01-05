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
struct DietPlan
{
    string chooseDinner( string diet, string breakfast, string lunch );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    DietPlan ___test;
    string _diet = "ABCD";
    string _breakfast = "AB";
    string _lunch = "C";
    string expected_result = "D";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.chooseDinner( _diet, _breakfast, _lunch ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    DietPlan ___test;
    string _diet = "ABEDCS";
    string _breakfast = "";
    string _lunch = "";
    string expected_result = "ABCDES";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.chooseDinner( _diet, _breakfast, _lunch ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    DietPlan ___test;
    string _diet = "EDSMB";
    string _breakfast = "MSD";
    string _lunch = "A";
    string expected_result = "CHEATER";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.chooseDinner( _diet, _breakfast, _lunch ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    DietPlan ___test;
    string _diet = "";
    string _breakfast = "";
    string _lunch = "";
    string expected_result = "";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.chooseDinner( _diet, _breakfast, _lunch ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test4 )
{
    DietPlan ___test;
    string _diet = "IWANTSODER";
    string _breakfast = "SOW";
    string _lunch = "RAT";
    string expected_result = "DEIN";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.chooseDinner( _diet, _breakfast, _lunch ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    DietPlan ___test;
    string _diet = "ABCD";
    string _breakfast = "AB";
    string _lunch = "C";
    string expected_result = "D";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.chooseDinner( _diet, _breakfast, _lunch ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
string DietPlan::chooseDinner( string diet, string breakfast, string lunch )
{
    string result{};
    map<char, int> M;
    for (char c : diet)
        ++M[c];
    for (char c : breakfast)
        if (--M[c] < 0)
            return "CHEATER";
    for (char c : lunch)
        if (--M[c] < 0)
            return "CHEATER";
    for (const auto& x : M)
        if (x.second > 0)
            result += x.first;
    return result;
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve: TEST, DietPlan
    return RUN_ALL_TESTS();
}
// END CUT HERE
