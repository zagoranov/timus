//http://acm.timus.ru/problem.aspx?space=1&num=2020
//2020. Пробка в Цветочном городе
#include <iostream>
#include <string>

int main()
{
	std::string sY, sN;
	std::cin >> sY >> sN;
	int nY = 0, nN = 0, time = 0;
	while (nY < sY.length() || nN < sN.length())
	{
		bool canY = true;
		bool canN = true;
		if ((sY[nY] == 'L' && nY < sY.length()) && (nN < sN.length() && sN[nN] != 'L')) { canY = false; }
		if ((nN < sN.length() && sN[nN] == 'L') && (nY < sY.length() && sY[nY] != 'L')) { canN = false; }
		if (canY) nY++;
		if (canN) nN++;
		++time;
	}
	std::cout << time << std::endl;
	system("pause");
}
