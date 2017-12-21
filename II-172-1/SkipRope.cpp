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
struct SkipRope
{
	struct comp: binary_function<int, int, bool>
	{
		comp( int height ): height_(height) {}
		bool operator() ( int a, int b ) const
		{
			if ( abs(height_ - a) != abs(height_ - b) ) return abs(height_ - a) < abs(height_ - b);
			return a > b;
		}
	private:
		int height_;
	};
	vi partners( vi candidates, int height )
	{
		vi result;
		sort( all(candidates), comp(height) );
		result = vi(candidates.begin(), candidates.begin() + 2);
		sort( all(result) );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<int> A1; vector<vi> A2;
	{ /*Test 0*/int _candidates[] = 
	{102, 99, 104}
	; vi candidates(_candidates, _candidates + (sizeof(_candidates) / sizeof(_candidates[0]))); A0.push_back( candidates ); int height = 
	100
	; A1.push_back( height ); int _result[] = 
	{ 99,  102 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 1*/int _candidates[] = 
	{102, 97, 104}
	; vi candidates(_candidates, _candidates + (sizeof(_candidates) / sizeof(_candidates[0]))); A0.push_back( candidates ); int height = 
	100
	; A1.push_back( height ); int _result[] = 
	{ 97,  102 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 2*/int _candidates[] = 
	{101, 100, 99}
	; vi candidates(_candidates, _candidates + (sizeof(_candidates) / sizeof(_candidates[0]))); A0.push_back( candidates ); int height = 
	100
	; A1.push_back( height ); int _result[] = 
	{ 100,  101 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 3*/int _candidates[] = 
	{75, 117, 170, 175, 168, 167, 167, 142, 170, 85, 89, 170}
	; vi candidates(_candidates, _candidates + (sizeof(_candidates) / sizeof(_candidates[0]))); A0.push_back( candidates ); int height = 
	169
	; A1.push_back( height ); int _result[] = 
	{ 170,  170 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 4*/int _candidates[] = 
	{134, 79, 164, 86, 131, 78, 99, 150, 105, 163, 150, 110, 90, 137, 127, 130, 121, 
 93, 97, 131, 170, 137, 171, 153, 137, 138, 92, 103, 149, 110, 156}
	; vi candidates(_candidates, _candidates + (sizeof(_candidates) / sizeof(_candidates[0]))); A0.push_back( candidates ); int height = 
	82
	; A1.push_back( height ); int _result[] = 
	{ 79,  86 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], partners( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	SkipRope ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
