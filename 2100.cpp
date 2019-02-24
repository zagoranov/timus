//http://acm.timus.ru/problem.aspx?space=1&num=2100

#include <iostream>
#include <string>

int main()
{
	size_t n = 0, res;
	std::cin >> n;
	res = n + 2;
	std::string s;
	if (n > 0) {
		for (size_t i = 0; i < n; ++i) {
			std::cin >> s;
			auto found = s.find("+one");
			if (found != std::string::npos)
				++res;

		}
		if (res == 13) res = 14;
		std::cout << res*100 << std::endl;
	}
	system("pause");
}
