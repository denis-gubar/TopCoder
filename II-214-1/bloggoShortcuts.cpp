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
#include <utility>
using namespace std;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE 
typedef long long lint;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct bloggoShortcuts
{
	string expand( string text )
	{
		string result;
		bool a = true, b = true;
		fora(i, text)
		{
			if ( text[i] == '*' )
			{
				result += a ? "<b>" : "</b>";
				a = !a;
			}
			else if ( text[i] == '_' )
			{
				result += b ? "<i>" : "</i>";
				b = !b;
			}
			else result += text[i];
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<string> A1;
	{ /*Test 0*/string Arg0 = 
	"You _should_ see the new walrus at the zoo!"
	; A0.push_back( Arg0 ); string Arg1 = 
	"You <i>should</i> see the new walrus at the zoo!"
	; A1.push_back( Arg1 );  }
	{ /*Test 1*/string Arg0 = 
	"Move it from *Accounts Payable* to *Receiving*."
	; A0.push_back( Arg0 ); string Arg1 = 
	"Move it from <b>Accounts Payable</b> to <b>Receiving</b>."
	; A1.push_back( Arg1 );  }
	{ /*Test 2*/string Arg0 = 
	"I saw _Chelydra serpentina_ in *Centennial Park*."
	; A0.push_back( Arg0 ); string Arg1 = 
	"I saw <i>Chelydra serpentina</i> in <b>Centennial Park</b>."
	; A1.push_back( Arg1 );  }
	{ /*Test 3*/string Arg0 = 
	" _ _ __  _ yabba dabba _   *  dooooo  * ****"
	; A0.push_back( Arg0 ); string Arg1 = 
	" <i> </i> <i></i>  <i> yabba dabba </i>   <b>  dooooo  </b> <b></b><b></b>"
	; A1.push_back( Arg1 );  }
	{ /*Test 4*/string Arg0 = 
	"_now_I_know_*my*_ABC_next_time_*sing*it_with_me"
	; A0.push_back( Arg0 ); string Arg1 = 
	"<i>now</i>I<i>know</i><b>my</b><i>ABC</i>next<i>time</i><b>sing</b>it<i>with</i>me"
	; A1.push_back( Arg1 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], expand( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	bloggoShortcuts ___test;
	___test.run_test();
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
