#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string  index;
    queue<char> q;
    stack<char> s;
    
    cin >> index;
    for (int i = 0; index[i] != '\0'; i++)
    {
        if (isalpha(index[i])) q.push(index[i]);
        else 
        {
            if (index[i] == ')')
            {
                while (s.top() != '(')
                {
                    q.push(s.top());
                    s.pop();
                }
                s.pop();
            }
            else if (index[i] == '*' || index[i] == '/')
            {
                while (!s.empty() && (s.top() == '*' || s.top() == '/'))
                {
                    q.push(s.top());
                    s.pop();
                }
                s.push(index[i]);
            }
            else if (index[i] == '+' || index[i] == '-')
            {
                while (!s.empty() && s.top() != '(')
                {
                    q.push(s.top());
                    s.pop();
                }
                s.push(index[i]);
            }
            else s.push(index[i]);
        }
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }
    return 0;
}
