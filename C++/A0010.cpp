#include <bits/stdc++.h>

using namespace std;


int main()
{
    int times;
    string a;
    cin >> a >> times;
    int r = stoi(a);

    for(int i = 1; i < times; i++)
    {
        int s = stoi(a);
        s *= r;
        a = to_string(s);

        if(a.length() > 5)
        {
            string temp = "";
            for(int j  = a.length()-5; j < a.length(); j++)
            {
                temp += a[j];
            }

            a = temp;
        }

    }

    int ans = stoi(a);
    cout << ans;

    return 0;
}


