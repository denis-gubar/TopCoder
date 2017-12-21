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
struct DiskSpace
{
	int minDrives( vi used, vi total )
	{
		int result = 0, sum = accumulate( all(used), 0 );
		sort( all(total), greater<int>() );
		for( int i = 0; sum > 0; ++i )
		{
			sum -= total[i];
			++result;
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<int> A2;
	{ /*Test 0*/int _used[] = 
	{300,525,110}
	; vi used(_used, _used + (sizeof(_used) / sizeof(_used[0]))); A0.push_back( used ); int _total[] = 
	{350,600,115}
	; vi total(_total, _total + (sizeof(_total) / sizeof(_total[0]))); A1.push_back( total ); int result = 
	2
	; A2.push_back( result );  }
	{ /*Test 1*/int _used[] = 
	{1,200,200,199,200,200}
	; vi used(_used, _used + (sizeof(_used) / sizeof(_used[0]))); A0.push_back( used ); int _total[] = 
	{1000,200,200,200,200,200}
	; vi total(_total, _total + (sizeof(_total) / sizeof(_total[0]))); A1.push_back( total ); int result = 
	1
	; A2.push_back( result );  }
	{ /*Test 2*/int _used[] = 
	{750,800,850,900,950}
	; vi used(_used, _used + (sizeof(_used) / sizeof(_used[0]))); A0.push_back( used ); int _total[] = 
	{800,850,900,950,1000}
	; vi total(_total, _total + (sizeof(_total) / sizeof(_total[0]))); A1.push_back( total ); int result = 
	5
	; A2.push_back( result );  }
	{ /*Test 3*/int _used[] = 
	{49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,
 49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49}
	; vi used(_used, _used + (sizeof(_used) / sizeof(_used[0]))); A0.push_back( used ); int _total[] = 
	{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,
 50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50}
	; vi total(_total, _total + (sizeof(_total) / sizeof(_total[0]))); A1.push_back( total ); int result = 
	49
	; A2.push_back( result );  }
	{ /*Test 4*/int _used[] = 
	{331,242,384,366,428,114,145,89,381,170,329,190,482,246,2,38,220,290,402,385}
	; vi used(_used, _used + (sizeof(_used) / sizeof(_used[0]))); A0.push_back( used ); int _total[] = 
	{992,509,997,946,976,873,771,565,693,714,755,878,897,789,969,727,765,521,961,906}
	; vi total(_total, _total + (sizeof(_total) / sizeof(_total[0]))); A1.push_back( total ); int result = 
	6
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], minDrives( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	DiskSpace ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
