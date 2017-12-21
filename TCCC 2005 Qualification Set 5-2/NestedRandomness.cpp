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
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE
typedef long long lint;
typedef vector<double> vd;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct NestedRandomness
{
	double probability( int N, int nestings, int target )
	{
		vd a(N, 1.0 / N);
		for( int step = 1; step < nestings; ++step )
		{
			vd b(N, 0);
			fora(i, b)
				for( int j = i + 1; j < N; ++j )
					b[i] += a[j] / j;
			a = b;
		}
		return a[target];
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<int> A2; vector<double> A3;
	{ /*Test 0*/int Arg0 = 
	5
	; A0.push_back( Arg0 ); int Arg1 = 
	2
	; A1.push_back( Arg1 ); int Arg2 = 
	1
	; A2.push_back( Arg2 ); double Arg3 = 
	0.21666666666666667
	; A3.push_back( Arg3 );  }
	{ /*Test 1*/int Arg0 = 
	10
	; A0.push_back( Arg0 ); int Arg1 = 
	4
	; A1.push_back( Arg1 ); int Arg2 = 
	0
	; A2.push_back( Arg2 ); double Arg3 = 
	0.19942680776014104
	; A3.push_back( Arg3 );  }
	{ /*Test 2*/int Arg0 = 
	1000
	; A0.push_back( Arg0 ); int Arg1 = 
	10
	; A1.push_back( Arg1 ); int Arg2 = 
	990
	; A2.push_back( Arg2 ); double Arg3 = 
	1.0461776397050886E-30
	; A3.push_back( Arg3 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], probability( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	NestedRandomness ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
