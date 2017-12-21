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
typedef vector<int> vi;
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
struct Shuffling
{
	int position( int cards, vi shuffles )
	{
		int result = 0;
        fora(i, shuffles)
        {
            int k = shuffles[i];
            if ( k < 0 )
            {
                result = (result + cards / 2) % cards;
                k = -k;
            }
            if ( k > 0 )
            {
                if ( result < k || result + k >= cards )
                    continue;
                if ( result < cards / 2 )
                    result += result - k + 1;
                else
                    result += result - cards + k;
            }
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<vi> A1; vector<int> A2;
	{ /*Test 0*/int cards = 
	10
	; A0.push_back( cards ); int _shuffles[] = 
	{ -2 }
	; vi shuffles(_shuffles, _shuffles + (sizeof(_shuffles) / sizeof(_shuffles[0]))); A1.push_back( shuffles ); int result = 
	2
	; A2.push_back( result );  }
	{ /*Test 1*/int cards = 
	52
	; A0.push_back( cards ); int _shuffles[] = 
	{ 1, 17, 12, 26, 9 }
	; vi shuffles(_shuffles, _shuffles + (sizeof(_shuffles) / sizeof(_shuffles[0]))); A1.push_back( shuffles ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 2*/int cards = 
	10
	; A0.push_back( cards ); int _shuffles[] = 
	{ -1, -1, -1, -1, -1, -1, -1, -1, -1 }
	; vi shuffles(_shuffles, _shuffles + (sizeof(_shuffles) / sizeof(_shuffles[0]))); A1.push_back( shuffles ); int result = 
	5
	; A2.push_back( result );  }
	{ /*Test 3*/int cards = 
	100
	; A0.push_back( cards ); int _shuffles[] = 
	{ -50 }
	; vi shuffles(_shuffles, _shuffles + (sizeof(_shuffles) / sizeof(_shuffles[0]))); A1.push_back( shuffles ); int result = 
	50
	; A2.push_back( result );  }
	{ /*Test 4*/int cards = 
	100
	; A0.push_back( cards ); int _shuffles[] = 
	{ -48, -49, -2, 10 }
	; vi shuffles(_shuffles, _shuffles + (sizeof(_shuffles) / sizeof(_shuffles[0]))); A1.push_back( shuffles ); int result = 
	95
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], position( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Shuffling ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
