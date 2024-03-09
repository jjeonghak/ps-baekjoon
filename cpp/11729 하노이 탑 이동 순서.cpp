#include<iostream>
#include<math.h>
using namespace std;

int n;

void    hanoi(int n, int s, int e)
{
    if (n == 0) return ;
    hanoi(n - 1, s, 6 - s - e);
    cout << s << ' ' << e << '\n';
    hanoi(n - 1, 6 - s - e, e);
    return ;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    cout << (long long)pow(2, n) - 1 << '\n';
    hanoi(n, 1, 3);
    return 0;
}
