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
struct Animation
{
	vs animate( int speed, string init )
	{
		vs result;
		int n = init.size();
		while( count_if( all(init), bind2nd( not_equal_to<char>(), '.' ) ) )
		{
			string s(init);
			replace( all(s), 'R', 'X' );
			replace( all(s), 'L', 'X' );
			result.push_back( s );
			s = string(n, '.');
			fora(i, init)
			{
				if ( (init[i] == 'X' || init[i] == 'R') && i + speed < n )
					s[i + speed] = s[i + speed] == '.' ? 'R' : 'X';
				if ( (init[i] == 'X' || init[i] == 'L') && i - speed >= 0 )
					s[i - speed] = s[i - speed] == '.' ? 'L' : 'X';
			}
			s.swap( init );
		}
		result.push_back( init );
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<string> A1; vector<vs> A2;
	{ /*Test 0*/int speed = 
	2
	; A0.push_back( speed ); string init = 
	 "..R...." 
	; A1.push_back( init ); string _result[] = 
	{ "..X....",  "....X..",  "......X",  "......." }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 1*/int speed = 
	3
	; A0.push_back( speed ); string init = 
	"RR..LRL" 
	; A1.push_back( init ); string _result[] = 
	{ "XX..XXX",  ".X.XX..",  "X.....X",  "......." }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 2*/int speed = 
	2
	; A0.push_back( speed ); string init = 
	"LRLR.LRLR"
	; A1.push_back( init ); string _result[] = 
	{ "XXXX.XXXX",  "X..X.X..X",  ".X.X.X.X.",  ".X.....X.",  "........." }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 3*/int speed = 
	10
	; A0.push_back( speed ); string init = 
	"RLRLRLRLRL"
	; A1.push_back( init ); string _result[] = 
	{ "XXXXXXXXXX",  ".........." }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 4*/int speed = 
	1
	; A0.push_back( speed ); string init = 
	"..."
	; A1.push_back( init ); string _result[] = 
	{ "..." }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 5*/int speed = 
	1
	; A0.push_back( speed ); string init = 
	"LRRL.LR.LRR.R.LRRL."
	; A1.push_back( init ); string _result[] = 
	{ "XXXX.XX.XXX.X.XXXX.",  "..XXX..X..XX.X..XX.",  ".X.XX.X.X..XX.XX.XX",  "X.X.XX...X.XXXXX..X",  ".X..XXX...X..XX.X..",  "X..X..XX.X.XX.XX.X.",  "..X....XX..XX..XX.X",  ".X.....XXXX..X..XX.",  "X.....X..XX...X..XX",  ".....X..X.XX...X..X",  "....X..X...XX...X..",  "...X..X.....XX...X.",  "..X..X.......XX...X",  ".X..X.........XX...",  "X..X...........XX..",  "..X.............XX.",  ".X...............XX",  "X.................X",  "..................." }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], animate( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Animation ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
