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
typedef vector<vs> vvs;
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
#define all(v) (v).begin(), (v).end()
template<typename Predicate> vs parse( const string& s, Predicate predicate )
{
	vs result;
	for( size_t i = 0, j = 0, n = s.size(), isWord = 0; i <= n; ++i )
		if ( isWord == (i == n || !predicate( s[i] )) )
			if ( (isWord = !isWord) ) j = i;
			else result.push_back( s.substr( j, i - j ) );
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
vs split( const string& s, const string& delimeter = " " )
{
	return parse( s, split_helper( delimeter ) );
}
struct Bingo
{
    struct comp: binary_function<vs, vs, bool>
    {
        int calc( const vs& line ) const
        {
            if ( line.size() == 1 )
                return 100000;
            vi result;
            int a = 0;
            fora(i, calls)
            {
                if ( find( all(line), calls[i] ) != line.end() )
                {
                    ++a; result.push_back( i );
                }
                if ( a == line.size() )
                    return result.back() * 100 + result[0];
            }
            return 10000000;
        }
        bool operator() ( const vs& a, const vs& b ) const
        {
            return calc( a ) < calc( b );
        }
        comp( const vs& calls): calls(calls) {}
    private:
        vs calls;
    };
	string winner( vs card, vs calls )
	{
		string result;
        vvs lines(1, vs(1, "YOU LOSE"));
        vvs M;
        fora(i, card)
            M.push_back( split( card[i] ) );
        for( int i = 1; i < 6; ++i )
        {
            lines.push_back( vs() );
            for( int j = 0; j < 5; ++j )
                if ( i != 3 || j != 2 )
                    lines.back().push_back( M[0][j] + M[i][j] );
        }
        for( int j = 0; j < 5; ++j )
        {
            lines.push_back( vs() );
            for( int i = 1; i < 6; ++i )
                if ( i != 3 || j != 2 )
                    lines.back().push_back( M[0][j] + M[i][j] );
        }
        lines.push_back( vs() );
        for( int j = 0; j < 5; ++j )
            if ( j != 2 )
                lines.back().push_back( M[0][j] + M[j + 1][j] );
        lines.push_back( vs() );
        for( int j = 0; j < 5; ++j )
            if ( j != 2 )
                lines.back().push_back( M[0][4 - j] + M[j + 1][4 - j] );
        vs best = *min_element( all(lines), comp(calls) );
        if ( best.size() == 1 )
            return best[0];
        fora(i, calls)
            if ( find( all(best), calls[i] ) != best.end() )
                result += "," + calls[i];        
		return result.substr( 1 );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1; vector<string> A2;
	{ /*Test 0*/string _card[] = 
	{ "  B  I  N  G  O",
  " 12 22 33 55 66",
  "  9 23 34 52 72",
  "  1 24  F 59 71",
  "  4 16 40 48 61",
  "  3 18 41 49 63"}
	; vs card(_card, _card + (sizeof(_card) / sizeof(_card[0]))); A0.push_back( card ); string _calls[] = 
	{"B12","B3","I16","N40","B2","O70","B1","B9","O71","B4","B7","B11","O68","BINGO"}
	; vs calls(_calls, _calls + (sizeof(_calls) / sizeof(_calls[0]))); A1.push_back( calls ); string result = 
	"B12,B3,B1,B9,B4"
	; A2.push_back( result );  }
	{ /*Test 1*/string _card[] = 
	{ "  B  I  N  G  O",
  " 12 22 33 55 66",
  "  9 23 34 52 72",
  "  1 24  F 59 71",
  "  4 16 40 48 61",
  "  3 18 41 49 63"}
	; vs card(_card, _card + (sizeof(_card) / sizeof(_card[0]))); A0.push_back( card ); string _calls[] = 
	{"B12","B3","I16","N40","B2","O70","B1","B9","BINGO"}
	; vs calls(_calls, _calls + (sizeof(_calls) / sizeof(_calls[0]))); A1.push_back( calls ); string result = 
	"YOU LOSE"
	; A2.push_back( result );  }
	{ /*Test 2*/string _card[] = 
	{ "  B  I  N  G  O",
  " 12 22 33 55 66",
  "  9 23 34 52 72",
  "  1 24  F 59 71",
  "  4 16 40 48 61",
  "  3 18 41 49 63"}
	; vs card(_card, _card + (sizeof(_card) / sizeof(_card[0]))); A0.push_back( card ); string _calls[] = 
	{"O63","G48","I23","B9","B1","B4","B3","B7","B12","G49","BINGO"}
	; vs calls(_calls, _calls + (sizeof(_calls) / sizeof(_calls[0]))); A1.push_back( calls ); string result = 
	"O63,G48,I23,B12"
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], winner( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Bingo ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
