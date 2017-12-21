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
#define all(v) (v).begin(), (v).end()
struct GoldenChain
{
	int minCuts( vi sections )
	{
		int result = 0, j = 0;
		sort( all(sections) );
		for( int i = 0; i < sections.size(); ++i )
			if ( sections[j] )
			{
				--sections[j]; ++result;
			}
			else ++j;
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<int> A1;
	{ /*Test 0*/int _sections[] = 
	{3,3,3,3}
	; vi sections(_sections, _sections + (sizeof(_sections) / sizeof(_sections[0]))); A0.push_back( sections ); int result = 
	3
	; A1.push_back( result );  }
	{ /*Test 1*/int _sections[] = 
	{2000000000}
	; vi sections(_sections, _sections + (sizeof(_sections) / sizeof(_sections[0]))); A0.push_back( sections ); int result = 
	1
	; A1.push_back( result );  }
	{ /*Test 2*/int _sections[] = 
	{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,
38,39,40,41,42,43,44,45,46,47,48,49,50}
	; vi sections(_sections, _sections + (sizeof(_sections) / sizeof(_sections[0]))); A0.push_back( sections ); int result = 
	42
	; A1.push_back( result );  }
	{ /*Test 3*/int _sections[] = 
	{20000000,20000000,2000000000}
	; vi sections(_sections, _sections + (sizeof(_sections) / sizeof(_sections[0]))); A0.push_back( sections ); int result = 
	3
	; A1.push_back( result );  }
	{ /*Test 4*/int _sections[] = 
	{10,10,10,10,10,1,1,1,1,1}
	; vi sections(_sections, _sections + (sizeof(_sections) / sizeof(_sections[0]))); A0.push_back( sections ); int result = 
	5
	; A1.push_back( result );  }
	{ /*Test 5*/int _sections[] = 
	{1,10}
	; vi sections(_sections, _sections + (sizeof(_sections) / sizeof(_sections[0]))); A0.push_back( sections ); int result = 
	1
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], minCuts( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	GoldenChain ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
