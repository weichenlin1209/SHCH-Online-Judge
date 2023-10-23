#include <bits/stdc++.h>

using namespace std;

vector<string> a;
vector<string> b;
vector<int> ans;

int main()
{
    int M ,N;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> M;

        for(int j = 0; j < M; j++)
        {
            string A ,B;
            cin >> A >> B;

            a.push_back(A);
            b.push_back(B);
        }


        int p = 0;
        for(int j = 0; j < M; j++)
        {
            for(int k = j+1; k < M; k++)
            {
                if(b[j] == a[k] && b[k] == a[j])
                {
                    p++;
                    M--;

                    a.erase(a.begin() + k);
                    b.erase(b.begin() + k);
                }


            }
        }

        ans.push_back(p);

        a.clear();
        b.clear();
    }


    for(int &v : ans)
    {
        printf("%d\n" ,v);
    }

    return 0;
}
