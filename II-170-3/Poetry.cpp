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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define forad(i,v) for(int i = (v).size() - 1; i >= 0; i--)
#define all(v) (v).begin(), (v).end()
string replace_all( string s, string oldValue, string newValue )
{
	string result; int j = 0;
	for( int i = s.find( oldValue ); i > -1; i = s.find( oldValue, i + oldValue.size() ) )
	{
		result += s.substr( j, i - j ) + newValue;
		j = i + oldValue.size();
	}
	result.append( s.substr( j ) );
	return result;
}
template<typename Predicate> vs parse( string s, Predicate predicate, bool skipEmpty = true )
{
	vs result; bool isWord = false; int j = 0;
	for( int i = 0; i < s.size(); i++ )
		if ( isWord )
		{
			if ( !predicate( s[i] ) )
			{
				result.push_back( s.substr( j, i - j ) ); isWord = false;
			}
		}
		else
		{
			if ( predicate( s[i] ) )
			{
				j = i; isWord = true;
			} else if ( !skipEmpty )
				result.push_back( "" );
		}
		if ( isWord )
			result.push_back( s.substr( j ) );
		else if ( !skipEmpty && !s.empty() )
			result.push_back( "" );
		return result;
}
struct split_helper: unary_function<int, bool>
{
	explicit split_helper( string delimeter ): delimeter(delimeter) {};
	bool operator() ( int c ) const
	{
		return delimeter.find( c ) == string::npos;
	}
private: string delimeter;
};
vs split( const string& s, const string& delimeter = " ", bool skipEmpty = true )
{
	return parse( s, split_helper( delimeter ), skipEmpty );
}
struct Poetry
{
	string rhymeScheme( vs poem )
	{
		string result, vowels("aeiouy");
		int n = poem.size(), count = -1;
		vs words(n); vi A(n, -1);
		fora(i, poem)
		{
			string s = poem[i];
			transform( all(s), s.begin(), ::tolower );
			s = replace_all( replace_all( " " + s + " ", " y", " +" ), "y ", "+ " );
			vs z = split( s );
			forad(j, z)
				if ( vowels.find_first_of( z[j] ) != string::npos )
				{
					int k = z[j].size() - 1;
					while( vowels.find( z[j][k] ) == string::npos )
						--k;
					while( vowels.find( z[j][k] ) != string::npos )
						--k;
					++k;
					words[i] = z[j].substr( k );
					break;
				}
		}
		fora(i, A)
			if ( !words[i].empty() )
			{
				bool flag = false;
				for( int j = 0; j < i; ++j )
					if ( words[i] == words[j] )
					{
						A[i] = A[j]; flag = true; break;
					}
				if ( !flag )
					A[i] = ++count;
			}
		fora(i, A)
			if ( A[i] == -1 )
				result += ' ';
			else if ( A[i] < 26 )
				result += 'a' + A[i];
			else
				result += 'A' + A[i] - 26;
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<string> A1;
	{ /*Test 0*/string _poem[] = 
	{"I hope this problem",
 "is a whole lot better than",
 "this stupid haiku"}
	; vs poem(_poem, _poem + (sizeof(_poem) / sizeof(_poem[0]))); A0.push_back( poem ); string result = 
	"abc"
	; A1.push_back( result );  }
	{ /*Test 1*/string _poem[] = 
	{"     ",
 "Measure your height",
 "AND WEIGHT      ",
 "said the doctor",
 "",
 "And make sure to take your pills",
 "   to   cure   your    ills",
 "Every",
 "DAY"}
	; vs poem(_poem, _poem + (sizeof(_poem) / sizeof(_poem[0]))); A0.push_back( poem ); string result = 
	" aab ccde"
	; A1.push_back( result );  }
	{ /*Test 2*/string _poem[] = 
	{"One bright day in the middle of the night",
 "Two dead boys got up to fight",
 "Back to back they faced each other",
 "Drew their swords and shot each other",
 "",
 "A deaf policeman heard the noise",
 "And came to arrest the two dead boys",
 "And if you dont believe this lie is true",
 "Ask the blind man he saw it too"}
	; vs poem(_poem, _poem + (sizeof(_poem) / sizeof(_poem[0]))); A0.push_back( poem ); string result = 
	"aabb cdef"
	; A1.push_back( result );  }
	{ /*Test 3*/string _poem[] = 
	{"",
 "",
 "",
 ""}
	; vs poem(_poem, _poem + (sizeof(_poem) / sizeof(_poem[0]))); A0.push_back( poem ); string result = 
	"    "
	; A1.push_back( result );  }
	{ /*Test 4*/string _poem[] = 
	{"This poem has uppercase letters",
 "In its rhyme scheme",
 "Alpha", "Blaster", "Cat", "Desert", "Elephant", "Frog", "Gulch", 
 "Horse", "Ireland", "Jam", "Krispy Kreme", "Loofah", "Moo", "Narf",
 "Old", "Pink", "Quash", "Rainbow", "Star", "Tour", "Uvula", "Very",
 "Will", "Xmas", "Young", "Zed", "deception", "comic", "grout",
 "oval", "cable", "rob", "steal", "steel", "weak"}
	; vs poem(_poem, _poem + (sizeof(_poem) / sizeof(_poem[0]))); A0.push_back( poem ); string result = 
	"abcdefghibjkblmnopqrstcuvwxyzABCbDEFG"
	; A1.push_back( result );  }
	{ /*Test 5*/string _poem[] = 
	{" ",
 "     ",
 "This poem",
 "         ",
 " ",
 " ",
 "",
 "Has lots of blank lines",
 " ",
 "      ",
 "                                            ",
 "         ",
 " ",
 "              ",
 "                                                  ",
 "  in      it           "}
	; vs poem(_poem, _poem + (sizeof(_poem) / sizeof(_poem[0]))); A0.push_back( poem ); string result = 
	"  a    b       c"
	; A1.push_back( result );  }
	{ /*Test 6*/string _poem[] = 
	{"too bad   your",
 "     solution went   sour"}
	; vs poem(_poem, _poem + (sizeof(_poem) / sizeof(_poem[0]))); A0.push_back( poem ); string result = 
	"aa"
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], rhymeScheme( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Poetry ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
