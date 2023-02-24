#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string, int> mp;

    int m, n;
    cin >> m >> n;

    while(m--){
        string s;
        int num;
        cin >> s >> num;
        mp[s] = num;
    }

    while(n--){
        string word;
        int salary = 0;
        while(cin >> word){ // cin遇到space會停下來
            if(word == ".")
                break;

            if(mp.find(word) != mp.end())
                salary += mp[word];
        }

        cout << salary << '\n';
    }
    return 0;
}
