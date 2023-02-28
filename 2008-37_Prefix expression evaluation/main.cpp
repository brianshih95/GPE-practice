// 無測資

//從後面開始看，一個個放入stack，遇到operator就取出兩個再放進新的數值

#include <bits/stdc++.h>

using namespace std;

bool isoperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string expr;
    while(getline(cin, expr)){
        if(expr == ".")
            break;

        vector<string> v;
        string tmp;
        for(int i=expr.size()-1; i>=0; i--){
            if(expr[i] == ' '){
                if(tmp.empty())
                    continue;
                else{
                    reverse(tmp.begin(), tmp.end());
                    v.push_back(tmp);
                    tmp = "";
                }
            }
            else if(isdigit(expr[i]))
                tmp += expr[i];
            else if(isoperator(expr[i]))
                v.push_back(string(1, expr[i]));    // 將char轉string可用string(1, c)
        }

        stack<int> s;
        int num1, num2;
        bool flag = 0;  // illegal expression detected
        for(int i=0; i<v.size(); i++){
            if(isoperator(v[i][0])){    // string轉char可用s[0]
                if(s.empty()){
                    flag = 1;
                    break;
                }
                num1 = s.top();
                s.pop();
                if(s.empty()){
                    flag = 1;
                    break;
                }
                num2 = s.top();
                s.pop();
                if(v[i] == "+")
                    s.push(num1 + num2);
                else if(v[i] == "-")
                    s.push(num1 - num2);
                else if(v[i] == "*")
                    s.push(num1 * num2);
                else if(v[i] == "/")
                    s.push(num1 / num2);
                else if(v[i] == "%")
                    s.push(num1 % num2);
            }
            else
                s.push(stoi(v[i]));
        }

        if(!flag)
            cout << s.top() << '\n';
        else
            cout << "illegal" << '\n';
    }
    return 0;
}
