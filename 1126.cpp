/*
http://acm.timus.ru/problem.aspx?space=1&num=1126
1126. Магнитные бури
*/

#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

long main()
{
	std::multiset<int> vSet;
	std::queue<std::multiset<int>::iterator> vIts;
	size_t n = 0, i;
	std::cin >> n;
	while (true) {
		std::cin >> i;
		if (i == -1) break;
		vIts.push(vSet.emplace(i));
		if (vSet.size() > n) {
			vSet.erase(vIts.front());
			vIts.pop();
		}
		if(vSet.size() == n) {
		std::cout << *(vSet.rbegin()) << std::endl;
		}
	}
	system("pause");
}


