//完成时间：5/27/2020

//坑点：无，完全二叉树的遍历还是很简单的

#include<iostream>
#include<queue>

using namespace std;

int Data[110][1010]={0};
int M, N;

queue<int> q;

bool isMaxHeap(int t, int root){
    int left = root * 2;
    int right = left + 1;
    if(right<=N){
        if(Data[t][left]<=Data[t][root]&&Data[t][right]<=Data[t][root])
            return isMaxHeap(t, left) && isMaxHeap(t, right);
        else
            return false;
    }
    else if(left<=N){
        return Data[t][root] >= Data[t][left];
    }
    else
        return true;
}

bool isMinHeap(int t, int root){
    int left = root * 2;
    int right = left + 1;
    if(right<=N){
        if(Data[t][left]>=Data[t][root]&&Data[t][right]>=Data[t][root])
            return isMinHeap(t, left) && isMinHeap(t, right);
        else
            return false;
    }
    else if(left<=N){
        return Data[t][root] <= Data[t][left];
    }
    else
        return true;
}

void postorder(int t, int root){
    int left = root * 2;
    int right = left + 1;
    if(right<=N){
        postorder(t, left);
        postorder(t, right);
        q.push(Data[t][root]);
    }
    else if(left<=N){
        postorder(t, left);
        q.push(Data[t][root]);
    }
    else
        q.push(Data[t][root]);
}

int main(){
    cin >> M >> N;
    for (int i = 1; i < M+1; i++){
        for (int j = 1; j < N+1; j++){
            cin >> Data[i][j];
        }
    }
    for (int i = 1; i <= M; i++){
        if(isMaxHeap(i,1))
            cout << "Max Heap\n";
        else if(isMinHeap(i,1))
            cout << "Min Heap\n";
        else
            cout << "Not Heap\n";
        postorder(i, 1);
        while(q.size()>1){
            cout << q.front() << " ";
            q.pop();
        }
        cout << q.front() << endl;
        q.pop();
    }
    system("PAUSE");
    return 0;
}