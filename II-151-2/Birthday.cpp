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
struct Birthday
{
	string getNext( string date, vs birthdays )
	{
		fora(i, birthdays)
		{
			vs z = split( birthdays[i] );
			birthdays[i] = z[0];
		}
		sort( all(birthdays) );
		vs::iterator it = lower_bound( all(birthdays), date );
		if ( it == birthdays.end() ) it = birthdays.begin();
		return *it;
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<vs> A1; vector<string> A2;
	{ /*Test 0*/string date = 
	"06/17"
	; A0.push_back( date ); string _birthdays[] = 
	{"02/17 Wernie", "10/12 Stefan"}
	; vs birthdays(_birthdays, _birthdays + (sizeof(_birthdays) / sizeof(_birthdays[0]))); A1.push_back( birthdays ); string result = 
	"10/12"
	; A2.push_back( result );  }
	{ /*Test 1*/string date = 
	"06/17"
	; A0.push_back( date ); string _birthdays[] = 
	{"10/12 Stefan"}
	; vs birthdays(_birthdays, _birthdays + (sizeof(_birthdays) / sizeof(_birthdays[0]))); A1.push_back( birthdays ); string result = 
	"10/12"
	; A2.push_back( result );  }
	{ /*Test 2*/string date = 
	"02/17"
	; A0.push_back( date ); string _birthdays[] = 
	{"02/17 Wernie", "10/12 Stefan"}
	; vs birthdays(_birthdays, _birthdays + (sizeof(_birthdays) / sizeof(_birthdays[0]))); A1.push_back( birthdays ); string result = 
	"02/17"
	; A2.push_back( result );  }
	{ /*Test 3*/string date = 
	"12/24"
	; A0.push_back( date ); string _birthdays[] = 
	{"10/12 Stefan"}
	; vs birthdays(_birthdays, _birthdays + (sizeof(_birthdays) / sizeof(_birthdays[0]))); A1.push_back( birthdays ); string result = 
	"10/12"
	; A2.push_back( result );  }
	{ /*Test 4*/string date = 
	"01/02"
	; A0.push_back( date ); string _birthdays[] = 
	{"02/17 Wernie",
 "10/12 Stefan",
 "02/17 MichaelJordan",
 "10/12 LucianoPavarotti",
 "05/18 WilhelmSteinitz"}
	; vs birthdays(_birthdays, _birthdays + (sizeof(_birthdays) / sizeof(_birthdays[0]))); A1.push_back( birthdays ); string result = 
	"02/17"
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], getNext( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Birthday ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
