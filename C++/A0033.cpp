#include <bits/stdc++.h>

using namespace std;

struct cardData
{
    char name;
    int value;
    bool adopt = false;

};

bool ready(string &s ,vector<cardData> &card);
bool detect(char add ,vector<cardData> card);
void triple(vector<string> &possible ,vector<cardData> card);
void straight(vector<string> &possible ,vector<cardData> card);
bool change(cardData a ,cardData b);
void clean(cardData &a);
bool is_correct(string attempt ,vector<cardData> card);

vector<char> S = {'1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G'};

int main()
{
    vector<string> answer;
    string wrong = "-1";
    for(int i = 0; i < 3; i++)
    {
        vector<cardData> card;
        cardData token;

        string s ,ans;
        cin >> s;

        if(ready(s ,card))
        {
            ans = "Ready for";
            for(const auto &c : S)
            {
                if(detect(c ,card))
                {
                    ans += " ";
                    ans.push_back(c);
                }
            }
        }
        else
        {
            //cout << "ready == false" << endl;
            //cout << -1;
            answer.push_back(wrong);
        }


        if(ans == "Ready for")
        {
            //cout << "Not ready";
            //cout << -1;
            answer.push_back(wrong);
        }
        else
        {
            //cout << ans;
            answer.push_back(ans);
        }
    }

    for(const auto &a : answer)
    {
        if(a == "")
        {
            continue;
        }
        else
        {
            cout << a << endl;
        }
    }



    return 0;
}

bool ready(string &s ,vector<cardData> &card)
{
    map<char ,int> quantity;
    cardData token;

    if(s.length() != 7)
    {
        //cout << "length error" << endl;
        return false;
    }

    for(const char &c : s)
    {
        clean(token);
        token.name = c;
        token.value = (int)c;
        card.push_back(token);

        if(quantity.count(c))
        {
            quantity[c]++;
        }
        else
        {
            quantity[c] = 1;
        }
    }

    for(const auto &m : quantity)
    {
        if(m.second > 4)
        {
            //cout << "quantity error" << endl;
            return false;
        }
    }

    for(const cardData &a : card)
    {
        if(!((a.value >= 49 && a.value <= 57) || (a.value >= 65 && a.value <= 71)))
        {
            //cout << a.name << " " << a.value << endl;
            //cout << "card type error" << endl;
            return false;
        }
    }

    return true;

}


bool detect(char add ,vector<cardData> card)
{
    vector<string> possible;
    vector<string> p;
    cardData a;
    clean(a);
    a.name = add;
    a.value = (int)add;
    card.push_back(a);
/*
    cout << "================" << endl;
    cout << "c: ";
    for(cardData &c : card)
    {
       cout << c.name << " " << c.value << " " << endl;;
    }
    cout << endl;
*/
    triple(possible ,card);
    straight(possible ,card);


    for(const auto &attemp : possible)
    {
        for(cardData &c : card)
        {
            c.adopt = false;
        }

        for(const char &s : attemp)
        {
            for(cardData &c : card)
            {
                if (s == c.name && c.adopt == false)
                {
                    c.adopt = true;
                    break;
                }
            }
        }
/*
        cout << "attempt: " << attemp  << endl;
        for(cardData &c : card)
        {
            cout << "name: " << c.name;
            cout << " adopt: " << c.adopt << endl;
            cout << "--------" << endl;
        }
*/

        p.clear();
        triple(p ,card);
        straight(p ,card);
/*
        cout << "p:" << endl;
        for(auto &c : p)
        {
            cout << c << endl;
        }
*/
        if(!p.empty())
        {
            for(const string &s : p)
            {
                if(is_correct(s ,card))
                {
                    return true;
                }
            }
        }
    }

    return false;

}

void triple(vector<string> &possible ,vector<cardData> card)
{
    vector<int> index;
    index.clear();

    for(int i = 0; i < 8; i++)
    {
        for(int j = i+1; j < 8; j++)
        {
            for(int k = j+1; k < 8; k++)
            {
                if(card[i].value == card[j].value && card[j].value == card[k].value && card[i].adopt == false && card[j].adopt == false && card[k].value)
                {
                    string p;
                    p.push_back(card[i].name);
                    p.push_back(card[j].name);
                    p.push_back(card[k].name);
                    possible.push_back(string(p));
                }
            }
        }
    }
}

void straight(vector<string> &possible ,vector<cardData> card)
{
    sort(card.begin() ,card.end() ,change);

    for(int i = 0; i < 8; i++)
    {
        for(int j = i + 1; j < 8; j++)
        {
            if(card[i].value + 1 == card[j].value && card[i].adopt == false)
            {
                for(int k = j + 1; k < 8; k++)
                {
                    if(card[j].value + 1 == card[k].value && card[j].adopt == false && card[k].adopt == false)
                    {
                        if(card[i].value >= 65 && card[i].value <= 71)
                        {
                            continue;
                        }
                        else
                        {
                            string p;
                            p.push_back(card[i].name);
                            p.push_back(card[j].name);
                            p.push_back(card[k].name);

                            possible.push_back(string(p));
                        }
                    }
                }
            }
        }
    }
}

bool is_correct(string attempt ,vector<cardData> card)
{
    for(const char &s : attempt)
    {
        for(cardData &c : card)
        {
            if(s == c.name && c.adopt == false)
            {
                c.adopt = true;
                break;
            }
        }
    }
/*
    cout << "is_correct: " << attempt << endl;
    for(cardData &c : card)
    {
        cout << "name: " << c.name;
        cout << " adopt: " << c.adopt << endl;
        cout << "--------" << endl;
    }
*/
    vector<int> k;
    for(cardData &c : card)
    {
        if(c.adopt == false)
        {
            k.push_back(c.value);
        }
    }

    if(k[0] == k[1])
    {
        //cout << "true" << endl;
        return true;
    }
    else
    {
        //cout << "false" << endl;
        return false;
    }
}

bool change(cardData a ,cardData b)
{
    return a.value < b.value;
}

void clean(cardData &a)
{
    a.name = '0';
    a.value = 0;
    a.adopt = false;
}
