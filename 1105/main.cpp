//说不上题目坑吧，就是一道模拟题
//注意判断t的范围，等于N的时候就不要填充了

#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

vector<int> num;
int m, n, N;
vector<vector<int>> mtx;

bool cmp(int a, int b) {
    return a > b;
}

void find_m_n() {
    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            n = i;
            m = N / i;
        }
    }
}

void fill_matrix() {
    //初始化
    vector<int> tmp;
    tmp.resize(n, 0);
    for (int i = 0; i < m; i++) {
        mtx.push_back(tmp);
    }
    //填充
    int corner = 0;
    int right = n;
    int low = m;
    //向右填充
    int t = 0;
    while (corner < right) {
        for (int i = corner; i < right; i++)
        {
            if(t<N)
                mtx[corner][i] = num[t++];
        }
        //向下填充
        for (int i = corner + 1; i < low; i++) {
            if (t < N)
                mtx[i][right - 1] = num[t++];
        }
        //向左填充
        for (int i = right - 2; i >= corner; i--) {
            if (t < N)
                mtx[low - 1][i] = num[t++];
        }
        //向上填充
        for (int i = low - 2; i > corner; i--) {
            if (t < N)
                mtx[i][corner] = num[t++];
        }
        corner++;
        right--;
        low--;
    }
}

int main() {
    scanf("%d", &N);
    num.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }
    find_m_n();
    sort(num.begin(), num.end(), cmp);
    fill_matrix();
    //输出
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", mtx[i][j]);
            if (j < n - 1)
                printf(" ");
            else
                printf("\n");
        }
    }
    system("PAUSE");
    return 0;
}