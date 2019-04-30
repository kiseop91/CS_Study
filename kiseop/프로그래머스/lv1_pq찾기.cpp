
bool solution(string s) {
	bool answer = true;
	int pcount = 0;
	int ycount = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'p' || s[i] == 'P')
			pcount++;
		if (s[i] == 'y' || s[i] == 'Y')
			ycount++;
	}
	if (pcount == ycount)
		return true;
	else
		return false;
	//return answer;
}