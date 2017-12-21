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
struct CellRemoval
{
	int cellsLeft( vi parent, int deletedCell )
	{
		int result = 0;
		vi isParent( parent.size(), 0 );
		fora(i, parent)
			if ( parent[i] != -1 )
				isParent[parent[i]] = 1;
		fora(i, isParent)
			if ( !isParent[i] )
			{
				int x = i;
				while( x != -1 && x != deletedCell )
					x = parent[x];
				if ( x == -1 )
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<int> A1; vector<int> A2;
	{ /*Test 0*/int _parent[] = 
	{-1,0,0,1,1}
	; vi parent(_parent, _parent + (sizeof(_parent) / sizeof(_parent[0]))); A0.push_back( parent ); int deletedCell = 
	2
	; A1.push_back( deletedCell ); int result = 
	2
	; A2.push_back( result );  }
	{ /*Test 1*/int _parent[] = 
	{-1,0,0,1,1}
	; vi parent(_parent, _parent + (sizeof(_parent) / sizeof(_parent[0]))); A0.push_back( parent ); int deletedCell = 
	1
	; A1.push_back( deletedCell ); int result = 
	1
	; A2.push_back( result );  }
	{ /*Test 2*/int _parent[] = 
	{-1,0,0,1,1}
	; vi parent(_parent, _parent + (sizeof(_parent) / sizeof(_parent[0]))); A0.push_back( parent ); int deletedCell = 
	0
	; A1.push_back( deletedCell ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 3*/int _parent[] = 
	{-1,0,0,2,2,4,4,6,6}
	; vi parent(_parent, _parent + (sizeof(_parent) / sizeof(_parent[0]))); A0.push_back( parent ); int deletedCell = 
	4
	; A1.push_back( deletedCell ); int result = 
	2
	; A2.push_back( result );  }
	{ /*Test 4*/int _parent[] = 
	{26,2,32,36,40,19,43,24,30,13,21,14,24,21,19,4,30,10,44,12,7,32,17,43,
 35,18,7,36,10,16,5,38,35,4,13,-1,16,26,1,12,2,5,18,40,1,17,38,44,14}
	; vi parent(_parent, _parent + (sizeof(_parent) / sizeof(_parent[0]))); A0.push_back( parent ); int deletedCell = 
	24
	; A1.push_back( deletedCell ); int result = 
	14
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], cellsLeft( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	CellRemoval ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
