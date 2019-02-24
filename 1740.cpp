//http://acm.timus.ru/problem.aspx?space=1&num=1740
//1740. А олени лучше!
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <iterator>


std::vector<int> get_inlines() {

	std::string text = "";
	while (text == "")
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
	std::vector<int> v1 = get_inlines();
	if (v1.size() > 2) {
		std::cout << v1[2] * (v1[0] / v1[1]) << ' ' << v1[2] * (v1[0] / v1[1] + !(v1[0] % v1[1] == 0)) << std::endl;
	}
	else
		std::cout << "Error!!!" << std::endl;
	system("pause");
}
