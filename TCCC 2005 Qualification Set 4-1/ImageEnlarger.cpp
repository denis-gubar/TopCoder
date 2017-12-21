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
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
struct ImageEnlarger
{
	vs enlarge( vs image, int factor )
	{
		int n = image.size(), m = image[0].size();
		if ( !n ) return vs();
		vs result( n * factor, string(m * factor, ' ') );
		if ( factor )
		{
			for( int x = 0; x < factor; ++x )
				for( int y = 0; y < factor; ++y )
					fora2(i, j, image)
						result[i * factor + x][j * factor + y] = image[i][j];
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<int> A1; vector<vs> A2;
	{ /*Test 0*/string _Arg0[] = 
	{"abc",
 "def",
 "ghi"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	3
	; A1.push_back( Arg1 ); string _Arg2[] = 
	{ "aaabbbccc",  "aaabbbccc",  "aaabbbccc",  "dddeeefff",  "dddeeefff",  "dddeeefff",  "ggghhhiii",  "ggghhhiii",  "ggghhhiii" }
	; vs Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 );  }
	{ /*Test 1*/string _Arg0[] = 
	{"ab",
 "cd"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	0
	; A1.push_back( Arg1 ); vs Arg2; A2.push_back( Arg2 );  }
	{ /*Test 2*/string _Arg0[] = 
	{"---------",
 "-TTT--CC-",
 "--T--C---",
 "--T--C---",
 "--T---CC-",
 "---------"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	10
	; A1.push_back( Arg1 ); string _Arg2[] = 
	{ "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------" }
	; vs Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], enlarge( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ImageEnlarger ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
