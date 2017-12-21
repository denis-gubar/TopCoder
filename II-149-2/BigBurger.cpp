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
struct BigBurger
{
	int maxWait( vi arrival, vi service )
	{
		int result = 0;
		int left = 0;
		fora(i, arrival)
			if ( arrival[i] > left ) left = arrival[i] + service[i];
			else
			{
				result = max( result, left - arrival[i] );
				left = left + service[i];
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
	{ /*Test 0*/int _arrival[] = 
	{3,3,9}
	; vi arrival(_arrival, _arrival + (sizeof(_arrival) / sizeof(_arrival[0]))); A0.push_back( arrival ); int _service[] = 
	{2,15,14}
	; vi service(_service, _service + (sizeof(_service) / sizeof(_service[0]))); A1.push_back( service ); int result = 
	11
	; A2.push_back( result );  }
	{ /*Test 1*/int _arrival[] = 
	{182}
	; vi arrival(_arrival, _arrival + (sizeof(_arrival) / sizeof(_arrival[0]))); A0.push_back( arrival ); int _service[] = 
	{11}
	; vi service(_service, _service + (sizeof(_service) / sizeof(_service[0]))); A1.push_back( service ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 2*/int _arrival[] = 
	{2,10,11}
	; vi arrival(_arrival, _arrival + (sizeof(_arrival) / sizeof(_arrival[0]))); A0.push_back( arrival ); int _service[] = 
	{3,4,3}
	; vi service(_service, _service + (sizeof(_service) / sizeof(_service[0]))); A1.push_back( service ); int result = 
	3
	; A2.push_back( result );  }
	{ /*Test 3*/int _arrival[] = 
	{2,10,12}
	; vi arrival(_arrival, _arrival + (sizeof(_arrival) / sizeof(_arrival[0]))); A0.push_back( arrival ); int _service[] = 
	{15,1,15}
	; vi service(_service, _service + (sizeof(_service) / sizeof(_service[0]))); A1.push_back( service ); int result = 
	7
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], maxWait( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	BigBurger ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
