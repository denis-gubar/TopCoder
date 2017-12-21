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
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
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
				if ( S.rdstate() ^ ios::failbit )
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
struct RepeatedSubstrings
{
	string decompress( string compressed )
	{
		string result; vector<pair<int, int> > A; vi I;
		int i = 0;
		while( true )
		{
			if ( compressed[i] >= 'A' && compressed[i] <= 'Z' || compressed[i] == ' ' )
				result += compressed[i++];
			else
			{
				int j = i + 1;
				while( j < compressed.size() && 
					!(compressed[j] >= 'A' && compressed[j] <= 'Z' || compressed[j] == ' ' || compressed[j] == '&' ) )
					j++;
				vi z = Split<int>( compressed.substr( i, j - i ), "&-" );
				i = j;
				A.push_back( make_pair( z[0], z[1] ) ); I.push_back( result.size() );
				result += string(z[1] - z[0] + 1, '?');
			}
			if ( i >= compressed.size() ) break;
		}
		bool flag = true;
		while( flag )
		{
			flag = false;
			fora(i, A)
				for( int j = A[i].first; j <= A[i].second; j++ )
					if ( I[i] + j - A[i].first < result.size() && result[I[i] + j - A[i].first] == '?' && result[j] != '?' )
					{
						result[I[i] + j - A[i].first] = result[j];
						flag = true;
					}
		}
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCDEFG &0-6"; string Arg1 = "ABCDEFG ABCDEFG"; verify_case(0, Arg1, decompress(Arg0)); }
	void test_case_1() { string Arg0 = "AB&7-9&2-6"; string Arg1 = "AB????????"; verify_case(1, Arg1, decompress(Arg0)); }
	void test_case_2() { string Arg0 = "IT WAS THE BE&39-49 &0-10WORST OF TIMES"; string Arg1 = "IT WAS THE BEST OF TIMES IT WAS THE WORST OF TIMES"; verify_case(2, Arg1, decompress(Arg0)); }
	void test_case_3() { string Arg0 = "ABC&0-21"; string Arg1 = "ABCABCABCABCABCABCABCABCA"; verify_case(3, Arg1, decompress(Arg0)); }
	void test_case_4() { string Arg0 = "&0-10"; string Arg1 = "???????????"; verify_case(4, Arg1, decompress(Arg0)); }
	void test_case_5() { string Arg0 = "&5-9ABC&2-7DE&20-22&17-19F"; string Arg1 = "ABCCCABCCCCABCDEF?F?F?F"; verify_case(5, Arg1, decompress(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	RepeatedSubstrings ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
