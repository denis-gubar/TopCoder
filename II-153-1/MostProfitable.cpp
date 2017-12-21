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
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct MostProfitable
{
	string bestItem( vi costs, vi prices, vi sales, vs items )
	{
		string result;
		int best = -1;
		fora(i, items)
			if ( ((best == -1) ? 0 : ( prices[best] - costs[best] ) * sales[best] ) < ( prices[i] - costs[i] ) * sales[i] )
				best = i;
		if ( best >= 0 ) result = items[best];
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<vi> A2; vector<vs> A3; vector<string> A4;
	{ /*Test 0*/int _costs[] = 
	{100,120,150,1000}
	; vi costs(_costs, _costs + (sizeof(_costs) / sizeof(_costs[0]))); A0.push_back( costs ); int _prices[] = 
	{110,110,200,2000}
	; vi prices(_prices, _prices + (sizeof(_prices) / sizeof(_prices[0]))); A1.push_back( prices ); int _sales[] = 
	{20,100,50,3}
	; vi sales(_sales, _sales + (sizeof(_sales) / sizeof(_sales[0]))); A2.push_back( sales ); string _items[] = 
	{"Video Card","256M Mem","CPU/Mobo combo","Complete machine"}
	; vs items(_items, _items + (sizeof(_items) / sizeof(_items[0]))); A3.push_back( items ); string result = 
	"Complete machine"
	; A4.push_back( result );  }
	{ /*Test 1*/int _costs[] = 
	{100}
	; vi costs(_costs, _costs + (sizeof(_costs) / sizeof(_costs[0]))); A0.push_back( costs ); int _prices[] = 
	{100}
	; vi prices(_prices, _prices + (sizeof(_prices) / sizeof(_prices[0]))); A1.push_back( prices ); int _sales[] = 
	{134}
	; vi sales(_sales, _sales + (sizeof(_sales) / sizeof(_sales[0]))); A2.push_back( sales ); string _items[] = 
	{"Service, at cost"}
	; vs items(_items, _items + (sizeof(_items) / sizeof(_items[0]))); A3.push_back( items ); string result = 
	""
	; A4.push_back( result );  }
	{ /*Test 2*/int _costs[] = 
	{38,24}
	; vi costs(_costs, _costs + (sizeof(_costs) / sizeof(_costs[0]))); A0.push_back( costs ); int _prices[] = 
	{37,23}
	; vi prices(_prices, _prices + (sizeof(_prices) / sizeof(_prices[0]))); A1.push_back( prices ); int _sales[] = 
	{1000,643}
	; vi sales(_sales, _sales + (sizeof(_sales) / sizeof(_sales[0]))); A2.push_back( sales ); string _items[] = 
	{"Letter","Postcard"}
	; vs items(_items, _items + (sizeof(_items) / sizeof(_items[0]))); A3.push_back( items ); string result = 
	""
	; A4.push_back( result );  }
	{ /*Test 3*/int _costs[] = 
	{10,10}
	; vi costs(_costs, _costs + (sizeof(_costs) / sizeof(_costs[0]))); A0.push_back( costs ); int _prices[] = 
	{11,12}
	; vi prices(_prices, _prices + (sizeof(_prices) / sizeof(_prices[0]))); A1.push_back( prices ); int _sales[] = 
	{2,1}
	; vi sales(_sales, _sales + (sizeof(_sales) / sizeof(_sales[0]))); A2.push_back( sales ); string _items[] = 
	{"A","B"}
	; vs items(_items, _items + (sizeof(_items) / sizeof(_items[0]))); A3.push_back( items ); string result = 
	"A"
	; A4.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A4[i], bestItem( A0[i], A1[i], A2[i], A3[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	MostProfitable ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
