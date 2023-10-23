#include <bits/stdc++.h>

using namespace std;

void change(int &a ,int &b)
{
    int c = a;
    a = b;
    b = c;
}

int main()
{
    int a ,b ,sum_a ,sum_b;

    cin >> a >> b;

    if (a > b)
        change(a ,b);


    a = a - 1;
    sum_a = a*(a+1)*(2*a+1)/6;
    sum_b = b*(b+1)*(2*b+1)/6;

    int sum = sum_b - sum_a;

    cout << sum;
    return 0;
}



