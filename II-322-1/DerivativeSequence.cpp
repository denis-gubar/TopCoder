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
struct DerivativeSequence
{
    vector <int> derSeq( vector <int> a, int n );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    DerivativeSequence ___test;
    vector <int> _a = {5,6,3,9,-1};
    int _n = 1;
    vector <int> expected_result = {1, -3, 6, -10 };
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.derSeq( _a, _n ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    DerivativeSequence ___test;
    vector <int> _a = {5,6,3,9,-1};
    int _n = 2;
    vector <int> expected_result = {-4, 9, -16 };
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.derSeq( _a, _n ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    DerivativeSequence ___test;
    vector <int> _a = {5,6,3,9,-1};
    int _n = 4;
    vector <int> expected_result = {-38 };
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.derSeq( _a, _n ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    DerivativeSequence ___test;
    vector <int> _a = {4,4,4,4,4,4,4,4};
    int _n = 3;
    vector <int> expected_result = {0, 0, 0, 0, 0 };
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.derSeq( _a, _n ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test4 )
{
    DerivativeSequence ___test;
    vector <int> _a = {-100,100};
    int _n = 0;
    vector <int> expected_result = {-100, 100 };
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.derSeq( _a, _n ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    DerivativeSequence ___test;
    vector <int> _a = {5,6,3,9,-1};
    int _n = 1;
    vector <int> expected_result = {1, -3, 6, -10 };
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.derSeq( _a, _n ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
vector <int> DerivativeSequence::derSeq( vector <int> a, int n )
{
    vector <int> result{a};
    for (int k = 0; k < n; ++k)
    {
        vi next;
        for (int i = 0; i + 1 < result.size(); ++i)
            next.push_back( result[i + 1] - result[i] );
        result = move( next );
    }
    return result;
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve: TEST, DerivativeSequence
    return RUN_ALL_TESTS();
}
// END CUT HERE
