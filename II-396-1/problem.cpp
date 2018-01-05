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
struct VerifyCreditCard
{
    string checkDigits( string cardNumber );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    VerifyCreditCard ___test;
    string _cardNumber = "21378";
    string expected_result = "VALID";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.checkDigits( _cardNumber ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    VerifyCreditCard ___test;
    string _cardNumber = "31378";
    string expected_result = "INVALID";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.checkDigits( _cardNumber ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    VerifyCreditCard ___test;
    string _cardNumber = "11111101";
    string expected_result = "VALID";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.checkDigits( _cardNumber ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    VerifyCreditCard ___test;
    string _cardNumber = "50005";
    string expected_result = "VALID";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.checkDigits( _cardNumber ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test4 )
{
    VerifyCreditCard ___test;
    string _cardNumber = "542987223412";
    string expected_result = "INVALID";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.checkDigits( _cardNumber ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    VerifyCreditCard ___test;
    string _cardNumber = "21378";
    string expected_result = "VALID";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.checkDigits( _cardNumber ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
string VerifyCreditCard::checkDigits( string cardNumber )
{
    int n = cardNumber.size();
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        int c = cardNumber[i] - '0';
        if ((n % 2 == 0) ^ (i % 2 == 1))
           k += c * 2 + (c > 4 ? 1 : 0);
        else
           k += c;
    }
    if (k % 10 == 0)
        return "VALID";
    return "INVALID";
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve: TEST, VerifyCreditCard
    return RUN_ALL_TESTS();
}
// END CUT HERE
