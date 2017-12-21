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
struct TextCompressor
{
	string longestRepeat( string sourceText )
	{
		string result;
		int n = sourceText.size();
		for( int i = n / 2; i > 0; --i )
			for( int k = 0; k + 2 * i <= n; ++k )
			{
				string s = sourceText.substr( k, i );
				int j = sourceText.find( s );
				if ( j != string::npos )
				{
					j = sourceText.find( s, j + i );
					if ( j != string::npos )
						return s;
				}
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<string> A1;
	{ /*Test 0*/string Arg0 = 
	"ABCDABCFG"
	; A0.push_back( Arg0 ); string Arg1 = 
	"ABC"
	; A1.push_back( Arg1 );  }
	{ /*Test 1*/string Arg0 = 
	"ABABA"
	; A0.push_back( Arg0 ); string Arg1 = 
	"AB"
	; A1.push_back( Arg1 );  }
	{ /*Test 2*/string Arg0 = 
	"This is a test."
	; A0.push_back( Arg0 ); string Arg1 = 
	"is "
	; A1.push_back( Arg1 );  }
	{ /*Test 3*/string Arg0 = 
	"Testing testing 1 2 3."
	; A0.push_back( Arg0 ); string Arg1 = 
	"esting "
	; A1.push_back( Arg1 );  }
	{ /*Test 4*/string Arg0 = 
	"The quick brown fox jumps over the lazy dog."
	; A0.push_back( Arg0 ); string Arg1 = 
	"he "
	; A1.push_back( Arg1 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], longestRepeat( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	TextCompressor ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
