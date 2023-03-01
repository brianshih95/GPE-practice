#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n){
        unordered_map<string, int> mp;
        string line;
        while(getline(cin, line)){
            if(line == "EndOfText")
                break;

            stringstream ss;
            ss << line;
            string tmp1;
            while(ss >> tmp1){
                string tmp2;
                for(int i=0; i<tmp1.size(); i++){
                    if(isalpha(tmp1[i]))
                        tmp2 += tolower(tmp1[i]);
                    else{
                        mp[tmp2]++;
                        tmp2 = "";
                    }
                }
                if(!tmp2.empty())
                    mp[tmp2]++;
            }
        }

        vector<string> ans;
        for(auto p: mp)
            if(p.second == n)
                ans.push_back(p.first);
        sort(ans.begin(), ans.end());

        if(!ans.empty())
            for(auto s: ans)
                cout << s << '\n';
        else
            cout << "There is no such word.\n";
        cout << '\n';
    }
    return 0;
}
