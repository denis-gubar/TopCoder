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
struct StringTrain
{
	string buildTrain( vs cars )
	{
		string result, train = cars[0];
		for( int i = 1; i < cars.size(); ++i )
			for( int j = min(cars[i].size() - 1, train.size() - 1); j > 0; --j )
				if ( cars[i].substr(0, j) == train.substr(train.size() - j, j) )
				{
					train += cars[i].substr(j);
					break;
				}
		int n = train.size();
		for( int i = train.size() - 1; i >= 0; --i )
			if ( result.find( train[i] ) == string::npos )
				result = train[i] + result;
		ostringstream s;
		s << n << ' ' << result;
		return s.str();
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<string> A1;
	{ /*Test 0*/string _cars[] = 
	{"ABCDE","CDFFF","CDE","CDEGG","GABC"}
	; vs cars(_cars, _cars + (sizeof(_cars) / sizeof(_cars[0]))); A0.push_back( cars ); string result = 
	"10 DEGABC"
	; A1.push_back( result );  }
	{ /*Test 1*/string _cars[] = 
	{"AAAAA","AAAAA","AAAAA"}
	; vs cars(_cars, _cars + (sizeof(_cars) / sizeof(_cars[0]))); A0.push_back( cars ); string result = 
	"7 A"
	; A1.push_back( result );  }
	{ /*Test 2*/string _cars[] = 
	{"CABABDABAB","CABAB","ABABDABAB","DABAB"}
	; vs cars(_cars, _cars + (sizeof(_cars) / sizeof(_cars[0]))); A0.push_back( cars ); string result = 
	"15 CDAB"
	; A1.push_back( result );  }
	{ /*Test 3*/string _cars[] = 
	{"ABABAB","ABABAB","ABABABAB","BZZZZZ"}
	; vs cars(_cars, _cars + (sizeof(_cars) / sizeof(_cars[0]))); A0.push_back( cars ); string result = 
	"15 ABZ"
	; A1.push_back( result );  }
	{ /*Test 4*/string _cars[] = 
	{"A","A","A","AA"}
	; vs cars(_cars, _cars + (sizeof(_cars) / sizeof(_cars[0]))); A0.push_back( cars ); string result = 
	"1 A"
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], buildTrain( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	StringTrain ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
