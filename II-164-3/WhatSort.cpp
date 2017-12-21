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
typedef vector<string> vs;
struct WhatSort
{
	string sortType( vs name, vi age, vi wt )
	{
		bool nwa = true;
		bool naw = true;
		bool wan = true;
		bool wna = true;
		bool awn = true;
		bool anw = true;
		for( int i = 1; i < name.size(); i++ )
		{
			bool n0 = name[i - 1] == name[i];
			bool n1 = name[i - 1] < name[i];
			bool a0 = age[i - 1] == age[i];
			bool a1 = age[i - 1] < age[i];
			bool w0 = wt[i - 1] == wt[i];
			bool w1 = wt[i - 1] > wt[i];
			nwa &= n1 || (n0 && (w1 || (w0 && (a0 || a1))));
			naw &= n1 || (n0 && (a1 || (a0 && (w0 || w1))));
			wan &= w1 || (w0 && (a1 || (a0 && (n0 || a1))));
			wna &= w1 || (w0 && (n1 || (n0 && (a0 || a1))));
			awn &= a1 || (a0 && (w1 || (w0 && (n0 || n1))));
			anw &= a1 || (a0 && (n1 || (n0 && (w0 || w1))));
		}
		int count = 0;
		count += nwa ? 1 : 0;
		count += naw ? 1 : 0;
		count += wan ? 1 : 0;
		count += wna ? 1 : 0;
		count += awn ? 1 : 0;
		count += anw ? 1 : 0;
		if ( count > 1 ) return "IND";
		if ( nwa ) return "NWA";
		if ( naw ) return "NAW";
		if ( wan ) return "WAN";
		if ( wna ) return "WNA";
		if ( awn ) return "AWN";
		if ( anw ) return "ANW";
		return "NOT";
	}
	// BEGIN CUT HERE
	private:
	template <typename T> string print_array( const vector<T>& v ) { ostringstream os; os << "{ "; for( typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it ) os << '\"' << *it << "\","; os << " }"; return os.str(); }
	template<typename T> void verify_case( int Case, const vector<T>& expected, const vector<T>& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: " << print_array( expected ) << endl; cerr << "\tReceived: " << print_array( received ) << endl; } }
	void verify_case( int Case, const long long& expected, const long long& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const double& expected, const double& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const int& expected, const int& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const string& expected, const string& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	public:
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vi> A1; vector<vi> A2; vector<string> A3;
	{ /*Test 0*/string _name[] = 
	{"BOB","BOB","DAVE","JOE"}
	; vs name(_name, _name + (sizeof(_name) / sizeof(_name[0]))); A0.push_back( name ); int _age[] = 
	{22, 35, 35, 30}
	; vi age(_age, _age + (sizeof(_age) / sizeof(_age[0]))); A1.push_back( age ); int _wt[] = 
	 {122, 122, 195,  200}
	; vi wt(_wt, _wt + (sizeof(_wt) / sizeof(_wt[0]))); A2.push_back( wt ); string result = 
	"IND"
	; A3.push_back( result );  }
	{ /*Test 1*/string _name[] = 
	{"BOB","BOB","DAVE","DAVE"}
	; vs name(_name, _name + (sizeof(_name) / sizeof(_name[0]))); A0.push_back( name ); int _age[] = 
	{22, 35, 35, 30}
	; vi age(_age, _age + (sizeof(_age) / sizeof(_age[0]))); A1.push_back( age ); int _wt[] = 
	 {122, 122, 195,  200}
	; vi wt(_wt, _wt + (sizeof(_wt) / sizeof(_wt[0]))); A2.push_back( wt ); string result = 
	"NOT"
	; A3.push_back( result );  }
	{ /*Test 2*/string _name[] = 
	{"BOB","BOB","DAVE","DAVE"}
	; vs name(_name, _name + (sizeof(_name) / sizeof(_name[0]))); A0.push_back( name ); int _age[] = 
	 {22, 35, 35, 30}
	; vi age(_age, _age + (sizeof(_age) / sizeof(_age[0]))); A1.push_back( age ); int _wt[] = 
	{122, 122, 195,  190}
	; vi wt(_wt, _wt + (sizeof(_wt) / sizeof(_wt[0]))); A2.push_back( wt ); string result = 
	"NWA"
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], sortType( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	WhatSort ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
