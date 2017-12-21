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
typedef vector<vi> vvi;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct FairWorkload
{
	int getMostWork( vi folders, int workers )
	{
		int n = folders.size();
		vvi M(workers, vi(n, 1 << 30));
		fora(i, folders)
			M[0][i] = accumulate( folders.begin(), folders.begin() + i + 1, 0 );
		for( int i = 1; i < workers; ++i )
			for( int j = i; j < n; ++j )
				for( int k = i; k <= j; ++k )
					M[i][j] = min( M[i][j], max( M[i - 1][k - 1], accumulate( folders.begin() + k, folders.begin() + j + 1, 0 ) ) );
		return M[workers - 1][n - 1];
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
	{ /*Test 0*/int _folders[] = 
	{ 10, 20, 30, 40, 50, 60, 70, 80, 90 }
	; vi folders(_folders, _folders + (sizeof(_folders) / sizeof(_folders[0]))); A0.push_back( folders ); int workers = 
	3
	; A1.push_back( workers ); int result = 
	170
	; A2.push_back( result );  }
	{ /*Test 1*/int _folders[] = 
	{ 10, 20, 30, 40, 50, 60, 70, 80, 90 }
	; vi folders(_folders, _folders + (sizeof(_folders) / sizeof(_folders[0]))); A0.push_back( folders ); int workers = 
	5
	; A1.push_back( workers ); int result = 
	110
	; A2.push_back( result );  }
	{ /*Test 2*/int _folders[] = 
	{ 568, 712, 412, 231, 241, 393, 865, 287, 128, 457, 238, 98, 980, 23, 782 }
	; vi folders(_folders, _folders + (sizeof(_folders) / sizeof(_folders[0]))); A0.push_back( folders ); int workers = 
	4
	; A1.push_back( workers ); int result = 
	1785
	; A2.push_back( result );  }
	{ /*Test 3*/int _folders[] = 
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1000 }
	; vi folders(_folders, _folders + (sizeof(_folders) / sizeof(_folders[0]))); A0.push_back( folders ); int workers = 
	2
	; A1.push_back( workers ); int result = 
	1000
	; A2.push_back( result );  }
	{ /*Test 4*/int _folders[] = 
	{ 50, 50, 50, 50, 50, 50, 50 }
	; vi folders(_folders, _folders + (sizeof(_folders) / sizeof(_folders[0]))); A0.push_back( folders ); int workers = 
	2
	; A1.push_back( workers ); int result = 
	200
	; A2.push_back( result );  }
	{ /*Test 5*/int _folders[] = 
	{1,1,1,1,100}
	; vi folders(_folders, _folders + (sizeof(_folders) / sizeof(_folders[0]))); A0.push_back( folders ); int workers = 
	5
	; A1.push_back( workers ); int result = 
	100
	; A2.push_back( result );  }
	{ /*Test 6*/int _folders[] = 
	{ 950, 650, 250, 250, 350, 100, 650, 150, 150, 700 }
	; vi folders(_folders, _folders + (sizeof(_folders) / sizeof(_folders[0]))); A0.push_back( folders ); int workers = 
	6
	; A1.push_back( workers ); int result = 
	950
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], getMostWork( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	FairWorkload ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
