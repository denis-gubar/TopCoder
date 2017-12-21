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
typedef long long lint;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
template<typename T> string ToString( T x )
{
	ostringstream S; S << x; return S.str();
}
vs split( string s, string delimeters = " ", bool skipEmpty = true )
{
	vs result; s += delimeters[0];
	for( int i = 0, prev = 0; i < s.size(); i++ )
		if ( delimeters.find( s[i] ) != -1 )
		{
			if ( !skipEmpty || prev < i )
				result.push_back( s.substr( prev, i - prev ) );
			prev = i + 1;
		}
	return result;
}
vpii parseWords( string s, pointer_to_unary_function<int, int> predicate = ptr_fun(::isalpha) )
{
	vpii result; s += ' '; bool isWord = false;
	for( int i = 0, j; i < s.size(); i++ )
		switch ( isWord )
		{
			case true:
				if ( !predicate( s[i] ) )
				{
					result.push_back( make_pair(j, i) ); isWord = false;
				}
				break;
			case false:
				if ( predicate( s[i] ) )
				{
					j = i; isWord = true;
				}
				break;
		}
	return result;
}
struct bloggoSequenceSearch
{
	struct Data
	{
		int doc; pii interval;
		Data( int doc, pii interval ): doc(doc), interval(interval) {}
		int length()
		{
			return interval.second - interval.first;
		}
	};
	struct comp: binary_function<Data, Data, bool>
	{
		bool operator() ( Data a, Data b ) const
		{
			if ( a.length() != b.length() ) return a.length() < b.length();
			if ( a.doc != b.doc ) return a.doc < b.doc;
			return a.interval.first < b.interval.first;
		}
	};
	vs findPassages( vs documents, string query )
	{
		vs result;
		transform( all(query), query.begin(), ::tolower );
		vs Q = split( query, "." ); int n = Q.size();
		vector<Data> captures;
		fora(i, documents)
		{
			string s = documents[i];
			transform( all(s), s.begin(), ::tolower );
			vpii w = parseWords( s ); vs words;
			fora(j, w)
				words.push_back( s.substr( w[j].first, w[j].second - w[j].first ) );
			for( vs::iterator it1 = find( all(words), Q[0] ); it1 != words.end(); it1 = find( it1 + 1, words.end(), Q[0] ) )
			{
				if ( n == 1 )
				{
					captures.push_back( Data(i, w[distance( words.begin(), it1 )] ) ); continue;
				}
				bool flag = true;
				vs::iterator it2 = it1 + 1;
				for( int k = 1; k < n - 1; k++ )
				{
					it2 = find( it2, words.end(), Q[k] );
					if ( it2 == words.end() )
					{
						flag = false; break;
					}
					++it2;
				}
				if ( !flag ) break;
				for( vs::iterator it3 = find( it2, words.end(), Q[n - 1] ); it3 != words.end(); it3 = find( it3 + 1, words.end(), Q[n - 1] ) )
					captures.push_back( Data(i, make_pair(w[distance( words.begin(), it1 )].first, w[distance( words.begin(), it3 )].second) ) );
			}
		}
		sort( all(captures), comp() );
		for( int i = 0; i < 5 && i < captures.size(); i++ )
			result.push_back( ToString(captures[i].doc) + " " + ToString(captures[i].interval.first) + " [" +
				documents[captures[i].doc].substr( captures[i].interval.first, captures[i].interval.second - captures[i].interval.first ) + "]" );
		return result;
	}
// BEGIN CUT HERE
	private:
	template <typename T> string print_array( const vector<T>& v ) { ostringstream os; os << "{ "; for( typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it ) os << '\"' << *it << "\","; os << " }"; return os.str(); }
	template<typename T> void verify_case( int Case, const vector<T>& expected, const vector<T>& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: " << print_array( expected ) << endl; cerr << "\tReceived: " << print_array( received ) << endl; } }
	void verify_case( int Case, const lint& expected, const lint& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const double& expected, const double& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const int& expected, const int& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const string& expected, const string& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	public:
	void run_test( int Case = -1 ) { vector<vs> A0; vector<string> A1; vector<vs> A2;
	{ /*Test 0*/string _Arg0[] = 
	{"But in a larger sense we can not dedicate --",
 "we can not consecrate -- we can not hallow this",
 "ground. The brave men, living and dead, who",
 "struggled, here, have consecrated it far above",
 "our poor power to add or detract. The world will",
 "little note, nor long remember, what we say here,", 
 "but can never forget what they did here. It is",
 "for us, the living, rather to be dedicated here",
 "to the unfinished work which they have, thus",
 "far, so nobly carried on. It is rather for us",
 "to be here dedicated to the great task remaining", 
 "before us -- that from these honored dead we take",
 "increased devotion to that cause for which they",
 "here gave the last full measure of devotion --",
 "that we here highly resolve that these dead",
 "shall not have died in vain; that this nation",
 "shall have a new birth of freedom; and that",
 "this government of the people, by the people,", 
 "for the people, shall not perish from the earth."}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string Arg1 = 
	"the...People"
	; A1.push_back( Arg1 ); string _Arg2[] = 
	{ "17 19 [the people]",  "17 34 [the people]",  "18 4 [the people]",  "17 19 [the people, by the people]" }
	; vs Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 );  }
	{ /*Test 1*/string _Arg0[] = 
	{"But in a larger sense we can not dedicate --",
 "we can not consecrate -- we can not hallow this",
 "ground. The brave men, living and dead, who",
 "struggled, here, have consecrated it far above",
 "our poor power to add or detract. The world will",
 "little note, nor long remember, what we say here,", 
 "but can never forget what they did here. It is",
 "for us, the living, rather to be dedicated here",
 "to the unfinished work which they have, thus",
 "far, so nobly carried on. It is rather for us",
 "to be here dedicated to the great task remaining", 
 "before us -- that from these honored dead we take",
 "increased devotion to that cause for which they",
 "here gave the last full measure of devotion --",
 "that we here highly resolve that these dead",
 "shall not have died in vain; that this nation",
 "shall have a new birth of freedom; and that",
 "this government of the people, by the people,", 
 "for the people, shall not perish from the earth."}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string Arg1 = 
	"Shall...The"
	; A1.push_back( Arg1 ); string _Arg2[] = 
	{ "18 16 [shall not perish from the]" }
	; vs Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 );  }
	{ /*Test 2*/string _Arg0[] = 
	{"But in a larger sense we can not dedicate --",
 "we can not consecrate -- we can not hallow this",
 "ground. The brave men, living and dead, who",
 "struggled, here, have consecrated it far above",
 "our poor power to add or detract. The world will",
 "little note, nor long remember, what we say here,", 
 "but can never forget what they did here. It is",
 "for us, the living, rather to be dedicated here",
 "to the unfinished work which they have, thus",
 "far, so nobly carried on. It is rather for us",
 "to be here dedicated to the great task remaining", 
 "before us -- that from these honored dead we take",
 "increased devotion to that cause for which they",
 "here gave the last full measure of devotion --",
 "that we here highly resolve that these dead",
 "shall not have died in vain; that this nation",
 "shall have a new birth of freedom; and that",
 "this government of the people, by the people,", 
 "for the people, shall not perish from the earth."}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string Arg1 = 
	"wE...nOT"
	; A1.push_back( Arg1 ); string _Arg2[] = 
	{ "0 22 [we can not]",  "1 0 [we can not]",  "1 25 [we can not]",  "1 0 [we can not consecrate -- we can not]" }
	; vs Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 );  }
	{ /*Test 3*/string _Arg0[] = 
	{"But in a larger sense we can not dedicate --",
 "we can not consecrate -- we can not hallow this",
 "ground. The brave men, living and dead, who",
 "struggled, here, have consecrated it far above",
 "our poor power to add or detract. The world will",
 "little note, nor long remember, what we say here,", 
 "but can never forget what they did here. It is",
 "for us, the living, rather to be dedicated here",
 "to the unfinished work which they have, thus",
 "far, so nobly carried on. It is rather for us",
 "to be here dedicated to the great task remaining", 
 "before us -- that from these honored dead we take",
 "increased devotion to that cause for which they",
 "here gave the last full measure of devotion --",
 "that we here highly resolve that these dead",
 "shall not have died in vain; that this nation",
 "shall have a new birth of freedom; and that",
 "this government of the people, by the people,", 
 "for the people, shall not perish from the earth."}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string Arg1 = 
	"we...can...not"
	; A1.push_back( Arg1 ); string _Arg2[] = 
	{ "0 22 [we can not]",  "1 0 [we can not]",  "1 25 [we can not]",  "1 0 [we can not consecrate -- we can not]" }
	; vs Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 );  }
	{ /*Test 4*/string _Arg0[] = 
	{"B A b B B A b a A B b b b a a a B a A b a B B b b ",
 "A B b b A a A b A A a b b A A a A a A b A a A B b ",
 "B B a A a a A A A b A b b a a B B b a A a A b a A ",
 "a b b b b A B a A A A A a b A b A A B a A b b a A ",
 "A b a A b B B a b A A A A B A A B a A B a b b b B ",
 "A A A b b a a a A b b b a A A b a B a a B b B a b ",
 "B A B A a b A B a B b A b B b b A B A A a B A b B ",
 "A A b B a a b B b a b a A A A B A b b b b A b b A ",
 "B B A A B B A b a a b a a A B B A A B B A B b A b ",
 "A a A b B B b A a b b B A a B b b A B b a a a b b ",
 "B B a b A A a b a A a A a B B A B A A a B B b a B ",
 "B b B B a B A B b B B a A a a a b b B a A A b a A ",
 "b B a a a B b a A a A b a a A b A B b a B a b A A ",
 "A A b B b A a B a a a b B A b B B a b B b b b B B ",
 "b B a A A A B B b b b b a b B B a a a b B b A A B ",
 "a B A a a a a A A B A A B b a b A A a A a a B B B ",
 "B B A B b B B a b B A B A b b A b A B A A b A a b ",
 "B A A A b A B a b b b a b b b a a A A b A b a A b ",
 "A a B B B A B b b A B a B a A b B b b a B A B b a ",
 "B a A A B a a b b B b B A A a A b a a b b b a B b ",
 "a a b A B a b B B B A A B a B b B A b B b a b A B ",
 "A a a b a A b B A b B a A B a a A B a A b a b a B ",
 "A b A b b A b b a B b a A a b A a A A A A a A b A ",
 "a B B A a B B a b B b a B b A a B B B a B a a b a ",
 "a a A b B B B a A B a B a A a B a a B b A B b b B ",
 "A a A B A A A b b B A A a A b B b a A b B A b b A ",
 "A A a a b B A b a b a A A A B B b B A a A B A B b ",
 "b a b B a A B a a b B B B A b a A a A A A a a A b ",
 "a b a a B a B b a B B A A b a B A B b A b a A a a ",
 "b a a B a a b A B A a b a B A B b b B A b A a b a ",
 "a B b B a a a A b B B A b b b A A B A b b b B b A ",
 "B B a A b b a B B b A a a A B B A a A b a a B A A ",
 "a A a A b b B B a B B b a b b A B a B A a a b a A ",
 "A B A A a a b A b A B B A b A B b B B a a a A b a ",
 "b A B b b b a b b A A a A B b B B A a b b B a b a ",
 "A B B b b a a a B A B b b a b A a a B A b B A B B ",
 "A b B b B a b a B B B B A a A a a B B b b a b A A ",
 "B B a a b B a A b A A A a A a b b b a B B A a B a ",
 "A B a a B A B B a B B b b a B a b b A A B b A A b ",
 "B b a a A a B b B a b A B B B A b B b A A B a a B ",
 "B b b A B a a b a B a b A A b B a b b a A B B a A ",
 "A A b A a a a a B B b b b b A B A B B a B b A a a ",
 "B B B A b A a a a B a B b b B b a A a b b A B a B ",
 "A B b b B a b A b B b A B A A A a B B a A b b b B ",
 "B a A B A b b A b b a A A b b b A B a b B a b A b ",
 "B a a B a B A b B A b b a b B a b a A b b a A b B ",
 "a b b a A b A a A B B a b B B a A B A a b B a a a ",
 "b b a A a a A a a B b A B a A B B a A a B A b A a ",
 "b b B b B a a b a B B A B b A b A a b b B A B b a ",
 "a b a B a A B a A A A A A a B a A A a B a b b b b "}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string Arg1 = 
	"a...b...a...b...a...a...b...b...a...a...b...b"
	; A1.push_back( Arg1 ); string _Arg2[] = 
	{ "45 24 [a b B a b a A b b a A b B]",  "8 12 [A b a a b a a A B B A A B B]",  "18 18 [A B a B a A b B b b a B A B b]",  "40 16 [a B a b A A b B a b b a A B B]",  "47 16 [a B b A B a A B B a A a B A b]" }
	; vs Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 );  }
	{ /*Test 5*/string _Arg0[] = 
	{ "this government of the people, by the people,", 
 "for the people, shall not perish from the earth."}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string Arg1 = 
	"people"
	; A1.push_back( Arg1 ); string _Arg2[] = 
	{ "0 23 [people]",  "0 38 [people]",  "1 8 [people]" }
	; vs Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], findPassages( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	bloggoSequenceSearch ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
