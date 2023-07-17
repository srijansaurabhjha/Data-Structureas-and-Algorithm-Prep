// You are given N<=1000, each with some weight w[i] . Is there a subset with total weight exactly W? W<=10^6

#include <bits/stdc++.h>
using namespace std;

int main()
{

    bool can[10001];

    int n, W;
    cin >> n, W;
    can[0] = true;
    for (int id = 0; id < n; id++)
    {
        int x;
        cin >> x;
        for (int i = W; i >= x; i--)
        {
            if (can[i - x])
                can[i] = true;
        }
    }

    cout << (can[W] ? "YES" : "NO");
    return 0;
}