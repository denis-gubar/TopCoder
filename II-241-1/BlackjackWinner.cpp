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
struct BlackjackWinner
{
	int winnings( int bet, int dealer, int dealerBlackjack, int player, int blackjack )
	{
        if ( dealer > 21 )
            dealer = 0;
        if ( player > 21 )
            player = -1;
        if ( dealerBlackjack * 100 + dealer == blackjack * 100 + player )
            return 0;
        if ( blackjack * 100 + player == 121 )
            return bet * 3 / 2;
        if ( dealerBlackjack * 100 + dealer > blackjack * 100 + player )
            return -bet;
		return bet;
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<int> A2; vector<int> A3; vector<int> A4; vector<int> A5;
	{ /*Test 0*/int bet = 
	10
	; A0.push_back( bet ); int dealer = 
	20
	; A1.push_back( dealer ); int dealerBlackjack = 
	0
	; A2.push_back( dealerBlackjack ); int player = 
	21
	; A3.push_back( player ); int blackjack = 
	0
	; A4.push_back( blackjack ); int result = 
	10
	; A5.push_back( result );  }
	{ /*Test 1*/int bet = 
	26
	; A0.push_back( bet ); int dealer = 
	21
	; A1.push_back( dealer ); int dealerBlackjack = 
	1
	; A2.push_back( dealerBlackjack ); int player = 
	21
	; A3.push_back( player ); int blackjack = 
	0
	; A4.push_back( blackjack ); int result = 
	-26
	; A5.push_back( result );  }
	{ /*Test 2*/int bet = 
	100
	; A0.push_back( bet ); int dealer = 
	25
	; A1.push_back( dealer ); int dealerBlackjack = 
	0
	; A2.push_back( dealerBlackjack ); int player = 
	21
	; A3.push_back( player ); int blackjack = 
	1
	; A4.push_back( blackjack ); int result = 
	150
	; A5.push_back( result );  }
	{ /*Test 3*/int bet = 
	78
	; A0.push_back( bet ); int dealer = 
	22
	; A1.push_back( dealer ); int dealerBlackjack = 
	0
	; A2.push_back( dealerBlackjack ); int player = 
	23
	; A3.push_back( player ); int blackjack = 
	0
	; A4.push_back( blackjack ); int result = 
	-78
	; A5.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A5[i], winnings( A0[i], A1[i], A2[i], A3[i], A4[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	BlackjackWinner ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
