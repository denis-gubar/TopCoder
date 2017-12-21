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
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE 
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
template <typename T> vector<T> Split( string s, string delimeters = " " )
{
	vector<T> result; s += delimeters[0];
	for( int i = 0, prev = 0; i < s.size(); i++ )
		if ( delimeters.find( s[i] ) != -1 )
		{
			if ( prev < i )
			{
				istringstream S( s.substr( prev, i - prev ) );
				T current; S >> current;
				result.push_back( current );
			}
			prev = i + 1;
		}
	return result;
}
vs Split( string s, string delimeters = " ", bool skipEmpty = true )
{
	vs result; s += delimeters[0];
	for( int i = 0, prev = 0; i < s.size(); i++ )
		if ( delimeters.find( s[i] ) != -1 )
		{
			if ( !skipEmpty || prev < i )
				result.push_back( s.substr( prev, i - prev ) );
			prev = i + 1;
		}
	return result;
}
struct SpamDetector
{
	int countKeywords( string subjectLine, vector <string> keywords )
	{
		int result = 0;
		transform( all(subjectLine), subjectLine.begin(), ::tolower );
		vs s = Split( subjectLine );
		fora(i, keywords)
			transform( all(keywords[i]), keywords[i].begin(), ::tolower );
		fora(k, s)
		{
			bool flag = false;
			fora(l, keywords)
			{
				string t = " " + s[k], w = keywords[l];
				int i = 1, j = 0;
				while( i < t.size() && j < w.size() )
				{
					if ( t[i] == w[j] )
					{
						i++; j++; continue;
					}
					if ( t[i] == t[i - 1] )
					{
						i++; continue;
					}
					break;
				}
				while( i < t.size() && t[i] == t[i - 1] ) i++;
				if ( i == t.size() && j == w.size() )
				{
					flag = true; break;
				}
			}
			if ( flag ) result++;
		}		
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LoooW INTEREST RATES available dont BE slow"; string Arr1[] = {"interest","rates","loan","available","LOW"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, countKeywords(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "Dear Richard Get Rich Quick            no risk"; string Arr1[] = {"rich","risk","Quicken","wealth","SAVE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, countKeywords(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "in debbtt againn and aAgain and AGAaiIN"; string Arr1[] = {"AGAIN","again","Again","again"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, countKeywords(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "PlAyy ThEE Lottto     get Loottoo feever"; string Arr1[] = {"play","lotto","lottery","looser"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, countKeywords(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "                                   "; string Arr1[] = {"empty","space","does","not","match"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, countKeywords(Arg0, Arg1)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	SpamDetector ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
