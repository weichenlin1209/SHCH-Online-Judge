#include <bits/stdc++.h>

using namespace std;


int main()
{
    double sum = 1;
    string n;
    cin >> n;

    for(int i = 0; i < n.length(); i++)
    {
        int a = (int)n[i] - 48;
        sum *= a;
    }

    cout << sum;

    return 0;
}



