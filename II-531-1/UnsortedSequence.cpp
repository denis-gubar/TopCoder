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
struct UnsortedSequence
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
        vector<vector <int>> A0;
        vector<vector <int>> A1;
        { /* Test 0 */ vector <int> s = 
        {1,2}
        ; A0.push_back( s ); vector <int> result = 
        {2, 1 }
        ; A1.push_back( result ); }
        { /* Test 1 */ vector <int> s = 
        {1,2,3}
        ; A0.push_back( s ); vector <int> result = 
        {1, 3, 2 }
        ; A1.push_back( result ); }
        { /* Test 2 */ vector <int> s = 
        {7,2,2}
        ; A0.push_back( s ); vector <int> result = 
        {2, 7, 2 }
        ; A1.push_back( result ); }
        { /* Test 3 */ vector <int> s = 
        {1000}
        ; A0.push_back( s ); vector <int> result = 
        { }
        ; A1.push_back( result ); }
        { /* Test 4 */ vector <int> s = 
        {1,1}
        ; A0.push_back( s ); vector <int> result = 
        { }
        ; A1.push_back( result ); }
        { /* Test 5 */ vector <int> s = 
        {1,2,4,3}
        ; A0.push_back( s ); vector <int> result = 
        {1, 2, 4, 3 }
        ; A1.push_back( result ); }
        { /* Test 6 */ vector <int> s = 
        {2,8,5,1,10,5,9,9,3,10,5,6,6,2,8,2,10}
        ; A0.push_back( s ); vector <int> result = 
        {1, 2, 2, 2, 3, 5, 5, 5, 6, 6, 8, 8, 9, 10, 9, 10, 10 }
        ; A1.push_back( result ); }
        for (int i = 0; i < A0.size(); ++i)
            if (Case == -1 || i == Case)
            {
                boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
                verify_case( i, A1[i], getUnsorted( A0[i]) );
                boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
                cout << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
            }
    }
// END CUT HERE
    vector <int> getUnsorted( vector <int> s )
    {
        sort( s.begin(), s.end() );
        if (next_permutation( s.begin(), s.end() ))
            return s;
        return vi{};
    }
};
// BEGIN CUT HERE
int main()
{
    boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
    UnsortedSequence ___test; 
    ___test.run_test(); 
    boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
    cout << endl << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
} 
// END CUT HERE
