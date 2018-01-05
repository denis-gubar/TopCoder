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
typedef vector<vs> vvs;
struct MnemonicMemory
{
    string getPhrase( string number, vector <string> dictionary );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    MnemonicMemory ___test;
    string _number = "25735";
    vector <string> _dictionary = {"is", "there", "anybody", "out", "there"};
    string expected_result = "is there anybody out there";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getPhrase( _number, _dictionary ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    MnemonicMemory ___test;
    string _number = "31415926";
    vector <string> _dictionary = {"may", "i", "have", "a", "large", "container", "of", "coffee"};
    string expected_result = "may a have i large container of coffee";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getPhrase( _number, _dictionary ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    MnemonicMemory ___test;
    string _number = "1212";
    vector <string> _dictionary = {"a", "aa", "a", "aa"};
    string expected_result = "a aa a aa";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getPhrase( _number, _dictionary ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    MnemonicMemory ___test;
    string _number = "11111111122";
    vector <string> _dictionary = {"a", "b", "d", "c", "a", "e", "f", "z", "zz", "za", "az", "e"};
    string expected_result = "a a b c d e e f z az za";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getPhrase( _number, _dictionary ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test4 )
{
    MnemonicMemory ___test;
    string _number = "2222";
    vector <string> _dictionary = {"ab", "cd", "ef", "a", "b", "ab"};
    string expected_result = "ab ab cd ef";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getPhrase( _number, _dictionary ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    MnemonicMemory ___test;
    string _number = "25735";
    vector <string> _dictionary = {"is", "there", "anybody", "out", "there"};
    string expected_result = "is there anybody out there";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getPhrase( _number, _dictionary ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
string MnemonicMemory::getPhrase( string number, vector <string> dictionary )
{
    string result{};
    vvs S( 10 );
    for (const string& s : dictionary)
        S[s.size()].push_back( s );
    for (auto& x : S)
        sort( x.begin(), x.end(), greater<string>() );
    for (char c : number)
    {
        int x = c - '0';
        string s = S[x].back();
        S[x].pop_back();
        result.append( " " ).append( s );
    }
    return result.substr( 1 );
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve: TEST, MnemonicMemory
    return RUN_ALL_TESTS();
}
// END CUT HERE
