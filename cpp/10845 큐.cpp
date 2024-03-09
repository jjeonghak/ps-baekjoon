#include<iostream>
using namespace std;

class   Queue
{
private:
    int lb;
    int rb;
    int index[10001];

public:
    Queue() : lb(1), rb(0) {}
    void    push(int x) { index[++rb] = x; }
    int     pop()
    {
        if (this->empty()) return -1;
        else return index[lb++];
    }
    int     size() { return rb - lb + 1; }
    int     empty()
    {
        if (lb > rb ) return 1;
        else return 0;
    }
    int    front()
    {
        if (this->empty()) return -1;
        else return index[lb];
    }
    int     back()
    {
        if (this->empty()) return -1;
        else return index[rb];
    }
};

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    
    cin >> n;
    Queue q;
    for (int i = 0; i < n; i++)
    {
        string command;
        
        cin >> command;
        if (command == "push")
        {
            int index;
            
            cin >> index;
            q.push(index);
        }
        else if (command == "pop") cout << q.pop() << '\n';
        else if (command == "size") cout << q.size() << '\n';
        else if (command == "empty") cout << q.empty() << '\n';
        else if (command == "front") cout << q.front() << '\n';
        else if (command == "back") cout << q.back() << '\n';
    }
    return 0;
}
