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
struct TournamentsAmbiguityNumber
{
    int scrutinizeTable( vector <string> table );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    TournamentsAmbiguityNumber ___test;
    vector <string> _table = {"-10",
 "0-1",
 "10-"};
    int expected_result = 3;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.scrutinizeTable( _table ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    TournamentsAmbiguityNumber ___test;
    vector <string> _table = {"----",
 "----",
 "----",
 "----"};
    int expected_result = 0;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.scrutinizeTable( _table ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    TournamentsAmbiguityNumber ___test;
    vector <string> _table = {"-1",
 "0-"};
    int expected_result = 0;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.scrutinizeTable( _table ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    TournamentsAmbiguityNumber ___test;
    vector <string> _table = {"--1-10-1---1--1-00",
 "--0110000--0---10-",
 "01--00000100-00011",
 "-0---0010-11110100",
 "001--01-00-0001-1-",
 "11111--100--1-1-01",
 "-1110--00110-11-01",
 "0110-01--100110-10",
 "-111111---01--0-01",
 "--0-1100----10011-",
 "--10--011--1--101-",
 "01101-110-0--1-0-1",
 "---010-0-0---00-11",
 "--101-00-1-01-0-0-",
 "0-110001110-11-110",
 "-010-----011--0--0",
 "11010110100-010--0",
 "1-01-0010--00-111-"};
    int expected_result = 198;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.scrutinizeTable( _table ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    TournamentsAmbiguityNumber ___test;
    vector <string> _table = {"-10",
 "0-1",
 "10-"};
    int expected_result = 3;
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.scrutinizeTable( _table ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
int TournamentsAmbiguityNumber::scrutinizeTable( vector <string> table )
{
    int result{};
    int n = table.size();
    for (int a = 0; a < n; ++a)
        for (int b = 0; b < n; ++b)
            if (a != b)
                for (int c = 0; c < n; ++c)
                    if (a != c && b != c)
                        result += table[a][b] == '1' && table[b][c] == '1' && table[c][a] == '1';
    return result;
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve: TEST, TournamentsAmbiguityNumber
    return RUN_ALL_TESTS();
}
// END CUT HERE
