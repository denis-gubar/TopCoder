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
typedef vector<double> vd;
struct CarBuyer
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
        vector<int> A1;
        vector<int> A2;
        vector<int> A3;
        vector<double> A4;
        { /* Test 0 */ vector <string> cars = 
        {"10000 50 50","12000 500 10","15000 100 65","20000 20 80","25000 10 90"}
        ; A0.push_back( cars ); int fuelPrice = 
        2
        ; A1.push_back( fuelPrice ); int annualDistance = 
        5000
        ; A2.push_back( annualDistance ); int years = 
        2
        ; A3.push_back( years ); double result = 
        10500.0
        ; A4.push_back( result ); }
        { /* Test 1 */ vector <string> cars = 
        {"10000 50 50","12000 500 10","15000 100 65","20000 20 80","25000 10 90"}
        ; A0.push_back( cars ); int fuelPrice = 
        8
        ; A1.push_back( fuelPrice ); int annualDistance = 
        25000
        ; A2.push_back( annualDistance ); int years = 
        10
        ; A3.push_back( years ); double result = 
        45200.0
        ; A4.push_back( result ); }
        { /* Test 2 */ vector <string> cars = 
        {"8426 774 19","29709 325 31","30783 853 68","20796 781 3"
,"27726 4 81","20788 369 69","17554 359 34","12039 502 24"
,"6264 230 69","14151 420 65","25115 528 70","22234 719 55"
,"2050 926 40","18618 714 29","173 358 57"}
        ; A0.push_back( cars ); int fuelPrice = 
        33
        ; A1.push_back( fuelPrice ); int annualDistance = 
        8673
        ; A2.push_back( annualDistance ); int years = 
        64
        ; A3.push_back( years ); double result = 
        254122.44444444444
        ; A4.push_back( result ); }
        for (int i = 0; i < A0.size(); ++i)
            if (Case == -1 || i == Case)
            {
                boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
                verify_case( i, A4[i], lowestCost( A0[i], A1[i], A2[i], A3[i]) );
                boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
                cout << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
            }
    }
// END CUT HERE
    double lowestCost( vector <string> cars, int fuelPrice, int annualDistance, int years )
    {        
        vd results;
        for (const auto& car : cars)
        {
            istringstream s( car );
            double purchace_cost, tax, fuel_eff;
            s >> purchace_cost >> tax >> fuel_eff;
            results.push_back( purchace_cost + years * tax + 1.0 * fuelPrice * years * annualDistance / fuel_eff );            
        }
        return *min_element(results.begin(), results.end());
    }
};
// BEGIN CUT HERE
int main()
{
    boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
    CarBuyer ___test; 
    ___test.run_test(); 
    boost::chrono::high_resolution_clock::time_point finish = boost::chrono::high_resolution_clock::now();
    cout << endl << "Elapsed " << boost::chrono::round<boost::chrono::milliseconds>( finish - start ) << endl;
} 
// END CUT HERE
