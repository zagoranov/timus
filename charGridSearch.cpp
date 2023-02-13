/*
https://leetcode.com/problems/word-search/

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.

The same letter cell may not be used more than once.
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(size_t i = 0; i < board.size(); ++i)
            for(size_t j = 0; j < board[i].size(); ++j) {
                cout << "[" << j << " " << i << "]:" << "\n";
                if ( board[i][j] == word[0] && further1(board, word, j, i, 0) )
                        return true;
                }
        return false;
    }

    bool further1(vector<vector<char>> &board, string& word, size_t col, size_t row, size_t w_pos) {
        vector<vector<char>> newboard;
        copy(board.begin(), board.end(), back_inserter(newboard)); 
        return further(newboard, word, col, row, 0);
    }

    bool further(vector<vector<char>> &board, string& word, size_t col, size_t row, size_t w_pos) {
        cout << "[" << col << " " << row << "] - " << w_pos << " " << board[row][col] << "\n";
        if (w_pos == word.length() || board[row][col] != word[w_pos])
            return false;
        cout << "+\n";
        if (w_pos == word.length()-1)
            return true;
        board[row][col] = ' ';
        return (col < board[row].size()-1 && further(board, word, col+1, row, w_pos+1) ) ||
            (row < board.size()-1 && further(board, word, col, row+1, w_pos+1) ) || 
            (col > 0 && further(board, word, col-1, row, w_pos+1) ) ||
            (row > 0 && further(board, word, col, row-1, w_pos+1) );
    }
};


int main(int argc, char *argv[]) {
    Solution S;

    vector< vector<char> > vv =
           { {'A','B','C','E'},
             {'S','F','E','S'},
             {'A','D','E','E'} }; //ABCESEEEFS

    std::string s = argv[1];
    cout << S.exist( vv, s);
}
