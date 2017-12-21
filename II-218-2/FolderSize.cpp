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
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
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
struct FolderSize
{
	vi calculateWaste( vs files, int folderCount, int clusterSize )
	{
		vi result(folderCount, 0);
		fora(i, files)
		{
			vi z = Split<int>( files[i] );
			result[z[0]] += (clusterSize - z[1] % clusterSize) % clusterSize;
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<int> A1; vector<int> A2; vector<vi> A3;
	{ /*Test 0*/string _Arg0[] = 
	{"0 55", "0 47", "1 86"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	3
	; A1.push_back( Arg1 ); int Arg2 = 
	50
	; A2.push_back( Arg2 ); int _Arg3[] = 
	{ 48,  14,  0 }
	; vi Arg3(_Arg3, _Arg3 + (sizeof(_Arg3) / sizeof(_Arg3[0]))); A3.push_back( Arg3 );  }
	{ /*Test 1*/string _Arg0[] = 
	{"0 123", "2 456", "4 789", "6 012", "8 345"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	10
	; A1.push_back( Arg1 ); int Arg2 = 
	98
	; A2.push_back( Arg2 ); int _Arg3[] = 
	{ 73,  0,  34,  0,  93,  0,  86,  0,  47,  0 }
	; vi Arg3(_Arg3, _Arg3 + (sizeof(_Arg3) / sizeof(_Arg3[0]))); A3.push_back( Arg3 );  }
	{ /*Test 2*/vs Arg0; A0.push_back( Arg0 ); int Arg1 = 
	5
	; A1.push_back( Arg1 ); int Arg2 = 
	100
	; A2.push_back( Arg2 ); int _Arg3[] = 
	{ 0,  0,  0,  0,  0 }
	; vi Arg3(_Arg3, _Arg3 + (sizeof(_Arg3) / sizeof(_Arg3[0]))); A3.push_back( Arg3 );  }
	{ /*Test 3*/string _Arg0[] = 
	{"0 93842", "1 493784", "2 43212", "3 99327", "4 456209",
"5 947243", "6 59348", "7 58237", "8 5834", "9 492384",
"0 58342", "3 538432", "6 1432", "9 453983", "2 4321",
"4 583729", "6 6974", "8 9864", "4 43211", "8 38437"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	10
	; A1.push_back( Arg1 ); int Arg2 = 
	22485
	; A2.push_back( Arg2 ); int _Arg3[] = 
	{ 27696,  886,  19922,  14306,  18616,  19612,  44671,  9218,  35805,  20488 }
	; vi Arg3(_Arg3, _Arg3 + (sizeof(_Arg3) / sizeof(_Arg3[0]))); A3.push_back( Arg3 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], calculateWaste( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	FolderSize ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
