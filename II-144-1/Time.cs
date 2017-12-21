public class Time
{
	public string whatTime(int seconds)
	{
		return (seconds / 3600).ToString() + ":" + ((seconds - seconds / 3600 * 3600)/60) + ":" + (seconds % 60).ToString();
	}
}
