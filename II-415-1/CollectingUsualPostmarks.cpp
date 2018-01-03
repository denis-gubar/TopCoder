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
struct CollectingUsualPostmarks
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
        vector<int> A2;
        { /* Test 0 */ vector <int> prices = 
        {13,10,14,20}
        ; A0.push_back( prices ); vector <int> have = 
        {3,0,2,1}
        ; A1.push_back( have ); int result = 
        4
        ; A2.push_back( result ); }
        { /* Test 1 */ vector <int> prices = 
        {7,5,9,7}
        ; A0.push_back( prices ); vector <int> have = 
        {}
        ; A1.push_back( have ); int result = 
        0
        ; A2.push_back( result ); }
        { /* Test 2 */ vector <int> prices = 
        {4,13,9,1,5}
        ; A0.push_back( prices ); vector <int> have = 
        {1,3,2}
        ; A1.push_back( have ); int result = 
        4
        ; A2.push_back( result ); }
        { /* Test 3 */ vector <int> prices = 
        {16,32,13,2,17,10,8,8,20,17}
        ; A0.push_back( prices ); vector <int> have = 
        {7,0,4,1,6,8}
        ; A1.push_back( have ); int result = 
        8
        ; A2.push_back( result ); }
        for (int i = 0; i < A0.size(); ++i)
            if (Case == -1 || i == Case)
            {
                boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
                verify_case( i, A2[i], numberOfPostmarks( A0[i], A1[i]) );
                boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
                cout << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
            }
    }
// END CUT HERE
    int numberOfPostmarks( vector <int> prices, vector <int> have )
    {
        vi P{ prices }, H, A;
        for (const auto& h : have)
            H.push_back( prices[h] );
        sort( P.begin(), P.end() );
        sort( H.begin(), H.end() );
        set_difference( P.begin(), P.end(), H.begin(), H.end(), back_inserter( A ) );
        int result = H.size();
        if (A.empty())
            return result;
        int money = 0;
        int h = result - 1, a = 0;
        while (a < A.size() && h >= 0 && H[h] > A[a])
        {
            money += H[h];
            --h;
            --result;
            while (a < A.size() && money >= A[a])
            {
                money -= A[a];
                ++a;
                ++result;
            }
        }
        return result;
    }
};
// BEGIN CUT HERE
int main()
{
    boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
    CollectingUsualPostmarks ___test; 
    ___test.run_test(); 
    boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
    cout << endl << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
} 
// END CUT HERE
