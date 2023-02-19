// find median
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n){
        vector<int> v(n);
        for(int i=0; i<n; i++)
            cin >> v[i];

        int m1 = v.size() / 2;
        int m2 = (v.size() - 1) / 2;
        nth_element(v.begin(), v.begin() + m1, v.end());
        nth_element(v.begin(), v.begin() + m2, v.end());

        int cnt = 0;
        for(int i=0; i<n; i++)
           if(v[i] == v[m1] || v[i] == v[m2])
                cnt++;

        cout << v[m2] << ' ' << cnt << ' ' << v[m1] - v[m2] + 1 << '\n';
    }
    return 0;
}
