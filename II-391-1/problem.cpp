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
struct SnowyWinter
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
        { /* Test 0 */ vector <int> startPoints = 
        {17,85,57}
        ; A0.push_back( startPoints ); vector <int> endPoints = 
        {33,86,84}
        ; A1.push_back( endPoints ); int result = 
        44
        ; A2.push_back( result ); }
        { /* Test 1 */ vector <int> startPoints = 
        {45,100,125,10,15,35,30,9}
        ; A0.push_back( startPoints ); vector <int> endPoints = 
        {46,200,175,20,25,45,40,10}
        ; A1.push_back( endPoints ); int result = 
        132
        ; A2.push_back( result ); }
        { /* Test 2 */ vector <int> startPoints = 
        {4387,711,2510,1001,4687,3400,5254,584,284,1423,3755,929,2154,5719,1326,2368,554}
        ; A0.push_back( startPoints ); vector <int> endPoints = 
        {7890,5075,2600,6867,7860,9789,6422,5002,4180,7086,8615,9832,4169,7188,9975,8690,1423}
        ; A1.push_back( endPoints ); int result = 
        9691
        ; A2.push_back( result ); }
        { /* Test 3 */ vector <int> startPoints = 
        {4906,5601,5087,1020,4362,2657,6257,5509,5107,5315,277,6801,2136,2921,5233,5082,497,8250,3956,5720}
        ; A0.push_back( startPoints ); vector <int> endPoints = 
        {4930,9130,9366,2322,4687,4848,8856,6302,5496,5438,829,9053,4233,4119,9781,8034,3956,9939,4908,5928}
        ; A1.push_back( endPoints ); int result = 
        9510
        ; A2.push_back( result ); }
        { /* Test 4 */ vector <int> startPoints = 
        {51,807,943,4313,8319,3644,481,220,2161,448,465,1657,6290,22,6152,647,3185,4474,2168}
        ; A0.push_back( startPoints ); vector <int> endPoints = 
        {1182,912,1832,7754,9557,7980,4144,3194,7129,5535,1172,2043,6437,7252,9508,4745,8313,8020,4017}
        ; A1.push_back( endPoints ); int result = 
        9535
        ; A2.push_back( result ); }
        { /* Test 5 */ vector <int> startPoints = 
        {8786,7391,201,4414,5822,5872,157,1832,7487,7518,2267,1763,3984,3102,7627,4099,524,1543,1022,3060}
        ; A0.push_back( startPoints ); vector <int> endPoints = 
        {9905,7957,3625,6475,9314,9332,4370,8068,8295,8177,7772,2668,7191,8480,9211,4802,2625,1924,9970,4180}
        ; A1.push_back( endPoints ); int result = 
        9813
        ; A2.push_back( result ); }
        for (int i = 0; i < A0.size(); ++i)
            if (Case == -1 || i == Case)
            {
                boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
                verify_case( i, A2[i], snowyHighwayLength( A0[i], A1[i]) );
                boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
                cout << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
            }
    }
// END CUT HERE
    int snowyHighwayLength( vector <int> startPoints, vector <int> endPoints )
    {
        vector<char> M( 10001 );
        for (int i = 0; i < startPoints.size(); ++i)
            for (int k = startPoints[i]; k < endPoints[i]; ++k)
                M[k] = 1;
        return accumulate(M.begin(), M.end(), 0);
    }
};
// BEGIN CUT HERE
int main()
{
    boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
    SnowyWinter ___test; 
    ___test.run_test(); 
    boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
    cout << endl << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
} 
// END CUT HERE
