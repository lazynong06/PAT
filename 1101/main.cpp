//结果列表为空时单独处理，否则会出现段错误，而且列表为空时，第二行输出也要输出一个换行，不然格式错误
//这题时间复杂度O(n)，直接从左到右扫描，同时记录最大值；再从右到左扫描，同时记录最小值

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int num[100000];
bool Left[100000];
int N;

vector<int> result;

bool cmp(int a,int b){
    return a < b;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> num[i];
    }

    //从左到右遍历，同时记录路径上的最大值
    int Max = 0;
    for (int i = 0; i < N; i++){
        if(num[i]>Max){
            Left[i] = true;
            Max = num[i];
        }
        else{
            Left[i] = false;
        }
    }
    int Min = 0x7fffffff;
    for (int i = N-1; i >= 0; i--){
        if(num[i]<Min){
            Min = num[i];
            if(Left[i])
                result.push_back(num[i]);
        }
    }
    cout << result.size() << endl;
    if(result.size()>0){
        sort(result.begin(), result.end(), cmp);
        for (int i = 0; i < result.size() - 1; i++){
            cout << result[i] << ' ';
        }
        cout << result[result.size() - 1];
    }
    system("PAUSE");
    return 0;
}