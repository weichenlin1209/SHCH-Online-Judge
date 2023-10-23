#include <bits/stdc++.h>

using namespace std;

map<char ,int> alphabet;


int _minus(char a ,char b)
{
    int result;
    result = alphabet[a] - alphabet[b];
    if(result < 0)
    {
        result *= -1;
    }

    return result;
}


int main()
{
    for(int i = 0; i < 26; i++)
    {
        int a = 65;
        a += i;
        char s ;
        s = (char) a;

        alphabet[s] = i+1;
    }

    int s;
    string n ,k ,ans;
    cin >> n;

    for(int i = 0; i < n.length()-1; i++)
    {

        s = _minus(n[i] ,n[i+1]);
        k = to_string(s);

        ans += k;
    }

    cout << ans;

    return 0;
}


