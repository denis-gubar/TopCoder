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
typedef vector<string> vs;
typedef set<string> ss;
vector<string> split( const string& s, char delimeter = ' ' )
{
    vector<string> result;
    istringstream ss( s );
    for (string token; !ss.eof(); )
    {
        getline( ss, token, delimeter );
        result.push_back( token );
    }
    return result;
}
struct MirroredClock
{
    string whatTimeIsIt( string time );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    MirroredClock ___test;
    string _time = "10:00";
    string expected_result = "02:00";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.whatTimeIsIt( _time ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    MirroredClock ___test;
    string _time = "01:15";
    string expected_result = "10:45";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.whatTimeIsIt( _time ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    MirroredClock ___test;
    string _time = "03:40";
    string expected_result = "08:20";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.whatTimeIsIt( _time ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    MirroredClock ___test;
    string _time = "00:00";
    string expected_result = "00:00";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.whatTimeIsIt( _time ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test4 )
{
    MirroredClock ___test;
    string _time = "11:53";
    string expected_result = "00:07";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.whatTimeIsIt( _time ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    MirroredClock ___test;
    string _time = "10:00";
    string expected_result = "02:00";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.whatTimeIsIt( _time ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
string MirroredClock::whatTimeIsIt( string time )
{
    vs s( split( time, ':' ) );
    int h = stoi( s[0] );
    int m = stoi( s[1] );
    int x = (720 - h * 60 - m) % 720;
    return to_string(100 + x / 60).substr( 1 ) + ":" + to_string(100 + x % 60).substr(1);
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve: TEST, MirroredClock
    return RUN_ALL_TESTS();
}
// END CUT HERE
