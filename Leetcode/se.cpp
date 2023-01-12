#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<int> pre(n, 1), suf(n, 1), ans(n, 1);

    pre[0] = 1;
    for (int i = 1; i < n; i++)
    {
        pre[i] = nums[i - 1] * pre[i - 1];
    }

    suf[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = nums[i + 1] * suf[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        ans[i] = pre[i] * suf[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}