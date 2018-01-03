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
typedef vector<string> vs;
struct MarbleNecklace
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
        vector<string> A0;
        vector<string> A1;
        { /* Test 0 */ string necklace = 
        "CDAB"
        ; A0.push_back( necklace ); string result = 
        "ABCD"
        ; A1.push_back( result ); }
        { /* Test 1 */ string necklace = 
        "RGB"
        ; A0.push_back( necklace ); string result = 
        "BGR"
        ; A1.push_back( result ); }
        { /* Test 2 */ string necklace = 
        "TOPCODER"
        ; A0.push_back( necklace ); string result = 
        "CODERTOP"
        ; A1.push_back( result ); }
        { /* Test 3 */ string necklace = 
        "SONBZELGFEQMSULZCNPJODOWPEWLHJFOEW"
        ; A0.push_back( necklace ); string result = 
        "BNOSWEOFJHLWEPWODOJPNCZLUSMQEFGLEZ"
        ; A1.push_back( result ); }
        for (int i = 0; i < A0.size(); ++i)
            if (Case == -1 || i == Case)
            {
                boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
                verify_case( i, A1[i], normalize( A0[i]) );
                boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
                cout << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
            }
    }
// END CUT HERE
    string normalize( string necklace )
    {
        vs results;
        string s( necklace );
        for (int i = 0; i < necklace.size(); ++i)
        {
            string t( s );
            reverse( t.begin(), t.end() );
            results.push_back( s );
            results.push_back( t );
            rotate( s.begin(), s.begin() + 1, s.end() );
        }
        return *min_element(results.begin(), results.end());
    }
};
// BEGIN CUT HERE
int main()
{
    boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
    MarbleNecklace ___test; 
    ___test.run_test(); 
    boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
    cout << endl << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
} 
// END CUT HERE
