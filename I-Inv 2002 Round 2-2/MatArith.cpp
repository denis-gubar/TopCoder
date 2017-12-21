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

template<typename T> void print( T collection, char* separator = "\n" )
{
	if ( !collection.empty() )
	{
		copy( collection.begin(), collection.end() - 1, ostream_iterator<T::value_type>( cout, separator ) );
		cout << collection.back();
	}
	cout << endl;
}
// END CUT HERE 

typedef long long lint;
typedef unsigned long long ulint;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<lint> vl;
typedef vector<vector<lint> > vvl;
typedef vector<string> vs;
typedef vector<vector<string> > vvs;
typedef vector<double> vd;
typedef vector<vector<double> > vvd;
typedef vector<bool> vb;
typedef vector<vector<bool> > vvb;
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
bool flag = false;
vvi operator+( vvi A, vvi B )
{
	if ( flag ) return vvi();
	flag |= !(A.size() == B.size() && A[0].size() == B[0].size() && A.size() && A[0].size());
	if ( flag ) return vvi();
	vvl temp( A.size(), vl(A[0].size(), 0) );
	vvi result( A.size(), vi(A[0].size(), 0) );
	fora(i, A)
		fora(j, A[0])
		{
			temp[i][j] = A[i][j];
			temp[i][j] += B[i][j];
		}
	fora(i, A)
		fora(j, A[0])
		{			
			result[i][j] = temp[i][j];
			flag |= temp[i][j] != result[i][j];
		}
	return result;
}
vvi operator*( vvi A, vvi B )
{
	if ( flag ) return vvi();
	flag |= !(A[0].size() == B.size() && A.size() && A[0].size() && B[0].size() );
	if ( flag ) return vvi();
	vvl temp( A.size(), vl(B[0].size(), 0) );
	vvi result( A.size(), vi(B[0].size(), 0) );
	fora(i, A)
		fora(j, B)
			fora(k, B[0])
				temp[i][k] += ((lint) A[i][j]) * B[j][k];
	fora(i, result)
		fora(j, result[0])
		{			
			result[i][j] = temp[i][j];
			flag |= temp[i][j] != result[i][j];
		}
	return result;
}
struct MatArith
{
	vector <string> calculate( vector <string> a, vector <string> b, vector <string> c, string equation )
	{
		vvi A, B, C;
		fora(i, a)
			A.push_back( Split<int>( a[i] ) );
		fora(i, b)
			B.push_back( Split<int>( b[i] ) );
		fora(i, c)
			C.push_back( Split<int>( c[i] ) );
		flag = false;
		vs s = Split( equation, "+" );
		vector<vvi> M( s.size() );
		fora(i, s)
		{
		   vs m = Split( s[i], "*" );
		   if ( m[0][0] == 'A' )
			   M[i] = A;
		   if ( m[0][0] == 'B' )
			   M[i] = B;
		   if ( m[0][0] == 'C' )
			   M[i] = C;
		   for( int j = 1; j < m.size(); j++ )
		   {
				if ( m[j][0] == 'A' )
					M[i] = M[i] * A;
				if ( m[j][0] == 'B' )
					M[i] = M[i] * B;
				if ( m[j][0] == 'C' )
					M[i] = M[i] * C;
		   }
		}
		vvi res = M[0];
		for( int i = 1; i < M.size(); i++ )
			res = res + M[i];
		if ( flag ) return vs();
		vector <string> result( res.size() );
		fora(i, res)
			fora(j, res[0])
				if ( result[i] == "" ) result[i] = ToString( res[i][j] );
				else result[i] += " " + ToString( res[i][j] );
		return result;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1 2 3","2 3 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 2","3 4","5 6"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "A*B"; string Arr4[] = { "22 28",  "31 40" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"1 2 3","2 3 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 2","3 4","5 6"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "A+B+C"; vector <string> Arg4; verify_case(1, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"3 5 7","5 4 3","-2 3 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 1 1","2 5 2","3 5 -3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "A+C"; string Arr4[] = { "4 6 8",  "7 9 5",  "1 8 -1" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"10 0","0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "A*A*A*A*A*A*A*A*A"; string Arr4[] = { "1000000000 0",  "0 0" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"10 0","0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "A*A*A*A*A*A*A*A*A*A"; vector <string> Arg4; verify_case(4, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	MatArith ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
