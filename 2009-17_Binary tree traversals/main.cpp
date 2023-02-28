// 無測資
// preorder[0]為root，將inorder分成兩半

#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> inIdx; // 紀錄inorder的idx
int preIdx;

void postorder(vector<char>& in, vector<char>& pre, int start, int end){
    if(start > end)
        return;

    int idx = inIdx[pre[preIdx]];
    preIdx++;
    postorder(in, pre, start, idx-1);   // left subtree
    postorder(in, pre, idx+1, end);     // right subtree
    cout << in[idx] << ' ';             // root
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> m;
    while(m--){
        inIdx.clear();
        preIdx = 0;

        int n;
        cin >> n;
        vector<char> pre(n), in(n);
        for(int i=0; i<n; i++)
            cin >> pre[i];
        for(int i=0; i<n; i++){
            cin >> in[i];
            inIdx[in[i]] = i;
        }

        postorder(in, pre, 0, n-1);
        cout << '\n';
    }
    return 0;
}
