//自己写了一个小时，用枚举的方法求解，一开始写成O(n^3)，后来改进成O(n^2)，后两个case还是超时
//研究每个元素出现的次数，无果
//然后看了柳神的代码，我佛了，原来每个元素出现的次数就是它左边的长度乘右边的长度，因为两个指针在其左右移动就能代表所有包含它的子串
//柳神的方法才O(n)...

//有一个坑：接收数据时要用double，不能用float，精度不够；printf输出double时必须是lf，不能是f

#include<stdio.h>

int n;
double s = 0;

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        double tmp;
        scanf("%lf", &tmp);
        s += tmp * (i + 1) * (n - i);
    }
    
    printf("%.2f", s);
    system("PAUSE");
    return 0;
}