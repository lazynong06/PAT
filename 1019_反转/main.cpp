//坑点：不能用string存回文！因为string最大长度为255，如果输入的N为1e+9，b为2，肯定会超过string的长度

#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> d2x(int n,int b){
    vector<int> r;
    while(n){
        r.push_back(n % b);
        n /= b;
    }
    return r;
}

//判断是否为回文
bool isP(vector<int> s){
    bool flag = true;
    int len = s.size();
    for (int i = 0; i < len / 2 + 1; i++){
        if(s[i]!=s[len-i-1]){
            flag = false;
            break;
        }
    }
    return flag;
}

int main(){
    int N, b;
    cin >> N >> b;
    if(N<b){
        cout << "Yes\n"
             << N;
    }
    else{
        vector<int> r = d2x(N, b);
        if(isP(r))
            cout << "Yes\n";
        else
            cout << "No\n";
        int len = r.size();
        for (int i = 0; i < len - 1; i++){
            cout << r[len-i-1] << " ";
        }
        cout << r[0];
    }
    system("PAUSE");
    return 0;
}