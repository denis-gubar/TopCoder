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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
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
struct PrintScheduler
{
	string getOutput( vector <string> threads, vector <string> slices )
	{
		string result;
		vi A(threads.size());
		fora(i, slices)
		{
			vi z(Split<int>( slices[i] ));
            for( int j = 0; j < z[1]; ++j )
				result += threads[z[0]][(A[z[0]]++) % threads[z[0]].size()];
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
	void run_test( int Case = -1 ) { vector< vector <string> > A0; vector< vector <string> > A1; vector< string > A2;
	{ /*Test 0*/string _threads[] = 
	{"AB","CD"}
	; vector <string> threads(_threads, _threads + (sizeof(_threads) / sizeof(_threads[0]))); A0.push_back( threads ); string _slices[] = 
	{"0 1","1 1","0 1","1 2"} 
	; vector <string> slices(_slices, _slices + (sizeof(_slices) / sizeof(_slices[0]))); A1.push_back( slices ); string result = 
	"ACBDC"
	; A2.push_back( result );  }
	{ /*Test 1*/string _threads[] = 
	{"ABCDE"}
	; vector <string> threads(_threads, _threads + (sizeof(_threads) / sizeof(_threads[0]))); A0.push_back( threads ); string _slices[] = 
	{"0 20","0 21"}
	; vector <string> slices(_slices, _slices + (sizeof(_slices) / sizeof(_slices[0]))); A1.push_back( slices ); string result = 
	"ABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEA"
	; A2.push_back( result );  }
	{ /*Test 2*/string _threads[] = 
	{"A","B"}
	; vector <string> threads(_threads, _threads + (sizeof(_threads) / sizeof(_threads[0]))); A0.push_back( threads ); string _slices[] = 
	{"1 10","0 1","1 10","0 2"}
	; vector <string> slices(_slices, _slices + (sizeof(_slices) / sizeof(_slices[0]))); A1.push_back( slices ); string result = 
	"BBBBBBBBBBABBBBBBBBBBAA"
	; A2.push_back( result );  }
	{ /*Test 3*/string _threads[] = 
	{"A"}
	; vector <string> threads(_threads, _threads + (sizeof(_threads) / sizeof(_threads[0]))); A0.push_back( threads ); string _slices[] = 
	{"0 1"}
	; vector <string> slices(_slices, _slices + (sizeof(_slices) / sizeof(_slices[0]))); A1.push_back( slices ); string result = 
	"A"
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], getOutput( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	PrintScheduler ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
