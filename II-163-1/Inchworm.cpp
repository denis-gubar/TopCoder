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
struct Inchworm
{
	int lunchtime( int branch, int rest, int leaf )
	{
		int result = 0;
		for( int i = 0; i <= branch; i += rest )
			if ( i % leaf == 0 )
				++result;
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<int> A2; vector<int> A3;
	{ /*Test 0*/int branch = 
	11
	; A0.push_back( branch ); int rest = 
	2
	; A1.push_back( rest ); int leaf = 
	4
	; A2.push_back( leaf ); int result = 
	3
	; A3.push_back( result );  }
	{ /*Test 1*/int branch = 
	12
	; A0.push_back( branch ); int rest = 
	6
	; A1.push_back( rest ); int leaf = 
	4
	; A2.push_back( leaf ); int result = 
	2
	; A3.push_back( result );  }
	{ /*Test 2*/int branch = 
	20
	; A0.push_back( branch ); int rest = 
	3
	; A1.push_back( rest ); int leaf = 
	7
	; A2.push_back( leaf ); int result = 
	1
	; A3.push_back( result );  }
	{ /*Test 3*/int branch = 
	21
	; A0.push_back( branch ); int rest = 
	7
	; A1.push_back( rest ); int leaf = 
	3
	; A2.push_back( leaf ); int result = 
	2
	; A3.push_back( result );  }
	{ /*Test 4*/int branch = 
	15
	; A0.push_back( branch ); int rest = 
	16
	; A1.push_back( rest ); int leaf = 
	5
	; A2.push_back( leaf ); int result = 
	1
	; A3.push_back( result );  }
	{ /*Test 5*/int branch = 
	1000
	; A0.push_back( branch ); int rest = 
	3
	; A1.push_back( rest ); int leaf = 
	7
	; A2.push_back( leaf ); int result = 
	48
	; A3.push_back( result );  }
	{ /*Test 6*/int branch = 
	1000
	; A0.push_back( branch ); int rest = 
	7
	; A1.push_back( rest ); int leaf = 
	3
	; A2.push_back( leaf ); int result = 
	48
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], lunchtime( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Inchworm ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
