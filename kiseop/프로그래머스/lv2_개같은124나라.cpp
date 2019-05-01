string solution(int n) {
	string answer = "";
	int remainder;

	while (n > 0) {
		remainder = n % 3;
		n = n / 3;

		if (remainder == 0) {
			n -= 1;
			remainder = 4;
		}

		answer = to_string(remainder) + answer;
	}
	return answer;
}