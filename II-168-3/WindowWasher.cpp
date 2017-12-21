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
#define all(v) (v).begin(), (v).end()
struct WindowWasher
{
	int fastest( int width, int height, vi washTimes )
	{
		vi work(washTimes.size(), 0);
		for( int i = 0; i < width; ++i )
		{
			int x = 0;
			fora(i, work)
				if ( work[x] + washTimes[x] > work[i] + washTimes[i] )
					x = i;
			work[x] += washTimes[x];
		}
		sort( all(work), greater<int>() );
		return work[0] * height;
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<vi> A2; vector<int> A3;
	{ /*Test 0*/int width = 
	10
	; A0.push_back( width ); int height = 
	10
	; A1.push_back( height ); int _washTimes[] = 
	{60}
	; vi washTimes(_washTimes, _washTimes + (sizeof(_washTimes) / sizeof(_washTimes[0]))); A2.push_back( washTimes ); int result = 
	6000
	; A3.push_back( result );  }
	{ /*Test 1*/int width = 
	10
	; A0.push_back( width ); int height = 
	10
	; A1.push_back( height ); int _washTimes[] = 
	{60, 60}
	; vi washTimes(_washTimes, _washTimes + (sizeof(_washTimes) / sizeof(_washTimes[0]))); A2.push_back( washTimes ); int result = 
	3000
	; A3.push_back( result );  }
	{ /*Test 2*/int width = 
	10
	; A0.push_back( width ); int height = 
	10
	; A1.push_back( height ); int _washTimes[] = 
	{60, 30}
	; vi washTimes(_washTimes, _washTimes + (sizeof(_washTimes) / sizeof(_washTimes[0]))); A2.push_back( washTimes ); int result = 
	2100
	; A3.push_back( result );  }
	{ /*Test 3*/int width = 
	1000
	; A0.push_back( width ); int height = 
	1000
	; A1.push_back( height ); int _washTimes[] = 
	{1000}
	; vi washTimes(_washTimes, _washTimes + (sizeof(_washTimes) / sizeof(_washTimes[0]))); A2.push_back( washTimes ); int result = 
	1000000000
	; A3.push_back( result );  }
	{ /*Test 4*/int width = 
	421
	; A0.push_back( width ); int height = 
	936
	; A1.push_back( height ); int _washTimes[] = 
	{111,56,931,22,445,90,14,222}
	; vi washTimes(_washTimes, _washTimes + (sizeof(_washTimes) / sizeof(_washTimes[0]))); A2.push_back( washTimes ); int result = 
	2450448
	; A3.push_back( result );  }
	{ /*Test 5*/int width = 
	25
	; A0.push_back( width ); int height = 
	25
	; A1.push_back( height ); int _washTimes[] = 
	{1,625}
	; vi washTimes(_washTimes, _washTimes + (sizeof(_washTimes) / sizeof(_washTimes[0]))); A2.push_back( washTimes ); int result = 
	625
	; A3.push_back( result );  }
	{ /*Test 6*/int width = 
	12
	; A0.push_back( width ); int height = 
	754
	; A1.push_back( height ); int _washTimes[] = 
	{728, 734, 147, 464, 6, 703, 254}
	; vi washTimes(_washTimes, _washTimes + (sizeof(_washTimes) / sizeof(_washTimes[0]))); A2.push_back( washTimes ); int result = 
	54288
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], fastest( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	WindowWasher ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
