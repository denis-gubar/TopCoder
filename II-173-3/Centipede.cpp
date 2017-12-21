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
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
using namespace std;
// BEGIN CUT HERE
*/
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE
typedef vector<string> vs;
struct Centipede
{
	int n, x, y, dir, k;
	void step( const vs& screenLayout )
	{
		++k;
		if ( x < n )
		{
			if ( screenLayout[x][y + dir] == ' ' ) y += dir;
			else if ( x < n - 1 && screenLayout[x + 1][y] == ' ' )
			{
				dir = -dir; ++x;
			}
			else if ( x < n - 1 ) dir = -dir;
			else ++x;
		}
	}
	vs simulate( vs screenLayout, int timeUnits )
	{
		vs result(screenLayout);
		n = screenLayout.size();
		x = 0; y = 10; dir = 1; k = 9;
		while( x < n )
			step( screenLayout );
		timeUnits %= k;
		x = 0; y = 10; dir = 1; k = 0;
        while( k < timeUnits - 10 )
			step( screenLayout );
		if ( timeUnits < 10 )
		{
			y = timeUnits;
			k = timeUnits - 10;
		}
		while( k < timeUnits )
		{
			step( screenLayout );
            if ( x < n ) result[x][y] = 'x';
		}
		return result;
	}
	// BEGIN CUT HERE
	private:
	template <typename T> string print_array( const vector<T>& v ) { ostringstream os; os << "{ "; for( typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it ) os << '\"' << *it << "\","; os << " }"; return os.str(); }
	template<typename T> void verify_case( int Case, const vector<T>& expected, const vector<T>& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: " << print_array( expected ) << endl; cerr << "\tReceived: " << print_array( received ) << endl; } }
	void verify_case( int Case, const long long& expected, const long long& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const double& expected, const double& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const int& expected, const int& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const string& expected, const string& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	public:
	void run_test( int Case = -1 ) { vector<vs> A0; vector<int> A1; vector<vs> A2;
	{ /*Test 0*/string _screenLayout[] = 
	{"#                #",
 "# #      #       #",
 "#   #    #   #   #",
 "#           #    #",
 "#   ##         # #",
 "# #      ##      #",
 "#    #           #",
 "#                #"}
	; vs screenLayout(_screenLayout, _screenLayout + (sizeof(_screenLayout) / sizeof(_screenLayout[0]))); A0.push_back( screenLayout ); int timeUnits = 
	24
	; A1.push_back( timeUnits ); string _result[] = 
	{ "#                #",  "# #      #       #",  "#   #    #xxx#   #",  "#         xx#    #",  "#   ##   xxx   # #",  "# #      ##      #",  "#    #           #",  "#                #" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 1*/string _screenLayout[] = 
	{"#          #",
 "#          #"}
	; vs screenLayout(_screenLayout, _screenLayout + (sizeof(_screenLayout) / sizeof(_screenLayout[0]))); A0.push_back( screenLayout ); int timeUnits = 
	16
	; A1.push_back( timeUnits ); string _result[] = 
	{ "#          #",  "#xxxx      #" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 2*/string _screenLayout[] = 
	{"#            #",
 "#     #      #",
 "#            #"}
	; vs screenLayout(_screenLayout, _screenLayout + (sizeof(_screenLayout) / sizeof(_screenLayout[0]))); A0.push_back( screenLayout ); int timeUnits = 
	24
	; A1.push_back( timeUnits ); string _result[] = 
	{ "#xxxxxxxxxx  #",  "#     #      #",  "#            #" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 3*/string _screenLayout[] = 
	{"#                        #",
 "#      #                 #",
 "#                 #      #",
 "#  ##    #               #",
 "#              #    #    #",
 "#     #                  #",
 "#       #          #     #",
 "#          #             #",
 "#              #         #"}
	; vs screenLayout(_screenLayout, _screenLayout + (sizeof(_screenLayout) / sizeof(_screenLayout[0]))); A0.push_back( screenLayout ); int timeUnits = 
	74607
	; A1.push_back( timeUnits ); string _result[] = 
	{ "#                        #",  "#      #                 #",  "#                 #      #",  "#  ##    #               #",  "#              #    #    #",  "#     #xxxxxxx           #",  "#      x#          #     #",  "#     xx   #             #",  "#              #         #" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 4*/string _screenLayout[] = 
	{"#                            #",
 "#   #     # # #           # ##",
 "#   #       #                #",
 "#                          # #",
 "#                   #        #",
 "##    #           #        # #",
 "#    #    #   #              #",
 "#  #    #  #          #      #",
 "#     #   #       #          #",
 "#                            #",
 "#     #        #         #   #",
 "#   ###          #        #  #",
 "#           ##             # #",
 "#                     #      #",
 "##           #               #",
 "#     #     #   #     # #    #",
 "#          #  ##   #         #",
 "#                    #       #",
 "#                    #  #    #"}
	; vs screenLayout(_screenLayout, _screenLayout + (sizeof(_screenLayout) / sizeof(_screenLayout[0]))); A0.push_back( screenLayout ); int timeUnits = 
	598273167
	; A1.push_back( timeUnits ); string _result[] = 
	{ "#                            #",  "#   #     # # #           # ##",  "#   #       #                #",  "#                          # #",  "#                   #        #",  "##    #           #        # #",  "#    #    #   #              #",  "#  #    #  #          #      #",  "#     #   #       #          #",  "#                         xxx#",  "#     #        #         #xxx#",  "#   ###          #        # x#",  "#           ##             # #",  "#                     #      #",  "##           #               #",  "#     #     #   #     # #    #",  "#          #  ##   #         #",  "#                    #       #",  "#                    #  #    #" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], simulate( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Centipede ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
