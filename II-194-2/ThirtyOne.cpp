#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#ifdef __GNUC__
#else
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
template<typename T>
void print( T collection, char* separator = "\n" )
{
	copy( collection.begin(), collection.end(), ostream_iterator<T::value_type>( cout, separator ) );
	cout << endl;
}
// END CUT HERE 
#endif
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
int ToInt( string a )
{
	int result;
	istringstream S( a );
	S >> result;
	return result;
}
vs Split( string s, string c = " " )
{
	vs result;
	string t = "";
	fora(i, s)
		if ( c.find( s[i] ) != -1 )
		{
			result.push_back( t );
			t = "";
		}
		else
			t += s[i];
	result.push_back( t );
	return result;
}
struct ThirtyOne
{
	int calc( string x )
	{
		if ( x == "J" || x == "K" || x == "Q" ) return 20;
		if ( x == "A" ) return 2;
		return ToInt( x ) * 2;
	}
	int findWinner( vector <string> hands )
	{
		int result = 0, best = 0;
		fora(i, hands)
		{
			int current = 0;
			vs s = Split( hands[i] );
			if ( s[0] == s[1] && s[0] == s[2] ) current = 61;
			else
			{
				current = calc( s[0] ) + calc( s[1] ) + calc( s[2] );
				int count = 0;
				fora(j, s)
					if ( s[j] == "A" ) count++;
				for( int j = 0; j < count; j++ )
					if ( current + 20 < 63 )
						current += 20;
			}
			if ( best < current )
			{
				result = i;
				best = current;
			}
		}
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"10 A A", "K 2 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, findWinner(Arg0)); }
	void test_case_1() { string Arr0[] = {"2 3 4", "10 6 8", "A K 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, findWinner(Arg0)); }
	void test_case_2() { string Arr0[] = {"J 5 2","2 7 5","10 J 2","J 6 2","J Q K"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, findWinner(Arg0)); }
	void test_case_3() { string Arr0[] = {"Q K K", "10 J Q", "A 8 A", "2 2 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, findWinner(Arg0)); }
	void test_case_4() { string Arr0[] = {"Q 6 6","7 8 3","3 7 2","K Q 6","Q 6 3","5 3 8","10 J Q","4 8 4","Q 2 5","8 A 8",
"9 10 10","2 K 5","10 4 5","Q 4 Q","3 J 2","7 4 4","3 9 7","A 4 4","Q 7 7","10 9 A",
"J 3 5","5 8 9","Q Q 7"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(4, Arg1, findWinner(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ThirtyOne ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
