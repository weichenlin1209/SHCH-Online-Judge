#include <bits/stdc++.h>

using namespace std;

struct Meeting{
    int index;
    int startTime;
    int endTime;
};

bool compare(Meeting a, Meeting b)
{
    return a.endTime < b.endTime;
}


int main()
{
    int n;
    cin >> n;

    vector<Meeting> meetings;
    vector<int> selectedMeet;

    //data storage
    for(int i = 0; i < n; i++)
    {
        Meeting s;
        cin >> s.index >> s.startTime >> s.endTime;
        meetings.push_back(s);
    }

    //select Meeting
    sort(meetings.begin() ,meetings.end() ,compare);

    int lastEndTime = 0;

    for(int i = 0; i < n; i++)
    {
        if (meetings[i].startTime >= lastEndTime)
        {
            selectedMeet.push_back(meetings[i].index);
            lastEndTime = meetings[i].endTime;
        }
    }

    cout << selectedMeet.size() << endl;

    for(int i = 0; i < selectedMeet.size(); i++)
    {
        cout << ((i == 0) ? "": " ") << selectedMeet[i];
    }




    return 0;
}


