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
#ifdef __GNUC__
#else
typedef __int64 lint;
typedef unsigned __int64 ulint;
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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct MakeUnique
{
public:
	bool calc( string original, string s, int a, int b )
	{
		fora(i, original)
		{
			a = s.find( original[i], a );
			if ( a < 0 || a > b ) return false;
		}
		return true;
	}
	string eliminated( string original )
	{
		string result = original;
		sort( all(original) );
		original.erase( unique( all(original) ), original.end() );
		for( int k = original.size() - 1; k < result.size(); k++ )
			for( int i = result.size() - 1 - k; i >= 0; i-- )
				if ( calc( original, result, i, i + k ) )
				{
					string s = result;
					int a = k + 1 - original.size();
					for( int j = i; j <= i + k; j++ )
					{
						s[j] = '.';
						if ( !calc( original, s, i, i + k ) )
							s[j] = result[j];
						else a--;
					}
					if ( !a )
					{
						result = s;
						fora(j, result)
							if ( j < i || j > i + k )
								result[j] = '.';
						return result;
					}
				}
		return "";
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABBBXCXABCX"; string Arg1 = ".......ABCX"; verify_case(0, Arg1, eliminated(Arg0)); }
	void test_case_1() { string Arg0 = "ABBBXCXABCB"; string Arg1 = "A..B.CX...."; verify_case(1, Arg1, eliminated(Arg0)); }
	void test_case_2() { string Arg0 = "ABBBXCABCB"; string Arg1 = ""; verify_case(2, Arg1, eliminated(Arg0)); }
	void test_case_3() { string Arg0 = "AABACBXABX"; string Arg1 = ".AB.C.X..."; verify_case(3, Arg1, eliminated(Arg0)); }
	void test_case_4() { string Arg0 = "CABDEAFDEGSDABCDEADFGSEFBGS"; string Arg1 = "............ABCDE..FGS....."; verify_case(4, Arg1, eliminated(Arg0)); }
	void test_case_5() { string Arg0 = "AAAAAA"; string Arg1 = ".....A"; verify_case(5, Arg1, eliminated(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	MakeUnique ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
