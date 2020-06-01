///之前用野方法实现的，70行代码，有一个测试点还出现了段错误
//这次用map重新实现了一遍，40行代码，一次过，美滋滋
//map的值是vector时，会自动初始化为空vector，不用额外声明。也就是说无论map变量mp是否有某个键k，直接mp[k].push_back(i)，就自动创建一个键为k的项，同时压入i

#include<iostream>
#include<map>
#include<vector>

using namespace std;

int N, M;
int depth[101] = {0};
map<int, vector<int>> mp;
int Max=0;

void tra(int c,int d){
    if(mp[c].size()==0){
        depth[d]++;
        if(d>Max)
            Max = d;
    }
    for (vector<int>::iterator it = mp[c].begin(); it != mp[c].end(); it++){
        tra(*it, d + 1);
    }
}

int main(){
    cin >> N >> M;
    int id, k,idi;
    for (int i = 0; i < M; i++){
        cin >> id >> k;
        for (int j = 0; j < k; j++){
            cin >> idi;
            mp[id].push_back(idi);
        }
    }
    tra(01, 0);
    for (int i = 0; i < Max; i++)
        cout << depth[i] << " ";
    cout << depth[Max];
    system("PAUSE");
    return 0;
}