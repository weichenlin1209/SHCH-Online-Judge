#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n ,a;
    float k;
    bool flag;
    string ans;
    cin >> n;

    k = sqrt(n);

    flag = true;

    for(int i = 2; i <= k; i++)
    {
        if(n % i == 0)
        {
            flag = false;
            break;
        }
    }

    ans = (flag == true) ? "質數" : "合數";

    cout << ans ;

    return 0;
}


