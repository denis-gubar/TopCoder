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
typedef vector<lint> vl;
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
string replace_all( string s, string oldValue, string newValue )
{
	string result;
	int j = 0;
	for( int i = s.find( oldValue ); i > -1; i = s.find( oldValue, i + oldValue.size() ) )
	{
		result += s.substr( j, i - j ) + newValue;
		j = i + oldValue.size();
	}
	result.append( s.substr( j ) );
	return result;
}
struct bloggoHyphenate
{
	vs correct( vs dictionary, vs candidates )
	{
		vs result, d;
		fora(i, dictionary)
			d.push_back( replace_all( dictionary[i], " ", "" ) );
		fora(i, candidates)
		{
			string s = replace_all( candidates[i], "-", "" );
			if ( find( all(dictionary), s ) != dictionary.end() )
			{
				result.push_back( s );
				continue;
			}
			int j = distance( d.begin(), find( all(d), s ) ), k = candidates[i].find( '-' ), e = 100;
			string r, best;
			fora(l, dictionary[j])
				if ( dictionary[j][l] != ' ' )
					r += dictionary[j][l];
				else
				{
					if ( r.size() == k )
					{
						e = 0; best = "correct"; break;
					}
					int z = abs( (int) r.size() - k );
					if ( e > z )
					{
						e = z; best = r + "-" + d[j].substr( r.size() );
					}
				}
			result.push_back( best );
		}
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1; vector<vs> A2;
	{ /*Test 0*/string _Arg0[] = 
	{"syl la ble", "dic tion a ry", "mole"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string _Arg1[] = 
	{"mo-le", "syl-lable"}
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); string _Arg2[] = 
	{ "mole",  "correct" }
	; vs Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 );  }
	{ /*Test 1*/string _Arg0[] = 
	{"syl la ble", "dic tion a ry", "mole"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string _Arg1[] = 
	{"dictio-nary", "syll-able"}
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); string _Arg2[] = 
	{ "diction-ary",  "syl-lable" }
	; vs Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 );  }
	{ /*Test 2*/string _Arg0[] = 
	{"syl la ble", "dic tion a ry", "mole"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string _Arg1[] = 
	{"dictionary-", "-syllable"}
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); string _Arg2[] = 
	{ "dictiona-ry",  "syl-lable" }
	; vs Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 );  }
	{ /*Test 3*/string _Arg0[] = 
	{"zsx kd ds jply rf", "auca wb ill", "kvqm kpd p kqi xpbk j",
 "cqf ccr ewq", "srl vu m u d b", "h qae qzge", "jdn qqjf y",
 "zpa hbr", "d uft ctsm qjg", "l hgcp ik twuy bsi nlmu iyx",
 "cjjz jn td zg", "h bd q hi", "obsr kci hjdm h yar zsq q xyr hxb",
 "izq iibd yuh tgx nkq", "cjgd wfns", "ohc bn duc",
 "pydv a geki s bo avdi wd", "zygp gqt p", "xq pqqb ufoe",
 "cvm yamq moqj vl zoig w", "ahz b lf ixjv d", "qpg ven d",
 "m cbxz yf tv djf", "kti wacd uvgb kmr ew r", "ng tfb unw ndl",
 "qruv ctw a", "d hk v pcxh zoxy", "etbo wabk", "x hxiu n",
 "wp qq u dvpi tclh ac l", "f am brs lk uss uyb pg",
 "dtfx h ict if koe jhj", "nl shp yeji b rw vrg", "bz qfnc u",
 "t ceoy eb ss myoe zaaj z jey", "j d uju mb irvu",
 "anmo emjs syam ta bfiy kk", "gl ej egla tha jbug",
 "zk u sz raij d", "kw lbya atdb pd", "no id hqum u wny qcy",
 "phv nv l f oq m", "b xup tnq fziw yth sn", "pvc hnr oky lzj",
 "ew wtwt gyty s uu pfe kif my", "t cw fsau",
 "esk gqtd o yh jbx wed fl z", "vvr hqw wo gxwm",
 "lei akz nzz bumb", "bc hlmw"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string _Arg1[] = 
	{"-duftctsmqjg", "-leiakznzzbumb", "-xhxiun", "-zpahbr",
 "ahzbl-fixjvd", "anmo-emjssyamtabfiykk", "aucawb-ill",
 "bchlmw-", "bxuptnqfziwyth-sn", "bzq-fncu", "c-vmyamqmoqjvlzoigw",
 "cjg-dwfns", "cjjzjn-tdzg", "cqfccre-wq", "dhkvpcxhzox-y",
 "dtfx-hictifkoejhj", "eskgqtdoyhjbx-wedflz", "etbowab-k",
 "ewwtwtgytysuupfe-kifmy", "fambrslkuss-uybpg", "glejegl-athajbug",
 "hbdqhi-", "hq-aeqzge", "izqiibd-yuhtgxnkq", "jd-nqqjfy",
 "jdujumb-irvu", "ktiwacduvgbkmr-ewr", "kv-qmkpdpkqixpbkj",
 "kwlbya-atdbpd", "lhgcpiktwuybsi-nlmuiyx", "mcbx-zyftvdjf",
 "ngtf-bunwndl", "nlshpyejibrwvrg-", "no-idhqumuwnyqcy", "o-hcbnduc",
 "obsr-kcihjdmhyarzsqqxyrhxb", "ph-vnvlfoqm", "pvchnrok-ylzj",
 "pydvageki-sboavdiwd", "qpgv-end", "qruvctw-a", "srlvumu-db",
 "tceoyebssmyo-ezaajzjey", "tcwfsau-", "vvrhqwwo-gxwm",
 "wpqqudvpit-clhacl", "xqpq-qbufoe", "zku-szraijd",
 "zsxkddsjp-lyrf", "zygpgqt-p"}
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); string _Arg2[] = 
	{ "d-uftctsmqjg",  "lei-akznzzbumb",  "x-hxiun",  "zpa-hbr",  "ahzb-lfixjvd",  "correct",  "correct",  "bc-hlmw",  "correct",  "bz-qfncu",  "cvm-yamqmoqjvlzoigw",  "cjgd-wfns",  "correct",  "cqfccr-ewq",  "dhkvpcxh-zoxy",  "correct",  "correct",  "etbo-wabk",  "correct",  "correct",  "glejegla-thajbug",  "hbdq-hi",  "h-qaeqzge",  "correct",  "jdn-qqjfy",  "correct",  "correct",  "kvqm-kpdpkqixpbkj",  "correct",  "correct",  "mcbxz-yftvdjf",  "ngtfb-unwndl",  "nlshpyejibrw-vrg",  "correct",  "ohc-bnduc",  "correct",  "phv-nvlfoqm",  "pvchnroky-lzj",  "correct",  "qpg-vend",  "correct",  "correct",  "tceoyebssmyoe-zaajzjey",  "tcw-fsau",  "correct",  "wpqqudvpi-tclhacl",  "xq-pqqbufoe",  "correct",  "zsxkdds-jplyrf",  "correct" }
	; vs Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], correct( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	bloggoHyphenate ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
