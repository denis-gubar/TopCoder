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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct SuperRot
{
	string decoder( string message )
	{
		string result(message);
		fora(i, result)
			if ( result[i] >= 'a' && result[i] <= 'm' || result[i] >= 'A' && result[i] <= 'M' )
				result[i] += 13;
			else if ( result[i] >= 'n' && result[i] <= 'z' || result[i] >= 'N' && result[i] <= 'Z' )
				result[i] -= 13;
			else if ( result[i] >= '0' && result[i] <= '4' )
				result[i] += 5;
			else if ( result[i] >= '5' && result[i] <= '9' )
				result[i] -= 5;
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<string> A1;
	{ /*Test 0*/string message = 
	"Uryyb 28"
	; A0.push_back( message ); string result = 
	"Hello 73"
	; A1.push_back( result );  }
	{ /*Test 1*/string message = 
	"GbcPbqre"
	; A0.push_back( message ); string result = 
	"TopCoder"
	; A1.push_back( result );  }
	{ /*Test 2*/string message = 
	""
	; A0.push_back( message ); string result = 
	""
	; A1.push_back( result );  }
	{ /*Test 3*/string message = 
	"5678901234"
	; A0.push_back( message ); string result = 
	"0123456789"
	; A1.push_back( result );  }
	{ /*Test 4*/string message = 
	"NnOoPpQqRr AaBbCcDdEe"
	; A0.push_back( message ); string result = 
	"AaBbCcDdEe NnOoPpQqRr"
	; A1.push_back( result );  }
	{ /*Test 5*/string message = 
	"Gvzr vf 54 71 CZ ba Whyl 4gu bs gur lrne 7558 NQ"
	; A0.push_back( message ); string result = 
	"Time is 09 26 PM on July 9th of the year 2003 AD"
	; A1.push_back( result );  }
	{ /*Test 6*/string message = 
	"Gur dhvpx oebja sbk whzcf bire n ynml qbt"
	; A0.push_back( message ); string result = 
	"The quick brown fox jumps over a lazy dog"
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], decoder( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	SuperRot ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
