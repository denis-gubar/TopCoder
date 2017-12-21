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
typedef vector<vs> vvs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct ShortPalindromes
{
	string shortest( string base )
	{
		int n = base.size();
		vvs M(n, vs(n));
		fora(i, M)
			M[i][i] += string( 1, base[i] );
		for( int j = 1; j < n; ++j )
			for( int i = 0; i + j < n; ++i )
				if ( base[i] == base[i + j] )
					M[i][i + j] = base[i] + M[i + 1][i + j - 1] + base[i];
				else
				{
					string a = base[i] + M[i + 1][i + j] + base[i];
					string b = base[i + j] + M[i][i + j - 1] + base[i + j];
					M[i][i + j] = (a.size() < b.size() || a.size() == b.size() && a < b) ? a : b;
				}
		return M[0][n - 1];
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
	{ /*Test 0*/string base = 
	"RACE"
	; A0.push_back( base ); string result = 
	"ECARACE"
	; A1.push_back( result );  }
	{ /*Test 1*/string base = 
	"TOPCODER"
	; A0.push_back( base ); string result = 
	"REDTOCPCOTDER"
	; A1.push_back( result );  }
	{ /*Test 2*/string base = 
	"Q"
	; A0.push_back( base ); string result = 
	"Q"
	; A1.push_back( result );  }
	{ /*Test 3*/string base = 
	"MADAMIMADAM"
	; A0.push_back( base ); string result = 
	"MADAMIMADAM"
	; A1.push_back( result );  }
	{ /*Test 4*/string base = 
	"ALRCAGOEUAOEURGCOEUOOIGFA"
	; A0.push_back( base ); string result = 
	"AFLRCAGIOEOUAEOCEGRURGECOEAUOEOIGACRLFA"
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], shortest( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ShortPalindromes ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
