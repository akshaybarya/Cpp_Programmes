// Find A Word

class Solution
{
private:
    bool check(vector<vector<char>> &board, int i, int j, char c)
    {
        if (i >= 0 and i < board.size() and j >= 0 and j < board[0].size() and board[i][j] == c)
            return true;
        return false;
    }

    bool helper(vector<vector<char>> board, int i, int j, string &word, int x)
    {
        x = 1;
        board[i][j] = '.';
        while (x < word.size())
        {
            cout << i << " " << j << endl;
            if (check(board, i + 1, j, word[x]))
            {
                i++;
            }
            else if (check(board, i - 1, j, word[x]))
            {
                i--;
            }
            else if (check(board, i, j + 1, word[x]))
            {
                j++;
            }
            else if (check(board, i, j - 1, word[x]))
            {
                j--;
            }
            else
            {
                return false;
            }
            board[i][j] = '.';
            x++;
        }
        return true;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    bool b = helper(board, i, j, word, 0);
                    cout << b << endl;
                    if (b)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
