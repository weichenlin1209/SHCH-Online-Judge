#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    if (n % 400 == 0) {
        cout << "閏年";

    }else if (n % 4 == 0) {
        if (n % 100 == 0) {
            cout << "平年";
        }else {
            cout << "閏年";
        }


    }else {
        cout << "平年";
    }
    return 0;
}



