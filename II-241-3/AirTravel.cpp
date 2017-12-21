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
typedef vector<double> vd;
typedef vector<vd> vvd;
#define fora(i,v) for(int i = 0; i < (v).size(); ++i)
template<typename T, typename Predicate> vector<T> Parse( const string& s, Predicate predicate )
{
	vector<T> result;
	for( size_t i = 0, j = 0, n = s.size(), isWord = 0; i <= n; ++i )
		if ( isWord == (i == n || !predicate( s[i] )) )
			if ( (isWord = !isWord) ) j = i;
			else
			{
				istringstream S( s.substr( j, i - j ) ); T current; S >> current; 
				if ( S.rdstate() ^ ios::failbit )
					result.push_back( current );
			}
	return result;
}
struct split_helper: unary_function<int, bool>
{
	explicit split_helper( string delimeter ): delimeter(delimeter) {};
	bool operator() ( int c ) const
	{
		return delimeter.find( c ) == string::npos;
	}
private: string delimeter;
};
template <typename T> vector<T> Split( string s, string delimeter = " " )
{
	return Parse<T>( s, split_helper( delimeter ) );
}
struct AirTravel
{
    double calc( double lat1, double lat2, double lon1, double lon2 )
    {
        double x = 3.14159265358979323846 / 180;
        lat1 *= x; lat2 *= x; lon1 *= x; lon2 *= x;
        return 4000 * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2));
    }
	double shortestTrip( vi latitude, vi longitude, vs canTravel, int origin, int destination )
	{
        if ( origin == destination )
            return 0;
        int n = latitude.size();
        vvd M(n, vd(n, 1000000));
        fora(i, canTravel)
        {
            vi z( Split<int>( canTravel[i] ) );
            fora(j, z)
                M[i][z[j]] = calc( latitude[i], latitude[z[j]], longitude[i], longitude[z[j]] );
        }
        for( int k = 0; k < n; ++k )
            for( int i = 0; i < n; ++i )
                for( int j = 0; j < n; ++j )
                    M[i][j] = min( M[i][j], M[i][k] + M[k][j] );
        if ( M[origin][destination] >= 1000000 )
            return -1;
		return M[origin][destination];
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<vs> A2; vector<int> A3; vector<int> A4; vector<double> A5;
	{ /*Test 0*/int _latitude[] = 
	{0, 0, 70}
	; vi latitude(_latitude, _latitude + (sizeof(_latitude) / sizeof(_latitude[0]))); A0.push_back( latitude ); int _longitude[] = 
	{90, 0, 45}
	; vi longitude(_longitude, _longitude + (sizeof(_longitude) / sizeof(_longitude[0]))); A1.push_back( longitude ); string _canTravel[] = 
	{"2", "0 2", "0 1"}
	; vs canTravel(_canTravel, _canTravel + (sizeof(_canTravel) / sizeof(_canTravel[0]))); A2.push_back( canTravel ); int origin = 
	0
	; A3.push_back( origin ); int destination = 
	1
	; A4.push_back( destination ); double result = 
	10612.237799994255
	; A5.push_back( result );  }
	{ /*Test 1*/int _latitude[] = 
	{0, 0, 70}
	; vi latitude(_latitude, _latitude + (sizeof(_latitude) / sizeof(_latitude[0]))); A0.push_back( latitude ); int _longitude[] = 
	{90, 0, 45}
	; vi longitude(_longitude, _longitude + (sizeof(_longitude) / sizeof(_longitude[0]))); A1.push_back( longitude ); string _canTravel[] = 
	{"1 2", "0 2", "0 1"}
	; vs canTravel(_canTravel, _canTravel + (sizeof(_canTravel) / sizeof(_canTravel[0]))); A2.push_back( canTravel ); int origin = 
	0
	; A3.push_back( origin ); int destination = 
	1
	; A4.push_back( destination ); double result = 
	6283.185307179586
	; A5.push_back( result );  }
	{ /*Test 2*/int _latitude[] = 
	{0, 30, 60}
	; vi latitude(_latitude, _latitude + (sizeof(_latitude) / sizeof(_latitude[0]))); A0.push_back( latitude ); int _longitude[] = 
	{25, -130, 78}
	; vi longitude(_longitude, _longitude + (sizeof(_longitude) / sizeof(_longitude[0]))); A1.push_back( longitude ); string _canTravel[] = 
	{"1 2", "0 2", "1 2"}
	; vs canTravel(_canTravel, _canTravel + (sizeof(_canTravel) / sizeof(_canTravel[0]))); A2.push_back( canTravel ); int origin = 
	0
	; A3.push_back( origin ); int destination = 
	0
	; A4.push_back( destination ); double result = 
	0.0
	; A5.push_back( result );  }
	{ /*Test 3*/int _latitude[] = 
	{0, 20, 55}
	; vi latitude(_latitude, _latitude + (sizeof(_latitude) / sizeof(_latitude[0]))); A0.push_back( latitude ); int _longitude[] = 
	{-20, 85, 42}
	; vi longitude(_longitude, _longitude + (sizeof(_longitude) / sizeof(_longitude[0]))); A1.push_back( longitude ); string _canTravel[] = 
	{"1", "0", "0"}
	; vs canTravel(_canTravel, _canTravel + (sizeof(_canTravel) / sizeof(_canTravel[0]))); A2.push_back( canTravel ); int origin = 
	0
	; A3.push_back( origin ); int destination = 
	2
	; A4.push_back( destination ); double result = 
	-1.0
	; A5.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A5[i], shortestTrip( A0[i], A1[i], A2[i], A3[i], A4[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	AirTravel ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
