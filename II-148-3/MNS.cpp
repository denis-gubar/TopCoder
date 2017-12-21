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
struct MNS
{
	int combos( vi numbers )
	{
		int result = 0, sum = accumulate( all(numbers), 0 ) / 3;
		sort( all(numbers) );
		do
		{
			if ( numbers[0] + numbers[1] + numbers[2] == sum &&
				numbers[3] + numbers[4] + numbers[5] == sum &&
				numbers[6] + numbers[7] + numbers[8] == sum &&
				numbers[0] + numbers[3] + numbers[6] == sum &&
				numbers[1] + numbers[4] + numbers[7] == sum &&
				numbers[2] + numbers[5] + numbers[8] == sum )
				++result;
		} while( next_permutation( all(numbers) ) );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<int> A1;
	{ /*Test 0*/int _numbers[] = 
	{1,2,3,3,2,1,2,2,2}
	; vi numbers(_numbers, _numbers + (sizeof(_numbers) / sizeof(_numbers[0]))); A0.push_back( numbers ); int result = 
	18
	; A1.push_back( result );  }
	{ /*Test 1*/int _numbers[] = 
	{4,4,4,4,4,4,4,4,4}
	; vi numbers(_numbers, _numbers + (sizeof(_numbers) / sizeof(_numbers[0]))); A0.push_back( numbers ); int result = 
	1
	; A1.push_back( result );  }
	{ /*Test 2*/int _numbers[] = 
	{1,5,1,2,5,6,2,3,2}
	; vi numbers(_numbers, _numbers + (sizeof(_numbers) / sizeof(_numbers[0]))); A0.push_back( numbers ); int result = 
	36
	; A1.push_back( result );  }
	{ /*Test 3*/int _numbers[] = 
	{1,2,6,6,6,4,2,6,4}
	; vi numbers(_numbers, _numbers + (sizeof(_numbers) / sizeof(_numbers[0]))); A0.push_back( numbers ); int result = 
	0
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], combos( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	MNS ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
