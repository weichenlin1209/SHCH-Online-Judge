#include <bits/stdc++.h>

using namespace std;

typedef vector<int> dvector;

int area(int a ,int b ,int x ,int y ,vector<dvector> &value);

int main()
{
    int n;
    cin >> n;

    vector<dvector> value;

    for(int i = 0; i < n; i++)
    {
        vector<int> t;
        for(int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            t.push_back(a);
        }
        value.push_back(t);
    }

    int ans = -INT_MAX;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int x = 0; x < n; x++)
            {
                for(int y = 0; y < n; y++)
                {
                    ans = (area(i ,j ,x ,y ,value) > ans) ? area(i ,j ,x ,y ,value) : ans;

                }
            }
        }
    }

    cout << ans;

    return 0;
}

int area(int a ,int b ,int x ,int y ,vector<dvector> &value)
{
    int sum = 0;
    for(int i = a; i <= x; i++)
    {
        for(int j = b; j <= y; j++)
        {
            sum += value[i][j];
        }
    }

    return sum;
}
