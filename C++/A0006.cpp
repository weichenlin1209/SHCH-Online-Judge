#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    cin >> a;

    if (a > 100){
        cout << "錯誤";

    }else if (a >= 90){
        cout << "優";

    }else if (a >= 80){
        cout << "甲";

    }else if (a >= 70){
        cout << "乙";

    }else if (a >= 60){
        cout << "丙";

    }else if (a >= 0){
        cout << "丁";

    }else{
        cout << "錯誤";
    }

    return 0;
}



