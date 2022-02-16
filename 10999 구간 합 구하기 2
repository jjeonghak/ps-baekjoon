#include<iostream>

using namespace std;

int n, m, k, r;
long long   seg[1 << 21];
long long   lazy[1 << 21];
long long   arr[1 << 20];

long long   set_seg(int index, int s, int e)  //일반적인 인덱스트리가 아닌 세그멘트 트리로 만들어야 
{
    if (s == e)
        return seg[index] = arr[s];
    int mid = (s + e) / 2;
    return seg[index] = set_seg(2 * index, s, mid) + set_seg(2 * index + 1, mid + 1, e);
}

void    lazy_propagation(int index, int s, int e)
{
    int mid = (s + e) / 2;
    seg[2 * index] += (mid - s + 1) * lazy[index];
    seg[2 * index + 1] += (e - mid) * lazy[index];
    lazy[2 * index] += lazy[index];
    lazy[2 * index + 1] += lazy[index];
    lazy[index] = 0;
    return ;
}

void    update_seg(int lb, int rb, long long add, int index, int s, int e)
{
    if (rb < s || e < lb) return ;
    else if (lb <= s && e <= rb)
    {
        seg[index] += (e - s + 1) * add;
        lazy[index] += add;
        return ;
    }
    lazy_propagation(index, s, e);
    int mid = (s + e) / 2;
    update_seg(lb, rb, add, 2 * index, s, mid);
    update_seg(lb, rb, add, 2 * index + 1, mid + 1, e);
    seg[index] = seg[2 * index] + seg[2 * index + 1];
    return ;
}

long long   query_seg(int lb, int rb, int index, int s, int e)
{
    if (rb < s || e < lb) return 0;
    else if (lb <= s && e <= rb) return seg[index];
    lazy_propagation(index, s, e);
    int mid = (s + e) / 2;
    return query_seg(lb, rb, 2 * index, s, mid)
            + query_seg(lb, rb, 2 * index + 1, mid + 1, e);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> k;
    for (r = 1; r < n; r <<= 1);
    for (int i = 0; i < n; i++)
    {
        long long   index;
        
        cin >> index;
        arr[i] = index;
    }
    set_seg(1, 0, n - 1);
    for (int i = 0; i < m + k; i++)
    {
        int a, b, c;
        
        cin >> a >> b >> c;
        if (a == 1)
        {
            long long   d;
            
            cin >> d;
            update_seg(r + b - 1, r + c - 1, d, 1, r, r + n - 1);
        }
        else
            cout << query_seg(r + b - 1, r + c - 1, 1, r, r + n - 1) << '\n';
    }
    return 0;
}
