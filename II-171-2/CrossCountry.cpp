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
typedef pair<int, int> pii;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct CrossCountry
{
	struct comp: binary_function<int, int, bool>
	{
		comp( string finishOrder ): finishOrder_(finishOrder) {}
		pii calc( int x ) const
		{
			int result5 = 0, result6 = finishOrder_.size(), count = 0;
			fora(i, finishOrder_)
				if ( finishOrder_[i] == x )
				{
					++count;
					if ( count <= 5 )
						result5 += i;
					if ( count == 6 )
						result6 = i;
				}
			return make_pair( result5, result6 );
		}
		bool operator() ( int a, int b ) const
		{
			if ( calc(a) != calc(b) ) return calc(a) < calc(b);
			return a < b;
		}
	private:
		string finishOrder_;
	};
	string scoreMeet( int numTeams, string finishOrder )
	{
		string result;
		vi teams;
		fora(i, finishOrder)
			if ( find( all(teams), finishOrder[i] ) == teams.end() && count( all(finishOrder), finishOrder[i] ) >= 5 )
				teams.push_back( finishOrder[i] );
		sort( all(teams), comp(finishOrder) );
		fora(i, teams)
			result += teams[i];
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<string> A1; vector<string> A2;
	{ /*Test 0*/int numTeams = 
	2
	; A0.push_back( numTeams ); string finishOrder = 
	"AABBABBABBA"
	; A1.push_back( finishOrder ); string result = 
	"AB"
	; A2.push_back( result );  }
	{ /*Test 1*/int numTeams = 
	3
	; A0.push_back( numTeams ); string finishOrder = 
	"CCCBBBBBAAACC"
	; A1.push_back( finishOrder ); string result = 
	"BC"
	; A2.push_back( result );  }
	{ /*Test 2*/int numTeams = 
	4
	; A0.push_back( numTeams ); string finishOrder = 
	"ABDCBADBDCCDBCDBCAAAC"
	; A1.push_back( finishOrder ); string result = 
	"BDCA"
	; A2.push_back( result );  }
	{ /*Test 3*/int numTeams = 
	10
	; A0.push_back( numTeams ); string finishOrder = 
	"BDHCEAJBIDBCCHGCBDJEBAAHEGAGGADHGIECJEHAEBDADJCDHG"
	; A1.push_back( finishOrder ); string result = 
	"BCDAHEG"
	; A2.push_back( result );  }
	{ /*Test 4*/int numTeams = 
	3
	; A0.push_back( numTeams ); string finishOrder = 
	"BABCAABABAB"
	; A1.push_back( finishOrder ); string result = 
	"AB"
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], scoreMeet( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	CrossCountry ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
