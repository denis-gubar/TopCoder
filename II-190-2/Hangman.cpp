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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct Hangman
{
public:
	string guessWord( string feedback, vector <string> words )
	{
		string result;
		fora(i, words)
		{
			if ( feedback.size() != words[i].size() ) continue;
			bool flag = true;
			fora(j, feedback)
			{
				if ( feedback[j] == '-' ) continue;
				flag &= feedback[j] == words[i][j];
                flag &= count( all(feedback), feedback[j] ) == count( all(words[i]), feedback[j] );
			}
			if ( flag )
			{
				if ( result == "" ) result = words[i];
				else return "";
			}
		}
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "N-N-A"; string Arr1[] = {"NINJA", "NINJAS", "FLIPS", "OUT", "FRISBEE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NINJA"; verify_case(0, Arg2, guessWord(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "B--B--"; string Arr1[] = {"BRINGS", "BARBED", "BUBBLE"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "BARBED"; verify_case(1, Arg2, guessWord(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "---------"; string Arr1[] = {"MONKEY", "FORCE", "IS", "GAINING", "STRENGTH"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(2, Arg2, guessWord(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "-AAA--"; string Arr1[] = {"CAAABB", "BAAACC"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(3, Arg2, guessWord(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "---H-O-H-B-OPHOB--"; string Arr1[] = {"ROSACEA", "GYROVAGUE", "SHACONIAN", "ALTITONANT",
 "BRACHIATION", "CERCOPITHECAN", "SCOLECOPHAGOUS",
 "RESISTENTIALISM", "SLUBBERDEGULLION", 
 "AICHMORHABDOPHOBIA", "SPECTOCLOACAPHOBIA",
 "ULTRACREPIDARIANISM", "HIPPOPOTOMONSTROSESQUIPEDALIAN",
 "CHARGOGGAGOGGMANCHAUGGAGOGGCHAUBUNAGUNGAMAUGG"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "AICHMORHABDOPHOBIA"; verify_case(4, Arg2, guessWord(Arg0, Arg1)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Hangman ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
