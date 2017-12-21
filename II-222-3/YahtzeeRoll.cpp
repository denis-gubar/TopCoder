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
typedef long long lint;
typedef vector<int> vi;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct YahtzeeRoll
{
	int calc( vi x )
	{
		sort( all(x) );
		vi a(7, 0), f(7, 0);
		fora(i, x)
		{
			++a[x[i]]; f[x[i]] = 1;
		}
		sort( all(a), greater<int>() );
		if ( a[0] == 5 ) return 50;
		if ( a[0] == 3 && a[1] == 2 ) return 25;
		for( int i = 1; i < 3; ++i )
			if ( accumulate( f.begin() + i, f.begin() + i + 5, 0 ) == 5 ) return 40;
		for( int i = 1; i < 4; ++i )
			if ( accumulate( f.begin() + i, f.begin() + i + 4, 0 ) == 4 ) return 30;
		return 0;
	}
	double bestChoice( vi dice )
	{
		double result = calc( dice );
		vi x; int sum;
		fora(i0, dice)
			fora(i1, dice)
				fora(i2, dice)
					fora(i3, dice)
		{
			x = dice; sum = 0;
			for( int j0 = 1; j0 <= 6; ++j0 )
			{
				x[i0] = j0;
				for( int j1 = 1; j1 <= 6; ++j1 )
				{
					x[i1] = j1;
					for( int j2 = 1; j2 <= 6; ++j2 )
					{
						x[i2] = j2;
						for( int j3 = 1; j3 <= 6; ++j3 )
						{
							x[i3] = j3;
							sum += calc( x );
						}
					}
				}
			}
			if ( result < sum / 1296.0 ) result = sum / 1296.0;
		}
		sum = 0;
		for( int j0 = 1; j0 <= 6; ++j0 )
		{
			x[0] = j0;
			for( int j1 = 1; j1 <= 6; ++j1 )
			{
				x[1] = j1;
				for( int j2 = 1; j2 <= 6; ++j2 )
				{
					x[2] = j2;
					for( int j3 = 1; j3 <= 6; ++j3 )
					{
						x[3] = j3;
						for( int j4 = 1; j4 <= 6; ++j4 )
						{
							x[4] = j4;
							sum += calc( x );
						}
					}
				}
			}
			if ( result < sum / 7776.0 ) result = sum / 7776.0;
		}
		return result;
	}
// BEGIN CUT HERE
	private:
	template <typename T> string print_array( const vector<T>& v ) { ostringstream os; os << "{ "; for( typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it ) os << '\"' << *it << "\","; os << " }"; return os.str(); }
	template<typename T> void verify_case( int Case, const vector<T>& expected, const vector<T>& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: " << print_array( expected ) << endl; cerr << "\tReceived: " << print_array( received ) << endl; } }
	void verify_case( int Case, const lint& expected, const lint& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const double& expected, const double& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const int& expected, const int& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const string& expected, const string& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	public:
	void run_test( int Case = -1 ) { vector<vi> A0; vector<double> A1;
	{ /*Test 0*/int _Arg0[] = 
	{ 1, 1, 1, 1, 2 }
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); double Arg1 = 
	8.333333333333334
	; A1.push_back( Arg1 );  }
	{ /*Test 1*/int _Arg0[] = 
	{ 1, 1, 1, 2, 2 }
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); double Arg1 = 
	25.0
	; A1.push_back( Arg1 );  }
	{ /*Test 2*/int _Arg0[] = 
	{ 2, 3, 4, 5, 5 }
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); double Arg1 = 
	33.333333333333336
	; A1.push_back( Arg1 );  }
	{ /*Test 3*/int _Arg0[] = 
	{ 2, 2, 3, 4, 4 }
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); double Arg1 = 
	17.77777777777778
	; A1.push_back( Arg1 );  }
	{ /*Test 4*/int _Arg0[] = 
	{ 6, 1, 3, 5, 5 }
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); double Arg1 = 
	9.722222222222221
	; A1.push_back( Arg1 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], bestChoice( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	YahtzeeRoll ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
