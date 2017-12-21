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
typedef vector<vi> vvi;
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
template<typename T, typename Predicate> vector<T> Parse( string s, Predicate predicate )
{
	vector<T> result; bool isWord = false; int j = 0;
	for( int i = 0; i < s.size(); i++ )
		if ( isWord )
		{
			if ( !predicate( s[i] ) )
			{
				istringstream S( s.substr( j, i - j ) );
				T current; S >> current; 
				if ( S.rdstate() ^ ios::failbit )
					result.push_back( current );
				isWord = false;
			}
		}
		else
		{
			if ( predicate( s[i] ) )
			{
				j = i; isWord = true;
			}
		}
		if ( isWord )
		{
			istringstream S( s.substr( j ) );
			T current; S >> current; 
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
struct ExperimentalAnalyzer
{
	bool calc( const vi& A, const vi& R )
	{
		fora( i, A )
		{
			bool flag = true;
			fora(j, A)	
				flag &= (A[i] <= A[j]) ^ R[j];
			if ( flag )
				return true;
			flag = true;
			fora(j, A)	
				flag &= (A[i] > A[j]) ^ R[j];
			if ( flag )
				return true;
		}
		return false;
	}
	vi getPredictors( vs data )
	{
		vi result;
		vvi M; vi R;
		fora(i, data)
		{
			M.push_back( Split<int>( data[i] ) );
			R.push_back( M[i][0] );
		}
		int n = M[0].size() - 1;
		int total = accumulate( all( R ), 0 );
		if ( !total || total == M.size() )
			return result;
		for( int i = 1; i <= n; ++i )
		{
			vi A;
			fora(j, M)
				A.push_back( M[j][i] );
			if ( calc( A, R ) )
				result.push_back( i );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vi> A1;
	{ /*Test 0*/string _data[] = 
	{
"0 10 20 20 0",
"1 20 30 17 98765",
"0 10 30 29 1234567",
"1 20 40 10 42"}
	; vs data(_data, _data + (sizeof(_data) / sizeof(_data[0]))); A0.push_back( data ); int _result[] = 
	{ 1,  3 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 1*/string _data[] = 
	{
"1 220 212 247 764 928 956 946 66 640 983 125 994",
"0 816 835 98 81 783 267 946 584 309 757 876 670"}
	; vs data(_data, _data + (sizeof(_data) / sizeof(_data[0]))); A0.push_back( data ); int _result[] = 
	{ 1,  2,  3,  4,  5,  6,  8,  9,  10,  11,  12 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 2*/string _data[] = 
	{
"0 1944914038 1696137778 1525367830",
"0 1547932733 1185820653 1500052399",
"0 230149443 1358715189 501418065",
"0 1676118083 1499656529 2103271593",
"0 1441540020 1189300515 1544659186"}
	; vs data(_data, _data + (sizeof(_data) / sizeof(_data[0]))); A0.push_back( data ); vi result; A1.push_back( result );  }
	{ /*Test 3*/string _data[] = 
	{
"0 163869663 388719849 383049741",
"1 1982032201 1346175990 1500891700",
"0 436834674 559375803 994453722",
"0 652316051 372955428 361692727",
"1 1946362869 1204080206 2066121600",
"0 840867095 22073435 1166658385",
"1 1864235269 2041251772 1847305529",
"0 852306016 447986701 407997336",
"1 1183214776 728141214 1985649244",
"0 70064437 7110416 107908753",
"1 1383409284 1328770197 1942831571",
"1 1023334064 1596272317 1226876467",
"1 2068895243 1481323649 1955807390",
"0 758836687 541737411 312747384",
"1 1432983907 1475284843 1512945413",
"1 1512506825 1933755150 2041997368",
"1 2041700103 1859742986 1995865005",
"0 323696628 328891715 893352493",
"1 1623710967 1193592990 1871502957",
"0 9241593 127579695 36337622",
"1 1935123182 1332735215 1400991717",
"1 2130762600 1874898210 1234793873",
"0 411777048 142083649 61450530",
"1 1042383468 1979605937 1276643901",
"0 219279208 371281702 65383690",
"0 948808405 243728462 984221323",
"0 999393888 131231007 1186873391",
"1 1294115986 1618148416 1324126407",
"1 1710811842 2024808989 1696767048",
"1 1399327255 1317859960 1427366434",
"0 145887863 452552798 165691442",
"0 685701683 334764463 1001631935",
"1 1596433536 1911594193 1533322508",
"0 128647261 372955025 1051296077",
"0 946946329 548039713 83591687",
"1 1490995704 1541151932 2052868342",
"0 805037508 405134691 593191395",
"1 2048614262 1171142414 1309623012",
"1 1024870244 1791074791 1778846631",
"1 1403452711 2033486235 1555085078",
"0 900806815 269954427 806033528",
"1 1598931622 938905156 1474311731",
"1 1468418323 749319445 2060324871",
"0 407246582 393808982 163347811",
"0 52629967 643176802 619367349"}
	; vs data(_data, _data + (sizeof(_data) / sizeof(_data[0]))); A0.push_back( data ); int _result[] = 
	{ 1,  2,  3 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], getPredictors( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ExperimentalAnalyzer ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
