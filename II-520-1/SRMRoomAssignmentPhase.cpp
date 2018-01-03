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
struct SRMRoomAssignmentPhase
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
        { /* Test 0 */ vector <int> ratings = 
        {491, 981, 1199, 763, 994, 879, 888}
        ; A0.push_back( ratings ); int K = 
        3
        ; A1.push_back( K ); int result = 
        2
        ; A2.push_back( result ); }
        { /* Test 1 */ vector <int> ratings = 
        {1024, 1000, 600}
        ; A0.push_back( ratings ); int K = 
        1
        ; A1.push_back( K ); int result = 
        0
        ; A2.push_back( result ); }
        { /* Test 2 */ vector <int> ratings = 
        {505, 679, 900, 1022}
        ; A0.push_back( ratings ); int K = 
        2
        ; A1.push_back( K ); int result = 
        1
        ; A2.push_back( result ); }
        { /* Test 3 */ vector <int> ratings = 
        {716, 58, 1000, 1004, 912, 822, 453, 1100, 558}
        ; A0.push_back( ratings ); int K = 
        3
        ; A1.push_back( K ); int result = 
        1
        ; A2.push_back( result ); }
        { /* Test 4 */ vector <int> ratings = 
        {422, 623, 1023, 941, 882, 776, 852, 495, 803, 622, 618, 532, 751, 500}
        ; A0.push_back( ratings ); int K = 
        4
        ; A1.push_back( K ); int result = 
        3
        ; A2.push_back( result ); }
        { /* Test 5 */ vector <int> ratings = 
        {1197, 1198, 1196, 1195, 1199}
        ; A0.push_back( ratings ); int K = 
        1
        ; A1.push_back( K ); int result = 
        2
        ; A2.push_back( result ); }
        for (int i = 0; i < A0.size(); ++i)
            if (Case == -1 || i == Case)
            {
                boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
                verify_case( i, A2[i], countCompetitors( A0[i], A1[i]) );
                boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
                cout << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
            }
    }
// END CUT HERE
    int countCompetitors( vector <int> ratings, int K )
    {
        int my = ratings[0];
        sort( ratings.begin(), ratings.end(), greater<int>() );
        vvi rooms(K);
        int t = 0, r = 0;
        while (ratings[t] > my)
        {
            ++t;
            rooms[r].push_back( ratings[t] );
            r = (r + 1) % K;
        }
        return rooms[r].size();
    }
};
// BEGIN CUT HERE
int main()
{
    boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
    SRMRoomAssignmentPhase ___test; 
    ___test.run_test(); 
    boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
    cout << endl << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
} 
// END CUT HERE
