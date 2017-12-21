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
struct Cubism
{
	int probe( vs& lattice, int x, int y, int z, string color )
	{
		return x >= 0 && y >= 0 && z >= 0 && x < 4 && y < 4 && z < 4 && (lattice[z][x * 4 + y] == 'B' ^ color == "white" );
	}
	int lines( vs lattice, string color )
	{
		int result = 0;
		for( int x = 0; x < 4; ++x )
			for( int y = 0; y < 4; ++y )
				for( int z = 0; z < 4; ++z )
					for( int dx = -1; dx <= 1; ++dx )
						for( int dy = -1; dy <= 1; ++dy )
							for( int dz = -1; dz <= 1; ++dz )
								if ( dx || dy || dz )
								{
									int count = 0;
									for( int k = 0; k < 4; ++k )
										count += probe( lattice, x + dx * k, y + dy * k, z + dz * k, color );
									result += count == 4;
								}
		return result / 2;
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<string> A1; vector<int> A2;
	{ /*Test 0*/string _lattice[] = 
	{"BBBBBWWWBWWWBWWW",
 "BWWWWWWWWWWWWWWW",
 "BWWWWWWWWWWWWWWW",
 "BWWWWWWWWWWWWWWW"}
	; vs lattice(_lattice, _lattice + (sizeof(_lattice) / sizeof(_lattice[0]))); A0.push_back( lattice ); string color = 
	"black"
	; A1.push_back( color ); int result = 
	3
	; A2.push_back( result );  }
	{ /*Test 1*/string _lattice[] = 
	{"BWWWWWWWWWWWWWWW",
 "WWWWWBWWWWWWWWWW",
 "WWWWWWWWWWBWWWWW",
 "WWWWWWWWWWWWWWWB"}
	; vs lattice(_lattice, _lattice + (sizeof(_lattice) / sizeof(_lattice[0]))); A0.push_back( lattice ); string color = 
	"black"
	; A1.push_back( color ); int result = 
	1
	; A2.push_back( result );  }
	{ /*Test 2*/string _lattice[] = 
	{"WWWWWWWWWWWWWWWW",
 "WWWWWWWWWWWWWWWW",
 "WWWWWWWWWWWWWWWW",
 "WWWWWWWWWWWWWWWW"}
	; vs lattice(_lattice, _lattice + (sizeof(_lattice) / sizeof(_lattice[0]))); A0.push_back( lattice ); string color = 
	"black"
	; A1.push_back( color ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 3*/string _lattice[] = 
	{"WWWWWWWWWWWWWWWW",
 "WWWWWWWWWWWWWWWW",
 "WWWWWWWWWWWWWWWW",
 "WWWWWWWWWWWWWWWW"}
	; vs lattice(_lattice, _lattice + (sizeof(_lattice) / sizeof(_lattice[0]))); A0.push_back( lattice ); string color = 
	"white"
	; A1.push_back( color ); int result = 
	76
	; A2.push_back( result );  }
	{ /*Test 4*/string _lattice[] = 
	{"WWWWWWWWWBWWWWWW",
 "WWWBWWWWWWWWWWWW",
 "WWWWWWWWWWWWBWWW",
 "WWWBWWWWWWWWWWWW"}
	; vs lattice(_lattice, _lattice + (sizeof(_lattice) / sizeof(_lattice[0]))); A0.push_back( lattice ); string color = 
	"white"
	; A1.push_back( color ); int result = 
	58
	; A2.push_back( result );  }
	{ /*Test 5*/string _lattice[] = 
	{"BWBWBWBWBWBWBWBW","BWBWBWBWBWBWBWBW",
 "BWBWBWBWBWBWBWBW","BWBWBWBWBWBWBWBW"}
	; vs lattice(_lattice, _lattice + (sizeof(_lattice) / sizeof(_lattice[0]))); A0.push_back( lattice ); string color = 
	"white"
	; A1.push_back( color ); int result = 
	20
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], lines( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Cubism ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
