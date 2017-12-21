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
typedef vector<int> vi;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct WordParts
{
	int partCount( string original, string compound )
	{
		vi A(compound.size() + 1, 100);
		A[0] = 0;
		fora(i, compound)
			if ( compound[i] < 100 )
				fora(j, original)
				{
					if ( original.substr( 0, j + 1 ) == compound.substr(i, j + 1) )
						A[i + j + 1] = min( A[i + j + 1], A[i] + 1 );
					if ( original.substr( j ) == compound.substr(i, original.size() - j) )
						A[i + original.size() - j] = min( A[i + original.size() - j], A[i] + 1 );
				}
		return A.back() < 100 ? A.back() : -1;
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
	{ /*Test 0*/string original = 
	"ANTIDISESTABLISHMENTARIANISM"
	; A0.push_back( original ); string compound = 
	"ANTIDISIANISMISM"
	; A1.push_back( compound ); int result = 
	3
	; A2.push_back( result );  }
	{ /*Test 1*/string original = 
	"ANTIDISESTABLISHMENTARIANISM"
	; A0.push_back( original ); string compound = 
	"ESTABLISHMENT"
	; A1.push_back( compound ); int result = 
	-1
	; A2.push_back( result );  }
	{ /*Test 2*/string original = 
	"TOPCODERDOTCOM"
	; A0.push_back( original ); string compound = 
	"TOMTMODERDOTCOM"
	; A1.push_back( compound ); int result = 
	5
	; A2.push_back( result );  }
	{ /*Test 3*/string original = 
	"HELLO"
	; A0.push_back( original ); string compound = 
	"HELLOHEHELLOLOHELLO"
	; A1.push_back( compound ); int result = 
	5
	; A2.push_back( result );  }
	{ /*Test 4*/string original = 
	"DONTFORGETTHEEMPTYCASE"
	; A0.push_back( original ); string compound = 
	""
	; A1.push_back( compound ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 5*/string original = 
	"BAAABA"
	; A0.push_back( original ); string compound = 
	"BAAABAAA"
	; A1.push_back( compound ); int result = 
	2
	; A2.push_back( result );  }
	{ /*Test 6*/string original = 
	"ABBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABB"
	; A0.push_back( original ); string compound = 
	"BBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABAA"
	; A1.push_back( compound ); int result = 
	17
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], partCount( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	WordParts ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
