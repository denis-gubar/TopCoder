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
string replace_all( string s, string oldValue, string newValue )
{
	string result; int j = 0;
	for( int i = s.find( oldValue ); i > -1; i = s.find( oldValue, i + oldValue.size() ) )
	{
		result += s.substr( j, i - j ) + newValue;
		j = i + oldValue.size();
	}
	result.append( s.substr( j ) );
	return result;
}
struct Twain
{
	string getNewSpelling( int year, string phrase )
	{
		string result(phrase);
		if ( year >= 1 )
			result = replace_all( replace_all( " " + result, " x", " z" ), "x", "ks" ).substr( 1 );
		if ( year >= 2 )
			result = replace_all( result, "y", "i" );
		if ( year >= 3 )
			result = replace_all( replace_all( result, "ce", "se" ), "ci", "si" );
		if ( year >= 4 )
		{
			string s;
			while( s.size() != result.size() )
			{
				s = replace_all( result, "ck", "k" );
				s.swap( result );
			}
		}
		if ( year >= 5 )
			result = replace_all( replace_all( replace_all( replace_all( replace_all( " " + result, " sch", " sk" ), "chr", "kr" ).substr( 1 ),
				"ch", "+h" ), "c", "k"), "+", "c" );
		if ( year >= 6 )
			result = replace_all( " " + result, " kn", " n" ).substr( 1 );
		if ( year >= 7 )
		{
			string s; s.swap(result);
			result = s.substr( 0, 1 );
			for(int i = 1; i < s.size(); ++i )
				if ( s[i] != s[i - 1] || string( "aeiou " ).find( s[i] ) != string::npos )
					result += s[i];
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<string> A1; vector<string> A2;
	{ /*Test 0*/int year = 
	1
	; A0.push_back( year ); string phrase = 
	"i fixed the chrome xerox by the cyclical church"
	; A1.push_back( phrase ); string result = 
	"i fiksed the chrome zeroks by the cyclical church"
	; A2.push_back( result );  }
	{ /*Test 1*/int year = 
	2
	; A0.push_back( year ); string phrase = 
	"i fixed the chrome xerox by the cyclical church"
	; A1.push_back( phrase ); string result = 
	"i fiksed the chrome zeroks bi the ciclical church"
	; A2.push_back( result );  }
	{ /*Test 2*/int year = 
	0
	; A0.push_back( year ); string phrase = 
	"this is unchanged"
	; A1.push_back( phrase ); string result = 
	"this is unchanged"
	; A2.push_back( result );  }
	{ /*Test 3*/int year = 
	7
	; A0.push_back( year ); string phrase = 
	"sch kn x xschrx cknnchc cyck xxceci"
	; A1.push_back( phrase ); string result = 
	"sk n z zskrks nchk sik zksesi"
	; A2.push_back( result );  }
	{ /*Test 4*/int year = 
	7
	; A0.push_back( year ); string phrase = 
	"  concoction   convalescence   cyclical   cello   "
	; A1.push_back( phrase ); string result = 
	"  konkoktion   konvalesense   siklikal   selo   "
	; A2.push_back( result );  }
	{ /*Test 5*/int year = 
	7
	; A0.push_back( year ); string phrase = 
	""
	; A1.push_back( phrase ); string result = 
	""
	; A2.push_back( result );  }
	{ /*Test 6*/int year = 
	7
	; A0.push_back( year ); string phrase = 
	"cck xzz aaaaa"
	; A1.push_back( phrase ); string result = 
	"k z aaaaa"
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], getNewSpelling( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Twain ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
