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
struct Cryptography
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
        vector<long long> A1;
        { /* Test 0 */ vector <int> numbers = 
        {1,2,3}
        ; A0.push_back( numbers ); long long result = 
        12
        ; A1.push_back( result ); }
        { /* Test 1 */ vector <int> numbers = 
        {1,3,2,1,1,3}
        ; A0.push_back( numbers ); long long result = 
        36
        ; A1.push_back( result ); }
        { /* Test 2 */ vector <int> numbers = 
        {1000,999,998,997,996,995}
        ; A0.push_back( numbers ); long long result = 
        986074810223904000
        ; A1.push_back( result ); }
        { /* Test 3 */ vector <int> numbers = 
        {1,1,1,1}
        ; A0.push_back( numbers ); long long result = 
        2
        ; A1.push_back( result ); }
        for (int i = 0; i < A0.size(); ++i)
            if (Case == -1 || i == Case)
            {
                boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
                verify_case( i, A1[i], encrypt( A0[i]) );
                boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
                cout << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
            }
    }
// END CUT HERE
    long long encrypt( vector <int> numbers )
    {
        vl results{};
        for (int i = 0; i < numbers.size(); ++i)
        {
            long long current = 1;
            for (int j = 0; j < numbers.size(); ++j)
                current *= i == j ? numbers[j] + 1 : numbers[j];
            results.push_back( current );
        }
        return *max_element( results.begin(), results.end() );
    }
};
// BEGIN CUT HERE
int main()
{
    boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
    Cryptography ___test; 
    ___test.run_test(); 
    boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
    cout << endl << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
} 
// END CUT HERE
