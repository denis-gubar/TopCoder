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
struct CityMap
{
    string getLegend( vector <string> cityMap, vector <int> POIs );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    CityMap ___test;
    vector <string> _cityMap = {"M....M",
 "...R.M",
 "R..R.R"};
    vector <int> _POIs = {3, 4};
    string expected_result = "MR";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getLegend( _cityMap, _POIs ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    CityMap ___test;
    vector <string> _cityMap = {"XXXXXXXZXYYY"};
    vector <int> _POIs = {1, 8, 3};
    string expected_result = "ZXY";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getLegend( _cityMap, _POIs ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    CityMap ___test;
    vector <string> _cityMap = {"...........",
 "...........",
 "...........",
 "..........T"};
    vector <int> _POIs = {1};
    string expected_result = "T";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getLegend( _cityMap, _POIs ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    CityMap ___test;
    vector <string> _cityMap = {"AIAAARRI.......GOAI.",
 ".O..AIIGI.OAAAGI.A.I",
 ".A.IAAAARI..AI.AAGR.",
 "....IAI..AOIGA.GAIA.",
 "I.AIIIAG...GAR.IIAGA",
 "IA.AOA....I....I.GAA",
 "IOIGRAAAO.AI.AA.RAAA",
 "AI.AAA.AIR.AGRIAAG..",
 "AAAAIAAAI...AAG.RGRA",
 ".J.IA...G.A.AA.II.AA"}
;
    vector <int> _POIs = {16,7,1,35,11,66}
;
    string expected_result = "GOJIRA";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getLegend( _cityMap, _POIs ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    CityMap ___test;
    vector <string> _cityMap = {"M....M",
 "...R.M",
 "R..R.R"};
    vector <int> _POIs = {3, 4};
    string expected_result = "MR";
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.getLegend( _cityMap, _POIs ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
string CityMap::getLegend( vector <string> cityMap, vector <int> POIs )
{
    string result{};
    vi M( 256 );
    for (const string& s : cityMap)
        for (char c : s)
            ++M[c];
    M['.'] = 0;
    for (int x : POIs)
        result += distance( M.begin(), find( M.begin(), M.end(), x ) );
    return result;
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve: TEST, CityMap
    return RUN_ALL_TESTS();
}
// END CUT HERE
