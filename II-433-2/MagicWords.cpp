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
typedef vector<string> vs;
typedef map<string, int> msi;
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
#define all(v) (v).begin(), (v).end()
struct MagicWords
{
	int count( vs S, int K )
	{
		int result = 0;
        int L = S.size();
        vi A( L - 1 );
        fora(i, A)
            A[i] = i;
        msi M;
        do
        {
            string s( S[0] );
            fora(i, A)
                s += S[A[i] + 1];
            if ( M.find( s ) == M.end() )
            {
                int k = 1;
                string t(s);
                for( int i = 1; i < s.size() && k <= K; ++i )
                {
                    rotate( t.begin(), t.begin() + 1, t.end() );
                    k += (s == t);
                }
                M[s] = (k == K);            
            }
            result += M[s] * L;
        } while ( next_permutation( all(A) ) );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<int> A1; vector<int> A2;
	{ /*Test 0*/string _S[] = 
	{"CAD","ABRA","ABRA"}
	; vs S(_S, _S + (sizeof(_S) / sizeof(_S[0]))); A0.push_back( S ); int K = 
	1
	; A1.push_back( K ); int result = 
	6
	; A2.push_back( result );  }
	{ /*Test 1*/string _S[] = 
	{"AB","RAAB","RA"}
	; vs S(_S, _S + (sizeof(_S) / sizeof(_S[0]))); A0.push_back( S ); int K = 
	2
	; A1.push_back( K ); int result = 
	3
	; A2.push_back( result );  }
	{ /*Test 2*/string _S[] = 
	{"AA","AA","AAA","A"}
	; vs S(_S, _S + (sizeof(_S) / sizeof(_S[0]))); A0.push_back( S ); int K = 
	1
	; A1.push_back( K ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 3*/string _S[] = 
	{"AA","AA","AAA","A","AAA","AAAA"}
	; vs S(_S, _S + (sizeof(_S) / sizeof(_S[0]))); A0.push_back( S ); int K = 
	15
	; A1.push_back( K ); int result = 
	720
	; A2.push_back( result );  }
	{ /*Test 4*/string _S[] = 
	{"ABC","AB","ABC","CA"}
	; vs S(_S, _S + (sizeof(_S) / sizeof(_S[0]))); A0.push_back( S ); int K = 
	3
	; A1.push_back( K ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 5*/string _S[] = 
	{"A","B","C","A","B","C"}
	; vs S(_S, _S + (sizeof(_S) / sizeof(_S[0]))); A0.push_back( S ); int K = 
	1
	; A1.push_back( K ); int result = 
	672
	; A2.push_back( result );  }
	{ /*Test 6*/string _S[] = 
	{"AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAB"}
	; vs S(_S, _S + (sizeof(_S) / sizeof(_S[0]))); A0.push_back( S ); int K = 
	1
	; A1.push_back( K ); int result = 
	40320
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], count( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	MagicWords ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
