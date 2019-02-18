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


using recuple = std::tuple<bool, std::string, size_t, int>;   //удача, результат, кол-во слов, длина без пробелов

inline bool new_better(recuple &old_res, recuple &new_res) {
	if ((std::get<0>(new_res) && !std::get<0>(old_res)) ||
		(std::get<0>(new_res) && std::get<0>(old_res) && std::get<3>(new_res) < std::get<3>(old_res)))
		return true;
	return false;
}


char ch_to_numb_ch(char ch, std::unordered_multimap<char, char> &nlm) {
	for (auto& x : nlm) {
		if (x.second == ch)
			return x.first;
	}
	return ' ';
}

std::string str_to_numbstr(std::string &str, std::unordered_multimap<char, char> &nlm) {
	std::string res = "";
	for (char ch : str) res += ch_to_numb_ch(ch, nlm);
	return res;
}


recuple recourse_find(recuple res, std::string phone, int cur_pos, std::vector<std::string> &w_vec, std::vector<std::string> &real_w_vec, std::unordered_multimap<int, int> &pos_map) {
	recuple local_res = res, best_res = res;

	for (auto& x : pos_map) {
		if (x.first == cur_pos) {
			recuple new_tmp = local_res;
			std::get<1>(new_tmp) += real_w_vec[x.second];
			std::get<2>(new_tmp) += w_vec[x.second].length();
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
					recuple temp_res = recourse_find(new_tmp, phone, std::get<2>(new_tmp), w_vec, real_w_vec, pos_map);
					if (std::get<0>(temp_res) && new_better(best_res, temp_res)) {
						best_res = temp_res;
					}
				}
			}
		}
	}
	return best_res;
}


int main()
{
	std::unordered_multimap<char, char> numb_let_map = { { '1','i' },{ '1','j' },{ '2','a' },{ '2','b' },{ '2','c' },
	{ '3','d' },{ '3','e' },{ '3','f' },
	{ '4','g' },{ '4','h' },{ '5','k' },{ '5','l' },{ '6','m' },{ '6','n' },{ '7','p' },{ '7','r' },{ '7','s' },
	{ '8','t' },{ '8','u' },{ '8','v' },{ '9','w' },{ '9','x' },{ '9','y' },{ '0','o' },{ '0','q' },{ '0','z' } };
	std::vector<std::string> words_vec;
	std::vector<std::string> words_vec2;

	std::unordered_multimap<int, int> pos_map;

	while (true) {
		std::string phone;
		size_t n_words, min_len = INT16_MAX;
		std::cin >> phone;
		std::string word;
		if (phone == "-1") break;
		std::cin >> n_words;
		words_vec.clear();
		words_vec.reserve(n_words);
		words_vec2.clear();
		words_vec2.reserve(n_words);
		for (size_t i = 0; i < n_words; ++i) {
			std::cin >> word;
			words_vec.emplace_back(word);
			if (word.length() < min_len)
				min_len = word.length();
		}
		std::sort(words_vec.begin(), words_vec.end(), [](std::string s1, std::string s2) { return s1.length() > s2.length(); });

		for (size_t i = 0; i < n_words; ++i) 
			words_vec2.emplace_back(str_to_numbstr(words_vec[i], numb_let_map));

		for (size_t i = 0; i < phone.length() - (min_len-1); ++i) {
			for (size_t j = 0; j < words_vec2.size(); ++j) {
				if ((i + words_vec2[j].length()) <= phone.length()) {
					std::string s1 = phone.substr(i, words_vec2[j].length());
					if (s1 == words_vec2[j])
						pos_map.emplace(i, j);
				}
			}
		}

		recuple res = { false, "", 0, 0 };
		res = recourse_find(res, phone, 0, words_vec2, words_vec, pos_map);

		if (!std::get<0>(res))
			std::cout << "No solution.";
		else
			std::cout << std::get<1>(res);
	}
}
