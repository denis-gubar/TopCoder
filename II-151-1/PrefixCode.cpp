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
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
template<typename T> string ToString( T x )
{
	ostringstream S; S << x; return S.str();
}
struct PrefixCode
{
	string isOne( vs words )
	{
		fora(i, words)
			fora(j, words)
				if ( i != j && words[j].find( words[i] ) == 0 )
					return "No, " + ToString( i );
		return "Yes";
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<string> A1;
	{ /*Test 0*/string _words[] = 
	{"trivial"}
	; vs words(_words, _words + (sizeof(_words) / sizeof(_words[0]))); A0.push_back( words ); string result = 
	"Yes"
	; A1.push_back( result );  }
	{ /*Test 1*/string _words[] = 
	{"10001", "011", "100", "001", "10"}
	; vs words(_words, _words + (sizeof(_words) / sizeof(_words[0]))); A0.push_back( words ); string result = 
	"No, 2"
	; A1.push_back( result );  }
	{ /*Test 2*/string _words[] = 
	{"no", "nosy", "neighbors", "needed"}
	; vs words(_words, _words + (sizeof(_words) / sizeof(_words[0]))); A0.push_back( words ); string result = 
	"No, 0"
	; A1.push_back( result );  }
	{ /*Test 3*/string _words[] = 
	{"1010", "11", "100", "0", "1011"}
	; vs words(_words, _words + (sizeof(_words) / sizeof(_words[0]))); A0.push_back( words ); string result = 
	"Yes"
	; A1.push_back( result );  }
	{ /*Test 4*/string _words[] = 
	{"No", "not"}
	; vs words(_words, _words + (sizeof(_words) / sizeof(_words[0]))); A0.push_back( words ); string result = 
	"Yes"
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], isOne( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	PrefixCode ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
