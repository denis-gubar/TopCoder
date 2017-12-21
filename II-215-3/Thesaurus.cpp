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
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
vs split( string s, string delimeters = " ", bool skipEmpty = true )
{
	vs result; s += delimeters[0];
	for( int i = 0, prev = 0; i < s.size(); i++ )
		if ( delimeters.find( s[i] ) != -1 )
		{
			if ( !skipEmpty || prev < i )
				result.push_back( s.substr( prev, i - prev ) );
			prev = i + 1;
		}
	return result;
}
struct Thesaurus
{
	vs edit( vs entry )
	{
		vs result; int n = entry.size();
		bool flag = true;
		while( flag )
		{
			flag = false;
			for( int i = 0; i < n; i++ )
			{
				vs a = split( entry[i] );
				set<string> A( all(a) );
				for( int j = i + 1; j < n; j++ )
				{
					vs b = split( entry[j] );
					set<string> B( all(b) );
					set<string> C;
					set_intersection( all(A), all(B), inserter(C, C.begin()) );
					if ( C.size() > 1 )
					{
						flag = true;
						set<string> D;
						set_union( all(A), all(B), inserter(D, D.begin()) );
						entry[i] = entry[j] = "";
						for( set<string>::iterator it = D.begin(); it != D.end(); ++it )
							entry[i] += entry[i].size() ? " " + *it : *it;
						break;
					}
				}
				if ( flag ) break;
			}
		}
		fora(i, entry)
		{
			vs d = split( entry[i] );
			set<string> D( all(d) );
			entry[i] = "";
			for( set<string>::iterator it = D.begin(); it != D.end(); ++it )
				entry[i] += entry[i].size() ? " " + *it : *it;
		}
		sort( all(entry) );
		fora(i, entry)
			if ( entry[i] != "" )
				result.push_back( entry[i] );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1;
	{ /*Test 0*/string _Arg0[] = 
	{"ape monkey wrench", "wrench twist strain"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string _Arg1[] = 
	{ "ape monkey wrench",  "strain twist wrench" }
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	{ /*Test 1*/string _Arg0[] = 
	{"ape monkey wrench", "wrench twist strain", "monkey twist frugue"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string _Arg1[] = 
	{ "ape monkey wrench",  "frugue monkey twist",  "strain twist wrench" }
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	{ /*Test 2*/string _Arg0[] = 
	{"ape monkey wrench", "wrench twist strain", "monkey twist frugue strain"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string _Arg1[] = 
	{ "ape frugue monkey strain twist wrench" }
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	{ /*Test 3*/string _Arg0[] = 
	{"point run score","point dot","cut run tear score","cut valley","cute pretty"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string _Arg1[] = 
	{ "cut point run score tear",  "cut valley",  "cute pretty",  "dot point" }
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], edit( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Thesaurus ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
