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
typedef vector<int> vi;
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
vi SplitInt( string s, string c = " " )
{
	vs temp = Split( s, c );
	vi result( temp.size() );
	transform( temp.begin(), temp.end(), result.begin(), ToInt );
	return result;
}
struct VolumeGuess
{
public:
	int correctVolume( vector <string> queries, int numberOfBoxes, int ithBox )
	{
		int result = 0;
		fora(i, queries)
		{
			vi s = SplitInt( queries[i], "," );
			if ( s[0] == ithBox || s[1] == ithBox )
				result = max(result, s[2]);
		}
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1,2,10","1,3,10","2,3,20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; int Arg3 = 10; verify_case(0, Arg3, correctVolume(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"1,02,10","2,3,010","1,3,20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 10; verify_case(1, Arg3, correctVolume(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1,2,31","1,3,9","1,4,31","2,4,32","3,4,9","3,2,9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 1; int Arg3 = 31; verify_case(2, Arg3, correctVolume(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"1,2,31","1,3,9","1,4,31","2,4,32","3,4,9","3,2,9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; int Arg3 = 9; verify_case(3, Arg3, correctVolume(Arg0, Arg1, Arg2)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	VolumeGuess ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
