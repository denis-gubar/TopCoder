using System;

public class HillHike
{	
	public long numPaths(int distance, int maxHeight, int[] landmarks)
	{
		long[, , , ] paths = new long[distance + 1, maxHeight + 1, landmarks.Length + 1, 2];		
		paths[1, 1, landmarks.Length > 0 && landmarks[0] == 1 ? 1 : 0, maxHeight == 1 ? 1 : 0] = 1;
		for( int w = 1; w <= distance; w++ )
		{
			for( int h = 0; h <= maxHeight; h++ )
			{
				for( int s = -1; s <= 1; s++ )
				{
					if ( (h + s > 0) && (h + s <= maxHeight) )
					{
						for( int l = 0; l <= landmarks.Length; l++ )
						{
							for( int p = 0; p <= 1; p++ )
							{
								paths[w, h, landmarks.Length > 0 && l < landmarks.Length && landmarks[l] == h ? l + 1 : l, h == maxHeight ? 1 : p] += paths[w - 1, h + s, l, p];
							}
						}
					}
				}
			}
		}
		return paths[distance, 0, landmarks.Length, 1];
	}
}
