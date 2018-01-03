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
struct PrimePalindromic
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
        { /* Test 0 */ int A = 
        2260
        ; A0.push_back( A ); int B = 
        2262
        ; A1.push_back( B ); int result = 
        1
        ; A2.push_back( result ); }
        { /* Test 1 */ int A = 
        2
        ; A0.push_back( A ); int B = 
        9
        ; A1.push_back( B ); int result = 
        7
        ; A2.push_back( result ); }
        { /* Test 2 */ int A = 
        2
        ; A0.push_back( A ); int B = 
        100
        ; A1.push_back( B ); int result = 
        36
        ; A2.push_back( result ); }
        for (int i = 0; i < A0.size(); ++i)
            if (Case == -1 || i == Case)
            {
                boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
                verify_case( i, A2[i], count( A0[i], A1[i]) );
                boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
                cout << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
            }
    }
// END CUT HERE
    vi get_primes( int N )
    {
        vector<char> isPrime( N + 1, 1 );
        isPrime[1] = isPrime[0] = 0;
        for (int i = 4; i <= N; i += 2)
            isPrime[i] = 0;
        for (int i = 3; i * i <= N; i += 2)
            if (isPrime[i])
                for (int k = 3 * i; k <= N; k += 2 * i)
                    isPrime[k] = 0;
        vi result;
        for (int i = 0; i <= N; ++i)
            if (isPrime[i])
                result.push_back( i );
        return result;
    }
    bool check( int x, const vi& primes )
    {
        vi divs;
        while (x > 1)
        {
            for(int i = 0; primes[i] <= x; ++i)
                while (x % primes[i] == 0)
                {
                    divs.push_back( primes[i] );
                    x /= primes[i];
                }
        }
        do
        {
            string s;
            for (const auto& d : divs)
                s += to_string( d );
            string t( s );
            reverse( t.begin(), t.end() );
            if (t == s)
                return true;
        } while (next_permutation( divs.begin(), divs.end() ));
        return false;
    }
    int count( int A, int B )
    {
        int result{};
        vi primes = get_primes( 20000 );
        for (int i = A; i <= B; ++i)
            result += check( i, primes );
        return result;
    }
};
// BEGIN CUT HERE
int main()
{
    boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
    PrimePalindromic ___test; 
    ___test.run_test(); 
    boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
    cout << endl << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
} 
// END CUT HERE
