#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'
int grid[9][9];
bool check(int i, int j, int val)
{
    for (int k = 0; k < 9; ++k)
    {
        if (grid[i][k] == val || grid[k][j] == val)
            return 0;
        int l = (i / 3) * 3;
        int r = (j / 3) * 3;
        for (int i = l; i < l + 3; ++i)
        {
            for (int j = r; j < r + 3; ++j)
            {
                if (grid[i][j] == val)
                    return 0;
            }
        }
    }
    return 1;
}

void sudoku_solver(int i, int j)
{
    if (i == 9)
    {

        cout << " ";
        for (int i = 0; i < 9; ++i)
            cout << "_"
                 << " "
                 << "_"
                 << " ";
        cout << endl;
        for (int i = 0; i < 9; ++i)
        {

            cout << "|";
            for (int j = 0; j < 9; ++j)
            {
                cout << "_" << grid[i][j] << "_"
                     << "|";
            }
            cout << endl;
        }
        // exit(0);
        return;
    }
    if (grid[i][j] == 0)
    {
        for (int k = 1; k <= 9; ++k)
        {
            if (check(i, j, k))
            {
                grid[i][j] = k;
                if (j == 8)
                    sudoku_solver(i + 1, 0);
                else
                    sudoku_solver(i, j + 1);
                grid[i][j] = 0;
            }
        }
    }
    else
    {
        if (j == 8)
            sudoku_solver(i + 1, 0);
        else
            sudoku_solver(i, j + 1);
    }
}
void solve()
{
    for (int i = 0; i < 9; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 9; ++j)
        {
            if (s[j] == '.')
                grid[i][j] = 0;
            else
                grid[i][j] = s[j] - '0';
        }
    }
    sudoku_solver(0, 0);
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}