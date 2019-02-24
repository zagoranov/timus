//http://acm.timus.ru/problem.aspx?space=1&num=1820

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <math.h>


std::vector<std::string> get_inlines() {
	std::string text;
	std::getline(std::cin, text);
	int iresult = 0;
	std::istringstream iss(text);
	std::vector<std::string> results(std::istream_iterator<std::string>{iss},
		std::istream_iterator<std::string>());
	return results;
}

int main()
{
	std::vector<std::string> results = get_inlines();
	if (results.size() > 1) {
		int n = std::stoi(results.at(0));
		int k = std::stoi(results.at(1));

		int res = 0;
		if (n <= k) 
			res = 2;
		else
			res = ceil(((double)n / (double)k) * 2);

		std::cout << res << std::endl;
	}
	system("pause");
}

