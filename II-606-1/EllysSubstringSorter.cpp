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
struct EllysSubstringSorter
{
    string getMin( string S, int L );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    EllysSubstringSorter ___test;
    string _S = "TOPCODER";
    int _L = 4;
    string expected_result = "COPTODER";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getMin( _S, _L ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    EllysSubstringSorter ___test;
    string _S = "ESPRIT";
    int _L = 3;
    string expected_result = "EPRSIT";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getMin( _S, _L ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    EllysSubstringSorter ___test;
    string _S = "AAAAAAAAA";
    int _L = 2;
    string expected_result = "AAAAAAAAA";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getMin( _S, _L ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    EllysSubstringSorter ___test;
    string _S = "ABRACADABRA";
    int _L = 5;
    string expected_result = "AAABCRDABRA";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getMin( _S, _L ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test4 )
{
    EllysSubstringSorter ___test;
    string _S = "BAZINGA";
    int _L = 6;
    string expected_result = "ABGINZA";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getMin( _S, _L ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test5 )
{
    EllysSubstringSorter ___test;
    string _S = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
    int _L = 21;
    string expected_result = "AAAAAABDDDEEIIIJOOSUWWWWDBPOAWDUISAWDOOPAWD";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getMin( _S, _L ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    EllysSubstringSorter ___test;
    string _S = "TOPCODER";
    int _L = 4;
    string expected_result = "COPTODER";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getMin( _S, _L ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
string EllysSubstringSorter::getMin( string S, int L )
{
    vs results;
    for (int i = 0; i <= S.size() - L; ++i)
    {
        string s = S;
        sort( s.begin() + i, s.begin() + i + L );
        results.push_back( s );
    }
    return *min_element(results.begin(), results.end());
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve TEST EllysSubstringSorter
    return RUN_ALL_TESTS();
}
// END CUT HERE
