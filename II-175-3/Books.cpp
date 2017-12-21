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
typedef vector<int> vi;
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct Books
{
	int sortMoves( vs titles )
	{
		int n = titles.size();
		vi A(n, 0);
		fora(i, titles)
		{
			A[i] = 1;
			for( int j = 0; j < i; ++j )
				if ( titles[j] <= titles[i] )
					A[i] = max( A[i], A[j] + 1 );
		}
		return n - *max_element( all(A) );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<int> A1;
	{ /*Test 0*/string _titles[] = 
	{"Algorithms", "Purely Functional Data Structures",
"Intro to C", "Automata and Computability"}
	; vs titles(_titles, _titles + (sizeof(_titles) / sizeof(_titles[0]))); A0.push_back( titles ); int result = 
	2
	; A1.push_back( result );  }
	{ /*Test 1*/string _titles[] = 
	{"the fellowship of the ring",
"the return of the king",
"The two towers"}
	; vs titles(_titles, _titles + (sizeof(_titles) / sizeof(_titles[0]))); A0.push_back( titles ); int result = 
	1
	; A1.push_back( result );  }
	{ /*Test 2*/string _titles[] = 
	{"Basic Engineering Circuit Analysis", "A Course in Combinatorics",
"Artificial Intelligence", "Asimovs Guide to Shakespeare",
"The Nature of Space and Time", "A Time for Trumpets",
"Essentials of Artificial Intelligence", "Life by the Numbers",
"Cognitive Psychology", "ColdFusion"}
	; vs titles(_titles, _titles + (sizeof(_titles) / sizeof(_titles[0]))); A0.push_back( titles ); int result = 
	5
	; A1.push_back( result );  }
	{ /*Test 3*/string _titles[] = 
	{"A", "B", "A", "A", "B"}
	; vs titles(_titles, _titles + (sizeof(_titles) / sizeof(_titles[0]))); A0.push_back( titles ); int result = 
	1
	; A1.push_back( result );  }
	{ /*Test 4*/string _titles[] = 
	{"This Book Has No Title", " This Book Does Have A Title"}
	; vs titles(_titles, _titles + (sizeof(_titles) / sizeof(_titles[0]))); A0.push_back( titles ); int result = 
	1
	; A1.push_back( result );  }
	{ /*Test 5*/string _titles[] = 
	{"What Is The", "What Is The ", "What Is The Title Of This Book"}
	; vs titles(_titles, _titles + (sizeof(_titles) / sizeof(_titles[0]))); A0.push_back( titles ); int result = 
	0
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], sortMoves( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Books ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
