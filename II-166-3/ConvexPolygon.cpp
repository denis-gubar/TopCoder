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
struct ConvexPolygon
{
	double findArea( vi x, vi y )
	{
		int result = 0;
		x.push_back( x[0] ); y.push_back( y[0] );
		for( int i = 1; i < x.size(); ++i )
			result += (x[i] - x[i - 1]) * (y[i] + y[i - 1]);
		return 0.5 * abs(result);
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<double> A2;
	{ /*Test 0*/int _x[] = 
	{0,0,1}
	; vi x(_x, _x + (sizeof(_x) / sizeof(_x[0]))); A0.push_back( x ); int _y[] = 
	{0,1,0}
	; vi y(_y, _y + (sizeof(_y) / sizeof(_y[0]))); A1.push_back( y ); double result = 
	0.5
	; A2.push_back( result );  }
	{ /*Test 1*/int _x[] = 
	{-10000,-10000,10000,10000}
	; vi x(_x, _x + (sizeof(_x) / sizeof(_x[0]))); A0.push_back( x ); int _y[] = 
	{10000,-10000,-10000,10000}
	; vi y(_y, _y + (sizeof(_y) / sizeof(_y[0]))); A1.push_back( y ); double result = 
	4.0E8
	; A2.push_back( result );  }
	{ /*Test 2*/int _x[] = 
	{100,80,30,-30,-80,-100,-80,-30,30,80}
	; vi x(_x, _x + (sizeof(_x) / sizeof(_x[0]))); A0.push_back( x ); int _y[] = 
	{0,58,95,95,58,0,-58,-95,-95,-58}
	; vi y(_y, _y + (sizeof(_y) / sizeof(_y[0]))); A1.push_back( y ); double result = 
	29020.0
	; A2.push_back( result );  }
	{ /*Test 3*/int _x[] = 
	{-1646,-9172,-9830,-9802,-9749,-9474,-8668,-6832,120,8380,9338,9307,8042}
	; vi x(_x, _x + (sizeof(_x) / sizeof(_x[0]))); A0.push_back( x ); int _y[] = 
	{-9998,-8619,-7863,3976,4541,5975,8127,9500,9612,8734,5216,-9042,-9689}
	; vi y(_y, _y + (sizeof(_y) / sizeof(_y[0]))); A1.push_back( y ); double result = 
	3.55115104E8
	; A2.push_back( result );  }
	{ /*Test 4*/int _x[] = 
	{-6010,-7937,-8782,-9506,-9654,-9852,-9854,-9998,-9999,-9996,-9901,-9811,
-9444,-8798,-8580,-2085,6842,8339,9827,9946,9993,9959,9940,9855,9657,
8504,8262,7552,6326,5537,4723}
	; vi x(_x, _x + (sizeof(_x) / sizeof(_x[0]))); A0.push_back( x ); int _y[] = 
	{-9976,-9947,-9873,-9739,-9654,-8501,-8475,-5009,475,4926,7078,8673,9417,
9785,9820,9974,9986,9979,9862,9211,-5070,-6599,-7121,-8624,-8912,-9710,
-9766,-9863,-9914,-9941,-9962}
	; vi y(_y, _y + (sizeof(_y) / sizeof(_y[0]))); A1.push_back( y ); double result = 
	3.939960635E8
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], findArea( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ConvexPolygon ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
