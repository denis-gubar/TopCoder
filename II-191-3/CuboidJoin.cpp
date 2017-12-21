#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
typedef long long lint;
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
struct Cuboid
{
	int x1, x2, y1, y2, z1, z2, label, sign;
	Cuboid( int x1, int y1, int z1, int x2, int y2, int z2, int label, int sign ):
		x1(x1), y1(y1), z1(z1), x2(x2), y2(y2), z2(z2), label(label), sign(sign) {}
	lint volume()
	{
		return (lint) sign * max(x2 - x1, 0) * max(y2 - y1, 0) * max(z2 - z1, 0);
	}
};
struct CuboidJoin
{
public:
	long long totalVolume( vector <int> cuboids )
	{
		long long result = 0;
		vector<Cuboid> M;
		queue<Cuboid> q;
		int n = cuboids.size() / 6;
		for( int i = 0; i < n; i++ )
		{
			M.push_back( Cuboid( cuboids[i * 6], cuboids[i * 6 + 1], cuboids[i * 6 + 2], cuboids[i * 6 + 3],
				cuboids[i * 6 + 4], cuboids[i * 6 + 5], i, 1 ) );
			q.push( M[i] );
		}
		while( !q.empty() )
		{
			Cuboid C = q.front(); q.pop();
			lint v = C.volume();
			if ( !v ) continue;
			result += v;
			for( int i = C.label + 1; i < n; i++ )
				q.push( Cuboid( max(C.x1, M[i].x1), max(C.y1, M[i].y1), max(C.z1, M[i].z1),
					min(C.x2, M[i].x2), min(C.y2, M[i].y2), min(C.z2, M[i].z2), i, -C.sign ) );
		}
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	//void test_case_0() { int Arr0[] = {0,0,0,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(0, Arg1, totalVolume(Arg0)); }
	void test_case_0() { int Arr0[] = {0,0,0,1,1,1,0,0,0,2,2,2,0,0,0,3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 27LL; verify_case(0, Arg1, totalVolume(Arg0)); }
	void test_case_1() { int Arr0[] = {0,0,0,1,1,1,1,1,1,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(1, Arg1, totalVolume(Arg0)); }
	void test_case_2() { int Arr0[] = {0,0,0,4,4,4,0,0,0,1,1,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 64LL; verify_case(2, Arg1, totalVolume(Arg0)); }
	void test_case_3() { int Arr0[] = {-5000,-5000,-5000,5000,5000,5000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1000000000000LL; verify_case(3, Arg1, totalVolume(Arg0)); }
	void test_case_4() { int Arr0[] = {0,0,0,1,2,3,5,5,5,6,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(4, Arg1, totalVolume(Arg0)); }
	void test_case_5() { vector <int> Arg0; long long Arg1 = 0LL; verify_case(5, Arg1, totalVolume(Arg0)); }
	void test_case_6() { int Arr0[] = {0,0,0,1,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(6, Arg1, totalVolume(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	CuboidJoin ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
