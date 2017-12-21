public class ExerciseMachine
{
	public int getPercentages( string t )
	{
		int x = 0;
		int seconds = int.Parse(t.Substring(0, 2)) * 3600 + int.Parse(t.Substring(3, 2)) * 60 + int.Parse(t.Substring(6, 2));
		for( int i = 1; i < 100; i++ )
		{
			if ( seconds * i % 100 == 0 ) x++;
		}
		return x;
	}
}
