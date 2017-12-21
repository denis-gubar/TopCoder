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
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
#define fora(i,v) for(int i = 0; i < (v).size(); ++i)
#define all(v) (v).begin(), (v).end()
struct MoneyExchange
{
	double bestRate( vs rates, string type1, string type2 )
	{
        if ( type1 == type2 )
            return 1;
        set<string> S;
        S.insert( type1 ); S.insert( type2 );
        fora(i, rates)
        {
            istringstream s(rates[i]);
            int a, b; string A, B;
            s >> A >> a >> B >> b;
            S.insert( A ); S.insert( B );
        }
        vs T( all(S) );
        int n = T.size();
        vvd F(n, vd(n));
        map<string, int> M;
        fora(i, T)
            M[T[i]] = i;
        fora(i, rates)
        {
            istringstream s(rates[i]);
            int a, b; string A, B;
            s >> A >> a >> B >> b;
            F[M[A]][M[B]] = max( F[M[A]][M[B]], 1.0 * b / a );
        }
        for( int k = 0; k < n; ++k )
            for( int i = 0; i < n; ++i )
                for( int j = 0; j < n; ++j )
                    F[i][j] = max( F[i][j], F[i][k] * F[k][j] );
		double result = F[M[type1]][M[type2]];
        if ( !result )
            return -1;
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<string> A1; vector<string> A2; vector<double> A3;
	{ /*Test 0*/string _rates[] = 
	{"EUR 8 USD 10", "USD 10 EUR 7"}
	; vs rates(_rates, _rates + (sizeof(_rates) / sizeof(_rates[0]))); A0.push_back( rates ); string type1 = 
	"EUR"
	; A1.push_back( type1 ); string type2 = 
	"USD"
	; A2.push_back( type2 ); double result = 
	1.25
	; A3.push_back( result );  }
	{ /*Test 1*/string _rates[] = 
	{"EUR 0008 USD 0010"}
	; vs rates(_rates, _rates + (sizeof(_rates) / sizeof(_rates[0]))); A0.push_back( rates ); string type1 = 
	"USD"
	; A1.push_back( type1 ); string type2 = 
	"EUR"
	; A2.push_back( type2 ); double result = 
	-1.0
	; A3.push_back( result );  }
	{ /*Test 2*/string _rates[] = 
	{"EUR 8 USD 10","EUR 1 GOODBUY 2","GOODBUY 1 USD 2"}
	; vs rates(_rates, _rates + (sizeof(_rates) / sizeof(_rates[0]))); A0.push_back( rates ); string type1 = 
	"EUR"
	; A1.push_back( type1 ); string type2 = 
	"USD"
	; A2.push_back( type2 ); double result = 
	4.0
	; A3.push_back( result );  }
	{ /*Test 3*/string _rates[] = 
	{"A 1 B 2","A 1 C 3","B 2 D 3","C 9 D 10","D 7 E 2"}
	; vs rates(_rates, _rates + (sizeof(_rates) / sizeof(_rates[0]))); A0.push_back( rates ); string type1 = 
	"A"
	; A1.push_back( type1 ); string type2 = 
	"E"
	; A2.push_back( type2 ); double result = 
	0.9523809523809523
	; A3.push_back( result );  }
	{ /*Test 4*/vs rates; A0.push_back( rates ); string type1 = 
	"TYPEA"
	; A1.push_back( type1 ); string type2 = 
	"TYPEB"
	; A2.push_back( type2 ); double result = 
	-1.0
	; A3.push_back( result );  }
	{ /*Test 5*/string _rates[] = 
	{"A 7 A 5","A 1 B 1","B 2 A 2"}
	; vs rates(_rates, _rates + (sizeof(_rates) / sizeof(_rates[0]))); A0.push_back( rates ); string type1 = 
	"A"
	; A1.push_back( type1 ); string type2 = 
	"A"
	; A2.push_back( type2 ); double result = 
	1.0
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], bestRate( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	MoneyExchange ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
