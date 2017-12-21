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
struct Aquarium
{
	int peaceful( int minSize, int maxSize, vi fishSizes )
	{
		int result = maxSize - minSize + 1;
        for( int i = minSize; i <= maxSize; ++i )
            fora(j, fishSizes)            
                if ( i * 10 >= fishSizes[j] && i * 2 <= fishSizes[j] ||
                    fishSizes[j] * 10 >= i && fishSizes[j] * 2 <= i )
                {
                    --result;
                    break;                
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<vi> A2; vector<int> A3;
	{ /*Test 0*/int minSize = 
	1
	; A0.push_back( minSize ); int maxSize = 
	12
	; A1.push_back( maxSize ); int _fishSizes[] = 
	{1}
	; vi fishSizes(_fishSizes, _fishSizes + (sizeof(_fishSizes) / sizeof(_fishSizes[0]))); A2.push_back( fishSizes ); int result = 
	3
	; A3.push_back( result );  }
	{ /*Test 1*/int minSize = 
	1
	; A0.push_back( minSize ); int maxSize = 
	36
	; A1.push_back( maxSize ); int _fishSizes[] = 
	{3}
	; vi fishSizes(_fishSizes, _fishSizes + (sizeof(_fishSizes) / sizeof(_fishSizes[0]))); A2.push_back( fishSizes ); int result = 
	10
	; A3.push_back( result );  }
	{ /*Test 2*/int minSize = 
	1
	; A0.push_back( minSize ); int maxSize = 
	1000
	; A1.push_back( maxSize ); int _fishSizes[] = 
	{10, 100, 500}
	; vi fishSizes(_fishSizes, _fishSizes + (sizeof(_fishSizes) / sizeof(_fishSizes[0]))); A2.push_back( fishSizes ); int result = 
	4
	; A3.push_back( result );  }
	{ /*Test 3*/int minSize = 
	5
	; A0.push_back( minSize ); int maxSize = 
	880
	; A1.push_back( maxSize ); int _fishSizes[] = 
	{1, 3, 9, 27, 243, 729}
	; vi fishSizes(_fishSizes, _fishSizes + (sizeof(_fishSizes) / sizeof(_fishSizes[0]))); A2.push_back( fishSizes ); int result = 
	121
	; A3.push_back( result );  }
	{ /*Test 4*/int minSize = 
	3
	; A0.push_back( minSize ); int maxSize = 
	997
	; A1.push_back( maxSize ); int _fishSizes[] = 
	{10, 11, 12, 13, 14, 16, 82, 83, 84, 85, 720, 730, 740, 750, 760, 770}
	; vi fishSizes(_fishSizes, _fishSizes + (sizeof(_fishSizes) / sizeof(_fishSizes[0]))); A2.push_back( fishSizes ); int result = 
	147
	; A3.push_back( result );  }
	{ /*Test 5*/int minSize = 
	2
	; A0.push_back( minSize ); int maxSize = 
	999
	; A1.push_back( maxSize ); int _fishSizes[] = 
	{941, 797, 120, 45, 7, 120}
	; vi fishSizes(_fishSizes, _fishSizes + (sizeof(_fishSizes) / sizeof(_fishSizes[0]))); A2.push_back( fishSizes ); int result = 
	10
	; A3.push_back( result );  }
	{ /*Test 6*/int minSize = 
	1
	; A0.push_back( minSize ); int maxSize = 
	791
	; A1.push_back( maxSize ); int _fishSizes[] = 
	{1, 4, 12, 25, 79, 556, 625, 800, 801, 950, 952, 954, 956, 958, 980, 1000}
	; vi fishSizes(_fishSizes, _fishSizes + (sizeof(_fishSizes) / sizeof(_fishSizes[0]))); A2.push_back( fishSizes ); int result = 
	1
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], peaceful( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Aquarium ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
