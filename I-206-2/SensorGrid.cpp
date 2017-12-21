#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE 
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define forad(i,v) for(int i = (v).size() - 1; i >= 0; i--)
#define all(v) (v).begin(), (v).end()
struct SensorGrid
{
public:
	vector <int> largestRectangle( int width, int height, vector <int> x, vector <int> y )
	{
		vector <int> result(4);
		vi X, Y;
		Y.push_back( -1 );
		Y.push_back( 0 );
		Y.push_back( height - 1 );
		Y.push_back( height );
		X.push_back( -1 );
		X.push_back( 0 );
		X.push_back( width - 1 );
		X.push_back( width );
		fora(i, x)
		{
			X.push_back( x[i] - 1 );
			X.push_back( x[i] );
			X.push_back( x[i] + 1 );
			Y.push_back( y[i] - 1 );
			Y.push_back( y[i] );
			Y.push_back( y[i] + 1 );
		}
		sort( all(X) );
		sort( all(Y) );
		X.erase( unique(all(X)), X.end() );
		Y.erase( unique(all(Y)), Y.end() );
		map<int, int> Mx, My;
		vvi A(Y.size(), vi(X.size(), 0)), M(A);
		fora(i, X)
			Mx[X[i]] = i;
		fora(i, Y)
			My[Y[i]] = i;
		fora(i, x)
			A[My[y[i]]][Mx[x[i]]] = 1;
		fora(i, A)
			A[i][0] = A[i][A[0].size() - 1] = 1;
		fora(i, A[0])
			A[0][i] = A[A.size() - 1][i] = 1;
		int best = 0;
		fora(i, A)
		{
			int last = 0;
			forad(j, A[0])
			{
				if ( A[i][j] ) last = j;
				M[i][j] = last;
			}
		}
		for( int i = 1; i < A.size() - 1; i++ )
			for( int j = 1; j < A[0].size() - 1; j++ )
				if ( !A[i][j] )
				{
					int h = i, w = M[h][j], current = 0, cx = 0, cy = 0;
					while( w > j )
					{
						if ( (X[w] - X[j]) * (Y[h + 1] - Y[i]) > current )
						{
							cx = X[w] - X[j];
							cy = Y[h + 1] - Y[i];
							current = cx * cy;
						}
						h++;
						w = min(w, M[h][j]);
					}
					if ( best < current )
					{
						best = current;
						result[0] = X[j];
						result[1] = Y[i];
						result[2] = cx;
						result[3] = cy;
					}					
				}
		return result;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 7; int Arr2[] = { 1, 5, 1, 5, 3, 7, 3, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 0, 0, 2, 2, 4, 4, 6, 6 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 2,  0,  3,  4 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, largestRectangle(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 5; int Arr2[] = { 5, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 2, 4 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 0,  0,  5,  4 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, largestRectangle(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 17; int Arg1 = 16; int Arr2[] = { 1, 3, 5, 7, 11, 13, 15,
  1, 3, 5, 7, 11, 13, 15,
  1, 3, 5, 7, 11, 13, 15,
  1, 3, 5, 7, 11, 13, 15,
  1, 3, 5, 7, 11, 13, 15,
  1, 3, 5, 7, 11, 13, 15,
  1, 3, 5, 7, 11, 13, 15 }
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 1, 1, 1, 1, 1, 1, 1,
  3, 3, 3, 3, 3, 3, 3,
  5, 5, 5, 5, 5, 5, 5,
  7, 7, 7, 7, 7, 7, 7,
  10, 10, 10, 10, 10, 10, 10,
  12, 12, 12, 12, 12, 12, 12,
  14, 14, 14, 14, 14, 14, 14 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 8,  0,  3,  16 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, largestRectangle(Arg0, Arg1, Arg2, Arg3)); }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	SensorGrid ___test;
	___test.run_test(-1);
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
