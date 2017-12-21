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
typedef long long lint;
typedef vector<int> vi;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct PrimeAnagrams
{
	bool isPrime( vi& primes, int x )
	{
		if ( x == 1 ) return false;
		if ( !binary_search( all(primes), x ) )
		{
			if ( primes.back() > x ) return false;
			for( vi::iterator it = primes.begin(); it != primes.end() && *it * *it <= x; ++it )
				if ( x % *it == 0 ) return false;
		}
		return true;
	}
	vi primes( string anagram )
	{
		int n = anagram.size(), best = 1 << 30;
		vi result(3), primes, a(n);
		fora(i, a)
			a[i] = anagram[i] - '0';
		sort( all(a) );
		primes.push_back( 2 );
		primes.push_back( 3 );
		for( int i = 5; i < 10000; i += 2 )
		{
			bool flag = true;
			for( vi::iterator it = primes.begin(); it != primes.end() && *it * *it <= i; ++it )
				if ( i % *it == 0 )
				{
					flag = false; break;
				}
			if ( flag ) primes.push_back( i );
		}
		do
		{
			if ( a[0] )
				for( int i1 = 1; i1 <= n - 2; ++i1 )
				{
					if ( !a[i1] ) continue;
					int a1 = 0;
					for( int j1 = 0; j1 < i1; ++j1 )
						a1 = a1 * 10 + a[j1];
					if ( !isPrime( primes, a1 ) ) continue;
					for( int i2 = 1; i1 + i2 <= n - 1; ++i2 )
					{
						if ( !a[i1 + i2] ) continue;
						int a2 = 0, a3 = 0;
						for( int j2 = i1; j2 < i1 + i2; ++j2 )
							a2 = a2 * 10 + a[j2];
						if ( !isPrime( primes, a2 ) ) continue;
						for( int j3 = i1 + i2; j3 < n; ++j3 )
							a3 = a3 * 10 + a[j3];
						if ( !isPrime( primes, a3 ) ) continue;
						if ( best > a1 * a2 * a3 )
						{
							best = a1 * a2 * a3;
							result[0] = a1; result[1] = a2; result[2] = a3;
							sort( all(result) );
						}
					}
				}
		} while( next_permutation( all(a) ) );
		if ( best == 1 << 30 ) return vi();
		return result;
	}
// BEGIN CUT HERE
	private:
	template <typename T> string print_array( const vector<T>& v ) { ostringstream os; os << "{ "; for( typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it ) os << '\"' << *it << "\","; os << " }"; return os.str(); }
	template<typename T> void verify_case( int Case, const vector<T>& expected, const vector<T>& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: " << print_array( expected ) << endl; cerr << "\tReceived: " << print_array( received ) << endl; } }
	void verify_case( int Case, const lint& expected, const lint& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const double& expected, const double& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const int& expected, const int& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const string& expected, const string& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	public:
	void run_test( int Case = -1 ) { vector<string> A0; vector<vi> A1;
	{ /*Test 0*/string Arg0 = 
	"12345678"
	; A0.push_back( Arg0 ); int _Arg1[] = 
	{ 2,  3,  145687 }
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	{ /*Test 0*/string Arg0 = 
	"39151"
	; A0.push_back( Arg0 ); int _Arg1[] = 
	{ 5,  13,  19 }
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	{ /*Test 1*/string Arg0 = 
	"921179"
	; A0.push_back( Arg0 ); int _Arg1[] = 
	{ 2,  17,  199 }
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	{ /*Test 2*/string Arg0 = 
	"01123"
	; A0.push_back( Arg0 ); int _Arg1[] = 
	{ 2,  3,  101 }
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	{ /*Test 3*/string Arg0 = 
	"0707070"
	; A0.push_back( Arg0 ); vi Arg1; A1.push_back( Arg1 );  }
	{ /*Test 4*/string Arg0 = 
	"222"
	; A0.push_back( Arg0 ); int _Arg1[] = 
	{ 2,  2,  2 }
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	{ /*Test 5*/string Arg0 = 
	"123"
	; A0.push_back( Arg0 ); vi Arg1; A1.push_back( Arg1 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], primes( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	PrimeAnagrams ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
