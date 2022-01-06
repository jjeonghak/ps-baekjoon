#include<iostream>
using namespace std;

class   Stack
{
private:
    int ptr;
    int index[10001];

public:
    Stack() : ptr(0) {}
    void    push(int x) { index[++ptr] = x; }
    int     pop()
    {
        if (this->empty()) return -1;
        else return index[ptr--];
    }
    int     size() { return ptr; }
    int     empty()
    {
        if (ptr == 0 ) return 1;
        else return 0;
    }
    int    top()
    {
        if (this->empty()) return -1;
        else return index[ptr];
    }
};

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    
    cin >> n;
    Stack s;
    for (int i = 0; i < n; i++)
    {
        string command;
        
        cin >> command;
        if (command == "push")
        {
            int index;
            
            cin >> index;
            s.push(index);
        }
        else if (command == "pop") cout << s.pop() << '\n';
        else if (command == "size") cout << s.size() << '\n';
        else if (command == "empty") cout << s.empty() << '\n';
        else if (command == "top") cout << s.top() << '\n';
    }
    return 0;
}
