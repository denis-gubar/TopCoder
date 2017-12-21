#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
#define all(v) (v).begin(), (v).end()
struct NinePatch
{
	int numBlocks( vector <int> length, vector <int> width )
	{
		transform( all(length), length.begin(), bind2nd( divides<int>(), 2 ) );
		transform( all(width), width.begin(), bind2nd( divides<int>(), 2 ) );
		return inner_product( all(length), width.begin(), 0 ) / 9;
	}
	
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
