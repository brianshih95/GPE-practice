//將數字排序後轉成字串，記錄在map中

#include <bits/stdc++.h>

using namespace std;

string concat(vector<int>& v){
    stringstream ss;
    string res;
    for(int i: v)
        ss << i;
    ss >> res;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n){
        if(!n)
            break;

        unordered_map<string, int> mp;
        while(n--){
            vector<int> v(5);
            for(int i=0; i<5; i++)
               cin >> v[i];
            sort(v.begin(), v.end());
            string s = concat(v);
            mp[s]++;
        }

        int max = 0, cnt = 0;
        for(auto [s, i]: mp){
            if(i > max){    // 出現新高
                max = i;
                cnt = i;
            }
            else if(i == max)   // 跟最熱門的一樣多，也要算進去
                cnt += i;
        }
        cout << cnt << '\n';
    }
    return 0;
}
