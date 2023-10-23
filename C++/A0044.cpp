#include <bits/stdc++.h>

using namespace std;

string eval(int num);

map<int, string> val =
{
  {1 ,"I"},
  {4 ,"IV"},
  {5 ,"V"},
  {9 ,"IX"},
  {10 ,"X"},
  {40 ,"XL"},
  {50 ,"L"},
  {90 ,"XC"},
  {100 ,"C"},
  {400 ,"CD"},
  {500 ,"D"},
  {900 ,"CM"},
  {1000 ,"M"},
};

int main()
{
    int a;
    cin >> a;

    cout << eval(a);

    return 0;
}

string eval(int num)
{
    string ans;
    for(auto i = val.rbegin(); i != val.rend(); i++)
    {
        if(num >= (*i).first)
        {
            return ans + (*i).second + eval(num - (*i).first);
            break;
        }
    }

    return ans;
}
