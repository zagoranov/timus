//http://acm.timus.ru/problem.aspx?space=1&num=1002
//Телефонные номера
//Проверка:
//7325189087
//5
//it
//your
//reality
//real
//our

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <tuple>
#include <utility>
#include <algorithm>


using recuple = std::tuple<bool, std::string, int, int>;   //удача, результат, кол-во слов, длина без пробелов

inline recuple check_best(recuple &old_res, recuple &new_res) {
	if (std::get<2>(new_res) > std::get<2>(old_res) || (std::get<2>(new_res) = std::get<2>(old_res) && std::get<1>(new_res).length() < std::get<1>(old_res).length()))
		return new_res;
	return old_res;
}


inline bool check_letter(char letter, char number, std::unordered_multimap<char, char> &nlm) {
	for (auto& x : nlm) {
		if (x.first == number && x.second == letter)
			return true;
	}
	return false;
}

inline bool check_word(std::string word, std::string phone, size_t cur_n, std::unordered_multimap<char, char> &nlm) {
	for (size_t i = 0; i<word.length(); ++i)
		if (!check_letter(word[i], phone[cur_n + i], nlm))
			return false;
	return true;
}


recuple recourse_find(recuple local_res, std::string phone, std::unordered_multimap<char, char> &nlm, std::vector<std::string> & w_vec) {
	recuple best_res = local_res, new_tmp = local_res;
	for (std::string word : w_vec) {
		if (check_word(word, phone, std::get<2>(local_res), nlm)) {
			recuple new_tmp = local_res;
			std::get<1>(new_tmp) += word;
			std::get<2>(new_tmp) += word.length();
			std::get<3>(new_tmp) += 1;

			if (std::get<2>(new_tmp) == phone.length()) {
				std::get<0>(new_tmp) = true;
				return new_tmp;
			}
			else {
				std::get<1>(new_tmp) += " ";
				if (std::get<1>(new_tmp).length() > phone.length()) {
					return new_tmp;
				}
				else {
					recuple temp_res = recourse_find(new_tmp, phone, nlm, w_vec);
					if (std::get<0>(temp_res)) {
						best_res = check_best(best_res, temp_res);
					}
				}
			}
		}
	}
	return best_res;
}



int main()
{
	std::unordered_multimap<char, char> numb_let_map = { { '1','i' },{ '1','j'},{ '2','a' },{ '2','b' },{ '2','c' },
	{ '3','d' },{ '3','e' },{ '3','f' },
	{ '4','g' },{ '4','h'},{ '5','k' },{ '5','l' },{ '6','m' },{ '6','n' },{ '7','p' },{ '7','r' },{ '7','s' },
	{ '8','t' },{ '8','u'},{ '8','v' },{ '9','w' },{ '9','x' },{ '9','y' },{ '0','o' },{ '0','q' },{ '0','z' } };
	std::vector<std::string> words_vec;

	while (true) {
		std::string phone;
		size_t n_words;
		std::cin >> phone;
		std::string word;
		if (phone == "-1") break;
		std::cin >> n_words;
		words_vec.clear();
		words_vec.reserve(n_words);
		for (size_t i = 0; i < n_words; ++i) {
			std::cin >> word;
			words_vec.emplace_back(word);
		}
		std::sort(words_vec.begin(), words_vec.end(), [](std::string s1, std::string s2) { return s1.length() > s2.length(); });

		recuple res = { false, "", 0, 0};
		res = recourse_find(res, phone, numb_let_map, words_vec);
		if (!std::get<0>(res))
			std::cout << "No solution.";
		else
			std::cout << std::get<1>(res);
	}
}
