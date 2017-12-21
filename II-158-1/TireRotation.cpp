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
struct TireRotation
{
	int getCycle( string initial, string current )
	{
		if ( initial == current ) return 1;
		if ( (((initial[0] * 27 + initial[1]) * 27) * 27 + initial[2]) * 27 + initial[3] == (((current[2] * 27 + current[3]) * 27) * 27 + current[1]) * 27 + current[0] ) return 2;
		if ( (((initial[0] * 27 + initial[1]) * 27) * 27 + initial[2]) * 27 + initial[3] == (((current[3] * 27 + current[2]) * 27) * 27 + current[0]) * 27 + current[1] ) return 4;
		if ( (((initial[0] * 27 + initial[1]) * 27) * 27 + initial[2]) * 27 + initial[3] == (((current[1] * 27 + current[0]) * 27) * 27 + current[3]) * 27 + current[2] ) return 3;
		return -1;
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<string> A1; vector<int> A2;
	{ /*Test 0*/string initial = 
	"ABCD"
	; A0.push_back( initial ); string current = 
	"ABCD"
	; A1.push_back( current ); int result = 
	1
	; A2.push_back( result );  }
	{ /*Test 1*/string initial = 
	"ABCD"
	; A0.push_back( initial ); string current = 
	"DCAB"
	; A1.push_back( current ); int result = 
	2
	; A2.push_back( result );  }
	{ /*Test 2*/string initial = 
	"ABCD"
	; A0.push_back( initial ); string current = 
	"CDBA"
	; A1.push_back( current ); int result = 
	4
	; A2.push_back( result );  }
	{ /*Test 3*/string initial = 
	"ABCD"
	; A0.push_back( initial ); string current = 
	"ABDC"
	; A1.push_back( current ); int result = 
	-1
	; A2.push_back( result );  }
	{ /*Test 4*/string initial = 
	"ZAXN"
	; A0.push_back( initial ); string current = 
	"XNAZ"
	; A1.push_back( current ); int result = 
	4
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], getCycle( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	TireRotation ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
