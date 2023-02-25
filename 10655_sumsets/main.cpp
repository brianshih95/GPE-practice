#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n && n){

        vector<int> v(n);
        for(int i=0; i<n; i++)
            cin >> v[i];

        sort(v.begin(), v.end(), greater<int>());   // 從最大的開始看

        int ans;
        bool flag = 0;

        for(int d=0; d<n && !flag; d++){
            for(int a=0; a<n && !flag; a++){
                if(a == d)
                    continue;

                for(int b=a+1; b<n && !flag; b++){
                    if(b == d)
                        continue;

                    for(int c=b+1; c<n && !flag; c++){
                        if(c == d)
                            continue;

                        if(v[d] == v[a] + v[b] + v[c]){
                            ans = v[d];
                            flag = 1;
                        }
                    }
                }
            }
        }

        if(flag)
            cout << ans << '\n';
        else
            cout << "no solution" << '\n';
    }
    return 0;
}
