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
typedef vector<double> vd;
typedef vector<vd> vvd;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
struct ChessKnight
{
	double probability( int x, int y, int n )
	{
		double result = 0;
		vvd A(8, vd(8, 0));
		A[x - 1][y - 1] = 1.0;
		for( int step = 0; step < n; ++step )
		{
			vvd B(8, vd(8, 0));
			fora2(i, j, A)
				if ( A[i][j] > 0 )
					for( int k = 0; k < 8; ++k )
						if ( i + dx[k] >= 0 && i + dx[k] < 8 && j + dy[k] >= 0 && j + dy[k] < 8 ) 
							B[i + dx[k]][j + dy[k]] += A[i][j] * 0.125;
			A = B;
		}
		fora2(i, j, A)
			result += A[i][j];
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<int> A2; vector<double> A3;
	{ /*Test 0*/int Arg0 = 
	1
	; A0.push_back( Arg0 ); int Arg1 = 
	1
	; A1.push_back( Arg1 ); int Arg2 = 
	2
	; A2.push_back( Arg2 ); double Arg3 = 
	0.1875
	; A3.push_back( Arg3 );  }
	{ /*Test 1*/int Arg0 = 
	4
	; A0.push_back( Arg0 ); int Arg1 = 
	4
	; A1.push_back( Arg1 ); int Arg2 = 
	1
	; A2.push_back( Arg2 ); double Arg3 = 
	1.0
	; A3.push_back( Arg3 );  }
	{ /*Test 2*/int Arg0 = 
	2
	; A0.push_back( Arg0 ); int Arg1 = 
	3
	; A1.push_back( Arg1 ); int Arg2 = 
	10
	; A2.push_back( Arg2 ); double Arg3 = 
	0.0522148497402668
	; A3.push_back( Arg3 );  }
	{ /*Test 3*/int Arg0 = 
	4
	; A0.push_back( Arg0 ); int Arg1 = 
	3
	; A1.push_back( Arg1 ); int Arg2 = 
	50
	; A2.push_back( Arg2 ); double Arg3 = 
	8.356427906809618E-7
	; A3.push_back( Arg3 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], probability( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ChessKnight ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
