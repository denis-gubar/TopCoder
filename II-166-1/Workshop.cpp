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
struct Workshop
{
	int pictureFrames( vi pieces )
	{
		int result = 0, n = pieces.size();
		for( int i = 0; i < n; ++i )
			for( int j = i + 1; j < n; ++j )
				for( int k = j + 1; k < n; ++k )
					if ( pieces[i] < pieces[j] + pieces[k] &&
						pieces[j] < pieces[i] + pieces[k] &&
						pieces[k] < pieces[j] + pieces[i] )
						++result;
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
	{ /*Test 0*/int _pieces[] = 
	{1,2,3,4,5}
	; vi pieces(_pieces, _pieces + (sizeof(_pieces) / sizeof(_pieces[0]))); A0.push_back( pieces ); int result = 
	3
	; A1.push_back( result );  }
	{ /*Test 1*/int _pieces[] = 
	{8,5,3}
	; vi pieces(_pieces, _pieces + (sizeof(_pieces) / sizeof(_pieces[0]))); A0.push_back( pieces ); int result = 
	0
	; A1.push_back( result );  }
	{ /*Test 2*/int _pieces[] = 
	{4,23,76,22,87,3,1,99}
	; vi pieces(_pieces, _pieces + (sizeof(_pieces) / sizeof(_pieces[0]))); A0.push_back( pieces ); int result = 
	7
	; A1.push_back( result );  }
	{ /*Test 3*/int _pieces[] = 
	{10000,9999,9998,9997,9996,1,2,3,4,5}
	; vi pieces(_pieces, _pieces + (sizeof(_pieces) / sizeof(_pieces[0]))); A0.push_back( pieces ); int result = 
	43
	; A1.push_back( result );  }
	{ /*Test 4*/int _pieces[] = 
	{100}
	; vi pieces(_pieces, _pieces + (sizeof(_pieces) / sizeof(_pieces[0]))); A0.push_back( pieces ); int result = 
	0
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], pictureFrames( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Workshop ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
