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
#include <list>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
using namespace std;
// BEGIN CUT HERE
*/
// END CUT HERE
typedef long long lint;
typedef vector<lint> vl;
struct SpiralNumbers
{
// BEGIN CUT HERE
private:
    template<typename T> string print_array( const vector<T>& v )
    {
        ostringstream os; os << "{ ";
        for (const auto& x : v)
            os << '\"' << x << "\",";
        os << " }";
        return os.str();
    }
    template<typename T> void verify_case( int Case, const vector<T>& expected, const vector<T>& received )
    {
        cerr << "Test Case #" << Case << "...";
        if (expected == received)
            cerr << "PASSED. "; 
        else
        {
            cerr << "FAILED." << endl;
            cerr << "\tExpected: " << print_array( expected ) << endl;
            cerr << "\tReceived: " << print_array( received ) << endl;
        }
    }
    template<typename T> void verify_case( int Case, const T& expected, const T& received )
    {
        cerr << "Test Case #" << Case << "...";
        if (expected == received) 
            cerr << "PASSED. "; 
        else
        {
            cerr << "FAILED." << endl;
            cerr << "\tExpected: \"" << expected << '\"' << endl;
            cerr << "\tReceived: \"" << received << '\"' << endl;
        }    
    }
public:
    void run_test( int Case = -1 )
    {
        vector<int> A0;
        vector<string> A1;
        { /* Test 0 */ int N = 
        2
        ; A0.push_back( N ); string result = 
        "(0,1)"
        ; A1.push_back( result ); }
        { /* Test 1 */ int N = 
        3
        ; A0.push_back( N ); string result = 
        "(1,1)"
        ; A1.push_back( result ); }
        { /* Test 2 */ int N = 
        7
        ; A0.push_back( N ); string result = 
        "(-1,-1)"
        ; A1.push_back( result ); }
        { /* Test 3 */ int N = 
        17
        ; A0.push_back( N ); string result = 
        "(2,-2)"
        ; A1.push_back( result ); }
        { /* Test 4 */ int N = 
        24
        ; A0.push_back( N ); string result = 
        "(-2,1)"
        ; A1.push_back( result ); }
        { /* Test 5 */ int N = 
        830
        ; A0.push_back( N ); string result = 
        "(-14,3)"
        ; A1.push_back( result ); }
        { /* Test 6 */ int N = 
        765409
        ; A0.push_back( N ); string result = 
        "(-437,221)"
        ; A1.push_back( result ); }
        for (int i = 0; i < A0.size(); ++i)
            if (Case == -1 || i == Case)
            {
                boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
                verify_case( i, A1[i], getPosition( A0[i]) );
                boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
                cout << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
            }
    }
// END CUT HERE
    string getPosition( int N )
    {
        string result{};
        long long x = 0, y = 0, d = 0, k = 0, n = 1;
        vl dx = { 0, 1, 0, -1 };
        vl dy = { 1, 0, -1, 0 };
        while (n < N)
        {
            if (d % 2 == 0)
                ++k;
            if (n + k > N)
                k = N - n;
            x += dx[d] * k;
            y += dy[d] * k;
            n += k;
            d = (d + 1) % 4;
        }
        return "(" + to_string(x) + "," + to_string(y) + ")";
    }
};
// BEGIN CUT HERE
int main()
{
    boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
    SpiralNumbers ___test; 
    ___test.run_test(); 
    boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
    cout << endl << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
} 
// END CUT HERE
