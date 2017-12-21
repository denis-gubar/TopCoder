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
typedef vector<vector<int> > vvi;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct PowerOutage
{
	int estimateTimeOut( vi fromJunction, vi toJunction, vi ductLength )
	{
		vvi M(50, vi(50, 0)); vi A(50, 0);
		fora(i, fromJunction)
			M[fromJunction[i]][toJunction[i]] = M[toJunction[i]][fromJunction[i]] = ductLength[i];
		fora(i, M)
			for( int j = i + 1; j < M.size(); j++ )
				if ( M[i][j] )
					A[j] = A[i] + M[i][j];
		return 2 * accumulate( all(ductLength), 0 ) - *max_element( all(A) );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<vi> A2; vector<int> A3;
	{ /*Test 0*/int _Arg0[] = 
	{0}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{1}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int _Arg2[] = 
	{10}
	; vi Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 ); int Arg3 = 
	10
	; A3.push_back( Arg3 );  }
	{ /*Test 1*/int _Arg0[] = 
	{0,1,0}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{1,2,3}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int _Arg2[] = 
	{10,10,10}
	; vi Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 ); int Arg3 = 
	40
	; A3.push_back( Arg3 );  }
	{ /*Test 2*/int _Arg0[] = 
	{0,0,0,1,4}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{1,3,4,2,5}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int _Arg2[] = 
	{10,10,100,10,5}
	; vi Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 ); int Arg3 = 
	165
	; A3.push_back( Arg3 );  }
	{ /*Test 3*/int _Arg0[] = 
	{0,0,0,1,4,4,6,7,7,7,20}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{1,3,4,2,5,6,7,20,9,10,31}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int _Arg2[] = 
	{10,10,100,10,5,1,1,100,1,1,5}
	; vi Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 ); int Arg3 = 
	281
	; A3.push_back( Arg3 );  }
	{ /*Test 4*/int _Arg0[] = 
	{0,0,0,0,0}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{1,2,3,4,5}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int _Arg2[] = 
	{100,200,300,400,500}
	; vi Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 ); int Arg3 = 
	2500
	; A3.push_back( Arg3 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], estimateTimeOut( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	PowerOutage ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
