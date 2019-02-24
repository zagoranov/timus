/*
 http://acm.timus.ru/problem.aspx?space=1&num=1777
Задача прокучки и аборигенов
тест:
11 5 9
3
*/

#include <iostream>
#include <algorithm>
#include <set>

int main()
{
	std::multiset<unsigned long long > vKuchi;
	unsigned long long  n, min = INT64_MAX;
	for (size_t i = 0; i < 3; ++i) {
		std::cin >> n;
		vKuchi.emplace(n);
	}
	while (true) {
		std::multiset<unsigned long long >::iterator it = std::adjacent_find(vKuchi.begin(), vKuchi.end(), 
			[&min](unsigned long long  i, unsigned long long  j) { unsigned long long  qq = std::max(i, j) - std::min(i, j);  if (qq < min) min = qq; return false; });
		if (min == 0) break;
		else
			vKuchi.emplace(min);
	}
	std::cout << vKuchi.size() - 2 ;

system("pause");
}
