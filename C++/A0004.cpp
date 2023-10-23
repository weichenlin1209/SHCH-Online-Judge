#include <bits/stdc++.h>

using namespace std;

int reverse_str(string s)
{
    string n_string;
    for (int i = s.length()-1; i >= 0; i--)
    {
        n_string = n_string + s[i];
    }

    int result = stoi(n_string);
    return result;
}

int main()
{
    int times;
    cin >> times;
    vector<int> price;

    for (int i = 0; i < times; i++)
    {
        string s;
        cin >> s;

        int a = reverse_str(s);
        price.push_back(a);
    }

    int sum = 0;
    for (int i = 0; i < times; i++)
    {
        sum = sum + price[i];

    }

    cout << sum;

    return 0;
}

