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
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
#define all(v) (v).begin(), (v).end()
string replace_all( const string& s, const string& oldValue, const string& newValue )
{
	string result; size_t j = 0;
	for( size_t i = s.find( oldValue ), n = oldValue.size(); i != string::npos; i = s.find( oldValue, j ) )
		result += s.substr( j, i - j ) + newValue, j = i + n;
	return result + s.substr( j );
}
string base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct HexatridecimalSum
{	
	string sum( string a, string b )
	{
		string result( max(a.size(), b.size()) + 1, 0 );
		string x(a), y(b);
		reverse( all(x) );
		reverse( all(y) );
		x += '0'; y += '0';
		for( int i = 0; i < result.size() - 1; ++i )
		{
			int current = 0;
			if ( i < x.size() )
				current += base.find( x[i] );
			if ( i < y.size() )
				current += base.find( y[i] );
			result[i + 1] += (result[i] + current) / 36;
			result[i] = (result[i] + current) % 36;
		}
		fora(i, result)
			result[i] = base[result[i]];
		reverse( all(result) );
		if ( result[0] == '0' )
			return result.substr( 1 );
		return result;		
	}
	string sum( vs& A )
	{
		string result = A[0];
		for( int i = 1; i < A.size(); ++i )
			result = sum( result, A[i] );
		return result;
	}
	string maximizeSum( vs numbers, int k )
	{
		string result = sum( numbers );
		vs S( numbers );
		for( int step = 0; step < k; ++step )
		{
			int best = 35;
			for( int i = 0; i < 35; ++i )
			{
				vs C( S );
				fora(j, C)
					C[j] = replace_all( C[j], string(1, base[i]), "Z" );
				string current = sum( C );
				if ( current.size() > result.size() || current.size() == result.size() && current > result )
				{
					best = i; result = current;
				}
			}
			if ( best < 35 )
			{
				fora(j, S)
					S[j] = replace_all( S[j], string(1, base[best]), "Z" );
			}
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<int> A1; vector<string> A2;
	{ /*Test 0*/string _numbers[] = 
	{"HELLO"}
	; vs numbers(_numbers, _numbers + (sizeof(_numbers) / sizeof(_numbers[0]))); A0.push_back( numbers ); int k = 
	2
	; A1.push_back( k ); string result = 
	"ZZLLO"
	; A2.push_back( result );  }
	{ /*Test 1*/string _numbers[] = 
	{"500", "POINTS", "FOR", "THIS", "PROBLEM"}
	; vs numbers(_numbers, _numbers + (sizeof(_numbers) / sizeof(_numbers[0]))); A0.push_back( numbers ); int k = 
	5
	; A1.push_back( k ); string result = 
	"1100TC85"
	; A2.push_back( result );  }
	{ /*Test 2*/string _numbers[] = 
	{"TO", "BE", "OR", "NOT", "TO", "BE"}
	; vs numbers(_numbers, _numbers + (sizeof(_numbers) / sizeof(_numbers[0]))); A0.push_back( numbers ); int k = 
	0
	; A1.push_back( k ); string result = 
	"QNO"
	; A2.push_back( result );  }
	{ /*Test 3*/string _numbers[] = 
	{"KEQUALS36"}
	; vs numbers(_numbers, _numbers + (sizeof(_numbers) / sizeof(_numbers[0]))); A0.push_back( numbers ); int k = 
	36
	; A1.push_back( k ); string result = 
	"ZZZZZZZZZ"
	; A2.push_back( result );  }
	{ /*Test 4*/string _numbers[] = 
	{"GOOD", "LUCK", "AND", "HAVE", "FUN"}
	; vs numbers(_numbers, _numbers + (sizeof(_numbers) / sizeof(_numbers[0]))); A0.push_back( numbers ); int k = 
	7
	; A1.push_back( k ); string result = 
	"31YUB"
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], maximizeSum( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	HexatridecimalSum ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
