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
#define fora(i,v) for(unsigned int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct Tothello
{
public:
	vvi M, N;
	int probe( int x, int y )
	{
		if (x < 0 || y < 0 || x > 7 || y > 7) return 0;
		return M[x][y];
	}
	int calc( int color )
	{
		N = vvi(M);
		int result = 0;
		fora(i, M)
		{
			fora(j, M)
			{
				if ( !M[i][j] )
				{
					M = vvi(N);
					queue<pair<int, int> > q;
					q.push( make_pair( i, j ) );
					int total = 0;
					while( !q.empty() )
					{
						int	x = q.front().first, y = q.front().second;
						q.pop();
						for( int dx = -1; dx <= 1; dx++ )
							for( int dy = -1; dy <= 1; dy++ )
								if ( dx || dy )
								{
									int k = 1;
									while( probe(x + dx * k, y + dy * k) == 3 - color ) 
										k++;
									if ( probe(x + dx * k, y + dy * k) == color )
									{
										k--;
										total += k;
										while( k > 0 )
										{
											q.push( make_pair( x + dx * k, y + dy * k ) );
											M[x + dx * k][y + dy * k] = color;
											k--;
										}
									}
								}
					}
					result = max(result, total);
				}
			}
		}		
		return result;
	}
	int bestMove( vs redPieces, vs blackPieces, string whoseTurn )
	{
		M = vvi(8, vi(8, 0));
		int color, result;
		if ( whoseTurn == "Red" )
		{
			color = 1;
			result = redPieces.size() + 1;
		}
		else
		{
			color = 2;
			result = blackPieces.size() + 1;
		}
		fora(i, redPieces)
			M[redPieces[i][0] - 'A'][redPieces[i][1] - '1'] = 1;
		fora(i, blackPieces)
			M[blackPieces[i][0] - 'A'][blackPieces[i][1] - '1'] = 2;
		return result + calc( color );
	}
	// *** WARNING *** No test cases defined for this problem
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Tothello ___test;
	vs r, b;
	r.push_back("A1");
	r.push_back("B8");
	r.push_back("C6");
	r.push_back("C8");
	r.push_back("D8");
	b.push_back("B2");
	b.push_back("C2");
	b.push_back("C3");
	b.push_back("C4");
	b.push_back("C5");
	cout << ___test.bestMove( r, b, "Red" ) << endl;
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
