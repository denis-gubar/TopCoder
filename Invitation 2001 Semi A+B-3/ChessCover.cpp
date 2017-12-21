#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
using namespace std;
#ifdef __GNUC__
typedef long long lint;
typedef unsigned long long ulint;
#else
typedef __int64 lint;
typedef unsigned __int64 ulint;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
template <typename T>
void print( T collection, char* separator = "\n" )
{
	copy( collection.begin(), collection.end(), ostream_iterator<T::value_type>( cout, separator ) );
	cout << endl;
}
// END CUT HERE 
#endif
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<vector<string> > vvs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct ChessCover
{
public:
	vvi M;
	bool probe( int x, int y, vs boardLayout )
	{
		if ( x < 0 || y < 0 || 
			x == boardLayout.size() || y == boardLayout[0].size() || 
			boardLayout[x][y] != 'U' ) return false;
		M[x][y] = 1;
		return true;
	}	
	int getSafe(vs boardLayout)
	{
		int result = 0;
		M = vvi(boardLayout.size(), vi(boardLayout[0].size(), 0));
		fora(i, M)
		{
			fora(j, M[i])
			{
				switch( boardLayout[i][j] )
				{
					case 'P':
						probe(i - 1, j - 1, boardLayout);
                        probe(i - 1, j + 1, boardLayout);
						probe(i + 1, j - 1, boardLayout);
						probe(i + 1, j + 1, boardLayout);
						break;
					case 'K':
						for( int dx = i - 2; dx <= i + 2; dx++ )
							for( int dy = j - 2; dy <= j + 2; dy++ )
								if ( abs(dx - i) + abs(dy - j) == 3 )
									probe(dx, dy, boardLayout);
						break;
					case 'Q':
						for( int dx = -1; dx <= 1; dx++ )
							for( int dy = -1; dy <= 1; dy++ )
							{
								bool flag = true;
								for( int k = 1; flag && k < 10; k++ )
									flag = probe(i + dx * k, j + dy * k, boardLayout);
							}
						break;
					case 'B':
						for( int dx = -1; dx <= 1; dx++ )
							for( int dy = -1; dy <= 1; dy++ )
								if ( abs(dx) + abs(dy) == 2 )
								{
									bool flag = true;
									for( int k = 1; flag && k < 10; k++ )
										flag = probe(i + dx * k, j + dy * k, boardLayout);
								}
						break;
					case 'R':
						for( int dx = -1; dx <= 1; dx++ )
							for( int dy = -1; dy <= 1; dy++ )
								if ( abs(dx) + abs(dy) == 1 )
								{
									bool flag = true;
									for( int k = 1; flag && k < 10; k++ )
										flag = probe(i + dx * k, j + dy * k, boardLayout);
								}
						break;
				}
			}
		}
		fora(i, M)
			fora(j, M[i])
				if ( !M[i][j] && boardLayout[i][j] == 'U' ) result++;
		return result;
	}
	// *** WARNING *** No test cases defined for this problem
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ChessCover ___test;
	vs x;
	x.push_back("UBUKUUUBUU");
	x.push_back("UUUUBUUQUR");
	cout << ___test.getSafe( x ) << endl;
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
