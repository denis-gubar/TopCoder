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
template<typename T> string ToString( T x )
{
	ostringstream S; S << x; return S.str();
}
struct ProblemWriting
{
	enum S { s0, s1, s2, s3, s4 };
	string myCheckData( string dotForm )
	{
		if ( dotForm.empty() || dotForm.size() > 25 )
			return "dotForm must contain between 1 and 25 characters, inclusive.";
		int i = 0; S s = s0; string operators = "/*-+";
		for( ; i < dotForm.size(); ++i )
		{
			switch( s )
			{
				case s0:
					if ( ::isdigit( dotForm[i] ) ) s = s1;
					else s = s4;
					break;
				case s1:
					if ( operators.find( dotForm[i] ) != string::npos ) s = s3;
					else if ( dotForm[i] == '.' ) s = s2;
					else s = s4;
					break;
				case s2:
					if ( dotForm[i] == '.' ) s = s2;
					else if ( operators.find( dotForm[i] ) != string::npos ) s = s3;
					else s = s4;
					break;
				case s3:
					if ( dotForm[i] == '.' ) s = s3;
					else if ( ::isdigit( dotForm[i] ) ) s = s1;
					else s = s4;
					break;
			}
			if ( s == s4 ) break;
		}
		if ( s != s1 )
			return "dotForm is not in dot notation, check character " + ToString( i ) + ".";
		return "";
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<string> A1;
	{ /*Test 0*/string dotForm = 
	"3+5"
	; A0.push_back( dotForm ); string result = 
	""
	; A1.push_back( result );  }
	{ /*Test 1*/string dotForm = 
	"9..+.5...*....3"
	; A0.push_back( dotForm ); string result = 
	""
	; A1.push_back( result );  }
	{ /*Test 2*/string dotForm = 
	"5.3+4"
	; A0.push_back( dotForm ); string result = 
	"dotForm is not in dot notation, check character 2."
	; A1.push_back( result );  }
	{ /*Test 3*/string dotForm = 
	"9*9*9*9*9*9*9*9*9*9*9*9*9*9"
	; A0.push_back( dotForm ); string result = 
	"dotForm must contain between 1 and 25 characters, inclusive."
	; A1.push_back( result );  }
	{ /*Test 4*/string dotForm = 
	"3.........../...........4"
	; A0.push_back( dotForm ); string result = 
	""
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], myCheckData( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ProblemWriting ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
