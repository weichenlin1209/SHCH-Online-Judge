#include <bits/stdc++.h>

using namespace std;

struct coordinate
{
    int x;
    int y;
    float dist;
};

float distance(int x ,int y);
bool cmp(coordinate a, coordinate b);

vector<coordinate> pos;

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        coordinate c;
        cin >> c.x >> c.y;

        c.dist = distance(c.x ,c.y);
        pos.push_back(c);
    }

    sort(pos.begin() ,pos.end() ,cmp);

    for(int i = 0; i < n-1; i++)
    {
        printf("%d %d\n",pos[i].x ,pos[i].y);
    }
    printf("%d %d",pos[n-1].x ,pos[n-1].y);

    return 0;
}

float distance(int x ,int y)
{
    int a = pow(x ,2) + pow(y ,2);
    return sqrt(a);
}

bool cmp(coordinate a, coordinate b)
{
    if(a.dist == b.dist)
    {
        if(a.x == b.x)
        {
            if(a.y == b.y)
            {
                return true;
            }

            return a.y < b.y;
        }

        return a.x < b.x;
    }

    return a.dist < b.dist;
}


