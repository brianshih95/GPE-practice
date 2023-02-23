//�N�Ʀr�Ƨǫ��ন�r��A�O���bmap��

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
            if(i > max){    // �X�{�s��
                max = i;
                cnt = i;
            }
            else if(i == max)   // ��̼������@�˦h�A�]�n��i�h
                cnt += i;
        }
        cout << cnt << '\n';
    }
    return 0;
}
