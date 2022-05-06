#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // brute force
        int m = matrix.size();
        int n = matrix[0].size();

        vector<pair<int, int>> v;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    v.push_back(make_pair(i, j));
                }
            }
        }

        for (int i = 0; i < v.size(); i++)
        {
            int r = 0, c = 0;
            while (c < n)
            {
                matrix[v[i].first][c] = 0;
                c++;
            }
            while (r < m)
            {
                matrix[r][v[i].second] = 0;
                r++;
            }
        }

        // constant space approach
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][0] == 0)
                col0 = 0;
            for (int j = 1; j < cols; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }

        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};