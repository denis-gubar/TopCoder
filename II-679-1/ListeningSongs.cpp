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
struct ListeningSongs
{
    int listen( vector <int> durations1, vector <int> durations2, int minutes, int T );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    ListeningSongs ___test;
    vector <int> _durations1 = {300,200,100};
    vector <int> _durations2 = {400,500,600};
    int _minutes = 17;
    int _T = 1;
    int expected_result = 4;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.listen( _durations1, _durations2, _minutes, _T ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    ListeningSongs ___test;
    vector <int> _durations1 = {300,200,100};
    vector <int> _durations2 = {400,500,600};
    int _minutes = 10;
    int _T = 1;
    int expected_result = 2;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.listen( _durations1, _durations2, _minutes, _T ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    ListeningSongs ___test;
    vector <int> _durations1 = {60,60,60};
    vector <int> _durations2 = {60,60,60};
    int _minutes = 5;
    int _T = 2;
    int expected_result = 5;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.listen( _durations1, _durations2, _minutes, _T ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    ListeningSongs ___test;
    vector <int> _durations1 = {120,120,120,120,120};
    vector <int> _durations2 = {60,60,60,60,60,60};
    int _minutes = 10;
    int _T = 3;
    int expected_result = 7;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.listen( _durations1, _durations2, _minutes, _T ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test4 )
{
    ListeningSongs ___test;
    vector <int> _durations1 = {196,147,201,106,239,332,165,130,205,221,248,108,60};
    vector <int> _durations2 = {280,164,206,95,81,383,96,255,260,244,60,313,101};
    int _minutes = 60;
    int _T = 3;
    int expected_result = 22;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.listen( _durations1, _durations2, _minutes, _T ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test5 )
{
    ListeningSongs ___test;
    vector <int> _durations1 = {100,200,300};
    vector <int> _durations2 = {100,200,300};
    int _minutes = 2;
    int _T = 1;
    int expected_result = -1;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.listen( _durations1, _durations2, _minutes, _T ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test6 )
{
    ListeningSongs ___test;
    vector <int> _durations1 = {100,200,300,400,500,600};
    vector <int> _durations2 = {100,200};
    int _minutes = 1000;
    int _T = 3;
    int expected_result = -1;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.listen( _durations1, _durations2, _minutes, _T ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    ListeningSongs ___test;
    vector <int> _durations1 = {300,200,100};
    vector <int> _durations2 = {400,500,600};
    int _minutes = 17;
    int _T = 1;
    int expected_result = 4;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.listen( _durations1, _durations2, _minutes, _T ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
int ListeningSongs::listen( vector <int> durations1, vector <int> durations2, int minutes, int T )
{
    if (durations1.size() < T || durations2.size() < T)
        return -1;
    sort( durations1.begin(), durations1.end() );
    sort( durations2.begin(), durations2.end() );
    int minTime = accumulate( durations1.begin(), durations1.begin() + T, 0 ) + accumulate( durations2.begin(), durations2.begin() + T, 0 );
    if ( minTime > minutes * 60 )
        return -1;
    int result = 2 * T;
    vi rest( durations1.begin() + T, durations1.end() );
    copy( durations2.begin() + T, durations2.end(), back_inserter( rest ) );
    sort( rest.begin(), rest.end() );
    int x = 0;
    while (x < rest.size() && minTime + rest[x] <= minutes * 60)
    {
        minTime += rest[x];
        ++result;
        ++x;
    }
    return result;
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve TEST ListeningSongs
    return RUN_ALL_TESTS();
}
// END CUT HERE
