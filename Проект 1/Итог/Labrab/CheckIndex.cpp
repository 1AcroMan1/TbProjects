bool CheckIndex(int index, int count)
{
	if (count == 0)
	{
		return false;
	}
	if (index >= 0 || index < count)
		return true;
	else
		return false;
}