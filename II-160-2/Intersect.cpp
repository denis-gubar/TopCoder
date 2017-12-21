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
struct Intersect
{
	int area( vi x, vi y )
	{
		sort( x.begin(), x.begin() + 2 );
		sort( y.begin(), y.begin() + 2 );
		for( int i = 2; i < x.size(); i += 2 )
		{
			sort( x.begin() + i, x.begin() + i + 2 );
			sort( y.begin() + i, y.begin() + i + 2 );
			x[0] = max(x[0], x[i]); x[1] = min(x[1], x[i + 1]);
			y[0] = max(y[0], y[i]); y[1] = min(y[1], y[i + 1]);
		}
		return ( x[0] > x[1] || y[0] > y[1] ) ? 0 : (x[1] - x[0]) * (y[1] - y[0]);
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<int> A2;
	{ /*Test 0*/int _x[] = 
	{0,2,3,-4}
	; vi x(_x, _x + (sizeof(_x) / sizeof(_x[0]))); A0.push_back( x ); int _y[] = 
	{17,1000,18,6}
	; vi y(_y, _y + (sizeof(_y) / sizeof(_y[0]))); A1.push_back( y ); int result = 
	2
	; A2.push_back( result );  }
	{ /*Test 1*/int _x[] = 
	{10000,-10000}
	; vi x(_x, _x + (sizeof(_x) / sizeof(_x[0]))); A0.push_back( x ); int _y[] = 
	{-10000,10000}
	; vi y(_y, _y + (sizeof(_y) / sizeof(_y[0]))); A1.push_back( y ); int result = 
	400000000
	; A2.push_back( result );  }
	{ /*Test 2*/int _x[] = 
	{3,8,6,12,10,15}
	; vi x(_x, _x + (sizeof(_x) / sizeof(_x[0]))); A0.push_back( x ); int _y[] = 
	{7,17,7,17,7,17}
	; vi y(_y, _y + (sizeof(_y) / sizeof(_y[0]))); A1.push_back( y ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 3*/int _x[] = 
	{0,0,0,0,0,0,0,0}
	; vi x(_x, _x + (sizeof(_x) / sizeof(_x[0]))); A0.push_back( x ); int _y[] = 
	{5,5,5,5,5,5,5,5}
	; vi y(_y, _y + (sizeof(_y) / sizeof(_y[0]))); A1.push_back( y ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 4*/int _x[] = 
	{2,100,5,32,1000,-20,47,12}
	; vi x(_x, _x + (sizeof(_x) / sizeof(_x[0]))); A0.push_back( x ); int _y[] = 
	{29,-1000,-800,-200,-900,300,-600,-650}
	; vi y(_y, _y + (sizeof(_y) / sizeof(_y[0]))); A1.push_back( y ); int result = 
	1000
	; A2.push_back( result );  }
	{ /*Test 5*/int _x[] = 
	{1,7,12,3,16,8,3,12}	
	; vi x(_x, _x + (sizeof(_x) / sizeof(_x[0]))); A0.push_back( x ); int _y[] = 
	{-90,-60,-70,3,-60,-90,-80,-100}
	; vi y(_y, _y + (sizeof(_y) / sizeof(_y[0]))); A1.push_back( y ); int result = 
	0
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], area( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Intersect ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
