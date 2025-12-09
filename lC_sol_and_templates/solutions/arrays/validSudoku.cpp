#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}
class Solution_Optimal {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>>uniqueRow(9, vector<int>(9, 0));
        vector<vector<int>>uniqueCol(9, vector<int>(9, 0));
        vector<vector<int>>uniqueGrid(9, vector<int>(9, 0));

        int n = 9;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != '.'){
                    int grid = i/3 * 3 + j/3;
                    int curr = board[i][j] - '1';
                    if(uniqueRow[i][curr] || uniqueCol[j][curr] || uniqueGrid[grid][curr]){
                        return false;
                    }
                    uniqueRow[i][curr] = uniqueCol[j][curr] = uniqueGrid[grid][curr] = 1;
                }
            }
        }
        return true;
    }
};
class Solution {
private:
    bool rowCheck(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            unordered_set<char>mp;
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.' && mp.count(board[i][j])){
                    return false;
                }
                if(board[i][j] != '.') mp.insert(board[i][j]);
            }
        }
        return true;
    }

    bool colCheck(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            unordered_set<char>mp;
            for(int j = 0; j < 9; j++){
                if(board[j][i] != '.' && mp.count(board[j][i])){
                    return false;
                }
                if(board[j][i] != '.') mp.insert(board[j][i]);
            }
        }
        return true;
    }

    bool gridCheck(vector<vector<char>>& board){
        for(int i = 0; i < 9; i+=3){
            for(int k = 0; k < 9; k+=3){
                unordered_set<char>mp;
                for(int m = i; m < i + 3; m++){
                    for(int n = k; n < k + 3; n++){
                        if(board[m][n] != '.' && mp.count(board[m][n])){
                        return false;
                    }
                        if(board[m][n] != '.') mp.insert(board[m][n]);
                    }
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //row check 
        if(!rowCheck(board)) return false;
        //all cols
        if(!colCheck(board)) return false;
        //all grids check
        if(!gridCheck(board)) return false;

        return true;
    }
};