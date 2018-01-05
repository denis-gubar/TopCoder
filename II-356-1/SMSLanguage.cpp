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
string replace_all( const string& s, const string& what, const string& to )
{
    string result;
    int start = 0;
    for (int finish = s.find( what ); finish != string::npos; finish = s.find( what, start ) )
    {
        result.append( s, start, finish - start ).append( to );
        start = finish + what.size();
    }
    result.append( s, start, s.size() - start );
    return result;
}
struct SMSLanguage
{
    string translate( string text );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    SMSLanguage ___test;
    string _text = "I HATE rats, and you?";
    string expected_result = "i h8 r@s & U";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.translate( _text ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    SMSLanguage ___test;
    string _text = "What is the weather like today?";
    string expected_result = "wh@ is the we@her like today";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.translate( _text ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    SMSLanguage ___test;
    string _text = "It is not too late to..";
    string expected_result = "it is not too l8 to";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.translate( _text ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    SMSLanguage ___test;
    string _text = "this text is already in sms language";
    string expected_result = "this text is already in sms language";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.translate( _text ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    SMSLanguage ___test;
    string _text = "I HATE rats, and you?";
    string expected_result = "i h8 r@s & U";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.translate( _text ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
string SMSLanguage::translate( string text )
{
    string result{};
    for (char c : text)
        result += tolower( c );
    result.erase(remove_if(result.begin(), result.end(), [](char c) -> bool
        {
            return string( ".,?!" ).find( c ) != string::npos;
        }), result.end() );
    result = replace_all( result, "you", "U" );
    result = replace_all( result, "ate", "8" );
    result = replace_all( result, "at", "@" );
    result = replace_all( result, "and", "&" );
    return result;
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve: TEST, SMSLanguage
    return RUN_ALL_TESTS();
}
// END CUT HERE
