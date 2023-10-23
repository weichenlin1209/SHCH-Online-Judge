#include <bits/stdc++.h>

using namespace std;

string reverse_str(string s)
{
    string result;

    for(int i = s.length()-1; i >= 0; i--)
    {
        result += s[i];
    }

    return result;
}


int main()
{
    map<int,string> t_price;
    set<int> num;

    int n ,r_price;
    string price ,s;


    cin >> n;

    for(int i = 0; i < n; i++)
    {

        cin >> price;

        s = reverse_str(price);
        r_price = stoi(s);

        t_price[r_price] = price;
        num.insert(r_price);

    }

    set<int>::iterator low = num.begin();

    cout << t_price[*low] << " ";

    for(low = num.begin(); low != num.end(); low++)
    {

    }

    *low--;
    cout << t_price[*low];

    return 0;
}


