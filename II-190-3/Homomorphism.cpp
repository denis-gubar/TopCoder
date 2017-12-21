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
#define all(v) (v).begin(), (v).end()
struct Homomorphism
{
public:
	int count( string u, string v )
	{
		int result = 0;
		vi c(2);
		c[0] = std::count( all(u), '0' );
		c[1] = std::count( all(u), '1' );
		if ( c[0] * c[1] == 0 )
		{
			if ( v.size() % u.size() ) return 0;
			bool flag = true;
			for( int i = 0; i < v.size() / u.size(); i++ )
				for( int j = 0; j < u.size(); j++ )
					flag &= v[v.size() / u.size() * j + i] == v[i];
			return flag ? -1 : 0;
		}
		for( int i = 1; v.size() > i * c[0]; i++ )
		{
			if ( (v.size() - i * c[0]) % c[1] ) continue;
			int j = (v.size() - i * c[0]) / c[1];
			int z = 0;
			vs s(2);
			bool flag = true;
			fora(k, u)
			{
				if ( u[k] == '0' )
				{
					if ( s[0] == "" ) s[0] = v.substr( z, i );
					else flag &= s[0] == v.substr( z, i );
					z += i;
				}
				else
				{
					if ( s[1] == "" ) s[1] = v.substr( z, j );
					else flag &= s[1] == v.substr( z, j );
					z += j;
				}
				if ( !flag ) break;
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
	void test_case_0() { string Arg0 = "10"; string Arg1 = "11001"; int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "00"; string Arg1 = "11111"; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "11"; string Arg1 = "00"; int Arg2 = -1; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "001"; string Arg1 = "1010001"; int Arg2 = 1; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "101"; string Arg1 = "11111111111111111111111111111111111111111111111111"; int Arg2 = 24; verify_case(4, Arg2, count(Arg0, Arg1)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Homomorphism ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
