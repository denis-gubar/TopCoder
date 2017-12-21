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
struct PaperFold
{
	int calc( vi paper, vi box, int i )
	{
		if ( i > 9 ) return 10;
		sort( all(box) );
		if ( box[0] < paper[0] || box[1] < paper[1] )
		{
			vi a(box), b(box);
			a[0] *= 2; b[1] *= 2;
			return min( calc( paper, a, i + 1 ), calc( paper, b, i + 1 ) );
		}
		return i;
	}
	int numFolds( vi paper, vi box )
	{
		sort( all(paper) );
		return calc( paper, box, 1 ) % 10 - 1;
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
	{ /*Test 0*/int _paper[] = 
	{8, 11}
	; vi paper(_paper, _paper + (sizeof(_paper) / sizeof(_paper[0]))); A0.push_back( paper ); int _box[] = 
	{6, 10}
	; vi box(_box, _box + (sizeof(_box) / sizeof(_box[0]))); A1.push_back( box ); int result = 
	1
	; A2.push_back( result );  }
	{ /*Test 1*/int _paper[] = 
	{11, 17}
	; vi paper(_paper, _paper + (sizeof(_paper) / sizeof(_paper[0]))); A0.push_back( paper ); int _box[] = 
	{6, 4}
	; vi box(_box, _box + (sizeof(_box) / sizeof(_box[0]))); A1.push_back( box ); int result = 
	4
	; A2.push_back( result );  }
	{ /*Test 2*/int _paper[] = 
	{11, 17}
	; vi paper(_paper, _paper + (sizeof(_paper) / sizeof(_paper[0]))); A0.push_back( paper ); int _box[] = 
	{5, 4}
	; vi box(_box, _box + (sizeof(_box) / sizeof(_box[0]))); A1.push_back( box ); int result = 
	4
	; A2.push_back( result );  }
	{ /*Test 3*/int _paper[] = 
	{1000,1000}
	; vi paper(_paper, _paper + (sizeof(_paper) / sizeof(_paper[0]))); A0.push_back( paper ); int _box[] = 
	{62,63}
	; vi box(_box, _box + (sizeof(_box) / sizeof(_box[0]))); A1.push_back( box ); int result = 
	-1
	; A2.push_back( result );  }
	{ /*Test 4*/int _paper[] = 
	{100,30}
	; vi paper(_paper, _paper + (sizeof(_paper) / sizeof(_paper[0]))); A0.push_back( paper ); int _box[] = 
	{60,110}
	; vi box(_box, _box + (sizeof(_box) / sizeof(_box[0]))); A1.push_back( box ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 5*/int _paper[] = 
	{1895, 6416}
	; vi paper(_paper, _paper + (sizeof(_paper) / sizeof(_paper[0]))); A0.push_back( paper ); int _box[] = 
	{401, 1000}
	; vi box(_box, _box + (sizeof(_box) / sizeof(_box[0]))); A1.push_back( box ); int result = 
	5
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], numFolds( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	PaperFold ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
