#include <bits/stdc++.h>

using namespace std;

struct customer
{
    int arrive;
    int period;
    int leave;
};

int getLength(int index);
vector<customer> line;

int main()
{
    int n ,ans ,a;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        customer c;
        cin >> c.arrive >> c.period;

        if(i > 0 && line[i-1].leave >= c.arrive)
        {
            c.leave = line[i-1].leave + c.period;
        }
        else
        {
            c.leave =  c.arrive + c.period;
        }

        line.push_back(c);
    }

    for(int i = 0; i < n; i++)
    {
        a = getLength(i);
        ans = (a > ans) ? a : ans;
    }

    cout << ans;

    return 0;
}

int getLength(int index)
{
    int length = 0;
    for(int i = index+1; i < line.size(); i++)
    {
        if(line[index].leave > line[i].arrive)
        {
            length++;
        }
        else
        {
            return length;
        }
    }

    return length;
}
