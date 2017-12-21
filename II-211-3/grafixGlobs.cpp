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
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
#define ToVector(x, _x) copy( _x, _x + sizeof(_x)/sizeof(_x[0]), inserter( x, x.begin() ) );
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
string replace_all( string s, string oldValue, string newValue )
{
	string result;
	int j = 0;
	for( int i = s.find( oldValue ); i > -1; i = s.find( oldValue, i + oldValue.size() ) )
	{
		result += s.substr( j, i - j ) + newValue;
		j = i + oldValue.size();
	}
	result.append( s.substr( j ) );
	return result;
}
struct grafixGlobs
{
	void make( vvi& M, int i )
	{
		int k;
		for( k = 0; accumulate( all(M[k]), 0 ); k++ );
		M[k][i]++;
	}
	void del( vvi& M, int i )
	{
		M[i].assign(3, 0);
	}
	void merge( vvi& M, int i, int j )
	{
		fora(k, M[i])
			M[i][k] += M[j][k];
		del( M, j );
	}
	void split( vvi& M, int i )
	{
		vi z = M[i]; del( M, i );
		fora(k, z)
			for( int j = 0; j < z[k]; j++ )
				make( M, k );
	}
	vector <int> execute( vector <string> commands, int sel )
	{
		vvi M(1000, vi(3, 0));
		string _c[] = {"arc", "circle", "polygon"}; vs c; ToVector(c, _c);
		string _s[] = {"make", "merge", "delete", "split"}; vs s; ToVector(s, _s);
		fora(i, commands)
		{
			string a = commands[i];
			fora(j, c)
				a = replace_all( a, c[j], ToString( j ) );
			fora(j, s)
				a = replace_all( a, s[j], ToString( j ) );
			vi z = Split<int>( a );
			switch( z[0] )
			{
				case 0: make( M, z[1] ); break;
				case 1: merge( M, z[1], z[2] ); break;
				case 2: del( M, z[1] ); break;
				case 3: split( M, z[1] ); break;
			}
		}
		if ( accumulate( all(M[sel]), 0 ) ) return M[sel];
		return vi();
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"make polygon", "make circle", "make polygon", "merge 0 1", "merge 2 0", "split 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arr2[] = { 0,  1,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, execute(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"make circle", "make circle", "make arc", "merge 2 1", "delete 0",
 "split 2", "delete 0", "make polygon"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arr2[] = { 0,  0,  1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, execute(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"make circle", "make circle", "make arc", "merge 2 1", "delete 0",
 "split 2", "delete 0", "make polygon"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; vector <int> Arg2; verify_case(2, Arg2, execute(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"make arc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999; vector <int> Arg2; verify_case(3, Arg2, execute(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"make polygon", "make polygon", "make arc", "make circle",
 "make circle", "delete 3", "make polygon", "make arc",
 "make arc", "merge 1 3", "merge 1 4", "merge 2 1", "make arc",
 "make arc", "make circle", "make circle", "merge 6 5",
 "split 6", "merge 2 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = { 2,  1,  2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, execute(Arg0, Arg1)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	grafixGlobs ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
