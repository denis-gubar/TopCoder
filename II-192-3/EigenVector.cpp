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
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
int ToInt( string a )
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
	result.push_back( t );
	return result;
}
vi SplitInt( string s, string c = " " )
{
	vs temp = Split( s, c );
	vi result( temp.size() );
	transform( temp.begin(), temp.end(), result.begin(), ToInt );
	return result;
}
vi operator * ( vvi M, vi X )
{
	vi result(X.size(), 0);
	fora(i, X)
		fora(j, X)
			result[i] += M[i][j] * X[j];
	return result;
}
struct EigenVector
{
public:
	int bestNorm;
	vi best;
	vvi M;
	void calc( vi& A, int i, int norm )
	{
		if ( norm >= bestNorm ) return;
		if ( i == A.size() )
		{
			if ( !norm ) return;
			vi B = M * A;
			int normB = 0;
			fora(j, B)
				normB += abs(B[j]);
			if ( !normB ) return;
			fora(j, B)
				for( int k = j + 1; k < B.size(); k++ )
					if ( A[j] * B[k] != A[k] * B[j] ) return;
			bestNorm = norm;
			best = A;
			return;
		}
		for( int j = -9 + norm; j <= 9 - norm; j++ )
		{
			A[i] = j;
			bool flag = true;
			for( int k = 0; k <= i; k++ )
				if ( A[k] > 0 ) break;
				else if ( A[k] < 0 ) flag = false;
			if ( flag ) calc( A, i + 1, norm + abs(j) );
		}
	}
	vector <int> findEigenVector( vector <string> A )
	{
		M = vvi(A.size(), vi(A.size()));
		vi temp( A.size(), 0 );
		bestNorm = 10;
		fora(i, A)
			M[i] = SplitInt( A[i] );
		calc( temp, 0, 0 );
		return best;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1 0 0 0 0",
 "0 1 0 0 0",
 "0 0 1 0 0",
 "0 0 0 1 0",
 "0 0 0 0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  0,  0,  0,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findEigenVector(Arg0)); }
	void test_case_1() { string Arr0[] = {"100 0 0 0",
 "0 200 0 0",
 "0 0 333 0",
 "0 0 0 42"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  0,  0,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findEigenVector(Arg0)); }
	void test_case_2() { string Arr0[] = {"10 -10 -10 10",
 "20 40 -10 -10",
 "10 -10 10 20",
 "10 10 20 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  -5,  2,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findEigenVector(Arg0)); }
	void test_case_3() { string Arr0[] = {"30 20","87 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findEigenVector(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	EigenVector ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
