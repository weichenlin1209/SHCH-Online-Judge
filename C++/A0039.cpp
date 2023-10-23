#include <bits/stdc++.h>

using namespace std;

map<int ,int> all_num;
int main()
{
    int times;
    cin >> times;

    for(int i = 0; i < times; i++)
    {
        int n;
        cin >> n;

        if (all_num.empty() == true)
        {
            all_num[n] = 1;
        }
        else if (all_num.count(n) > 0)
        {
            all_num[n] += 1;
        }
        else
        {
            all_num[n] = 1;
        }
    }

    int max_val ,max_times = 0;

    for(const auto &s : all_num)
    {
        if (s.second >= max_times)
        {
            max_val = s.first;
            max_times = s.second;
        }
    }

    cout << max_val << " " << max_times << endl;

    return 0;
}


