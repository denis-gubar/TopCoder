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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct NumberChanger
{
	int transform( string start, string finish )
	{
		vi result;
		map<string, int> M;
		M[start] = 0;
		queue<string> Q; queue<int> q;
		Q.push( start ); q.push( 0 );
		while( !q.empty() )
		{
			string s( Q.front() ); Q.pop();
			int k = q.front() + 1; q.pop();
			fora(i, s)
				for( int j = i + 1; j < s.size(); ++j )
					if ( s[i] != s[j] )
					{
						string t(s); swap( t[i], t[j] );
						if ( M.find( t ) == M.end() )
						{
							M[t] = k;
							Q.push( t );
							q.push( k );
						}
					}
		}
		for( map<string, int>::iterator it = M.begin(); it != M.end(); ++it )
		{
			string s( it->first );
			int k = it->second;
			fora(i, s)
				k += abs( s[i] - finish[i] );
			result.push_back( k );
		}
		return *min_element( all(result) );
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<string> A1; vector<int> A2;
	{ /*Test 0*/string start = 
	"01234567"
	; A0.push_back( start ); string finish = 
	"01234567"
	; A1.push_back( finish ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 1*/string start = 
	"11119999"
	; A0.push_back( start ); string finish = 
	"99991111"
	; A1.push_back( finish ); int result = 
	4
	; A2.push_back( result );  }
	{ /*Test 2*/string start = 
	"55555555"
	; A0.push_back( start ); string finish = 
	"12345678"
	; A1.push_back( finish ); int result = 
	16
	; A2.push_back( result );  }
	{ /*Test 3*/string start = 
	"77771111"
	; A0.push_back( start ); string finish = 
	"00446688"
	; A1.push_back( finish ); int result = 
	16
	; A2.push_back( result );  }
	{ /*Test 4*/string start = 
	"12"
	; A0.push_back( start ); string finish = 
	"30"
	; A1.push_back( finish ); int result = 
	3
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], transform( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	NumberChanger ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
