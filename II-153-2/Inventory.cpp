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
struct Inventory
{
	int monthlyOrder( vi sales, vi daysAvailable )
	{
		int result = 0, y = 0;
		double x = 0;
		fora(i, daysAvailable)
			if ( daysAvailable[i] )
			{
				x += 30.0 * sales[i] / daysAvailable[i]; ++y;
			}
		result = static_cast<int>( ceil( x / y - 1e-9 ) );
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
	{ /*Test 0*/int _sales[] = 
	{5}
	; vi sales(_sales, _sales + (sizeof(_sales) / sizeof(_sales[0]))); A0.push_back( sales ); int _daysAvailable[] = 
	{15}
	; vi daysAvailable(_daysAvailable, _daysAvailable + (sizeof(_daysAvailable) / sizeof(_daysAvailable[0]))); A1.push_back( daysAvailable ); int result = 
	10
	; A2.push_back( result );  }
	{ /*Test 1*/int _sales[] = 
	{75,120,0,93}
	; vi sales(_sales, _sales + (sizeof(_sales) / sizeof(_sales[0]))); A0.push_back( sales ); int _daysAvailable[] = 
	{24,30,0,30}
	; vi daysAvailable(_daysAvailable, _daysAvailable + (sizeof(_daysAvailable) / sizeof(_daysAvailable[0]))); A1.push_back( daysAvailable ); int result = 
	103
	; A2.push_back( result );  }
	{ /*Test 2*/int _sales[] = 
	{8773}
	; vi sales(_sales, _sales + (sizeof(_sales) / sizeof(_sales[0]))); A0.push_back( sales ); int _daysAvailable[] = 
	{16}
	; vi daysAvailable(_daysAvailable, _daysAvailable + (sizeof(_daysAvailable) / sizeof(_daysAvailable[0]))); A1.push_back( daysAvailable ); int result = 
	16450
	; A2.push_back( result );  }
	{ /*Test 3*/int _sales[] = 
	{1115,7264,3206,6868,7301}
	; vi sales(_sales, _sales + (sizeof(_sales) / sizeof(_sales[0]))); A0.push_back( sales ); int _daysAvailable[] = 
	{1,3,9,4,18}
	; vi daysAvailable(_daysAvailable, _daysAvailable + (sizeof(_daysAvailable) / sizeof(_daysAvailable[0]))); A1.push_back( daysAvailable ); int result = 
	36091
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], monthlyOrder( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Inventory ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
