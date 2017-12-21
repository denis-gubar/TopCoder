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
#define all(v) (v).begin(), (v).end()
struct ProgressBar
{
	string showProgress( vi taskTimes, int tasksCompleted )
	{
		int k = accumulate( taskTimes.begin(), taskTimes.begin() + tasksCompleted, 0 ) * 20 / accumulate( all(taskTimes), 0 );
		return string(k, '#') + string(20 - k, '.');
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<int> A1; vector<string> A2;
	{ /*Test 0*/int _taskTimes[] = 
	{19,6,23,17}
	; vi taskTimes(_taskTimes, _taskTimes + (sizeof(_taskTimes) / sizeof(_taskTimes[0]))); A0.push_back( taskTimes ); int tasksCompleted = 
	3
	; A1.push_back( tasksCompleted ); string result = 
	"##############......"
	; A2.push_back( result );  }
	{ /*Test 1*/int _taskTimes[] = 
	{2,3,7,1,4,3}
	; vi taskTimes(_taskTimes, _taskTimes + (sizeof(_taskTimes) / sizeof(_taskTimes[0]))); A0.push_back( taskTimes ); int tasksCompleted = 
	4
	; A1.push_back( tasksCompleted ); string result = 
	"#############......."
	; A2.push_back( result );  }
	{ /*Test 2*/int _taskTimes[] = 
	{553,846,816,203,101,120,161,818,315,772}
	; vi taskTimes(_taskTimes, _taskTimes + (sizeof(_taskTimes) / sizeof(_taskTimes[0]))); A0.push_back( taskTimes ); int tasksCompleted = 
	4
	; A1.push_back( tasksCompleted ); string result = 
	"##########.........."
	; A2.push_back( result );  }
	{ /*Test 3*/int _taskTimes[] = 
	{7,60,468,489,707,499,350,998,1000,716,457,104,597,583,396,862}
	; vi taskTimes(_taskTimes, _taskTimes + (sizeof(_taskTimes) / sizeof(_taskTimes[0]))); A0.push_back( taskTimes ); int tasksCompleted = 
	2
	; A1.push_back( tasksCompleted ); string result = 
	"...................."
	; A2.push_back( result );  }
	{ /*Test 4*/int _taskTimes[] = 
	{419,337,853,513,632,861,336,594,94,367,336,297,966,627,399,433,846,859,80,2}
	; vi taskTimes(_taskTimes, _taskTimes + (sizeof(_taskTimes) / sizeof(_taskTimes[0]))); A0.push_back( taskTimes ); int tasksCompleted = 
	19
	; A1.push_back( tasksCompleted ); string result = 
	"###################."
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], showProgress( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ProgressBar ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
