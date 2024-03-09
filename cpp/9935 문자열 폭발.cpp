#include<iostream>
#include<deque>
using namespace std;

string  s1, s2;
deque<char> s;

void    ft_print()
{
    while (!s.empty())
    {
        cout << s.front();
        s.pop_front();
    }
    return ;
}

int check(int index)
{
    if (index == -1) return 1;
    else
    {
        char    c;
        
        c = s.back();
        s.pop_back();
        if (c == s2[index] && check(index - 1)) return 1;
        else
        {
            s.push_back(c);
            return 0;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
    {
        s.push_back(s1[i]);
        if (s1[i] == s2[s2.length() - 1] && s.size() >= s2.length())
            check(s2.length() - 1);
    }
    if (s.empty()) cout << "FRULA";
    else ft_print();
    return 0;
}
