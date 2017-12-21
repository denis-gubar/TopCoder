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
struct Sets
{
	vi operate( vi A, vi B, string operation )
	{
		vi result;
		sort( all(A) ); sort( all(B) );
		if ( operation == "INTERSECTION" )
			set_intersection( all(A), all(B), back_inserter( result ) );
		else if ( operation == "UNION" )
			set_union( all(A), all(B), back_inserter( result ) );
		else
		{
			vi C, D;
			set_intersection( all(A), all(B), back_inserter( C ) );
			set_union( all(A), all(B), back_inserter( D ) );
			set_difference( all(D), all(C), back_inserter( result ) );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<string> A2; vector<vi> A3;
	{ /*Test 0*/int _A[] = 
	{1,2,3,4}
	; vi A(_A, _A + (sizeof(_A) / sizeof(_A[0]))); A0.push_back( A ); int _B[] = 
	{3,4,5,6}
	; vi B(_B, _B + (sizeof(_B) / sizeof(_B[0]))); A1.push_back( B ); string operation = 
	"INTERSECTION"
	; A2.push_back( operation ); int _result[] = 
	{ 3,  4 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	{ /*Test 1*/int _A[] = 
	{1,2,3,4}
	; vi A(_A, _A + (sizeof(_A) / sizeof(_A[0]))); A0.push_back( A ); int _B[] = 
	{3,4,5,6}
	; vi B(_B, _B + (sizeof(_B) / sizeof(_B[0]))); A1.push_back( B ); string operation = 
	"UNION"
	; A2.push_back( operation ); int _result[] = 
	{ 1,  2,  3,  4,  5,  6 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	{ /*Test 2*/int _A[] = 
	{432,756,123}
	; vi A(_A, _A + (sizeof(_A) / sizeof(_A[0]))); A0.push_back( A ); int _B[] = 
	{534,76,1209}
	; vi B(_B, _B + (sizeof(_B) / sizeof(_B[0]))); A1.push_back( B ); string operation = 
	"INTERSECTION"
	; A2.push_back( operation ); vi result; A3.push_back( result );  }
	{ /*Test 3*/int _A[] = 
	{6,5,7,4}
	; vi A(_A, _A + (sizeof(_A) / sizeof(_A[0]))); A0.push_back( A ); int _B[] = 
	{7,6,4,10}
	; vi B(_B, _B + (sizeof(_B) / sizeof(_B[0]))); A1.push_back( B ); string operation = 
	"SYMMETRIC DIFFERENCE"
	; A2.push_back( operation ); int _result[] = 
	{ 5,  10 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	{ /*Test 4*/int _A[] = 
	{342,654,897,312,76,23,78}
	; vi A(_A, _A + (sizeof(_A) / sizeof(_A[0]))); A0.push_back( A ); int _B[] = 
	{21,43,87,98,23,756,897,234,645,876,123}
	; vi B(_B, _B + (sizeof(_B) / sizeof(_B[0]))); A1.push_back( B ); string operation = 
	"SYMMETRIC DIFFERENCE"
	; A2.push_back( operation ); int _result[] = 
	{ 21,  43,  76,  78,  87,  98,  123,  234,  312,  342,  645,  654,  756,  876 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], operate( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Sets ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
