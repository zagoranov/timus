
//http://acm.timus.ru/problem.aspx?space=1&num=1197
#include <iostream>
#include <string>

int main()
{
	size_t n = 0;
	std::cin >> n;
	if (n > 0) {
		for (size_t i = 0; i < n; ++i) {
			std::string pos;
			std::cin >> pos;
			size_t x = pos[1] - '1';
			size_t y = pos[0] - 'a';
			size_t res = 8;
			if (y < 2 || y > 5) res -= 2;
			if (x < 2 || x > 5) res -= 2;
			if (x == 0 || x == 7) {
				if (y > 1 && y < 6) res -= 2;
				else res -= 1;
			}

			if (y == 0 || y == 7) {
				if (x > 1 && x < 6) res -= 2;
				else res -= 1;
			}
			std::cout << res << std::endl;
		}
	}
	system("pause");
}

