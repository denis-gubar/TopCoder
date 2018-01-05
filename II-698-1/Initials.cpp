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
struct Initials
{
    string getInitials( string name );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    Initials ___test;
    string _name = "john fitzgerald kennedy";
    string expected_result = "jfk";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getInitials( _name ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    Initials ___test;
    string _name = "single";
    string expected_result = "s";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getInitials( _name ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    Initials ___test;
    string _name = "looks good to me";
    string expected_result = "lgtm";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getInitials( _name ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    Initials ___test;
    string _name = "single round match";
    string expected_result = "srm";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getInitials( _name ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test4 )
{
    Initials ___test;
    string _name = "a aa aaa aa a bbb bb b bb bbb";
    string expected_result = "aaaaabbbbb";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getInitials( _name ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    Initials ___test;
    string _name = "john fitzgerald kennedy";
    string expected_result = "jfk";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getInitials( _name ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
string Initials::getInitials( string name )
{
    string result{};
    istringstream s( name );
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
    //RemoveUnusedCode preserve: TEST, Initials
    return RUN_ALL_TESTS();
}
// END CUT HERE
