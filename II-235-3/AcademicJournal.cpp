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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
template<typename T, typename Predicate> vector<T> Parse( string s, Predicate predicate )
{
	vector<T> result; bool isWord = false; int j = 0;
	for( int i = 0; i < s.size(); i++ )
		if ( isWord )
		{
			if ( !predicate( s[i] ) )
			{
				istringstream S( s.substr( j, i - j ) );
				T current; S >> current; 
				if ( S.rdstate() ^ ios::failbit )
					result.push_back( current );
				isWord = false;
			}
		}
		else
		{
			if ( predicate( s[i] ) )
			{
				j = i; isWord = true;
			}
		}
		if ( isWord )
		{
			istringstream S( s.substr( j ) );
			T current; S >> current; 
			if ( S.rdstate() ^ ios::failbit )
				result.push_back( current );
		}
		return result;
}
struct split_helper: unary_function<int, bool>
{
	explicit split_helper( string delimeter ): delimeter(delimeter) {};
	bool operator() ( int c ) const
	{
		return delimeter.find( c ) == string::npos;
	}
private: string delimeter;
};
template <typename T> vector<T> Split( string s, string delimeter = " " )
{
	return Parse<T>( s, split_helper( delimeter ) );
}
struct AcademicJournal
{
	typedef map<string, int> M;
	struct comp: binary_function<string, string, bool>
	{
		mutable M A, B;
		comp( M A, M B ): A(A), B(B) {}
		bool operator() ( const string& a, const string& b ) const
		{
			if ( A[a] * B[b] != A[b] * B[a] )
				return A[a] * B[b] > A[b] * B[a];
			if ( A[a] != A[b] )
				return A[a] > A[b];
			return a < b;
		}
	};
	string getName( string s )
	{
		return s.substr( 0, s.find( '.' ) );
	}
	vs rankByImpact( vs papers )
	{
		vs result;
		M A, B;
		fora(i, papers)
		{
			string s = getName( papers[i] );
			++B[s];
			vi z( Split<int>( papers[i] ) );
			sort( all(z) );
			z.erase( unique( all(z) ), z.end() );
			fora(j, z)
			{
				string t = getName( papers[z[j]] );
				if ( t != s )
					++A[t];
			}
			result.push_back( s );
		}
		sort( all(result) );
		result.erase( unique( all(result) ), result.end() );
		sort( all(result), comp( A, B ) );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1;
	{ /*Test 0*/string _papers[] = 
	{"A.", "B. 0", "C. 1 0 3", "C. 2"}
	; vs papers(_papers, _papers + (sizeof(_papers) / sizeof(_papers[0]))); A0.push_back( papers ); string _result[] = 
	{"A", "B", "C" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 1*/string _papers[] = 
	{"RESPECTED JOURNAL.", "MEDIOCRE JOURNAL. 0", "LOUSY JOURNAL. 0 1",
"RESPECTED JOURNAL.", "MEDIOCRE JOURNAL. 3", "LOUSY JOURNAL. 4 3 3 4",
"RESPECTED SPECIFIC JOURNAL.", "MEDIOCRE SPECIFIC JOURNAL. 6", "LOUSY SPECIFIC JOURNAL. 6 7"}
	; vs papers(_papers, _papers + (sizeof(_papers) / sizeof(_papers[0]))); A0.push_back( papers ); string _result[] = 
	{"RESPECTED JOURNAL", "RESPECTED SPECIFIC JOURNAL", "MEDIOCRE JOURNAL", "MEDIOCRE SPECIFIC JOURNAL", "LOUSY JOURNAL", "LOUSY SPECIFIC JOURNAL" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 2*/string _papers[] = 
	{"NO CITATIONS.", "COMPLETELY ORIGINAL."}
	; vs papers(_papers, _papers + (sizeof(_papers) / sizeof(_papers[0]))); A0.push_back( papers ); string _result[] = 
	{"COMPLETELY ORIGINAL", "NO CITATIONS" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 3*/string _papers[] = 
	{"CONTEMPORARY PHYSICS. 5 4 6 8 7 1 9",
"EUROPHYSICS LETTERS. 9",
"J PHYS CHEM REF D. 5 4 6 8 7 1 9",
"J PHYS SOC JAPAN. 5 4 6 8 7 1 9",
"PHYSICAL REVIEW LETTERS. 5 6 8 7 1 9",
"PHYSICS LETTERS B. 6 8 7 1 9",
"PHYSICS REPORTS. 8 7 1 9",
"PHYSICS TODAY. 1 9",
"REP PROGRESS PHYSICS. 7 1 9",
"REV MODERN PHYSICS."}
	; vs papers(_papers, _papers + (sizeof(_papers) / sizeof(_papers[0]))); A0.push_back( papers ); string _result[] = 
	{"REV MODERN PHYSICS", "EUROPHYSICS LETTERS", "PHYSICS TODAY", "REP PROGRESS PHYSICS", "PHYSICS REPORTS", "PHYSICS LETTERS B", "PHYSICAL REVIEW LETTERS", "CONTEMPORARY PHYSICS", "J PHYS CHEM REF D", "J PHYS SOC JAPAN" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], rankByImpact( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	AcademicJournal ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
