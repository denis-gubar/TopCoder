// BEGIN CUT HERE
#include "precompiled.h"
/*
// END CUT HERE
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
*/
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE
typedef vector<int> vi;
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct HealthFood
{
	struct comp: binary_function<int, int, bool>
	{
		comp( vi protein, vi carbs, vi fat, string s ): protein(protein), carbs(carbs), fat(fat), s(s) {}
		bool operator() ( int a, int b ) const
		{
			fora(i, s)
			{
				int x, y;
				switch( s[i] )
				{
					case 'p':
						x = protein[a]; y = protein[b];
						break;
					case 'P':
						x = -protein[a]; y = -protein[b];
						break;
					case 'c':
						x = carbs[a]; y = carbs[b];
						break;
					case 'C':
						x = -carbs[a]; y = -carbs[b];
						break;
					case 'f':
						x = fat[a]; y = fat[b];
						break;
					case 'F':
						x = -fat[a]; y = -fat[b];
						break;
					case 't':
						x = protein[a] * 5 + carbs[a] * 5 + fat[a] * 9; y = protein[b] * 5 + carbs[b] * 5 + fat[b] * 9;
						break;
					case 'T':
						x = -(protein[a] * 5 + carbs[a] * 5 + fat[a] * 9); y = -(protein[b] * 5 + carbs[b] * 5 + fat[b] * 9);
						break;
				}
				if ( x != y )
					return x < y;
			}
			return a < b;
		}
		vi protein, carbs, fat;
		string s;
	};
	vi selectMeals( vi protein, vi carbs, vi fat, vs dietPlans )
	{
		vi result;
		fora(i, dietPlans)
		{
			vi temp;
			fora(j, fat)
				temp.push_back( j );
			result.push_back( *min_element( all(temp), comp( protein, carbs, fat, dietPlans[i] ) ) );
		}
		return result;
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<vi> A2; vector<vs> A3; vector<vi> A4;
	{ /*Test 0*/int _protein[] = 
	{3, 4}
	; vi protein(_protein, _protein + (sizeof(_protein) / sizeof(_protein[0]))); A0.push_back( protein ); int _carbs[] = 
	{2, 8}
	; vi carbs(_carbs, _carbs + (sizeof(_carbs) / sizeof(_carbs[0]))); A1.push_back( carbs ); int _fat[] = 
	{5, 2}
	; vi fat(_fat, _fat + (sizeof(_fat) / sizeof(_fat[0]))); A2.push_back( fat ); string _dietPlans[] = 
	{"P", "p", "C", "c", "F", "f", "T", "t"}
	; vs dietPlans(_dietPlans, _dietPlans + (sizeof(_dietPlans) / sizeof(_dietPlans[0]))); A3.push_back( dietPlans ); int _result[] = 
	{ 1,  0,  1,  0,  0,  1,  1,  0 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A4.push_back( result );  }
	{ /*Test 1*/int _protein[] = 
	{3, 4, 1, 5}
	; vi protein(_protein, _protein + (sizeof(_protein) / sizeof(_protein[0]))); A0.push_back( protein ); int _carbs[] = 
	{2, 8, 5, 1}
	; vi carbs(_carbs, _carbs + (sizeof(_carbs) / sizeof(_carbs[0]))); A1.push_back( carbs ); int _fat[] = 
	{5, 2, 4, 4}
	; vi fat(_fat, _fat + (sizeof(_fat) / sizeof(_fat[0]))); A2.push_back( fat ); string _dietPlans[] = 
	{"tFc", "tF", "Ftc"}
	; vs dietPlans(_dietPlans, _dietPlans + (sizeof(_dietPlans) / sizeof(_dietPlans[0]))); A3.push_back( dietPlans ); int _result[] = 
	{ 3,  2,  0 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A4.push_back( result );  }
	{ /*Test 2*/int _protein[] = 
	{18, 86, 76,  0, 34, 30, 95, 12, 21}
	; vi protein(_protein, _protein + (sizeof(_protein) / sizeof(_protein[0]))); A0.push_back( protein ); int _carbs[] = 
	{26, 56,  3, 45, 88,  0, 10, 27, 53}
	; vi carbs(_carbs, _carbs + (sizeof(_carbs) / sizeof(_carbs[0]))); A1.push_back( carbs ); int _fat[] = 
	{93, 96, 13, 95, 98, 18, 59, 49, 86}
	; vi fat(_fat, _fat + (sizeof(_fat) / sizeof(_fat[0]))); A2.push_back( fat ); string _dietPlans[] = 
	{"f", "Pt", "PT", "fT", "Cp", "C", "t", "",
 "cCp", "ttp", "PCFt", "P", "pCt", "cP", "Pc"}
	; vs dietPlans(_dietPlans, _dietPlans + (sizeof(_dietPlans) / sizeof(_dietPlans[0]))); A3.push_back( dietPlans ); int _result[] = 
	{ 2,  6,  6,  2,  4,  4,  5,  0,  5,  5,  6,  6,  3,  5,  6 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A4.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A4[i], selectMeals( A0[i], A1[i], A2[i], A3[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	HealthFood ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
