//http://acm.timus.ru/problem.aspx?space=1&num=1880


#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <math.h>
#include <iterator>
#include <algorithm>


std::vector<int> get_inlines() {
	
	std::string text = "";
	while(text == "")
		std::getline(std::cin, text);
	int iresult = 0;
	std::istringstream iss(text);
	std::vector<std::string> results(std::istream_iterator<std::string>{iss},
		std::istream_iterator<std::string>());
	std::vector<int> res;
	for (auto s : results)
		res.push_back(stoi(s));
	return res;
}

int main()
{
		size_t n1, n2, n3;
		std::cin >> n1;
		std::vector<int> v1 = get_inlines();
		std::cin >> n2;
		std::vector<int> v2 = get_inlines();
		std::cin >> n3;
		std::vector<int> v3 = get_inlines();

		std::sort(v1.begin(), v1.end());
		std::sort(v2.begin(), v2.end());
		std::sort(v3.begin(), v3.end());

		std::vector<int> v_intersection1, v_intersection2;

		std::set_intersection(v1.begin(), v1.end(),
			v2.begin(), v2.end(),
			std::back_inserter(v_intersection1));

		std::set_intersection(v_intersection1.begin(), v_intersection1.end(),
			v3.begin(), v3.end(),
			std::back_inserter(v_intersection2));

		std::cout << v_intersection2.size();

	system("pause");
}

