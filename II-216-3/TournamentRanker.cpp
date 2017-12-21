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
typedef pair<string, string> pss;
typedef vector<pss> vpss;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
map<string, int> M;
struct TournamentRanker
{
	struct comp: binary_function<pss, pss, bool>
	{
		comp( vs result ): result( result ) {}
		bool operator() ( const pss& a, const pss& b ) const
		{
			if ( M[a.first] != M[b.first] )
				return M[a.first] > M[b.first];
			return distance( result.begin(), find( all(result), a.second ) ) <
				distance( result.begin(), find( all(result), b.second ) );
		}
		vs result;
	};
	vs rankTeams( vs names, vs lostTo )
	{
		vs result;
		result.push_back( "" );
		M.clear();
		fora(i, names)
			++M[lostTo[i]];
		while( result.size() <= names.size() )
		{
			vpss current;
			fora(i, names)
				if ( find( all(result), names[i] ) == result.end() && find( all(result), lostTo[i] ) != result.end() )
					current.push_back( make_pair( names[i], lostTo[i] ) );
			sort( all(current), comp( result ) );
			result.push_back( current[0].first );
		}
		return vs( result.begin() + 1, result.end() );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1; vector<vs> A2;
	{ /*Test 0*/string _names[] = 
	{"RODDICK", "SCHUETTLER", "FERREIRA", "AGASSI"}
	; vs names(_names, _names + (sizeof(_names) / sizeof(_names[0]))); A0.push_back( names ); string _lostTo[] = 
	{"SCHUETTLER", "AGASSI", "AGASSI", ""}
	; vs lostTo(_lostTo, _lostTo + (sizeof(_lostTo) / sizeof(_lostTo[0]))); A1.push_back( lostTo ); string _result[] = 
	{ "AGASSI",  "SCHUETTLER",  "FERREIRA",  "RODDICK" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 1*/string _names[] = 
	{"DUKE", "SETON HALL", "ILLINOIS", "CINCINNATI",
 "NORTH CAROLINA", "TEXAS", "XAVIER", "MISSISSIPPI STATE"}
	; vs names(_names, _names + (sizeof(_names) / sizeof(_names[0]))); A0.push_back( names ); string _lostTo[] = 
	{"", "DUKE", "DUKE", "ILLINOIS",
 "TEXAS", "XAVIER", "DUKE", "XAVIER"}
	; vs lostTo(_lostTo, _lostTo + (sizeof(_lostTo) / sizeof(_lostTo[0]))); A1.push_back( lostTo ); string _result[] = 
	{ "DUKE",  "XAVIER",  "ILLINOIS",  "TEXAS",  "SETON HALL",  "MISSISSIPPI STATE",  "CINCINNATI",  "NORTH CAROLINA" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 2*/string _names[] = 
	{"JAVA", "VISUAL BASIC"}
	; vs names(_names, _names + (sizeof(_names) / sizeof(_names[0]))); A0.push_back( names ); string _lostTo[] = 
	{"VISUAL BASIC", ""}
	; vs lostTo(_lostTo, _lostTo + (sizeof(_lostTo) / sizeof(_lostTo[0]))); A1.push_back( lostTo ); string _result[] = 
	{ "VISUAL BASIC",  "JAVA" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], rankTeams( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	TournamentRanker ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
