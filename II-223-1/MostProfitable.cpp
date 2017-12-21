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
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct MostProfitable
{
	string bestItem( vi costs, vi prices, vi sales, vs items )
	{
		string result;
		int best = -1;
		fora(i, costs)
			if ( (best == -1 ? 0 : (prices[best] - costs[best]) * sales[best]) < (prices[i] - costs[i]) * sales[i] )
				best = i;
		if ( best >= 0 ) result = items[best];
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<vi> A2; vector<vs> A3; vector<string> A4;
	{ /*Test 0*/int _Arg0[] = 
	{100,120,150,1000}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{110,110,200,2000}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int _Arg2[] = 
	{20,100,50,3}
	; vi Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 ); string _Arg3[] = 
	{"Video Card","256M Mem","CPU/Mobo combo","Complete machine"}
	; vs Arg3(_Arg3, _Arg3 + (sizeof(_Arg3) / sizeof(_Arg3[0]))); A3.push_back( Arg3 ); string Arg4 = 
	"Complete machine"
	; A4.push_back( Arg4 );  }
	{ /*Test 1*/int _Arg0[] = 
	{100}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{100}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int _Arg2[] = 
	{134}
	; vi Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 ); string _Arg3[] = 
	{"Service, at cost"}
	; vs Arg3(_Arg3, _Arg3 + (sizeof(_Arg3) / sizeof(_Arg3[0]))); A3.push_back( Arg3 ); string Arg4 = 
	""
	; A4.push_back( Arg4 );  }
	{ /*Test 2*/int _Arg0[] = 
	{38,24}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{37,23}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int _Arg2[] = 
	{1000,643}
	; vi Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 ); string _Arg3[] = 
	{"Letter","Postcard"}
	; vs Arg3(_Arg3, _Arg3 + (sizeof(_Arg3) / sizeof(_Arg3[0]))); A3.push_back( Arg3 ); string Arg4 = 
	""
	; A4.push_back( Arg4 );  }
	{ /*Test 3*/int _Arg0[] = 
	{10,10}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{11,12}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int _Arg2[] = 
	{2,1}
	; vi Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 ); string _Arg3[] = 
	{"A","B"}
	; vs Arg3(_Arg3, _Arg3 + (sizeof(_Arg3) / sizeof(_Arg3[0]))); A3.push_back( Arg3 ); string Arg4 = 
	"A"
	; A4.push_back( Arg4 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A4[i], bestItem( A0[i], A1[i], A2[i], A3[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	MostProfitable ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
