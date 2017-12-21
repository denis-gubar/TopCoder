using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class TextEditor 
{
	public string[] twoColumn( string[] text, int width ) 
	{
		string s = text[0];
		for( int i = 1; i < text.Length; i++ ) s += " " + text[i];
		string[] x = s.Split();
		s = "";
		ArrayList A = new ArrayList();
		for( int i = 0; i < x.Length; i++ )
		{
			if ( x[i] != "" )
			{
				if ( s.Length + x[i].Length > width - 1 )
				{
					if ( s != "" ) A.Add( s );
					s = x[i];
				}
				else if ( s == "" ) s = x[i]; else s += " " + x[i];
			}
		}
		if ( s != "" ) A.Add( s );
		string[] result = new string[A.Count];
		for( int i = 0; i < (A.Count + 1) / 2; i++ )
		{
			result[i * 2] = (string) A[i];
		}
		for( int i = 0; i < A.Count / 2; i++ )
		{
			result[i * 2 + 1] = (string) A[(result.Length + 1) / 2 + i];
		}
		return result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new TextEditor()).twoColumn(new String[] {"The quick brown fox jumps over the lazy dog. "}, 7),new String[] { "The",  "over",  "quick",  "the",  "brown",  "lazy",  "fox",  "dog.",  "jumps" });
		eq(2,(new TextEditor()).twoColumn(new String[] {"Such a preposterous use of !punctuation! !!!","Who would write ... something like this ???"}, 17),new String[] { "Such a",  "write ...",  "preposterous use",  "something like",  "of !punctuation!",  "this ???",  "!!! Who would" });
		eq(3,(new TextEditor()).twoColumn(new String[] {" Forsaking monastic tradition,    twelve jovial",
"  friars gave up their vocation for a questionable",
"     existence on the flying trapeze.    "}
, 25),new String[] { "Forsaking monastic",  "vocation for a",  "tradition, twelve jovial",  "questionable existence on",  "friars gave up their",  "the flying trapeze." });
		eq(4,(new TextEditor()).twoColumn(new String[] {" "," "," "," "," "," "}, 7),new String[] { });
		eq(5,(new TextEditor()).twoColumn(new String[] {" I WONDER by my troth, what thou,",
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
, 45),new String[] { "I WONDER by my troth, what thou, and I Did,",  "seadiscoverers to new worlds have gone, Let",  "till we lovd? were we not weand till then?",  "Maps to other, worlds on worlds have showne,",  "But suckd on countrey pleasures, childishly?",  "Let us possesse one world, each hath one, and",  "Or snorted we in the seaven sleepers den?",  "is one. My face in thine eye, thine in mine",  "Twas so; But this, all pleasures fancies bee.",  "appeares, And true plaine hearts doe in the",  "If ever any beauty I did see, Which I desird,",  "faces rest, Where can we finde two better",  "and got, twas but a dreame of thee. And now",  "hemispheares Without sharpe North, without",  "good morrow to our waking soules, Which watch",  "declining West? What ever dyes, was not mixt",  "not one another out of feare; For love, all",  "equally; If our two loves be one, or, thou",  "love of other sights controules, And makes",  "and I Love so alike, that none doe slacken,",  "one little roome, an every where. Let",  "none can die. John Donne" });
		DateTime t2 = DateTime.Now;
		TimeSpan t = t2 - t1;
		Console.WriteLine( "{0} sec", t.TotalMilliseconds / 1000 ); 
	}
	private static void eq(int n, int a, int b)
	{
		if(a == b)
			Console.WriteLine("Case "+n+" passed.");
		else
			Console.WriteLine("Case "+n+" failed: expected \""+b+"\", received \""+a+"\".");
	}
	private static void eq(int n, double a, double b)
	{
		if(a == b)
			Console.WriteLine("Case "+n+" passed.");
		else
			Console.WriteLine("Case "+n+" failed: expected \""+b+"\", received \""+a+"\".");
	}
	private static void eq(int n, char a, char b)
	{
		if(a == b)
			Console.WriteLine("Case "+n+" passed.");
		else
			Console.WriteLine("Case "+n+" failed: expected '"+b+"', received '"+a+"'.");
	}
	private static void eq(int n, long a, long b)
	{
		if(a == b)
			Console.WriteLine("Case "+n+" passed.");
		else
			Console.WriteLine("Case "+n+" failed: expected \""+b+"\", received \""+a+"\".");
	}
	private static void eq(int n, bool a, bool b)
	{
		if(a == b)
			Console.WriteLine("Case "+n+" passed.");
		else
			Console.WriteLine("Case "+n+" failed: expected \""+b+"\", received \""+a+"\".");
	}
	private static void eq(int n, string a, string b)
	{
		if(a == b)
			Console.WriteLine("Case "+n+" passed.");
		else
			Console.WriteLine("Case "+n+" failed: expected \""+b+"\", received \""+a+"\".");
	}
	private static void eq(int n, int[] a, int[] b)
	{
		if(a.Length != b.Length)
		{
			Console.WriteLine("Case "+n+" failed: returned "+a.Length+" elements; expected "+b.Length+" elements.");
			return;
		}
		for(int i= 0; i < a.Length; i++)
			if(a[i] != b[i])
			{
				Console.WriteLine("Case "+n+" failed. Expected and returned array differ in position "+i);
				print(b);
				print(a);
				return;
			}
		Console.WriteLine("Case "+n+" passed.");
	}
	private static void eq(int n, double[] a, double[] b)
	{
		if(a.Length != b.Length)
		{
			Console.WriteLine("Case "+n+" failed: returned "+a.Length+" elements; expected "+b.Length+" elements.");
			return;
		}
		for(int i= 0; i < a.Length; i++)
			if(a[i] != b[i])
			{
				Console.WriteLine("Case "+n+" failed. Expected and returned array differ in position "+i);
				print(b);
				print(a);
				return;
			}
		Console.WriteLine("Case "+n+" passed.");
	}
	private static void eq(int n, long[] a, long[] b)
	{
		if(a.Length != b.Length)
		{
			Console.WriteLine("Case "+n+" failed: returned "+a.Length+" elements; expected "+b.Length+" elements.");
			return;
		}
		for(int i= 0; i < a.Length; i++)
			if(a[i] != b[i])
			{
				Console.WriteLine("Case "+n+" failed. Expected and returned array differ in position "+i);
				print(b);
				print(a);
				return;
			}
		Console.WriteLine("Case "+n+" passed.");
	}
	private static void eq(int n, string[] a, string[] b)
	{
		if(a.Length != b.Length)
		{
			Console.WriteLine("Case "+n+" failed: returned "+a.Length+" elements; expected "+b.Length+" elements.");
			return;
		}
		for(int i= 0; i < a.Length; i++)
			if(a[i] != b[i])
			{
				Console.WriteLine("Case "+n+" failed. Expected and returned array differ in position "+i);
				print(b);
				print(a);
				return;
			}
		Console.WriteLine("Case "+n+" passed.");
	}
	private static void print(int a)
	{
		Console.Write(a+" ");
	}
	private static void print(string s)
	{
		Console.Write("\""+s+"\" ");
	}
	private static void print(int[] rs)
	{
		if(rs == null) return;
		Console.Write('{');
		for(int i= 0; i < rs.Length; i++)
		{
			Console.Write(rs[i]);
			if(i != rs.Length-1)
				Console.Write(", ");
		}
		Console.WriteLine('}');
	}
	private static void print(double[] rs)
	{
		if(rs == null) return;
		Console.Write('{');
		for(int i= 0; i < rs.Length; i++)
		{
			Console.Write(rs[i]);
			if(i != rs.Length-1)
				Console.Write(", ");
		}
		Console.WriteLine('}');
	}
	private static void print(long[] rs)
	{
		if(rs == null) return;
		Console.Write('{');
		for(int i= 0; i < rs.Length; i++)
		{
			Console.Write(rs[i]);
			if(i != rs.Length-1)
				Console.Write(", ");
		}
		Console.WriteLine('}');
	}
	private static void print(string[] rs)
	{
		if(rs == null) return;
		Console.Write('{');
		for(int i= 0; i < rs.Length; i++)
		{
			Console.Write("\""+rs[i]+"\"");
			if(i != rs.Length-1)
				Console.Write(", ");
		}
		Console.WriteLine('}');
	}
	private static void nl()
	{
		Console.WriteLine();
	}
// END CUT HERE
}
