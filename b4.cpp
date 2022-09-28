#include <iostream>
#include <vector>
using namespace std;

bool checkMatrix(vector<vector<int>>& arr, int x, int y, int u) {
    for (int i = x; i < x + u; i++)
        for (int j = y; j < y + u; j++)
            if (arr[i][j] != arr[x][y]) return false;
    return true;
}
void countMatrix(vector<vector<int>>& arr, int b[3], int x, int y, int u) {
    if (checkMatrix(arr, x, y, u)) {
        b[arr[x][y]]++;
    }
    else {
        for (int i = x; i < x + u; i += u / 3)
            for (int j = y; j < y + u; j += u / 3)
                countMatrix(arr, b, i, j, u / 3);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(n));
    int b[3] = { 0,0,0 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vec[i][j];
        }
    }

    countMatrix(vec, b, 0, 0, n);
    cout << b[0] << endl << b[1] << endl << b[2];

    return 0;
}