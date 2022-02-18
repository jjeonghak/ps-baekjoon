#include<iostream>
#include<queue>
using namespace std;

int arr[1000001];
queue<int> q;
priority_queue<int> pq;

int find(int cnt, int index)
{
    int lb = 0, rb = cnt;
    
    while(lb < rb)
    {
        int mid = (lb + rb) / 2;
        
        if (index == arr[mid]) return mid;
        else if (index < arr[mid]) rb = mid - 1;
        else lb = mid + 1;
    }
    return lb;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, cnt = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int index;
        
        cin >> index;
        q.push(index);
        pq.push(-index);
    }
    while (!pq.empty())
    {
        arr[cnt] = -pq.top();
        while (!pq.empty() && arr[cnt] == -pq.top())
            pq.pop();
        cnt++;
    }
    cnt--;
    while (!q.empty())
    {
        cout << find(cnt, q.front()) << ' ';
        q.pop();
    }
    return 0;
}
