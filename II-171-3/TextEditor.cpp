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
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct TextEditor
{
	vs twoColumn( vs text, int width )
	{
		vs result, words, z;
		fora(i, text)
		{
			istringstream s( text[i] );
			copy( istream_iterator<string>( s ), istream_iterator<string>(), back_inserter( words ) );
		}
		int length = 0; string s;
		fora(i, words)
		{
			if ( length + !s.empty() + words[i].size() <= width )
			{
				length += !s.empty() + words[i].size();
				s += (s.empty() ? string() : string(" ")) + words[i];
			}
			else
			{
				z.push_back( s );
				length = words[i].size();
				s = words[i];
			}
		}
		if ( !s.empty() )
			z.push_back( s );
		result = vs(z.size());
		for( int i = 0; i < (z.size() + 1) / 2; ++i )
			result[i * 2] = z[i];
		for( int i = 0; i < z.size() / 2; ++i )
			result[i * 2 + 1] = z[i + (z.size() + 1) / 2];
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<int> A1; vector<vs> A2;
	{ /*Test 0*/string _text[] = 
	{"The quick brown fox jumps over the lazy dog. "}
	; vs text(_text, _text + (sizeof(_text) / sizeof(_text[0]))); A0.push_back( text ); int width = 
	7
	; A1.push_back( width ); string _result[] = 
	{ "The",  "over",  "quick",  "the",  "brown",  "lazy",  "fox",  "dog.",  "jumps" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 1*/string _text[] = 
	{"Such a preposterous use of !punctuation! !!!","Who would write ... something like this ???"}
	; vs text(_text, _text + (sizeof(_text) / sizeof(_text[0]))); A0.push_back( text ); int width = 
	17
	; A1.push_back( width ); string _result[] = 
	{ "Such a",  "write ...",  "preposterous use",  "something like",  "of !punctuation!",  "this ???",  "!!! Who would" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 2*/string _text[] = 
	{" Forsaking monastic tradition,    twelve jovial",
"  friars gave up their vocation for a questionable",
"     existence on the flying trapeze.    "}
	; vs text(_text, _text + (sizeof(_text) / sizeof(_text[0]))); A0.push_back( text ); int width = 
	25
	; A1.push_back( width ); string _result[] = 
	{ "Forsaking monastic",  "vocation for a",  "tradition, twelve jovial",  "questionable existence on",  "friars gave up their",  "the flying trapeze." }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 3*/string _text[] = 
	{" "," "," "," "," "," "}
	; vs text(_text, _text + (sizeof(_text) / sizeof(_text[0]))); A0.push_back( text ); int width = 
	7
	; A1.push_back( width ); vs result; A2.push_back( result );  }
	{ /*Test 4*/string _text[] = 
	{" I WONDER by my troth, what thou,",
"and I Did, till we lovd? were we",
"not weand till then? But suckd on",
"countrey pleasures, childishly? Or",
"snorted we in the seaven sleepers",
"den? Twas so; But this, all",
"pleasures fancies bee. If ever any",
"beauty I did see, Which I desird,",
"and got, twas but a dreame of",
"thee. And now good morrow to our",
"waking soules, Which watch not one",
"another out of feare; For love, all",
"love of other sights controules,",
"And makes one little roome, an",
"every where. Let seadiscoverers to",
"new worlds have gone, Let Maps to",
"other, worlds on worlds have",
"showne, Let us possesse one world,",
"each hath one, and is one. My face",
"in thine eye, thine in mine",
"appeares, And true plaine hearts",
"doe in the faces rest, Where can we",
"finde two better hemispheares",
"Without sharpe North, without",
"declining West? What ever dyes, was",
"not mixt equally; If our two loves",
"be one, or, thou and I Love so",
"alike, that none doe slacken, none",
"can die.",
"John Donne"}
	; vs text(_text, _text + (sizeof(_text) / sizeof(_text[0]))); A0.push_back( text ); int width = 
	45
	; A1.push_back( width ); string _result[] = 
	{ "I WONDER by my troth, what thou, and I Did,",  "seadiscoverers to new worlds have gone, Let",  "till we lovd? were we not weand till then?",  "Maps to other, worlds on worlds have showne,",  "But suckd on countrey pleasures, childishly?",  "Let us possesse one world, each hath one, and",  "Or snorted we in the seaven sleepers den?",  "is one. My face in thine eye, thine in mine",  "Twas so; But this, all pleasures fancies bee.",  "appeares, And true plaine hearts doe in the",  "If ever any beauty I did see, Which I desird,",  "faces rest, Where can we finde two better",  "and got, twas but a dreame of thee. And now",  "hemispheares Without sharpe North, without",  "good morrow to our waking soules, Which watch",  "declining West? What ever dyes, was not mixt",  "not one another out of feare; For love, all",  "equally; If our two loves be one, or, thou",  "love of other sights controules, And makes",  "and I Love so alike, that none doe slacken,",  "one little roome, an every where. Let",  "none can die. John Donne" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], twoColumn( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	TextEditor ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
