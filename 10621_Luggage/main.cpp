/*
很明顯總和為奇數必定無法平分
而偶數的狀況下，把總和的一半拿來當作背包的容量
就變成0/1背包問題了
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> m;
    cin.ignore();   // 避免getline將"\n"當作string
    while(m--){
        string line;
        stringstream ss;
        getline(cin, line);
        ss << line;

        vector<int> v;
        int weight, sum = 0;
        while(ss >> weight){
            v.push_back(weight);
            sum += weight;
        }

        if(sum & 1){
            cout << "NO" << '\n';
            continue;
        }

        vector<bool> dp(sum + 1, 0);    // dp[i]表示現有的行李是否能組成i公斤
        dp[0] = 1;

        for(int i=0; i<v.size(); i++)
            for(int j=sum; j>=v[i]; j--)
                if(dp[j - v[i]])
                    dp[j] = 1;

        cout << (dp[sum/2] ? "YES" : "NO") << '\n';

    }
    return 0;
}
