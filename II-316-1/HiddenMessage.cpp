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
struct HiddenMessage
{
    string getMessage( string text );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    HiddenMessage ___test;
    string _text = "compete online design event rating";
    string expected_result = "coder";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getMessage( _text ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    HiddenMessage ___test;
    string _text = "  c    o d     e      r    ";
    string expected_result = "coder";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getMessage( _text ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    HiddenMessage ___test;
    string _text = "round  elimination during  onsite  contest";
    string expected_result = "redoc";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getMessage( _text ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    HiddenMessage ___test;
    string _text = " ";
    string expected_result = "";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getMessage( _text ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    HiddenMessage ___test;
    string _text = "compete online design event rating";
    string expected_result = "coder";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getMessage( _text ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
string HiddenMessage::getMessage( string text )
{
    string result{};
    istringstream s( text );
    while (!s.eof())
    {
        string t;
        s >> t;
        if (!t.empty())
            result += t[0];
    }
    return result;
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve TEST HiddenMessage
    return RUN_ALL_TESTS();
}
// END CUT HERE
