class Solution
{
private:
    bool helper(vector<vector<char>> &board, int x, int y, char c)
    {
        if (x > -1 and x < board.size() and y > -1 and y < board.size() and board[x][y] == c)
            return true;
        return false;
    }

    bool check(vector<vector<char>> &board, int x, int y, string &word)
    {
        int w = 0;
        int dp[][] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        vector<vector<bool>> vis(n);
        while (w < word.size())
        {
            for (int i = 0; i < dp[]; i++)
            {
            }
        }
        return true;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    ans = check(board, i, j, word);
                    if (ans)
                        return ans;
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}