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
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct GroceryBagger
{
	int minimumBags( int strength, vs itemType )
	{
		int result = 0;
		map<string, int> M;
		fora(i, itemType)
			++M[itemType[i]];
		for( map<string, int>::iterator it = M.begin(); it != M.end(); ++it )
			result += ( it->second + strength - 1 ) / strength;
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<vs> A1; vector<int> A2;
	{ /*Test 0*/int Arg0 = 
	2
	; A0.push_back( Arg0 ); string _Arg1[] = 
	{"DAIRY",
 "DAIRY",
 "PRODUCE",
 "PRODUCE",
 "PRODUCE",
 "MEAT"}
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int Arg2 = 
	4
	; A2.push_back( Arg2 );  }
	{ /*Test 1*/int Arg0 = 
	3
	; A0.push_back( Arg0 ); string _Arg1[] = 
	{"DAIRY",
 "DAIRY",
 "PRODUCE",
 "PRODUCE",
 "PRODUCE",
 "MEAT"}
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int Arg2 = 
	3
	; A2.push_back( Arg2 );  }
	{ /*Test 2*/int Arg0 = 
	10
	; A0.push_back( Arg0 ); vs Arg1; A1.push_back( Arg1 ); int Arg2 = 
	0
	; A2.push_back( Arg2 );  }
	{ /*Test 3*/int Arg0 = 
	5
	; A0.push_back( Arg0 ); string _Arg1[] = 
	{"CANNED",   "CANNED",  "PRODUCE",
 "DAIRY",    "MEAT",    "BREAD",
 "HOUSEHOLD","PRODUCE", "FROZEN",
 "PRODUCE", "DAIRY"}
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int Arg2 = 
	7
	; A2.push_back( Arg2 );  }
	{ /*Test 4*/int Arg0 = 
	2
	; A0.push_back( Arg0 ); string _Arg1[] = 
	{"CANNED",   "CANNED",  "PRODUCE",
 "DAIRY",    "MEAT",    "BREAD",
 "HOUSEHOLD","PRODUCE", "FROZEN",
 "PRODUCE", "DAIRY"}
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int Arg2 = 
	8
	; A2.push_back( Arg2 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], minimumBags( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	GroceryBagger ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
