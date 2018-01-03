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
struct SerialNumbers
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
        vector<vector <string>> A0;
        vector<vector <string>> A1;
        { /* Test 0 */ vector <string> serialNumbers = 
        {"ABCD","145C","A","A910","Z321"}
        ; A0.push_back( serialNumbers ); vector <string> result = 
        {"A", "ABCD", "Z321", "145C", "A910" }
        ; A1.push_back( result ); }
        { /* Test 1 */ vector <string> serialNumbers = 
        {"Z19", "Z20"}
        ; A0.push_back( serialNumbers ); vector <string> result = 
        {"Z20", "Z19" }
        ; A1.push_back( result ); }
        { /* Test 2 */ vector <string> serialNumbers = 
        {"34H2BJS6N","PIM12MD7RCOLWW09","PYF1J14TF","FIPJOTEA5"}
        ; A0.push_back( serialNumbers ); vector <string> result = 
        {"FIPJOTEA5", "PYF1J14TF", "34H2BJS6N", "PIM12MD7RCOLWW09" }
        ; A1.push_back( result ); }
        { /* Test 3 */ vector <string> serialNumbers = 
        {"ABCDE", "BCDEF", "ABCDA", "BAAAA", "ACAAA"}
        ; A0.push_back( serialNumbers ); vector <string> result = 
        {"ABCDA", "ABCDE", "ACAAA", "BAAAA", "BCDEF" }
        ; A1.push_back( result ); }
        for (int i = 0; i < A0.size(); ++i)
            if (Case == -1 || i == Case)
            {
                boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
                verify_case( i, A1[i], sortSerials( A0[i]) );
                boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
                cout << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
            }
    }
// END CUT HERE
    int sum_of_digits( const string& s )
    {
        int result{};
        for (const auto& x : s)
            if (x >= '0' && x <= '9')
                result += x - '0';
        return result;
    }
    vector <string> sortSerials( vector <string> serialNumbers )
    {
        vector <string> result{serialNumbers};
        sort( result.begin(), result.end(),
              [&]( const string& a, const string& b ) -> bool
              {
                  if (a.size() < b.size())
                      return true;
                  if (a.size() > b.size())
                      return false;
                  int x = sum_of_digits( a ), y = sum_of_digits( b );
                  if (x < y)
                      return true;
                  if (x > y)
                      return false;
                  return a < b;
              }
        );
        return result;
    }
};
// BEGIN CUT HERE
int main()
{
    boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
    SerialNumbers ___test; 
    ___test.run_test(); 
    boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
    cout << endl << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
} 
// END CUT HERE
