#include <bits/stdc++.h>

using namespace std;

map<char,int> value =
{
    {'I' ,1},
    {'V' ,5},
    {'X' ,10},
    {'L' ,50},
    {'C' ,100},
    {'D' ,500},
    {'M' ,1000},
};

int eval(string num);

int main()
{
    string a ,b;
    cin >> a >> b;

    cout << abs(eval(a) - eval(b));

    return 0;
}

int eval(string num)
{
    int ans ,k;
    for(int i = 0; i < num.length(); i++)
    {
        if(value[num[i]] >= value[num[i+1]])
        {
            k = value[num[i]];
        }
        else
        {
            k = value[num[i+1]] - value[num[i]];
            i++;
        }

        ans += k;
    }

    return ans;
}
