public class DitherCounter
{
	public int count( string dithered, string[] screen)
	{
		int x = 0;
		for( int i = 0; i < screen.Length; i++ )
		{
			for( int j = 0; j < screen[i].Length; j++ )
			{
				for( int k = 0; k < dithered.Length; k++ )
				{
					if ( screen[i][j] == dithered[k] )
					{
						x++; break;
					}
				}
			}
		}
		return x;
	}
}
