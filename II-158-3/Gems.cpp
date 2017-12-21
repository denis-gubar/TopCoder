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
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
struct Gems
{
	int m, n;
	bool probe( vs& board, int i, int j )
	{
		int a = 0;
		for( int x = i - 1; x >= 0 && board[x][j] == board[i][j]; --x )
			++a;
		for( int x = i + 1; x < m && board[x][j] == board[i][j]; ++x )
			++a;
		if ( a > 1 ) return true;
		a = 0;
		for( int y = j - 1; y >= 0 && board[i][y] == board[i][j]; --y )
			++a;
		for( int y = j + 1; y < n && board[i][y] == board[i][j]; ++y )
			++a;
		if ( a > 1 ) return true;
		return false;
	}
	int numMoves( vs board )
	{
		int result = 0; m = board.size(), n = board[0].size();
		fora2(i, j, board)
		{
			if ( i )
			{
				swap( board[i][j], board[i - 1][j] );
				if ( probe( board, i, j ) || probe( board, i - 1, j ) )
					++result;
				swap( board[i][j], board[i - 1][j] );
			}
			if ( j )
			{
				swap( board[i][j], board[i][j - 1] );
				if ( probe( board, i, j ) || probe( board, i, j - 1 ) )
					++result;
				swap( board[i][j], board[i][j - 1] );
			}
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<int> A1;
	{ /*Test 0*/string _board[] = 
	{"ABC",
 "ABC",
 "BAD"}
	; vs board(_board, _board + (sizeof(_board) / sizeof(_board[0]))); A0.push_back( board ); int result = 
	1
	; A1.push_back( result );  }
	{ /*Test 1*/string _board[] = 
	{"ABB",
 "BAA",
 "ABB"}
	; vs board(_board, _board + (sizeof(_board) / sizeof(_board[0]))); A0.push_back( board ); int result = 
	3
	; A1.push_back( result );  }
	{ /*Test 2*/string _board[] = 
	{"ABA",
 "BAB",
 "ABA"}
	; vs board(_board, _board + (sizeof(_board) / sizeof(_board[0]))); A0.push_back( board ); int result = 
	4
	; A1.push_back( result );  }
	{ /*Test 3*/string _board[] = 
	{"ABC",
 "DEF",
 "GHI"}
	; vs board(_board, _board + (sizeof(_board) / sizeof(_board[0]))); A0.push_back( board ); int result = 
	0
	; A1.push_back( result );  }
	{ /*Test 4*/string _board[] = 
	{"SUMEEMEEPGPPG",
 "USPMIPSUSIISG",
 "UPSPGEGGPKEII",
 "KEMGISMKKIUIG",
 "MGSIIKMSISGKM",
 "SPGMSMIGMSMGM",
 "SSIIUKMPEPPUI",
 "UKUIUEMEEIGKE",
 "IPUPGUSEGSSUS",
 "EUPMKGGUKKEMI",
 "PEPSMUUEUSSIP",
 "SUMEEUSESUEKG",
 "EPSKUISGMSKGI",
 "IUGGUGGSIGUUP",
 "IUPIKKSGPPEEP",
 "KGEESGISPGGEM",
 "UEIUSSKPSSGPE",
 "KSUMKGEIMKPSE",
 "ESKEUEMMPPIGG",
 "UUIEUGGIGMEMK",
 "GPGMPPIUMEPMU",
 "IKIGGPIUEMIGS",
 "IPUSGUMKPKIPP",
 "UEEMUUEEGIPUS",
 "PPEKIKEMGGMSS",
 "EMKPMPUUMKEPU",
 "UKPGPKSUIEUPM",
 "PSUUMUKGIIPMS",
 "ESMGSKUEPGGEM",
 "SMEEIKGKGGPEG",
 "UEIEKPMESMEPP",
 "IPUIMGGMIPKMG",
 "ISSEKPKGKIUGU",
 "SSESKUGKISPUK"}
	; vs board(_board, _board + (sizeof(_board) / sizeof(_board[0]))); A0.push_back( board ); int result = 
	83
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], numMoves( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Gems ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
