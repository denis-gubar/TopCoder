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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct PeopleCircle
{
	string order( int numMales, int numFemales, int K )
	{
		string result(numMales + numFemales, 'F');
		--K;
		vi x(numMales + numFemales);
		fora(i, x)
			x[i] = i;
		for( int i = 0; i < numFemales; ++i )
		{
			vi y;
			copy( x.begin() + K % x.size() + 1, x.end(), back_inserter( y ) );
			copy( x.begin(), x.begin() + K % x.size(), back_inserter( y ) );
			y.swap( x );
		}
		fora(i, x)
			result[x[i]] = 'M';
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<int> A2; vector<string> A3;
	{ /*Test 0*/int numMales = 
	5
	; A0.push_back( numMales ); int numFemales = 
	3
	; A1.push_back( numFemales ); int K = 
	2
	; A2.push_back( K ); string result = 
	"MFMFMFMM"
	; A3.push_back( result );  }
	{ /*Test 1*/int numMales = 
	7
	; A0.push_back( numMales ); int numFemales = 
	3
	; A1.push_back( numFemales ); int K = 
	1
	; A2.push_back( K ); string result = 
	"FFFMMMMMMM"
	; A3.push_back( result );  }
	{ /*Test 2*/int numMales = 
	25
	; A0.push_back( numMales ); int numFemales = 
	25
	; A1.push_back( numFemales ); int K = 
	1000
	; A2.push_back( K ); string result = 
	"MMMMMFFFFFFMFMFMMMFFMFFFFFFFFFMMMMMMMFFMFMMMFMFMMF"
	; A3.push_back( result );  }
	{ /*Test 3*/int numMales = 
	5
	; A0.push_back( numMales ); int numFemales = 
	5
	; A1.push_back( numFemales ); int K = 
	3
	; A2.push_back( K ); string result = 
	"MFFMMFFMFM"
	; A3.push_back( result );  }
	{ /*Test 4*/int numMales = 
	1
	; A0.push_back( numMales ); int numFemales = 
	0
	; A1.push_back( numFemales ); int K = 
	245
	; A2.push_back( K ); string result = 
	"M"
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], order( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	PeopleCircle ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
