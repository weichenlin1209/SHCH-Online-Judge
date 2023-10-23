#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, value ,flag ,ans = 0,len ,k;
    string n ;
    cin >> n;
    len = n.length();

    for(int i = 0; i < n.length(); i++)
    {
        value = (int)n[i] - '0';
        k = pow(value ,len);
        ans += k;
    }

    flag = stoi(n);

    if(ans == flag)
    {
        cout << "是";
    }
    else
    {
        cout << "否";
    }

    return 0;
}


