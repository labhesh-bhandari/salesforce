#include<bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>> &board, 
                 vector<vector<string>> &ans, 
                 int n){

    vector<string> solution;

    for(int i = 0; i < n; i++){

        string temp = "";

        for(int j = 0; j < n; j++){

            if(board[i][j] == 0){
                temp.push_back('.');
            }
            else{
                temp.push_back('Q');
            }
        }

        solution.push_back(temp);
    }

    ans.push_back(solution);
}


bool isSafe(int row, int col, 
            vector<vector<int>> &board, 
            int n){

    int x = row;
    int y = col;

    // Left row
    while(y >= 0){

        if(board[x][y] == 1){
            return false;
        }

        y--;
    }

    // Upper-left diagonal
    x = row;
    y = col;

    while(x >= 0 && y >= 0){

        if(board[x][y] == 1){
            return false;
        }

        x--;
        y--;
    }

    // Lower-left diagonal
    x = row;
    y = col;

    while(x < n && y >= 0){

        if(board[x][y] == 1){
            return false;
        }

        x++;
        y--;
    }

    return true;
}


void solve(int col, 
           vector<vector<int>> &board, 
           vector<vector<string>> &ans, 
           int n){

    if(col == n){

        addSolution(board, ans, n);
        return;
    }

    for(int row = 0; row < n; row++){

        if(isSafe(row, col, board, n)){

            board[row][col] = 1;

            solve(col + 1, board, ans, n);

            board[row][col] = 0;
        }
    }
}


vector<vector<string>> solveNQueens(int n) {

    vector<vector<int>> board(n, vector<int>(n, 0));

    vector<vector<string>> ans;

    solve(0, board, ans, n);

    return ans;
}



int main(){

    int n;

    cout << "Enter value of n: ";
    cin >> n;

    vector<vector<string>> result = solveNQueens(n);

    cout << "\nTotal solutions: "
         << result.size() << endl;

    for(int i = 0; i < result.size(); i++){

        cout << "\nSolution "
             << i + 1
             << ":\n";

        for(auto row : result[i]){
            cout << row << endl;
        }
    }

    return 0;
}