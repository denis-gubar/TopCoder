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
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
struct TennisRallies
{
	int howMany( int numLength, vs forbidden, int allowed )
	{
		int result = 0;
		vi f(forbidden.size(), 0);
		fora2(i, j, forbidden)
			f[i] = (f[i] << 1) | (forbidden[i][j] == 'c');
		for( int i = 0; i < 1 << numLength; ++i )
		{
			int count = 0;
			fora(j, f)
			{
				for(int k = 0; k + forbidden[j].size() <= numLength; ++k )
					if ( ((i & (((1 << forbidden[j].size()) - 1) << k)) ^ (f[j] << k)) == 0 )
					{
						++count;
						if ( count == allowed ) break;
					}
				if ( count == allowed ) break;
			}
			if ( count < allowed ) ++result;
		}
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<vs> A1; vector<int> A2; vector<int> A3;
	{ /*Test 0*/int numLength = 
	3
	; A0.push_back( numLength ); string _forbidden[] = 
	{"cc","dd"}
	; vs forbidden(_forbidden, _forbidden + (sizeof(_forbidden) / sizeof(_forbidden[0]))); A1.push_back( forbidden ); int allowed = 
	1
	; A2.push_back( allowed ); int result = 
	2
	; A3.push_back( result );  }
	{ /*Test 1*/int numLength = 
	10
	; A0.push_back( numLength ); string _forbidden[] = 
	{"c"}
	; vs forbidden(_forbidden, _forbidden + (sizeof(_forbidden) / sizeof(_forbidden[0]))); A1.push_back( forbidden ); int allowed = 
	1
	; A2.push_back( allowed ); int result = 
	1
	; A3.push_back( result );  }
	{ /*Test 2*/int numLength = 
	10
	; A0.push_back( numLength ); string _forbidden[] = 
	{"c"}
	; vs forbidden(_forbidden, _forbidden + (sizeof(_forbidden) / sizeof(_forbidden[0]))); A1.push_back( forbidden ); int allowed = 
	2
	; A2.push_back( allowed ); int result = 
	11
	; A3.push_back( result );  }
	{ /*Test 3*/int numLength = 
	18
	; A0.push_back( numLength ); string _forbidden[] = 
	{"c","d"}
	; vs forbidden(_forbidden, _forbidden + (sizeof(_forbidden) / sizeof(_forbidden[0]))); A1.push_back( forbidden ); int allowed = 
	1
	; A2.push_back( allowed ); int result = 
	0
	; A3.push_back( result );  }
	{ /*Test 4*/int numLength = 
	18
	; A0.push_back( numLength ); vs forbidden; A1.push_back( forbidden ); int allowed = 
	1
	; A2.push_back( allowed ); int result = 
	262144
	; A3.push_back( result );  }
	{ /*Test 5*/int numLength = 
	18
	; A0.push_back( numLength ); string _forbidden[] = 
	{"c","cc","ccc","cccc","ccccc","cccccc","ccccccc",
 "cccccccc","ccccccccc","cccccccccc"}
	; vs forbidden(_forbidden, _forbidden + (sizeof(_forbidden) / sizeof(_forbidden[0]))); A1.push_back( forbidden ); int allowed = 
	100
	; A2.push_back( allowed ); int result = 
	262122
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], howMany( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	TennisRallies ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
