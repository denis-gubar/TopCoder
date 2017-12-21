using System;
public class Masterbrain
{
	private int[] black;
	private int[] white;
	private string[] guesses;
	private bool mistakes( char a, char b, char c, char d )
	{
		int count = 0;
		for( int i = 0; i < black.Length; i++ )
		{
			int bl = 0;
			int[] w = new int[8];
			if (a == guesses[i][0]) bl++;
			if (b == guesses[i][1]) bl++;
			if (c == guesses[i][2]) bl++;
			if (d == guesses[i][3]) bl++;
			w[int.Parse(a.ToString())]++;
			w[int.Parse(b.ToString())]++;
			w[int.Parse(c.ToString())]++;
			w[int.Parse(d.ToString())]++;
			w[int.Parse(guesses[i][0].ToString())]--;
			w[int.Parse(guesses[i][1].ToString())]--;
			w[int.Parse(guesses[i][2].ToString())]--;
			w[int.Parse(guesses[i][3].ToString())]--;
			int wh = 4 - bl;
			for( int x = 1; x < 8; x++ )
			{
				if( w[x] > 0 ) wh -= w[x];
			}
			if ( wh != white[i] || bl != black[i] )
			{
				count++;
				if ( count > 1 ) return false;
			} 
		}
		if ( count == 0 ) return false;
		return true;
	}
	public int possibleSecrets( string[] guesses, string[] results )
	{
		this.guesses = guesses;
		black = new int[guesses.Length];
		white = new int[guesses.Length];
		for( int i = 0; i < guesses.Length; i++ )
		{
			black[i] = int.Parse(results[i][0].ToString());
			white[i] = int.Parse(results[i][3].ToString());
		}
		int total = 0;
		for( char i1 = '1'; i1 <= '7'; i1++ ){
		for( char i2 = '1'; i2 <= '7'; i2++ ){
		for( char i3 = '1'; i3 <= '7'; i3++ ){
		for( char i4 = '1'; i4 <= '7'; i4++ ){
			if ( mistakes( i1, i2, i3, i4 ) ) total++;
		}}}}
		return total;
	}
}
