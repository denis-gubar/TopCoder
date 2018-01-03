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
typedef vector<int> vi;
struct MinDifference
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
        vector<int> A1;
        vector<int> A2;
        vector<int> A3;
        vector<int> A4;
        vector<int> A5;
        { /* Test 0 */ int _A0 = 
        3
        ; A0.push_back( _A0 ); int X = 
        7
        ; A1.push_back( X ); int Y = 
        1
        ; A2.push_back( Y ); int M = 
        101
        ; A3.push_back( M ); int n = 
        5
        ; A4.push_back( n ); int result = 
        6
        ; A5.push_back( result ); }
        { /* Test 1 */ int _A0 = 
        3
        ; A0.push_back( _A0 ); int X = 
        9
        ; A1.push_back( X ); int Y = 
        8
        ; A2.push_back( Y ); int M = 
        32
        ; A3.push_back( M ); int n = 
        8
        ; A4.push_back( n ); int result = 
        0
        ; A5.push_back( result ); }
        { /* Test 2 */ int _A0 = 
        67
        ; A0.push_back( _A0 ); int X = 
        13
        ; A1.push_back( X ); int Y = 
        17
        ; A2.push_back( Y ); int M = 
        4003
        ; A3.push_back( M ); int n = 
        23
        ; A4.push_back( n ); int result = 
        14
        ; A5.push_back( result ); }
        { /* Test 3 */ int _A0 = 
        1
        ; A0.push_back( _A0 ); int X = 
        1221
        ; A1.push_back( X ); int Y = 
        3553
        ; A2.push_back( Y ); int M = 
        9889
        ; A3.push_back( M ); int n = 
        11
        ; A4.push_back( n ); int result = 
        275
        ; A5.push_back( result ); }
        { /* Test 4 */ int _A0 = 
        1
        ; A0.push_back( _A0 ); int X = 
        1
        ; A1.push_back( X ); int Y = 
        1
        ; A2.push_back( Y ); int M = 
        2
        ; A3.push_back( M ); int n = 
        10000
        ; A4.push_back( n ); int result = 
        0
        ; A5.push_back( result ); }
        { /* Test 5 */ int _A0 = 
        1567
        ; A0.push_back( _A0 ); int X = 
        5003
        ; A1.push_back( X ); int Y = 
        9661
        ; A2.push_back( Y ); int M = 
        8929
        ; A3.push_back( M ); int n = 
        43
        ; A4.push_back( n ); int result = 
        14
        ; A5.push_back( result ); }
        for (int i = 0; i < A0.size(); ++i)
            if (Case == -1 || i == Case)
            {
                boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
                verify_case( i, A5[i], closestElements( A0[i], A1[i], A2[i], A3[i], A4[i]) );
                boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
                cout << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
            }
    }
// END CUT HERE
    int closestElements( int A0, int X, int Y, int M, int n )
    {
        vi A{ A0 };
        for (int i = 1; i < n; ++i)
            A.push_back( (A[i - 1] * X + Y) % M );
        sort( A.begin(), A.end() );
        vi results;
        for (int i = 0; i + 1 < n; ++i)
            results.push_back( A[i + 1] - A[i] );
        return *min_element(results.begin(), results.end());
    }
};
// BEGIN CUT HERE
int main()
{
    boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
    MinDifference ___test; 
    ___test.run_test(); 
    boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
    cout << endl << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
} 
// END CUT HERE
