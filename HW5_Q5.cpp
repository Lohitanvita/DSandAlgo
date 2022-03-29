#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    void DFSTraversal(vector <vector<char>>& board, int i, int j, int rows, int cols)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols)            // checking out of bound conditions
        {
            return;
        }
        if (board[i][j] == '.')                                  
        {
            return;
        }
        board[i][j] = '.';                                      // updating current cell (backtracking)
        DFSTraversal(board, i, j + 1, rows, cols);              // applying DFS to check adjacent cells
        DFSTraversal(board, i, j - 1, rows, cols);
        DFSTraversal(board, i + 1, j, rows, cols);
        DFSTraversal(board, i - 1, j, rows, cols);
    }
public:
    int countBattleships(vector <vector<char>>& board)
    {
        int rows = board.size(); 
        int columns = board[0].size();
        int battleship_count = 0;

        for (int i = 0; i < rows; i++)                             // traversing each cell in the board
        {
            for (int j = 0; j < columns; j++)
            {
                if (board[i][j] == 'X')
                {
                    battleship_count += 1;
                    DFSTraversal(board, i, j, rows, columns);
                }

            }
        } return battleship_count;
    }
};

/*int main()                                    // driver code
{
    Solution sol;
    vector <vector<char>> board{ {'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'} };
   int result = sol.countBattleships(board);
   cout << result << endl;
 

}*/