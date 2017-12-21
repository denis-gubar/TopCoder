#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
using namespace std;
// BEGIN CUT HERE
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<string, int> psi;
typedef vector<psi> vpsi;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct SMBus
{
	int transmitTime( vs messages, vi times )
	{
		int result = 0, n = messages.size();
		vpsi p;
		fora(i, messages)
			p.push_back( make_pair( messages[i], times[i] ) );
		sort( all(p) );
		fora(i, times)
		{
			int speed = 0, initialSpeed = 0, last = n - 1;
			fora(j, p[i].first)
			{
				int newSpeed = 0, t = last;
				for( int k = i; k <= last; ++k )
					if ( p[k].first.size() > j )
					{
						if ( !speed && initialSpeed < p[k].second ) initialSpeed = p[k].second;
						if ( p[k].first[j] == p[i].first[j] && newSpeed < p[k].second ) newSpeed = p[k].second;
						if ( p[k].first[j] != p[i].first[j] ) t = t < k - 1 ? t : k - 1;
					}
				last = t;
				if ( !speed ) speed = initialSpeed;
				result += speed;
				speed = newSpeed;
			}
		}
		return result;
	}
	// BEGIN CUT HERE
	private:
	template <typename T> string print_array( const vector<T>& v ) { ostringstream os; os << "{ "; for( typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it ) os << '\"' << *it << "\","; os << " }"; return os.str(); }
	template<typename T> void verify_case( int Case, const vector<T>& expected, const vector<T>& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: " << print_array( expected ) << endl; cerr << "\tReceived: " << print_array( received ) << endl; } }
	void verify_case( int Case, const long long& expected, const long long& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const double& expected, const double& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const int& expected, const int& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const string& expected, const string& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	public:
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vi> A1; vector<int> A2;
	{ /*Test 0*/string _messages[] = 
	{"123","124","134"}
	; vs messages(_messages, _messages + (sizeof(_messages) / sizeof(_messages[0]))); A0.push_back( messages ); int _times[] = 
	{1,2,3}
	; vi times(_times, _times + (sizeof(_times) / sizeof(_times[0]))); A1.push_back( times ); int result = 
	25
	; A2.push_back( result );  }
	{ /*Test 1*/string _messages[] = 
	{"012", "1234", "1233", "1223", "1123"}
	; vs messages(_messages, _messages + (sizeof(_messages) / sizeof(_messages[0]))); A0.push_back( messages ); int _times[] = 
	{4,1,5,2,9}
	; vi times(_times, _times + (sizeof(_times) / sizeof(_times[0]))); A1.push_back( times ); int result = 
	94
	; A2.push_back( result );  }
	{ /*Test 2*/string _messages[] = 
	{"0002019289019101039663222896280025447",
 "00201873554718989597528841094293294387326",
 "010699029378761", "0110118", "011143279122561420",
 "001046384966198", "00200570375817801109530240012",
 "0003163277589822", "01100240744590150136673219652442108",
 "012033596872642679096489479354", "0121059494098",
 "00001002303019117948961792176", "00216399923558", "02014",
 "00224999120803846121427603894967637446889670369",
 "01101009414735635151893037596051740080475886",
 "0000101211809647472761605153430927981533514",
 "176845042961739039392207791589",
 "02000047506929386333221966659552927385017901842706",
 "021001117450487502127241076595509511",
 "021010776262723557108100899515",
 "0210114830738951774606917781619656",
 "0211798433083855430", "00000005842153604632996228135814",
 "0001000766929248550736138555144997170272757787",
 "0001010247593342056062432721557",
 "01100004828618452515832113396660046634951",
 "0132559984733529872911444204991646138116334788",
 "0224149857349431864906523152249992",
 "00001142929552573133212195441932219",
 "0011090498947092002457447355036811372647896489218",
 "000001275414757476198997466", "00010014",
 "00111025861963467834393486017602553072649743",
 "000102085", "00120882661783539",
 "01100018938145727291185020",
 "01100191373790478446634214244459341793", "0001129060",
 "001111287431066271555393813846448",
 "011010160778408696098486370196313", "0002125146381515395"}
	; vs messages(_messages, _messages + (sizeof(_messages) / sizeof(_messages[0]))); A0.push_back( messages ); int _times[] = 
	{42, 86, 47, 86, 32, 95, 2, 98, 17, 58, 31, 32, 85, 77,
 87, 61, 1, 20, 15, 80, 20, 95, 55, 87, 52, 14, 55, 68,
 2, 66, 67, 3, 28, 97, 100, 67, 65, 20, 28, 77, 93, 64}
	; vi times(_times, _times + (sizeof(_times) / sizeof(_times[0]))); A1.push_back( times ); int result = 
	71048
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], transmitTime( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	SMBus ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
