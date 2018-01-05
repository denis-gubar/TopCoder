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
struct FallingSand
{
    vector <string> simulate( vector <string> board );
};
// BEGIN CUT HERE
TEST( TopCoderMain, Test0 )
{
    FallingSand ___test;
    vector <string> _board = {"ooooo",
 "..x..",
 "....x",
 ".....",
 "....o"};
    vector <string> expected_result = {"..o..", "..x.o", "....x", ".....", "oo.oo" };
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.simulate( _board ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test1 )
{
    FallingSand ___test;
    vector <string> _board = {"..o..", 
 "..x.o", 
 "....x", 
 ".....", 
 "oo.oo" };
    vector <string> expected_result = {"..o..", "..x.o", "....x", ".....", "oo.oo" };
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.simulate( _board ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test2 )
{
    FallingSand ___test;
    vector <string> _board = {"ooooxooo.ooxo.oxoxoooox.....x.oo"};
    vector <string> expected_result = {"ooooxooo.ooxo.oxoxoooox.....x.oo" };
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.simulate( _board ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test3 )
{
    FallingSand ___test;
    vector <string> _board = {"o",
 ".",
 "o",
 ".",
 "o",
 ".",
 "."};
    vector <string> expected_result = {".", ".", ".", ".", "o", "o", "o" };
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.simulate( _board ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test4 )
{
    FallingSand ___test;
    vector <string> _board = {"oxxxxooo",
 "xooooxxx",
 "..xx.ooo",
 "oooox.o.",
 "..x....."};
    vector <string> expected_result = {"oxxxxooo", "x.oo.xxx", "..xxo...", ".oo.x.o.", "ooxo.ooo" };
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.simulate( _board ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, Test5 )
{
    FallingSand ___test;
    vector <string> _board = {"..o..o..o..o..o..o..o..o..o..o..o",
 "o..o..o..o..o..o..o..o..o..o..o..",
 ".o..o..o..o..o..o..o..o..o..o..o.",
 "...xxx...xxx...xxxxxxxxx...xxx...",
 "...xxx...xxx...xxxxxxxxx...xxx...",
 "...xxx...xxx......xxx......xxx...",
 "...xxxxxxxxx......xxx......xxx...",
 "...xxxxxxxxx......xxx......xxx...",
 "...xxxxxxxxx......xxx......xxx...",
 "...xxx...xxx......xxx............",
 "...xxx...xxx...xxxxxxxxx...xxx...",
 "...xxx...xxx...xxxxxxxxx...xxx...",
 "..o..o..o..o..o..o..o..o..o..o..o",
 "o..o..o..o..o..o..o..o..o..o..o..",
 ".o..o..o..o..o..o..o..o..o..o..o."};
    vector <string> expected_result = {".................................", ".................................", "...ooo...ooo...ooooooooo...ooo...", "...xxx...xxx...xxxxxxxxx...xxx...", "...xxx...xxx...xxxxxxxxx...xxx...", "...xxxoooxxx......xxx......xxx...", "...xxxxxxxxx......xxx......xxx...", "...xxxxxxxxx......xxx......xxx...", "...xxxxxxxxx......xxx......xxx...", "...xxx...xxx......xxx............", "...xxx...xxx...xxxxxxxxx...xxx...", "...xxx...xxx...xxxxxxxxx...xxx...", ".................................", "ooo.........ooo.........ooo...ooo", "ooooooooooooooooooooooooooooooooo" };
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.simulate( _board ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
TEST( TopCoderMain, MyTest )
{
    FallingSand ___test;
    vector <string> _board = {"ooooo",
 "..x..",
 "....x",
 ".....",
 "....o"};
    vector <string> expected_result = {"..o..", "..x.o", "....x", ".....", "oo.oo" };
    TEST_TIMEOUT_BEGIN
        EXPECT_EQ( expected_result, ___test.simulate( _board ) );
    TEST_TIMEOUT_FAIL_END( 2000 )
}
// END CUT HERE
vector <string> FallingSand::simulate( vector <string> board )
{
    vector <string> result(board);
    for( int i = result.size() - 1; i >= 0; --i )
        for( int j = 0; j < result[0].size(); ++j )
            if (result[i][j] == 'o')
            {
                int x = i;
                result[i][j] = '.';
                while (x + 1 < result.size() && result[x + 1][j] == '.')
                    ++x;
                result[x][j] = 'o';
            }
    return result;
}
// BEGIN CUT HERE
int main( int argc, char **argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::GTEST_FLAG( filter ) = "TopCoderMain.Test*";
    //::testing::GTEST_FLAG( filter ) = "TopCoderMain.MyTest*";
    //RemoveUnusedCode preserve TEST FallingSand
    return RUN_ALL_TESTS();
}
// END CUT HERE
