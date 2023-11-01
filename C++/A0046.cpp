#include <bits/stdc++.h>

using namespace std;

enum TokenType
{
    OPERATOR, OPERAND ,ERROR
};

typedef struct {
    TokenType type = TokenType::ERROR;
    string val;
    int numerator = 0;
    int denominator = 0;
    int order = 0;
} Token;

const string OP = "+-*/";
const int Priority[] = {1, 1, 2, 2};
void ToInfix(string s, vector<Token> &infix);
void ToPostfix(vector<Token> &infix ,vector<Token> &postfix);
Token evaluate(vector<Token> &postfix);

int main()
{
    string expression;
    vector<Token> infix;
    vector<Token> postfix;
    Token result;

    cin >> expression;

    ToInfix(expression ,infix);
    ToPostfix(infix ,postfix);
    result = evaluate(postfix);

    cout << result.numerator << "/" << result.denominator;
    return 0;
}

int GetPrioirty(char s)
{
    int result = -1;
    if(OP.find(s) != string::npos)
        result = Priority[OP.find(s)];

    return result;
}

TokenType GetType(Token s)
{
    if(s.denominator == 0 && s.numerator == 0)
        return TokenType::OPERATOR;

    return TokenType::OPERAND;
}

void init(Token &t)
{
    t.type = TokenType::ERROR;
    t.val = "";
    t.numerator = 0;
    t.denominator = 0;
    t.order = 0;
}

string ctos(char &c)
{
    string s;
    return s+c;
}

void ToInfix(string s, vector<Token> &infix)
{
    int OPtimes = 0;
    Token token;
    string operand ,value;

    for(int i = 0; i < s.size(); i++)
    {
        if(OP.find(s[i]) != string::npos)
        {
            OPtimes++;

            if(OPtimes % 2 == 0)
            {
                //operand
                token.denominator = stoi(operand);
                token.val = value;
                token.type = GetType(token);
                infix.push_back(token);

                init(token);
                value = "";
                operand = "";

                //operator
                token.val = ctos(s[i]);
                token.type = GetType(token);
                token.order = GetPrioirty(s[i]);
                infix.push_back(token);
                init(token);
            }
            else if(OPtimes % 2 == 1)
            {
                token.numerator = stoi(operand);
                value += "/";
                operand = "";
            }
        }
        else
        {
            operand += s[i];
            value += s[i]; 
        }
    }

    token.denominator = stoi(operand);
    token.val = value;
    token.type = GetType(token);
    infix.push_back(token);
}

void ToPostfix(vector<Token> &infix ,vector<Token> &postfix)
{
    stack<Token> sOP;

    for(const Token &token : infix)
    {
        if(token.type == TokenType::OPERAND)
        {
            postfix.push_back(token);
        }
        else
        {
            if(sOP.empty())
            {
                sOP.push(token);
            }
            else
            {
                while(token.order >= sOP.top().order)
                {
                    postfix.push_back(sOP.top());
                    sOP.pop();

                    if(sOP.empty())
                    {
                        sOP.push(token);
                        break;
                    }
                }
            }
        }
    }

    while(!sOP.empty())
    {
        postfix.push_back(sOP.top());
        sOP.pop();
    }
}

void view(Token &a)
{
    cout << a.numerator << "/" << a.denominator << endl;
}

int GCD(int a ,int b)
{
    int tmp;
    while (a % b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }

    return b;
}

void simplifyFraction(Token &token)
{
    int gcd = GCD(token.denominator ,token.numerator);

    token.denominator /= gcd;
    token.numerator /= gcd;
}

void CommonPoint(Token &a ,Token &b)
{
    a.numerator *= b.denominator;
    b.numerator *= a.denominator;
    a.denominator *= b.denominator;
    b.denominator = a.denominator;
}



Token operator+ (Token a ,Token b)
{
    Token ans;
    init(ans);
    ans.type = TokenType::OPERAND;

    CommonPoint(a ,b);
    

    ans.numerator = a.numerator + b.numerator;
    ans.denominator = a.denominator;

    simplifyFraction(ans);

    return ans;
}

Token operator- (Token a ,Token b)
{
    Token ans;
    ans.type = TokenType::OPERAND;

    CommonPoint(a ,b);
    ans.numerator = a.numerator - b.numerator;
    ans.denominator = a.denominator;
    simplifyFraction(ans);

    return ans;

}

Token operator* (Token a ,Token b)
{
    Token ans;
    ans.type = TokenType::OPERAND;

    ans.numerator = a.numerator * b.numerator;
    ans.denominator = a.denominator * b.denominator;

    simplifyFraction(ans);

    return ans;

}

Token operator/ (Token a ,Token b)
{
    Token ans;
    ans.type = TokenType::OPERAND;

    ans.numerator = a.numerator * b.denominator;
    ans.denominator = a.denominator * b.numerator;

    simplifyFraction(ans);

    return ans;

}

Token evaluate(vector<Token> &postfix)
{
    stack<Token> calculate;
    int top = 0;

    for(int i = 0; i < postfix.size(); i++)
    {
        if(postfix[i].type == OPERAND)
        {
            calculate.push(postfix[i]);
            top++;
        }
        else
        {
            Token a ,b ,result;
            b = calculate.top();
            calculate.pop();
            a = calculate.top();
            calculate.pop();

            if(postfix[i].val == "+")
            {
                result = a + b;
            }
            else if(postfix[i].val == "-")
            {
                result = a - b;
            }
            else if(postfix[i].val == "*")
            {
                result = a * b;
            }
            else if(postfix[i].val == "/")
            {
                result = a / b;
            }

            calculate.push(result);
        }
    }

    return calculate.top();
}