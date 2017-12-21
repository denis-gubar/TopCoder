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
typedef vector<int> vi;
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct ComboBoxKeystrokes
{
	int minimumKeystrokes( vs elements )
	{
		int result = 0, n = elements.size();
		fora(i, elements)
			transform( all(elements[i]), elements[i].begin(), ::tolower );
		fora(i, elements)
		{
			vi A(n, n);
			A[i] = 0;
			queue<int> q; q.push( i );
			while( !q.empty() )
			{
				int k = q.front(); q.pop();
				for( char c = 'a'; c <= 'z'; ++c )
				{
					bool flag = true; int j;
					for( j = k + 1; flag && j < n; ++j )
						flag = elements[j][0] != c;
					if ( flag )
					{
						for( j = 0; flag && j < k; ++j )
							flag = elements[j][0] != c;
					}
					if ( !flag && A[j - 1] > A[k] + 1 )
					{
						A[j - 1] = A[k] + 1; q.push( j - 1 );
					}
				}
			}
			result = max(result, *max_element( all(A) ) );
		}
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<int> A1;
	{ /*Test 0*/string _Arg0[] = 
	{"alpha","beta","gamma","delta"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	1
	; A1.push_back( Arg1 );  }
	{ /*Test 1*/string _Arg0[] = 
	{"kyky","kalinov","kalmakka","Kavan","Kawigi","kaylin","Klinck","krijgertje","kupo"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	8
	; A1.push_back( Arg1 );  }
	{ /*Test 2*/string _Arg0[] = 
	{"a","b","c","b","d","b","e","b","f"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	2
	; A1.push_back( Arg1 );  }
	{ /*Test 3*/string _Arg0[] = 
	{"apple","Boy","CaRD","Dog","egG","FruiT",
 "Grape","hand","Ant","eagle","ice cream",
 "air","East","Exit","Door","camerA","bad",
 "fast","Zealot","internAtional","Bead",
 "Bread","Exit","fast", "actiVe","Cats",
 "beast","Alligator","drag","castle",
 "clean","iLlEgAl","crab","Free Willy",
 "first","dean","Fourth of July","King",
 "fellow","FrEaK","Elephant","bird","Bible",
 "creep","create","Deal","eEl","entrance",
 "cream","Fleece"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	4
	; A1.push_back( Arg1 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], minimumKeystrokes( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ComboBoxKeystrokes ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
