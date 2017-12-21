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
struct InsideOut
{
	string unscramble( string line )
	{
		reverse( line.begin(), line.begin() + line.size() / 2 );
		reverse( line.begin() + line.size() / 2, line.end() );
		return line;
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<string> A1;
	{ /*Test 0*/string Arg0 = 
	"I ENIL SIHTHSIREBBIG S"
	; A0.push_back( Arg0 ); string Arg1 = 
	"THIS LINE IS GIBBERISH"
	; A1.push_back( Arg1 );  }
	{ /*Test 1*/string Arg0 = 
	"LEVELKAYAK"
	; A0.push_back( Arg0 ); string Arg1 = 
	"LEVELKAYAK"
	; A1.push_back( Arg1 );  }
	{ /*Test 2*/string Arg0 = 
	"H YPPAHSYADILO"
	; A0.push_back( Arg0 ); string Arg1 = 
	"HAPPY HOLIDAYS"
	; A1.push_back( Arg1 );  }
	{ /*Test 3*/string Arg0 = 
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	; A0.push_back( Arg0 ); string Arg1 = 
	"MLKJIHGFEDCBAZYXWVUTSRQPON"
	; A1.push_back( Arg1 );  }
	{ /*Test 4*/string Arg0 = 
	"RUT OWT SNEH HCNERF EERHTEGDIRTRAP A DNA  SEVODELT"
	; A0.push_back( Arg0 ); string Arg1 = 
	"THREE FRENCH HENS TWO TURTLEDOVES  AND A PARTRIDGE"
	; A1.push_back( Arg1 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], unscramble( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	InsideOut ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
