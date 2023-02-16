#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    string name;
    vector<TreeNode> children;
    TreeNode():name(), children(){};
    TreeNode(string _name):name(_name), children(){};
};

bool cmp(TreeNode& a, TreeNode& b){
    return a.name < b.name; // ����r��j�p�i�H������
}

void insert(TreeNode& root, vector<string>& names){
    if(names.empty())
        return;

    int idx = -1;
    for(int i = 0; i < root.children.size(); i++){
        if(names[0] == root.children[i].name){
            idx = i;
            break;
        }
    }
    if(idx == -1){  // �Ĥ@���X�{
        TreeNode newNode(names[0]);
        names.erase(names.begin());
        root.children.push_back(newNode);
        insert(root.children.back(), names);    // �����D��ԣ�����newNode
    }
    else{   // �w�g�X�{�L��
        names.erase(names.begin());
        insert(root.children[idx], names);
    }
}

void sort(TreeNode& root){
    sort(root.children.begin(), root.children.end(), cmp);
    for(TreeNode& child: root.children)
        sort(child);
}

void print(TreeNode& root, int spaces){
    for(int i = 0; i < spaces; i++)
        cout << ' ';
    cout << root.name << '\n';
    for(TreeNode& child: root.children)
        print(child, spaces + 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    TreeNode root;
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        vector<string> names;
        while(s.find("\\") != string::npos){    // �r�ꪺfind�|�^�Ǿ��
            names.push_back(s.substr(0, s.find("\\"))); // substr(�_�l��m, ����)
            s.erase(0, s.find("\\") + 1);
        }
        names.push_back(s);
        insert(root, names);
    }
    sort(root);
    for(TreeNode& child: root.children)
        print(child, 0);
    return 0;
}
