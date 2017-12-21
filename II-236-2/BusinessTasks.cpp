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
typedef vector<string> vs;
struct BusinessTasks
{
	string getTask( vs list, int n )
	{
		vs result(list);
		int k = 0;
		for( int i = 1; i < list.size(); ++i )
			result.erase( result.begin() + (k = (k + n - 1) % result.size()) );
		return result[0];
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<int> A1; vector<string> A2;
	{ /*Test 0*/string _list[] = 
	{"a","b","c","d"}
	; vs list(_list, _list + (sizeof(_list) / sizeof(_list[0]))); A0.push_back( list ); int n = 
	2
	; A1.push_back( n ); string result = 
	"a"
	; A2.push_back( result );  }
	{ /*Test 1*/string _list[] = 
	{"a","b","c","d","e"}
	; vs list(_list, _list + (sizeof(_list) / sizeof(_list[0]))); A0.push_back( list ); int n = 
	3
	; A1.push_back( n ); string result = 
	"d"
	; A2.push_back( result );  }
	{ /*Test 2*/string _list[] = 
	{"alpha","beta","gamma","delta","epsilon"}
	; vs list(_list, _list + (sizeof(_list) / sizeof(_list[0]))); A0.push_back( list ); int n = 
	1
	; A1.push_back( n ); string result = 
	"epsilon"
	; A2.push_back( result );  }
	{ /*Test 3*/string _list[] = 
	{"a","b"}
	; vs list(_list, _list + (sizeof(_list) / sizeof(_list[0]))); A0.push_back( list ); int n = 
	1000
	; A1.push_back( n ); string result = 
	"a"
	; A2.push_back( result );  }
	{ /*Test 4*/string _list[] = 
	{"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t",
"u","v","w","x","y","z"}
	; vs list(_list, _list + (sizeof(_list) / sizeof(_list[0]))); A0.push_back( list ); int n = 
	17
	; A1.push_back( n ); string result = 
	"n"
	; A2.push_back( result );  }
	{ /*Test 5*/string _list[] = 
	{"zlqamum","yjsrpybmq","tjllfea","fxjqzznvg","nvhekxr","am","skmazcey","piklp",
"olcqvhg","dnpo","bhcfc","y","h","fj","bjeoaxglt","oafduixsz","kmtbaxu",
"qgcxjbfx","my","mlhy","bt","bo","q"}
	; vs list(_list, _list + (sizeof(_list) / sizeof(_list[0]))); A0.push_back( list ); int n = 
	9000000
	; A1.push_back( n ); string result = 
	"fxjqzznvg"
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], getTask( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	BusinessTasks ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
