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
struct BridgeCrossing
{
	int minTime( vi times )
	{
		int n = times.size();
		if ( n == 1 ) return times[0];
		sort( all(times) );
		vi states( 1 << (n + 1), 5000 );
		queue<int> q; q.push( (1 << n) - 1 ); q.push( 0 ); q.push( 1 );
		while( !q.empty() )
		{
			int state = q.front(); q.pop();
			int time = q.front(); q.pop();
			int direction = q.front(); q.pop();
			if ( state )
				if ( direction )
				{
					for( int i = 0; i < n; ++i )
						if ( state & (1 << i) )
							for( int j = i + 1; j < n; ++j )
								if ( state & (1 << j) )
								{
									int newState = state - (1 << i) - (1 << j), newTime = time + times[j];
									if ( states[2 * newState + 1] > newTime )
									{
										states[2 * newState + 1] = newTime;
										q.push( newState ); q.push( newTime ); q.push( !direction );
									}
								}
				}
				else
				{
					for( int j = 0; j < n; ++j )
						if ( !(state & (1 << j)) )
						{
							int newState = state + (1 << j), newTime = time + times[j];
							if ( states[2 * newState] > newTime )
							{
								states[2 * newState] = newTime;
								q.push( newState ); q.push( newTime ); q.push( !direction );
							}
						}
				}
		}
		return states[1];
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
	{ /*Test 0*/int _times[] = 
	{ 1, 2, 5, 10 }
	; vi times(_times, _times + (sizeof(_times) / sizeof(_times[0]))); A0.push_back( times ); int result = 
	17
	; A1.push_back( result );  }
	{ /*Test 1*/int _times[] = 
	{ 1, 2, 3, 4, 5 }
	; vi times(_times, _times + (sizeof(_times) / sizeof(_times[0]))); A0.push_back( times ); int result = 
	16
	; A1.push_back( result );  }
	{ /*Test 2*/int _times[] = 
	{ 100 }
	; vi times(_times, _times + (sizeof(_times) / sizeof(_times[0]))); A0.push_back( times ); int result = 
	100
	; A1.push_back( result );  }
	{ /*Test 3*/int _times[] = 
	{ 1, 2, 3, 50, 99, 100 }
	; vi times(_times, _times + (sizeof(_times) / sizeof(_times[0]))); A0.push_back( times ); int result = 
	162
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], minTime( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	BridgeCrossing ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
