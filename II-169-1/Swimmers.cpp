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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct Swimmers
{
	vi getSwimTimes( vi distances, vi speeds, int current )
	{
		vi result;
		fora(i, speeds)
			if ( !distances[i] ) result.push_back( 0 );
			else if ( speeds[i] <= current ) result.push_back( -1 );
			else result.push_back( distances[i] / (1.0 * speeds[i] - current) + distances[i] / (1.0 * speeds[i] + current) );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<int> A2; vector<vi> A3;
	{ /*Test 0*/int _distances[] = 
	{ 300, 300, 300 }
	; vi distances(_distances, _distances + (sizeof(_distances) / sizeof(_distances[0]))); A0.push_back( distances ); int _speeds[] = 
	{ 1, 2, 3 }
	; vi speeds(_speeds, _speeds + (sizeof(_speeds) / sizeof(_speeds[0]))); A1.push_back( speeds ); int current = 
	2
	; A2.push_back( current ); int _result[] = 
	{ -1,  -1,  360 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	{ /*Test 1*/int _distances[] = 
	{ 500, 500 }
	; vi distances(_distances, _distances + (sizeof(_distances) / sizeof(_distances[0]))); A0.push_back( distances ); int _speeds[] = 
	{ 4, 5 }
	; vi speeds(_speeds, _speeds + (sizeof(_speeds) / sizeof(_speeds[0]))); A1.push_back( speeds ); int current = 
	2
	; A2.push_back( current ); int _result[] = 
	{ 333,  238 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	{ /*Test 2*/int _distances[] = 
	{ 0, 0 }
	; vi distances(_distances, _distances + (sizeof(_distances) / sizeof(_distances[0]))); A0.push_back( distances ); int _speeds[] = 
	{ 1, 2 }
	; vi speeds(_speeds, _speeds + (sizeof(_speeds) / sizeof(_speeds[0]))); A1.push_back( speeds ); int current = 
	1
	; A2.push_back( current ); int _result[] = 
	{ 0,  0 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	{ /*Test 3*/int _distances[] = 
	{ 0, 1 }
	; vi distances(_distances, _distances + (sizeof(_distances) / sizeof(_distances[0]))); A0.push_back( distances ); int _speeds[] = 
	{ 0, 0 }
	; vi speeds(_speeds, _speeds + (sizeof(_speeds) / sizeof(_speeds[0]))); A1.push_back( speeds ); int current = 
	0
	; A2.push_back( current ); int _result[] = 
	{ 0,  -1 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	{ /*Test 4*/int _distances[] = 
	{ 7507, 7517, 7523, 7529, 7537, 7541, 7547, 7549, 7559, 7561, 7573, 7577, 7583,
  7589, 7591, 7603, 7607, 7621, 7639, 7643, 7649, 7669, 7673, 7681, 7687, 7691,
  7699, 7703, 7717, 7723, 7727, 7741, 7753, 7757, 7759, 7789, 7793, 7817, 7823,
  7829, 7841, 7853, 7867, 7873, 7877, 7879, 7883, 7901, 7907, 7919 }
	; vi distances(_distances, _distances + (sizeof(_distances) / sizeof(_distances[0]))); A0.push_back( distances ); int _speeds[] = 
	{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
  73, 79, 83, 89, 97, 99, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30,
  32, 34, 36, 38, 40, 42, 44, 46, 48, 51 }
	; vi speeds(_speeds, _speeds + (sizeof(_speeds) / sizeof(_speeds[0]))); A1.push_back( speeds ); int current = 
	6
	; A2.push_back( current ); int _result[] = 
	{ -1,  -1,  -1,  8108,  1950,  1474,  1014,  882,  705,  544,  507,  420,  377,  359,  328,  290,  260,  252,  229,  216,  210,  195,  185,  173,  159,  155,  -1,  -1,  4409,  2413,  1717,  1354,  1127,  969,  852,  764,  692,  635,  585,  543,  507,  476,  449,  424,  402,  383,  365,  349,  334,  314 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], getSwimTimes( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Swimmers ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
