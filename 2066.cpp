
//http://acm.timus.ru/problem.aspx?space=1&num=2066
	#include <iostream>
	#include <string>
	#include <algorithm>

	int main()
	{
		int a, b, c, res = 0;
		std::cin >> a >> b >> c;

		res = std::min((a - b * c), (a - b - c));

		std::cout << res << std::endl;
		system("pause");
	}
