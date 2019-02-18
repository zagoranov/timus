//http://acm.timus.ru/problem.aspx?space=1&num=1787

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	size_t razm = 0;
	std::cin >> razm;
	std::vector<std::vector<int> > vMars;;

	std::string sInp;
	for (size_t i = 0; i < razm; ++i) {
		std::cin >> sInp;
		std::vector<int> row;
		for (char ch : sInp)
			if (ch == 'S')
				row.push_back(1);
			else
				row.push_back(0);
		vMars.push_back(row);
	}
	int MaxS = 0;
	int Maxs = 0;

	for (int i = 0; i < razm-1; ++i) {
		int iHorMaxS = 0;
		for (int j = 0; j < razm - 1; ++j) {
			if (vMars[i][j] == 1 && vMars[i][j+1] == 1)
				++iHorMaxS;
		}
		int iHorMaxs = razm - (iHorMaxS > 0 ? iHorMaxS + 1 : 0);

		int iHorMaxS = std::count(vMars[i].begin(), vMars[i].end(), 1);
		int iHorMaxs = razm - iHorMaxS;
		if (iHorMaxS > MaxS)
			MaxS = iHorMaxS;
		if (iHorMaxs > Maxs)
			Maxs = iHorMaxs;
		int iVerMaxS = 0;
		for (int j = 0; j < razm-1; ++j) {
			if (vMars[j][i] == 1 && vMars[j+1][i] == 1)
				++iVerMaxS;
		}
		int iVerMaxs = razm - (iVerMaxS > 0 ? iVerMaxS + 1 : 0);
		if (iVerMaxS > MaxS)
			MaxS = iVerMaxS;
		if (iVerMaxs > Maxs)
			Maxs = iVerMaxs;
	}
	for (int i = 0; i < (razm*2) - 1; ++i) {
		
		int iDiag1MaxS = 0;
		int n = i;
		if (n >= razm) n = razm-1;
		for (int j = 0, k = n; j <= n; ++j, --k) {
			if (vMars[j][k] == 1)
					++iDiag1MaxS;
		}
		int iDiag1Maxs = (n + 1) - iDiag1MaxS;
		if (iDiag1MaxS > MaxS)
			MaxS = iDiag1MaxS;
		if (iDiag1Maxs > Maxs)
			Maxs = iDiag1Maxs;
		
		int iDiag2MaxS = 0;
		int n1 = i, m = 0, n2 = (razm - 1) - i;
		if (n1 >= razm) {
			n1 = razm - 1; 
			m = i - (razm - 1);
			n2 = 0;
		}
		for (int j = m, k = n2; j <= n1; ++j, ++k) {
			if (vMars[ k ][ j ] == 1)
				++iDiag2MaxS;
		}
		int iDiag2Maxs = ((n1 - m) + 1) - iDiag2MaxS;
		if (iDiag2MaxS > MaxS)
			MaxS = iDiag2MaxS;
		if (iDiag2Maxs > Maxs)
			Maxs = iDiag2Maxs;
	}

	if (MaxS > Maxs)
		std::cout << "S" << std::endl << MaxS << std::endl;
	else if(MaxS < Maxs)
			std::cout << "s" << std::endl << Maxs << std::endl;
		else
			std::cout << "?" << std::endl << std::max(Maxs, MaxS) << std::endl;

	system("pause");
}
