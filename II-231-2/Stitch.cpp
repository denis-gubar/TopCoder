// BEGIN CUT HERE
#include "precompiled.h"
/*
// END CUT HERE
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
*/
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE
typedef vector<string> vs;
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
struct Stitch
{
	vs stitch( vs A, vs B, int overlap )
	{
		vs result;
		fora(i, A)
		{
			string a = A[i].substr( 0, A[i].size() - overlap );
			string b = B[i].substr( overlap );
			string s;
			for( int k = 1, x = A[i].size() - overlap, y = 0; k <= overlap; ++k, ++x, ++y )
				s += string(1, (2 * ((overlap + 1 - k) * A[i][x] + (k * B[i][y])) / (overlap + 1) + 1) / 2);
			result.push_back( a + s + b );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1; vector<int> A2; vector<vs> A3;
	{ /*Test 0*/string _A[] = 
	{"AAAAAA"}
	; vs A(_A, _A + (sizeof(_A) / sizeof(_A[0]))); A0.push_back( A ); string _B[] = 
	{"JJJJJ"}
	; vs B(_B, _B + (sizeof(_B) / sizeof(_B[0]))); A1.push_back( B ); int overlap = 
	4
	; A2.push_back( overlap ); string _result[] = 
	{ "AACEFHJ" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	{ /*Test 1*/string _A[] = 
	{"14ABCD",
 "25EFGH",
 "36IJKL"}
	; vs A(_A, _A + (sizeof(_A) / sizeof(_A[0]))); A0.push_back( A ); string _B[] = 
	{"ABCD14",
 "EFGH25",
 "IJKL36"}
	; vs B(_B, _B + (sizeof(_B) / sizeof(_B[0]))); A1.push_back( B ); int overlap = 
	4
	; A2.push_back( overlap ); string _result[] = 
	{ "14ABCD14",  "25EFGH25",  "36IJKL36" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	{ /*Test 2*/string _A[] = 
	{" 32ygfd",
 "3uh53G:",
 ")O83gh3"}
	; vs A(_A, _A + (sizeof(_A) / sizeof(_A[0]))); A0.push_back( A ); string _B[] = 
	{"hsd$*(PH",
 "3G:$)(*P",
 "gh86$PBB"}
	; vs B(_B, _B + (sizeof(_B) / sizeof(_B[0]))); A1.push_back( B ); int overlap = 
	3
	; A2.push_back( overlap ); string _result[] = 
	{ " 32ygmd$*(PH",  "3uh53G:$)(*P",  ")O83gh76$PBB" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	{ /*Test 3*/string _A[] = 
	{"A"}
	; vs A(_A, _A + (sizeof(_A) / sizeof(_A[0]))); A0.push_back( A ); string _B[] = 
	{"A"}
	; vs B(_B, _B + (sizeof(_B) / sizeof(_B[0]))); A1.push_back( B ); int overlap = 
	0
	; A2.push_back( overlap ); string _result[] = 
	{ "AA" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], stitch( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Stitch ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
