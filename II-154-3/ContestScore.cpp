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
typedef vector<vi> vvi;
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
#define all(v) (v).begin(), (v).end()
struct ContestScore
{
	struct Data
	{
		string name; int rank, score;
		Data() {}
		Data( string name, int rank, int score ): name(name), rank(rank), score(score) {}
	};
	struct comp: binary_function<Data, Data, bool>
	{
		bool operator() ( const Data& a, const Data& b ) const
		{
			if ( a.rank != b.rank ) return a.rank < b.rank;
			if ( a.score != b.score ) return a.score > b.score;
			return a.name < b.name;
		}
	};
	vs sortResults( vs data )
	{
		if ( data.empty() ) return data;
		vs result;
		int n = data.size(), m = count_if( all(data[0]), bind2nd( equal_to<char>(), ' ' ) );
		vvi A(n, vi(m)); vector<Data> D(n);
		fora(i, data)
		{
			string t = data[i]; t.erase( remove_if( all(t), bind2nd( equal_to<char>(), '.' ) ), t.end() );
			istringstream s( t );
			s >> t;
			for( int j = 0; j < m; ++j )
				s >> A[i][j];
			D[i] = Data( t, m, accumulate( all(A[i]), 0 ) );
		}
		fora2(i, j, A)
			fora(k, A)
				if ( A[i][j] > A[k][j] )
					++D[k].rank;
		sort( all(D), comp() );
		fora(i, D)
		{
			ostringstream s;
			s << D[i].name << ' ' << D[i].rank << ' ' << D[i].score / 10 << '.' << D[i].score % 10;
			result.push_back( s.str() );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1;
	{ /*Test 0*/string _data[] = 
	{"A 90.7 92.9 87.4",
 "B 90.5 96.6 88.0",
 "C 92.2 91.0 95.3"}
	; vs data(_data, _data + (sizeof(_data) / sizeof(_data[0]))); A0.push_back( data ); string _result[] = 
	{ "C 5 278.5",  "B 6 275.1",  "A 7 271.0" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 1*/string _data[] = 
	{"STANFORD 85.3 90.1 82.6 84.6 96.6 94.5 87.3 90.3",
 "MIT 95.5 83.9 80.4 85.5 98.7 98.3 96.7 82.7",
 "PRINCETON 99.2 79.1 87.6 85.1 93.6 96.4 86.0 90.6",
 "HARVARD 83.6 92.0 85.5 94.3 97.5 91.5 92.5 83.0",
 "YALE 99.5 92.6 86.2 82.0 96.4 92.6 84.5 78.6",
 "COLUMBIA 97.2 87.6 81.7 93.7 88.0 86.3 95.9 89.6",
 "BROWN 92.2 95.8 92.1 81.5 89.5 87.0 95.5 86.4",
 "PENN 96.3 80.7 81.2 91.6 85.8 92.2 83.9 87.8",
 "CORNELL 88.0 83.7 85.0 83.8 99.8 92.1 91.0 88.9"}
	; vs data(_data, _data + (sizeof(_data) / sizeof(_data[0]))); A0.push_back( data ); string _result[] = 
	{ "PRINCETON 34 717.6",  "MIT 36 721.7",  "HARVARD 38 719.9",  "COLUMBIA 39 720.0",  "STANFORD 39 711.3",  "YALE 40 712.4",  "BROWN 41 720.0",  "CORNELL 42 712.3",  "PENN 51 699.5" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 2*/vs data; A0.push_back( data ); vs result; A1.push_back( result );  }
	{ /*Test 3*/string _data[] = 
	{"AA 90.0 80.0 70.0 60.0 50.0 40.0",
 "BBB 80.0 70.0 60.0 50.0 40.0 90.0",
 "EEE 70.0 60.0 50.0 40.0 90.0 80.0",
 "AAA 60.0 50.0 40.0 90.0 80.0 70.0",
 "DDD 50.0 40.0 90.0 80.0 70.0 60.0",
 "CCC 40.0 90.0 80.0 70.0 60.0 50.0"}
	; vs data(_data, _data + (sizeof(_data) / sizeof(_data[0]))); A0.push_back( data ); string _result[] = 
	{ "AA 21 390.0",  "AAA 21 390.0",  "BBB 21 390.0",  "CCC 21 390.0",  "DDD 21 390.0",  "EEE 21 390.0" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 4*/string _data[] = 
	{"A 00.1", "B 05.2", "C 29.0","D 00.0"}
	; vs data(_data, _data + (sizeof(_data) / sizeof(_data[0]))); A0.push_back( data ); string _result[] = 
	{ "C 1 29.0",  "B 2 5.2",  "A 3 0.1",  "D 4 0.0" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], sortResults( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ContestScore ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
