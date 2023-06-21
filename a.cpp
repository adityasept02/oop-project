#include <bits/stdc++.h>
using namespace std;
#define ll int long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        while (n)
        {
            ans += n;
            n = n / 2;
        }
        cout << ans << endl;
    }
    return 0;
}