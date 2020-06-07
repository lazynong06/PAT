//重新自己写柳婼的代码
//被自己菜哭

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include<stdio.h>
#include<cmath>

using namespace std;

int n, p, k, maxFacSum = -1;
vector<int> v, ans, tempAns;

void init() {
    int index = 0, temp = 0;
    while (temp <= n) {
        v.push_back(temp);
        index++;
        temp = pow(index, p);
    }
}

void dfs(int index, int tempK, int tempSum, int facSum) {
    if (tempK == k) {
        if (tempSum == n && facSum > maxFacSum) {
            ans = tempAns;
            maxFacSum = facSum;
        }
        return;
    }
    while (index) {
        if (v[index] + tempSum <= n) {
            tempAns[tempK] = index;
            bfs(index, tempK + 1, tempSum + v[index], facSum + index);
        }
        index--;
    }
}

int main() {
    scanf_s("%d%d%d", &n, &k, &p);
    init();
    tempAns.resize(k);
    dfs(v.size()-1, 0, 0, 0);
    if (maxFacSum == -1)
    {
        printf("Impossible");
        system("PAUSE");
        return 0;
    }
    printf("%d = ", n);
    for (int i = 0; i < k; i++) {
        printf("%d^%d", ans[i], p);
        if (i != k - 1)
            printf(" + ");
    }
    system("PAUSE");
    return 0;
}