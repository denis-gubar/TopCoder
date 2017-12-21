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
typedef vector<vi> vvi;
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct Quilting
{
	string lastPatch( int length, int width, vs colorList )
	{
		int dx[] = {-1, 0, 1, 0};
		int dy[] = {0, -1, 0, 1};
		int n = colorList.size(), x = length / 2, y = width / 2, d = 0, step = 0;
		vi colors(n, 0); ++colors[0];
		vvi M(length, vi(width, -1)); M[x][y] = 0;
		for( int i = 1; i < width * length; )
		{
			if ( d % 2 == 0 )
				++step;
			for( int j = 0; j < step && i < width * length; ++j )
			{
				++i;
				x += dx[d]; y += dy[d];
				vi neighbors(n, 0);
				for( int a = x - 1; a <= x + 1; ++a )
					if ( a >= 0 && a < length )
						for( int b = y - 1; b <= y + 1; ++b )
							if ( b >= 0 && b < width && M[a][b] >= 0 )
								++neighbors[M[a][b]];
				int k = *min_element( all(neighbors) );
				int c = -1;
				fora(z, neighbors)
					if ( neighbors[z] == k && (c == -1 || colors[c] > colors[z]) )
						c = z;
				M[x][y] = c; ++colors[c];
			}
			d = (d + 1) % 4;
		}
		return colorList[M[x][y]];
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<vs> A2; vector<string> A3;
	{ /*Test 0*/int length = 
	3
	; A0.push_back( length ); int width = 
	2
	; A1.push_back( width ); string _colorList[] = 
	{"RED","BLUE","TAN"}
	; vs colorList(_colorList, _colorList + (sizeof(_colorList) / sizeof(_colorList[0]))); A2.push_back( colorList ); string result = 
	"TAN"
	; A3.push_back( result );  }
	{ /*Test 1*/int length = 
	4
	; A0.push_back( length ); int width = 
	3
	; A1.push_back( width ); string _colorList[] = 
	{"E","D","C","B","A"}
	; vs colorList(_colorList, _colorList + (sizeof(_colorList) / sizeof(_colorList[0]))); A2.push_back( colorList ); string result = 
	"E"
	; A3.push_back( result );  }
	{ /*Test 2*/int length = 
	3
	; A0.push_back( length ); int width = 
	3
	; A1.push_back( width ); string _colorList[] = 
	{"A","B","C","D"}
	; vs colorList(_colorList, _colorList + (sizeof(_colorList) / sizeof(_colorList[0]))); A2.push_back( colorList ); string result = 
	"C"
	; A3.push_back( result );  }
	{ /*Test 3*/int length = 
	1
	; A0.push_back( length ); int width = 
	1
	; A1.push_back( width ); string _colorList[] = 
	{"RED","BLUE","YELLOW"}
	; vs colorList(_colorList, _colorList + (sizeof(_colorList) / sizeof(_colorList[0]))); A2.push_back( colorList ); string result = 
	"RED"
	; A3.push_back( result );  }
	{ /*Test 4*/int length = 
	10
	; A0.push_back( length ); int width = 
	10
	; A1.push_back( width ); string _colorList[] = 
	{"X","Y","Z"}
	; vs colorList(_colorList, _colorList + (sizeof(_colorList) / sizeof(_colorList[0]))); A2.push_back( colorList ); string result = 
	"Z"
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], lastPatch( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Quilting ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
