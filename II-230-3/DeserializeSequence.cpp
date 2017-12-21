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
typedef map<int, int> mii;
template<typename T> T FromString( const string& s, const T default_value = T() )
{
	istringstream S( s ); T result(default_value); S >> result; return result;
}
struct DeserializeSequence
{
	mii M;
	int calc( const string& str, int n, int maxx )
	{
		if ( !n ) return 1;
		int q = 2000000 * n + maxx;
		if ( M.find( q ) != M.end() )
			return M[q];
		int result = 0;
		for( int k = n - 1; k >= 0; --k )
		{
			int z = FromString<int>( str.substr( k, n - k ), maxx + 1 );
			if ( z > maxx )
				break;
			if ( z )
				result += calc( str, k, z );
		}
		return M[q] = result;
	}
	int howMany( string str )
	{
		M.clear();
		return calc( str, str.size(), 1000000 );
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<int> A1;
	{ /*Test 0*/string str = 
	"1234"
	; A0.push_back( str ); int result = 
	5
	; A1.push_back( result );  }
	{ /*Test 1*/string str = 
	"000000000001"
	; A0.push_back( str ); int result = 
	1
	; A1.push_back( result );  }
	{ /*Test 2*/string str = 
	"1000000000000"
	; A0.push_back( str ); int result = 
	0
	; A1.push_back( result );  }
	{ /*Test 3*/string str = 
	"9876543210"
	; A0.push_back( str ); int result = 
	5
	; A1.push_back( result );  }
	{ /*Test 4*/string str = 
	"11111111111111111111111111111111111111111111111111"
	; A0.push_back( str ); int result = 
	9192
	; A1.push_back( result );  }
	{ /*Test 5*/string str = 
	"10010010010010010010010010010010010010010010010010"
	; A0.push_back( str ); int result = 
	1217
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], howMany( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	DeserializeSequence ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
