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
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct PartySeats
{
	vs seating( vs attendees )
	{
		vs result;
		int n = attendees.size();
		if ( n % 4 == 0 && n )
		{
			vs boys, girls;
			fora(i, attendees)
			{
				istringstream s( attendees[i] );
				string name, gender;
				s >> name >> gender;
				if ( gender == "boy" )
					boys.push_back( name );
				else
					girls.push_back( name );
			}
			if ( boys.size() == girls.size() )
			{
				sort( all(boys) ); sort( all(girls) );
				result.push_back( "HOST" );
				for( int i = 0; i < n / 4; ++i )
				{
					result.push_back( girls[i] );
					result.push_back( boys[i] );
				}
				result.push_back( "HOSTESS" );
				for( int i = n / 4; i < n / 2; ++i )
				{
					result.push_back( boys[i] );
					result.push_back( girls[i] );
				}
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1;
	{ /*Test 0*/string _attendees[] = 
	{"BOB boy","SAM girl","DAVE boy","JO girl"}
	; vs attendees(_attendees, _attendees + (sizeof(_attendees) / sizeof(_attendees[0]))); A0.push_back( attendees ); string _result[] = 
	{ "HOST",  "JO",  "BOB",  "HOSTESS",  "DAVE",  "SAM" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 1*/string _attendees[] = 
	{"JOHN boy"}
	; vs attendees(_attendees, _attendees + (sizeof(_attendees) / sizeof(_attendees[0]))); A0.push_back( attendees ); vs result; A1.push_back( result );  }
	{ /*Test 2*/string _attendees[] = 
	{"JOHN boy","CARLA girl"}
	; vs attendees(_attendees, _attendees + (sizeof(_attendees) / sizeof(_attendees[0]))); A0.push_back( attendees ); vs result; A1.push_back( result );  }
	{ /*Test 3*/string _attendees[] = 
	{"BOB boy","SUZIE girl","DAVE boy","JO girl",
"AL boy","BOB boy","CARLA girl","DEBBIE girl"}
	; vs attendees(_attendees, _attendees + (sizeof(_attendees) / sizeof(_attendees[0]))); A0.push_back( attendees ); string _result[] = 
	{ "HOST",  "CARLA",  "AL",  "DEBBIE",  "BOB",  "HOSTESS",  "BOB",  "JO",  "DAVE",  "SUZIE" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], seating( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	PartySeats ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
