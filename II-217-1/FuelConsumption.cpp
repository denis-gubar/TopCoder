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
typedef vector<int> vi;
typedef vector<double> vd;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct FuelConsumption
{
	double maximalDistance( vi velocities, vi consumptions, int fuel )
	{
		vd a;
		fora(i, velocities)
			a.push_back( 1.0 * fuel * velocities[i] / consumptions[i] );		
		return *max_element( all(a) );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<int> A2; vector<double> A3;
	{ /*Test 0*/int _Arg0[] = 
	{100}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{10000}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int Arg2 = 
	10000
	; A2.push_back( Arg2 ); double Arg3 = 
	100.0
	; A3.push_back( Arg3 );  }
	{ /*Test 1*/int _Arg0[] = 
	{70, 80, 90, 100, 60, 110}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{4000, 4000, 4000, 4000, 4000, 4000}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int Arg2 = 
	40000
	; A2.push_back( Arg2 ); double Arg3 = 
	1100.0
	; A3.push_back( Arg3 );  }
	{ /*Test 2*/int _Arg0[] = 
	{250, 240, 230, 220, 210, 211}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{5000, 4500, 4000, 3500, 3000, 3000}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int Arg2 = 
	50000
	; A2.push_back( Arg2 ); double Arg3 = 
	3516.6666666666665
	; A3.push_back( Arg3 );  }
	{ /*Test 3*/int _Arg0[] = 
	{5, 10, 20, 40, 80}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{1000, 2500, 6250, 9000, 18000}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int Arg2 = 
	47832
	; A2.push_back( Arg2 ); double Arg3 = 
	239.16
	; A3.push_back( Arg3 );  }
	{ /*Test 4*/int _Arg0[] = 
	{5, 10, 20, 40, 80, 160}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{1000, 2500, 6250, 8000, 9500, 20000}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int Arg2 = 
	47832
	; A2.push_back( Arg2 ); double Arg3 = 
	402.79578947368424
	; A3.push_back( Arg3 );  }
	{ /*Test 5*/int _Arg0[] = 
	{240, 195, 130, 133, 15, 160, 111, 206, 72, 149,
 146, 115, 235, 183, 102, 96, 163, 61, 196, 52,
 87, 139, 33, 7, 90, 67, 118, 227, 197, 114}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{14837, 2981, 17292, 18591, 4832, 7461, 17991, 18369, 18291, 9400,
 15179, 3317, 2595, 2441, 6936, 8028, 14973, 18981, 12503, 7816,
 2883, 6385, 6230, 18157, 16567, 9310, 2866, 4687, 14171, 4477}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int Arg2 = 
	31710
	; A2.push_back( Arg2 ); double Arg3 = 
	2871.6184971098264
	; A3.push_back( Arg3 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], maximalDistance( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	FuelConsumption ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
