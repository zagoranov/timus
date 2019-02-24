#include <iostream>
#include <string>

//Палиндромы //http://acm.timus.ru/problem.aspx?space=1&num=1123
/*
Сделать числом наименьший число-палиндром из входящей строки
18
22

940
949

1999
2002

1250025
1250521
*/


bool CheckForPalindrom(std::string& s) {
	int pos = s.length() / 2 - 1;
	for (int i = pos; i >= 0; --i) {
		size_t pos2 = (s.length() - i) - 1;
		if (s[pos2] != s[i])
			return false;
	}
	return true;
}

void IncPos(std::string& s, int pos) {
	if (pos == -1) {
		s = "1" + s + "0";
	}
	else {
		if (s[pos] == '9') {
			s[pos] = '0';
			IncPos(s, pos-1);
		}
		else s[pos] += 1;
	}
}

int main()
{
	std::string s;
	std::cin >> s;
	
	int pos = s.length() / 2 - 1, i = pos;
	while(i >= 0) {
		int pos2 = (s.length() - i) - 1;
		if (s[pos2] > s[i]) {
			if (pos2 - i == 1) {
				s[i] = s[i] + 1;
				for (int j = i; j >= 0; --j)
					s[(s.length() - j) - 1] = s[j];
			}
			else {
				int center = (s.length() / 2 - 1) + (s.length() % 2 != 0 ? 1 : 0);
				IncPos(s, center);
				for (int j = center; j >= i; --j)
					s[(s.length() - j) - 1] = s[j];
			}
			
		}
		else 
			if (s[pos2] < s[i]) {
				s[pos2] = s[i];
				for (int j = i - 1; j >= 0; --j)
					s[(s.length() - j) - 1] = s[j];
			}
		if (CheckForPalindrom(s))
			break;
		--i;
	}
	std::cout << s << std::endl;

	system("pause");
}
