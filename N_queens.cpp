#include <iostream>
#include <vector>
using namespace std;

class NQueens {
public:
    int N;
    vector<vector<int>> board;

    NQueens(int N) : N(N), board(N, vector<int>(N, 0)) {}

    // Utility to check if a queen can be placed at board[row][col]
    bool isSafe(int row, int col) {
        // Check row on left side
        for (int i = 0; i < col; i++) 
            if (board[row][i]) 
                return false;

        // Check upper diagonal on left side
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j]) 
                return false;

        // Check lower diagonal on left side
        for (int i = row, j = col; i < N && j >= 0; i++, j--)
            if (board[i][j]) 
                return false;

        return true;
    }

    // Utility function to solve the N-Queens problem using backtracking
    bool solveNQueensUtil(int col) {
        // If all queens are placed, return true
        if (col >= N) 
            return true;

        // Try placing queen in each row of the current column
        for (int i = 0; i < N; i++) {
            if (isSafe(i, col)) {
                // Place the queen
                board[i][col] = 1;

                // Recur to place rest of the queens
                if (solveNQueensUtil(col + 1)) 
                    return true;

                // If placing queen here leads to a solution, return true; else backtrack
                board[i][col] = 0;
            }
        }
        return false;
    }

    // Solves the N-Queens problem
    bool solveNQueens() {
        if (!solveNQueensUtil(0)) {
            cout << "Solution does not exist." << endl;
            return false;
        }

        printSolution();
        return true;
    }

    // Print the solution
    void printSolution() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << (board[i][j] ? "Q " : ". ");
            cout << endl;
        }
    }
};

int main() {
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;

    NQueens nQueens(N);
    nQueens.solveNQueens();

    return 0;
}
