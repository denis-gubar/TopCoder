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
template<typename T> string ToString( T x )
{
	ostringstream S; S << x; return S.str();
}
struct FormatAmt
{
	string amount( int dollars, int cents )
	{
		string result;
		if ( !dollars ) result = "0";
		int k = 0;
		while( dollars )
		{
			if ( k && k % 3 == 0 )
				result = "," + result;
			result = ToString( dollars % 10 ) + result;
			dollars /= 10;
			++k;
		}
		result = "$" + result + ".";
		if ( cents < 10 )
			result += "0";
		result += ToString( cents );
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<string> A2;
	{ /*Test 0*/int dollars = 
		123456
		; A0.push_back( dollars ); int cents = 
		0
		; A1.push_back( cents ); string result = 
		"$123,456.00"
		; A2.push_back( result );  }
	{ /*Test 1*/int dollars = 
		49734321
		; A0.push_back( dollars ); int cents = 
		9
		; A1.push_back( cents ); string result = 
		"$49,734,321.09"
		; A2.push_back( result );  }
	{ /*Test 2*/int dollars = 
		0
		; A0.push_back( dollars ); int cents = 
		99
		; A1.push_back( cents ); string result = 
		"$0.99"
		; A2.push_back( result );  }
	{ /*Test 3*/int dollars = 
		249
		; A0.push_back( dollars ); int cents = 
		30
		; A1.push_back( cents ); string result = 
		"$249.30"
		; A2.push_back( result );  }
	{ /*Test 4*/int dollars = 
		1000
		; A0.push_back( dollars ); int cents = 
		1
		; A1.push_back( cents ); string result = 
		"$1,000.01"
		; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], amount( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
	// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	FormatAmt ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
