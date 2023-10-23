#include <bits/stdc++.h>

using namespace std;

const int muilty[] = {1, 2, 3, 5, 7, 11};

int main()
{
    string identity;
    cin >> identity;

    if(identity.size() != 6)
    {
        cout << "¿ù»~";
        return 0;
    }

    int first = (int)identity[0] - 65;
    if (first < 0 || first > 25)
    {
        cout << "¿ù»~";
        return 0;
    }

    if(identity[1] != '1' && identity[1] != '2')
    {
        cout << "¿ù»~";
        return 0;
    }

    int check = first;
    for(int i = 1; i < 6; i++)
    {
        check += ((int)identity[i] - '0') * muilty[i];
        check = check % 10;
    }

    cout << identity << check;

    return 0;
}
