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
typedef vector<double> vd;
#define all(v) (v).begin(), (v).end()
struct FixedPointTheorem
{
	double cycleRange( double R )
	{
		vd F; double x = .25;
		for( int i = 0; i <	200000; ++i )
			x = R * x * (1 - x);
		for( int i = 0; i < 1000; ++i )
			F.push_back( x = R * x * (1 - x) );
		return *max_element( all(F) ) - *min_element( all(F) );
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
	void run_test( int Case = -1 ) { vector<double> A0; vector<double> A1;
	{ /*Test 0*/double R = 
	0.1
	; A0.push_back( R ); double result = 
	0.0
	; A1.push_back( result );  }
	{ /*Test 1*/double R = 
	3.05
	; A0.push_back( R ); double result = 
	0.14754098360655865
	; A1.push_back( result );  }
	{ /*Test 2*/double R = 
	3.4499
	; A0.push_back( R ); double result = 
	0.4175631735867292
	; A1.push_back( result );  }
	{ /*Test 3*/double R = 
	3.55
	; A0.push_back( R ); double result = 
	0.5325704489850351
	; A1.push_back( result );  }
	{ /*Test 4*/double R = 
	3.565
	; A0.push_back( R ); double result = 
	0.5454276003030636
	; A1.push_back( result );  }
	{ /*Test 5*/double R = 
	3.5689
	; A0.push_back( R ); double result = 
	0.5489996297493569
	; A1.push_back( result );  }
	{ /*Test 6*/double R = 
	3.00005
	; A0.push_back( R ); double result = 
	0.004713996108955176
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], cycleRange( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	FixedPointTheorem ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
