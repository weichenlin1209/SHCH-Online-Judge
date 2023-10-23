#include <bits/stdc++.h>

using namespace std;

void change(int &a ,int &b)
{
    int c = a;
    a = b;
    b = c;
}

int HCF(int a ,int b)
{
    if (b % a != 0)
    {
        int c = b % a;
        return HCF(c ,a);
    }
    else
    {
        return a;
    }

}

int main()
{
    int a ,b;
    cin >> a >> b;

    if (a > b)
        change(a ,b);

    int flag = HCF(a ,b);

    string ans = (flag == 1) ? "True" : "False";

    cout << ans;

    return 0;
}



