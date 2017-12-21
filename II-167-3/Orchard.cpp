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
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
#define all(v) (v).begin(), (v).end()
struct Orchard
{
	struct calc: unary_function<pii, unsigned>
	{
		calc( vs orchard ): orchard_(orchard) {}
		unsigned operator() ( pii x ) const
		{
			unsigned result = min( min( orchard_.size() - x.first - 1, static_cast<unsigned>(x.first) ), 
				min( orchard_[0].size() - x.second - 1, static_cast<unsigned>(x.second) ) ) + 1;
			fora2(i, j, orchard_)
				if ( orchard_[i][j] == 'T' )
					result = min( result, static_cast<unsigned>( abs(i - x.first) + abs(j - x.second) ) );
			return result;
		}
	private:
		vs orchard_;
	};
	struct comp: binary_function<pii, pii, bool>
	{
		comp( vs orchard ): orchard_(orchard), calc_(orchard) {}
		bool operator() ( pii a, pii b ) const
		{
			return calc_( a ) < calc_( b );
		}
	private:
		vs orchard_;
		calc calc_;
	};
	vi nextTree( vs orchard )
	{
		vi result;
		vpii A;
		fora2(i, j, orchard)
			A.push_back( make_pair(i, j) );
		pii p = *max_element( all(A), comp(orchard) );
		result.push_back( p.first + 1 );
		result.push_back( p.second + 1 );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vi> A1;
	{ /*Test 0*/string _orchard[] = 
	{ "----" , "T---" , "----" , "----" }
	; vs orchard(_orchard, _orchard + (sizeof(_orchard) / sizeof(_orchard[0]))); A0.push_back( orchard ); int _result[] = 
	{ 2,  3 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 1*/string _orchard[] = 
	{"---T--","------","------","----T-","------","------"}
	; vs orchard(_orchard, _orchard + (sizeof(_orchard) / sizeof(_orchard[0]))); A0.push_back( orchard ); int _result[] = 
	{ 3,  3 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 2*/string _orchard[] = 
	{"------------","------------","------------","------------",
"------------","------------","------------","------------",
"------------","------------","------------","------------"}
	; vs orchard(_orchard, _orchard + (sizeof(_orchard) / sizeof(_orchard[0]))); A0.push_back( orchard ); int _result[] = 
	{ 6,  6 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 3*/string _orchard[] = 
	{"-T----T",
 "T---T--",
 "-----TT",
 "---TT--",
 "T-----T",
 "-------",
 "T-T--T-"}
	; vs orchard(_orchard, _orchard + (sizeof(_orchard) / sizeof(_orchard[0]))); A0.push_back( orchard ); int _result[] = 
	{ 2,  3 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], nextTree( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Orchard ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
