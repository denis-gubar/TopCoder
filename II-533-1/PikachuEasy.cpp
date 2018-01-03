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
struct PikachuEasy
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
        { /* Test 0 */ string word = 
        "pikapi"
        ; A0.push_back( word ); string result = 
        "YES"
        ; A1.push_back( result ); }
        { /* Test 1 */ string word = 
        "pipikachu"
        ; A0.push_back( word ); string result = 
        "YES"
        ; A1.push_back( result ); }
        { /* Test 2 */ string word = 
        "pikaqiu"
        ; A0.push_back( word ); string result = 
        "NO"
        ; A1.push_back( result ); }
        { /* Test 3 */ string word = 
        "topcoder"
        ; A0.push_back( word ); string result = 
        "NO"
        ; A1.push_back( result ); }
        { /* Test 4 */ string word = 
        "piika"
        ; A0.push_back( word ); string result = 
        "NO"
        ; A1.push_back( result ); }
        { /* Test 5 */ string word = 
        "chupikachupipichu"
        ; A0.push_back( word ); string result = 
        "YES"
        ; A1.push_back( result ); }
        { /* Test 6 */ string word = 
        "pikapipachu"
        ; A0.push_back( word ); string result = 
        "NO"
        ; A1.push_back( result ); }
        for (int i = 0; i < A0.size(); ++i)
            if (Case == -1 || i == Case)
            {
                boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
                verify_case( i, A1[i], check( A0[i]) );
                boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
                cout << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
            }
    }
// END CUT HERE
    string check( string word )
    {
        string result{};
        for (int i = 0; i < word.size(); )
        {
            if (word.substr( i, 2 ) == "pi" || word.substr( i, 2 ) == "ka")
                i += 2;
            else if (word.substr( i, 3 ) == "chu" )
                i += 3;
            else
                return "NO";
        }
        return "YES";
    }
};
// BEGIN CUT HERE
int main()
{
    boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
    PikachuEasy ___test; 
    ___test.run_test(); 
    boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
    cout << endl << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
} 
// END CUT HERE
