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
typedef vector<vi> vvi;
template <typename T> int sign( T val )
{
    return (T( 0 ) < val) - (val < T( 0 ));
}
struct Segments
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
        vector<vi> A0;
        vector<vi> A1;
        vector<string> A2;
        { /* Test 0 */ vi s1 = 
        {0, 0, 0, 1}	
        ; A0.push_back( s1 ); vi s2 = 
        {1, 0, 1, 1}
        ; A1.push_back( s2 ); string result = 
        "NO"
        ; A2.push_back( result ); }
        { /* Test 1 */ vi s1 = 
        {0, 0, 0, 1}
        ; A0.push_back( s1 ); vi s2 = 
        {0, 1, 0, 2}
        ; A1.push_back( s2 ); string result = 
        "POINT"
        ; A2.push_back( result ); }
        { /* Test 2 */ vi s1 = 
        {0, -1, 0, 1}
        ; A0.push_back( s1 ); vi s2 = 
        {-1, 0, 1, 0}
        ; A1.push_back( s2 ); string result = 
        "POINT"
        ; A2.push_back( result ); }
        { /* Test 3 */ vi s1 = 
        {0, 0, 2, 0}
        ; A0.push_back( s1 ); vi s2 = 
        {1, 0, 10, 0}
        ; A1.push_back( s2 ); string result = 
        "SEGMENT"
        ; A2.push_back( result ); }
        { /* Test 4 */ vi s1 = 
        {5, 5, 5, 5}
        ; A0.push_back( s1 ); vi s2 = 
        {6, 6, 6, 6}
        ; A1.push_back( s2 ); string result = 
        "NO"
        ; A2.push_back( result ); }
        { /* Test 5 */ vi s1 = 
        {10, 0, -10, 0}
        ; A0.push_back( s1 ); vi s2 = 
        {5, 0, -5, 0}
        ; A1.push_back( s2 ); string result = 
        "SEGMENT"
        ; A2.push_back( result ); }
        for (int i = 0; i < A0.size(); ++i)
            if (Case == -1 || i == Case)
            {
                boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
                verify_case( i, A2[i], intersection( A0[i], A1[i]) );
                boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
                cout << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
            }
    }
// END CUT HERE
    string intersection( vi s1, vi s2 )
    {
        set<int> S;
        for (const auto& s : s1)
            S.insert( s );
        for (const auto& s : s2)
            S.insert( s );
        int k = 0;
        map<int, int> M;
        for (const auto& s : S)
            M[s] = k++;
        for (auto& s : s1)
            s = M[s];
        for (auto& s : s2)
            s = M[s];
        vvi A( 8, vi( 8 ) );
        int x = s1[0], y = s1[1];
        A[x][y] = 1;
        while (x != s1[2] || y != s1[3])
        {
            x += sign( s1[2] - x );
            y += sign( s1[3] - y );
            A[x][y] = 1;
        }
        int points = 0;
        x = s2[0], y = s2[1];
        points += A[x][y];
        while (x != s2[2] || y != s2[3])
        {
            x += sign( s2[2] - x );
            y += sign( s2[3] - y );
            points += A[x][y];
        }
        if (points == 0)
            return "NO";
        if (points == 1)
            return "POINT";
        return "SEGMENT";
    }
};
// BEGIN CUT HERE
int main()
{
    boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
    Segments ___test; 
    ___test.run_test(); 
    boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
    cout << endl << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
} 
// END CUT HERE
