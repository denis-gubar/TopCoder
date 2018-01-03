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
struct UnluckyNumbers
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
        vector<int> A1;
        vector<int> A2;
        { /* Test 0 */ vector <int> luckySet = 
        {1, 7, 14, 10}
        ; A0.push_back( luckySet ); int n = 
        2
        ; A1.push_back( n ); int result = 
        4
        ; A2.push_back( result ); }
        { /* Test 1 */ vector <int> luckySet = 
        {4, 8, 13, 24, 30}
        ; A0.push_back( luckySet ); int n = 
        10
        ; A1.push_back( n ); int result = 
        5
        ; A2.push_back( result ); }
        { /* Test 2 */ vector <int> luckySet = 
        {10, 20, 30, 40, 50}
        ; A0.push_back( luckySet ); int n = 
        30
        ; A1.push_back( n ); int result = 
        0
        ; A2.push_back( result ); }
        { /* Test 3 */ vector <int> luckySet = 
        {3, 7, 12, 18, 25, 100, 33, 1000}
        ; A0.push_back( luckySet ); int n = 
        59
        ; A1.push_back( n ); int result = 
        1065
        ; A2.push_back( result ); }
        for (int i = 0; i < A0.size(); ++i)
            if (Case == -1 || i == Case)
            {
                boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
                verify_case( i, A2[i], getCount( A0[i], A1[i]) );
                boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
                cout << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
            }
    }
// END CUT HERE
    int getCount( vector <int> luckySet, int n )
    {
        int result{};
        vector<char> A( 1002 );
        A[1001] = A[0] = 2;
        for (const auto& l : luckySet)
            A[l] = 1;
        int a = n, b = n;
        while (A[a] == 0)
            --a;
        ++a;
        while (A[b] == 0)
            ++b;
        --b;
        for (int x = a; x <= n; ++x)
            for (int y = n; y <= b; ++y)
                if (x < y)
                    ++result;
        return result;
    }
};
// BEGIN CUT HERE
int main()
{
    boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
    UnluckyNumbers ___test; 
    ___test.run_test(); 
    boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
    cout << endl << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
} 
// END CUT HERE
