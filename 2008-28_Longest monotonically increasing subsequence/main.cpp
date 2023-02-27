// �L����

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<ll>> LISs;

void backtrack(int tail, vector<ll>& v, vector<int>& len, vector<ll>& tmp, int longest){
    // ��FLIS���}�Y�F
    if(tmp.size() == longest){
        LISs.push_back(tmp);
        return;
    }

    for(int i=0; i<tail; i++){
        if(v[i] <= v[tail] && len[i]+1 == len[tail]){
            tmp.push_back(v[i]);
            backtrack(i, v, len, tmp, longest);
            tmp.pop_back(); // ���n�ѰOpop�A���M�|�v�T���Lcase
        }
    }
}

void LIS(int n, vector<ll>& v){
    vector<int> len(n, 1);  // ��v[i]�ү�զ��̪���LIS����

    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(v[i] <= v[j])
                len[j] = max(len[j], len[i]+1);

    int longest = *max_element(len.begin(), len.end());

    for(int i=0; i<n; i++){
        if(len[i] == longest){
            vector<ll> tmp = {v[i]};    // �ΨӦs�ULIS
            backtrack(i, v, len, tmp, longest);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> m;
    while(m--){
        LISs.clear();
        int n;
        cin >> n;
        vector<ll> v(n);
        for(int i=0; i<n; i++)
            cin >> v[i];

        LIS(n, v);

        cout << LISs.size() << '\n';
        for(auto v: LISs){
            for(int i=v.size()-1; i>=0; i--)
                cout << v[i] << ' ';
            cout << '\n';
        }
    }
    return 0;
}
