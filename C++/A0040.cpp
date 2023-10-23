#include <bits/stdc++.h>

using namespace std;

map<int, string> m =
{
  {0, "0"},
  {1, "1"},
  {2, "2"},
  {3, "3"},
  {4, "4"},
  {5, "5"},
  {6, "6"},
  {7, "7"},
  {8, "8"},
  {9, "9"},
  {10, "A"},
  {11, "B"},
  {12, "C"},
  {13, "D"},
  {14, "E"},
  {15, "F"}
};

string hex(int num);

int main()
{
    int num;
    string ans;
    cin >> num;

    ans = hex(num);

    reverse(ans.begin() ,ans.end());

    cout << ans;

    return 0;
}

string hex(int num)
{
    string ans;

    if (num < 16)
    {
        return ans + m[num];
    }
    else
    {
        return ans + m[num % 16] + hex(num / 16);
    }
}
