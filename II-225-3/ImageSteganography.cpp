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
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct ImageSteganography
{
	void decode( int x, int& a, int& b, int& c )
	{
		int z = 63;
		if ( x == ' ' ) z = 0;
		else if ( x >= 'A' && x <= 'Z' ) z = 1 + x - 'A';
		else if ( x >= 'a' && x <= 'z' ) z = 27 + x - 'a';
		else if ( x >= '0' && x <= '9' ) z = 53 + x - '0';
		a = z & 3;
		b = (z >> 2) & 3;
		c = (z >> 4) & 3;
	}
	int decode( int a, int b, int c )
	{
		return ((a - '0') * 100 + (b - '0') * 10 + c - '0') / 4 * 4;
	}
	void encode( int x, char& a, char& b, char& c )
	{
		a = char(x / 100 + '0');
		b = char(x / 10 % 10 + '0');
		c = char(x % 10 + '0');
	}
	vs encode( vs image, string message )
	{
		vs result;
		string s = accumulate( all(image), string() ) + "000000000";
		message += string( s.size() / 9 - message.size(), '!' );
		fora(i, message)
		{
			int a, b, c; decode( message[i], a, b, c );
			int A, B, C;
			A = decode( s[9 * i + 0], s[9 * i + 1], s[9 * i + 2] );
			B = decode( s[9 * i + 3], s[9 * i + 4], s[9 * i + 5] );
			C = decode( s[9 * i + 6], s[9 * i + 7], s[9 * i + 8] );
			A += a; B += b; C += c;
			encode( A, s[9 * i + 0], s[9 * i + 1], s[9 * i + 2] );
			encode( B, s[9 * i + 3], s[9 * i + 4], s[9 * i + 5] );
			encode( C, s[9 * i + 6], s[9 * i + 7], s[9 * i + 8] );
		}
		int j = 0;
		fora(i, image)
		{
			result.push_back( s.substr( j, image[i].size() ) );
			j += image[i].size();
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<string> A1; vector<vs> A2;
	{ /*Test 0*/string _Arg0[] = 
	{"255123212001201222"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string Arg1 = 
	"hi"
	; A1.push_back( Arg1 ); string _Arg2[] = 
	{ "254120214003200222" }
	; vs Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 );  }
	{ /*Test 1*/string _Arg0[] = 
	{"255123212","001201222"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string Arg1 = 
	"hi"
	; A1.push_back( Arg1 ); string _Arg2[] = 
	{ "254120214",  "003200222" }
	; vs Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 );  }
	{ /*Test 2*/string _Arg0[] = 
	{"123234213001023213123145",
 "222111121101213198009",
 "121122123124125",
 "132212093039",
 "213110"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string Arg1 = 
	 "Hello 1"
	; A1.push_back( Arg1 ); string _Arg2[] = 
	{ "120234212003023213122145",  "222110121102213198010",  "120120120126125",  "135215095039",  "215111" }
	; vs Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], encode( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ImageSteganography ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
