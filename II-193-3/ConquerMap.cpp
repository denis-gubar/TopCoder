#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#ifdef __GNUC__
#else
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
template<typename T>
void print( T collection, char* separator = "\n" )
{
	copy( collection.begin(), collection.end(), ostream_iterator<T::value_type>( cout, separator ) );
	cout << endl;
}
// END CUT HERE 
#endif
typedef vector<int> vi;
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
int ToInt( string a )
{
	int result;
	istringstream S( a );
	S >> result;
	return result;
}
vs Split( string s, string c = " " )
{
	vs result;
	string t = "";
	fora(i, s)
		if ( c.find( s[i] ) != -1 )
		{
			result.push_back( t );
			t = "";
		}
		else
			t += s[i];
	result.push_back( t );
	return result;
}
vi SplitInt( string s, string c = " " )
{
	vs temp = Split( s, c );
	vi result( temp.size() );
	transform( temp.begin(), temp.end(), result.begin(), ToInt );
	return result;
}
vi t;
bool comp( int a, int b )
{
	return t[a] > t[b] || t[a] == t[b] && a < b;
}
struct ConquerMap
{
public:
	vs result;
	int probe( int x, int y )
	{
		if ( x >= 0 && y >= 0 && x < result.size() && y < result[0].size() ) return result[x][y] - '0';
		return -2;
	}
	vector <string> getMap( int rows, int cols, vector <string> times, int endTime )
	{
		result = vs(rows, string(cols, '.'));
		vi x, y; t = vi();
		fora(i, times)
		{
			vi M = SplitInt( times[i] );
			x.push_back( M[0] );
			y.push_back( M[1] );
			t.push_back( M[2] );
		}
		for( int time = 0; time <= endTime; time++ )
		{
			vs next = result;
			fora(i, result)
				fora(j, result[i])
				{
					set<int> H;
					for( int di = i - 1; di <= i + 1; di++ )
						for( int dj = j - 1; dj <= j + 1; dj++ )
							if ( abs(di - i) + abs(dj - j) <= 1 && probe(di, dj) >= 0 )
								H.insert( probe(di, dj) );
					if ( !H.empty() )
					{
						vi M( all(H) );
						sort( all(M), comp );
						next[i][j] = M[0] + '0';
					}
				}
			result = next;
			fora(i, t)
				if ( t[i] == time ) result[x[i]][y[i]] = i + '0';
		}
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 10; string Arr2[] = {"0 0 0","2 2 0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; string Arr4[] = { "00........",  "0.1.......",  ".111......",  "..1.......",  "..........",  "..........",  "..........",  "..........",  "..........",  ".........." }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, getMap(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 10; string Arr2[] = {"0 0 0","2 2 0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; string Arr4[] = { "000.......",  "0011......",  "01111.....",  ".111......",  "..1.......",  "..........",  "..........",  "..........",  "..........",  ".........." }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, getMap(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 21; int Arg1 = 21; string Arr2[] = {"5 5 0","5 5 3","17 17 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; string Arr4[] = { "00011111000..........",  "001111111000.........",  "0111111111000........",  "11111111111000.......",  "111111111111000......",  "1111111111111000.....",  "111111111111000......",  "11111111111000.......",  "0111111111000........",  "001111111000.........",  "00011111000..........",  ".000111000.......2...",  "..0001000.......222..",  "...00000.......22222.",  "....000.......2222222",  ".....0.......22222222",  "............222222222",  "...........2222222222",  "............222222222",  ".............22222222",  "..............2222222" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, getMap(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 21; int Arg1 = 21; string Arr2[] = {"0 20 0","20 20 0","0 0 0","20 0 0","5 5 60"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; string Arr4[] = { "222222220000000000000",  "222222222000000000000",  "222222222200000000000",  "2222222222.0000000000",  "222222222...000000000",  "22222222.....00000000",  "2222222.......0000000",  "222222.........000000",  "22222...........00000",  "2222.............0000",  "222...............000",  "2233.............1100",  "23333...........11110",  "333333.........111111",  "3333333.......1111111",  "33333333.....11111111",  "333333333...111111111",  "3333333333.1111111111",  "333333333311111111111",  "333333333111111111111",  "333333331111111111111" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, getMap(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"0 0 0","0 0 1","0 0 2","0 0 3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 100; string Arr4[] = { "33",  "33" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, getMap(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 21; int Arg1 = 21; string Arr2[] = {"0 0 1","10 0 2","20 0 3","0 10 2","10 10 2","0 20 3",
 "10 20 4","20 10 4","20 20 5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; string Arr4[] = { "000003333333333355555",  "000000333333333..5555",  "00000..3333333....555",  "0000....33333......55",  "000......333........5",  "10........3..........",  "11.......444.........",  "111.....44444.......6",  "1111...4444444.....66",  "11111.444444444...666",  "1111114444444444.6666",  "11111.444444444...666",  "1111...4444444.....66",  "111.....44444.......6",  "11.......444.........",  "1.........4..........",  "2....................",  "22........7..........",  "222......777........8",  "2222....77777......88",  "22222..7777777....888" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(5, Arg4, getMap(Arg0, Arg1, Arg2, Arg3)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ConquerMap ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
