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
typedef vector<int> vi;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
template<typename T> string ToString( T x )
{
    ostringstream S;
	S << x;
	return S.str();
}
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
struct MedalTable
{
	struct comp: binary_function<string, string, bool>
	{
		bool operator() ( string a, string b ) const
		{
			vi A = Split<int>( a ), B = Split<int>( b );
			if ( A == B ) return Split( a )[0] < Split( b )[0];
			return lexicographical_compare( all(B), all(A) );
		}
	};
	vector <string> generate( vector <string> results )
	{
		vector <string> result;
		set<string> S;
		map<string, int> A, B, C;
		fora(i, results)
		{
			vs z = Split( results[i] );
			if ( S.find( z[0] ) == S.end() )
			{
				S.insert( z[0] ); A[z[0]] = B[z[0]] = C[z[0]] = 0;
			}
			A[z[0]]++;
			if ( S.find( z[1] ) == S.end() )
			{
				S.insert( z[1] ); A[z[1]] = B[z[1]] = C[z[1]] = 0;
			}
			B[z[1]]++;
			if ( S.find( z[2] ) == S.end() )
			{
				S.insert( z[2] ); A[z[2]] = B[z[2]] = C[z[2]] = 0;
			}
			C[z[2]]++;
		}
		for( set<string>::iterator it = S.begin(); it != S.end(); ++it )
			result.push_back( *it + " " + ToString(A[*it]) + " " + ToString(B[*it]) + " " + ToString(C[*it]) );
		sort( all(result), comp() );
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ITA JPN AUS", "KOR TPE UKR", "KOR KOR GBR", "KOR CHN TPE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "KOR 3 1 0",  "ITA 1 0 0",  "TPE 0 1 1",  "CHN 0 1 0",  "JPN 0 1 0",  "AUS 0 0 1",  "GBR 0 0 1",  "UKR 0 0 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, generate(Arg0)); }
	void test_case_1() { string Arr0[] = {"USA AUT ROM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "USA 1 0 0",  "AUT 0 1 0",  "ROM 0 0 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, generate(Arg0)); }
	void test_case_2() { string Arr0[] = {"GER AUT SUI", "AUT SUI GER", "SUI GER AUT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "AUT 1 1 1",  "GER 1 1 1",  "SUI 1 1 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, generate(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	MedalTable ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
