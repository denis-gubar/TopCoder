#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
#ifdef __GNUC__
typedef long long lint;
typedef unsigned long long ulint;
#else
typedef __int64 lint;
typedef unsigned __int64 ulint;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE 
#endif
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<vector<string> > vvs;
#define fora(i,v) for(unsigned int i = 0; i < (v).size(); i++)
int toInt( string a )
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
	if ( t != "" )
		result.push_back( t );
	return result;
}
vi SplitInt( string s, string c = " " )
{
	vs temp = Split( s, c );
	vi result( temp.size() );
	transform( temp.begin(), temp.end(), result.begin(), toInt );
	return result;
}
struct Scheduling
{ 
public:
	vi times;
	int n;
	vvi M;
	map<int, short> H;
	int calc( int state )
	{
		if ( H.find( state ) != H.end() ) return H[state];
		int tasks = state & ((1 << n) - 1);
		int i = (state >> n) & ((1 << 4) - 1);
		int time = state >> (n + 4);
		if ( !tasks ) return time;
		short result = 125, x;
		fora(j, times)
			if ( ((1 << j) & tasks) && (i == n || !M[j][i] ) )
			{
				bool canExecute = true;
				fora(k, times)
					if ( M[j][k] && ((1 << k) & tasks) )
					{
						canExecute = false;
						break;
					}
				if ( canExecute )
				{
					if ( times[j] > time )
						x = time + calc( (tasks ^ (1 << j)) | (j << n) | ((times[j] - time) << (n + 4)));
					else
						x = times[j] + calc( (tasks ^ (1 << j)) | (i << n) | ((time - times[j]) << (n + 4)));
					result = min(result, x);
				}
			}
		if ( i < n )
		{
			x = time + calc( tasks | (n << n) );
			result = min(result, x);
		}
		H[state] = result;
		return result;
	}
	int fastest( vector <string> dag )
	{
		n = dag.size();
		times = vi(n);
		M = vvi(n, vi(n, 0));
		H.clear();
		fora(i, dag)
		{
			vi x = SplitInt( dag[i], ",:" );
			times[i] = x[0];
			for( int j = 1; j < x.size(); j++ )
				M[i][x[j]] = 1;
		}
		return calc( ((1 << n) - 1) | (n << n) );
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3:","2:","4:","7:0,1,2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(0, Arg1, fastest(Arg0)); }
	void test_case_1() { string Arr0[] = {"9:","8:","6:","4:","7:","7:0,1,2,3,4","3:2,3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(1, Arg1, fastest(Arg0)); }
	void test_case_2() { string Arr0[] = { "10:", "5:", "5:1", "5:1", "5:2,3" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(2, Arg1, fastest(Arg0)); }
	void test_case_3() { string Arr0[] = {"1:","2:","4:","8:","6:","3:","7:","5:","9:","5:","10:","3:"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(3, Arg1, fastest(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Scheduling ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
