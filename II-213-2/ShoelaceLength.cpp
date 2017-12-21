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
#include <utility>
using namespace std;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE 
typedef long long lint;
struct ShoelaceLength
{
	double calculate( int startWidth, int endWidth, int spread, int numPairs )
	{
		double result = startWidth;
		for( int i = 0; i < numPairs - 1; i++ )
		{
			double a = (1.0 * startWidth * (numPairs - i - 1) + endWidth * i) / (numPairs - 1);
			double b = (1.0 * startWidth * (numPairs - i - 2) + endWidth * (i + 1)) / (numPairs - 1);
			double x = (a + b) / 2;
			result += 2 * sqrt( x*x + spread*spread );
		}
		return result;
	}
	// BEGIN CUT HERE
	private:
	template <typename T> string print_array( const vector<T>& v ) { ostringstream os; os << "{ "; for( typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it ) os << '\"' << *it << "\","; os << " }"; return os.str(); }
	template<typename T> void verify_case( int Case, const vector<T>& expected, const vector<T>& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: " << print_array( expected ) << endl; cerr << "\tReceived: " << print_array( received ) << endl; } }
	void verify_case( int Case, const lint& expected, const lint& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const double& expected, const double& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const int& expected, const int& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const string& expected, const string& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	public:
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<int> A2; vector<int> A3; vector<double> A4;
	{ /*Test 0*/int Arg0 = 
	2
	; A0.push_back( Arg0 ); int Arg1 = 
	2
	; A1.push_back( Arg1 ); int Arg2 = 
	1
	; A2.push_back( Arg2 ); int Arg3 = 
	2
	; A3.push_back( Arg3 ); double Arg4 = 
	6.47213595499958
	; A4.push_back( Arg4 );  }
	{ /*Test 1*/int Arg0 = 
	10
	; A0.push_back( Arg0 ); int Arg1 = 
	1
	; A1.push_back( Arg1 ); int Arg2 = 
	1
	; A2.push_back( Arg2 ); int Arg3 = 
	10
	; A3.push_back( Arg3 ); double Arg4 = 
	111.1786186482248
	; A4.push_back( Arg4 );  }
	{ /*Test 2*/int Arg0 = 
	1
	; A0.push_back( Arg0 ); int Arg1 = 
	10
	; A1.push_back( Arg1 ); int Arg2 = 
	1
	; A2.push_back( Arg2 ); int Arg3 = 
	10
	; A3.push_back( Arg3 ); double Arg4 = 
	102.17861864822481
	; A4.push_back( Arg4 );  }
	{ /*Test 3*/int Arg0 = 
	1
	; A0.push_back( Arg0 ); int Arg1 = 
	1
	; A1.push_back( Arg1 ); int Arg2 = 
	1
	; A2.push_back( Arg2 ); int Arg3 = 
	2
	; A3.push_back( Arg3 ); double Arg4 = 
	3.8284271247461903
	; A4.push_back( Arg4 );  }
	{ /*Test 4*/int Arg0 = 
	1
	; A0.push_back( Arg0 ); int Arg1 = 
	99
	; A1.push_back( Arg1 ); int Arg2 = 
	19
	; A2.push_back( Arg2 ); int Arg3 = 
	2
	; A3.push_back( Arg3 ); double Arg4 = 
	107.97663296253066
	; A4.push_back( Arg4 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A4[i], calculate( A0[i], A1[i], A2[i], A3[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ShoelaceLength ___test;
	___test.run_test();
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
