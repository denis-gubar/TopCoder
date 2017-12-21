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
typedef vector<int> vi;
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
#define all(v) (v).begin(), (v).end()
struct CreateGroups
{
	int minChanges( vi groups, int minSize, int maxSize )
	{
		int n = groups.size(), total = accumulate(all(groups), 0) ;
        if ( !(minSize * n <= total && total <= maxSize * n) )
            return -1;
        sort( all(groups) );
        int a = 0, b = 0;
        fora(i, groups)
        {
            if ( groups[i] > maxSize )
                a += groups[i] - maxSize;
            if ( groups[i] < minSize )
                b += minSize - groups[i];
        }
		return max(a, b);
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<int> A1; vector<int> A2; vector<int> A3;
	{ /*Test 0*/int _groups[] = 
	{10,20}
	; vi groups(_groups, _groups + (sizeof(_groups) / sizeof(_groups[0]))); A0.push_back( groups ); int minSize = 
	10
	; A1.push_back( minSize ); int maxSize = 
	15
	; A2.push_back( maxSize ); int result = 
	5
	; A3.push_back( result );  }
	{ /*Test 1*/int _groups[] = 
	{20,8,6}
	; vi groups(_groups, _groups + (sizeof(_groups) / sizeof(_groups[0]))); A0.push_back( groups ); int minSize = 
	10
	; A1.push_back( minSize ); int maxSize = 
	15
	; A2.push_back( maxSize ); int result = 
	6
	; A3.push_back( result );  }
	{ /*Test 2*/int _groups[] = 
	{10,20,30}
	; vi groups(_groups, _groups + (sizeof(_groups) / sizeof(_groups[0]))); A0.push_back( groups ); int minSize = 
	1
	; A1.push_back( minSize ); int maxSize = 
	18
	; A2.push_back( maxSize ); int result = 
	-1
	; A3.push_back( result );  }
	{ /*Test 3*/int _groups[] = 
	{50,10,20,20,5}
	; vi groups(_groups, _groups + (sizeof(_groups) / sizeof(_groups[0]))); A0.push_back( groups ); int minSize = 
	15
	; A1.push_back( minSize ); int maxSize = 
	30
	; A2.push_back( maxSize ); int result = 
	20
	; A3.push_back( result );  }
	{ /*Test 4*/int _groups[] = 
	{100,200,301}
	; vi groups(_groups, _groups + (sizeof(_groups) / sizeof(_groups[0]))); A0.push_back( groups ); int minSize = 
	200
	; A1.push_back( minSize ); int maxSize = 
	200
	; A2.push_back( maxSize ); int result = 
	-1
	; A3.push_back( result );  }
	{ /*Test 5*/int _groups[] = 
	{1,10,10}	
	; vi groups(_groups, _groups + (sizeof(_groups) / sizeof(_groups[0]))); A0.push_back( groups ); int minSize = 
	9
	; A1.push_back( minSize ); int maxSize = 
	20
	; A2.push_back( maxSize ); int result = 
	-1
	; A3.push_back( result );  }
	{ /*Test 6*/int _groups[] = 
	{55,33,45,71,27,89,16,14,61}
	; vi groups(_groups, _groups + (sizeof(_groups) / sizeof(_groups[0]))); A0.push_back( groups ); int minSize = 
	33
	; A1.push_back( minSize ); int maxSize = 
	56
	; A2.push_back( maxSize ); int result = 
	53
	; A3.push_back( result );  }
	{ /*Test 7*/int _groups[] = 
	{49,60,36,34,36,52,60,43,52,59}
	; vi groups(_groups, _groups + (sizeof(_groups) / sizeof(_groups[0]))); A0.push_back( groups ); int minSize = 
	45
	; A1.push_back( minSize ); int maxSize = 
	51
	; A2.push_back( maxSize ); int result = 
	31
	; A3.push_back( result );  }
	{ /*Test 8*/int _groups[] = 
	{5,5,5,5,5}
	; vi groups(_groups, _groups + (sizeof(_groups) / sizeof(_groups[0]))); A0.push_back( groups ); int minSize = 
	5
	; A1.push_back( minSize ); int maxSize = 
	5
	; A2.push_back( maxSize ); int result = 
	0
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], minChanges( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	CreateGroups ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
