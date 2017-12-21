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
struct CCipher
{
	string decode( string cipherText, int shift )
	{
		string result (cipherText);
		fora(i, result)
			result[i] = (result[i] - 'A' - shift + 26) % 26 + 'A';
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<int> A1; vector<string> A2;
	{ /*Test 0*/string cipherText = 
	"VQREQFGT"
	; A0.push_back( cipherText ); int shift = 
	2
	; A1.push_back( shift ); string result = 
	"TOPCODER"
	; A2.push_back( result );  }
	{ /*Test 1*/string cipherText = 
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	; A0.push_back( cipherText ); int shift = 
	10
	; A1.push_back( shift ); string result = 
	"QRSTUVWXYZABCDEFGHIJKLMNOP"
	; A2.push_back( result );  }
	{ /*Test 2*/string cipherText = 
	"TOPCODER"
	; A0.push_back( cipherText ); int shift = 
	0
	; A1.push_back( shift ); string result = 
	"TOPCODER"
	; A2.push_back( result );  }
	{ /*Test 3*/string cipherText = 
	"ZWBGLZ"
	; A0.push_back( cipherText ); int shift = 
	25
	; A1.push_back( shift ); string result = 
	"AXCHMA"
	; A2.push_back( result );  }
	{ /*Test 4*/string cipherText = 
	"DBNPCBQ"
	; A0.push_back( cipherText ); int shift = 
	1
	; A1.push_back( shift ); string result = 
	"CAMOBAP"
	; A2.push_back( result );  }
	{ /*Test 5*/string cipherText = 
	"LIPPSASVPH"
	; A0.push_back( cipherText ); int shift = 
	4
	; A1.push_back( shift ); string result = 
	"HELLOWORLD"
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], decode( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	CCipher ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
