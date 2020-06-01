//坑点：编号13位，如果用long long int储存，printf输出的时候必须用lld，不是d
//补0不是13lld，是013lld，前面的0不能漏掉！

#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>

using namespace std;

struct stu
{
    long long int no;
    int score;
    int place;
    int loc_rank;
    int glo_rank;
    stu(long long int n, int s, int p){
        no = n;
        score = s;
        place = p;
    }
};

bool cmp(stu a, stu b){
    if(a.score==b.score)
        return a.no < b.no;
    return a.score > b.score;
}

vector<vector<stu>> all;
vector<stu> list;

int main(){
    int N;
    cin >> N;
    int K;
    long long int n;
    int s;
    for (int i = 0; i < N; i++){
        cin >> K;
        vector<stu> one;
        for (int j = 0; j < K; j++){
            cin >> n >> s;
            one.push_back(stu(n,s,i+1));
        }
        all.push_back(one);
    }
    //区域排序
    for (int i = 0; i < N; i++){
        sort(all[i].begin(), all[i].end(), cmp);
        //记录排名
        all[i][0].loc_rank = 1;
        list.push_back(all[i][0]);
        for (int j = 1; j < all[i].size(); j++){
            if(all[i][j].score==all[i][j-1].score)
                all[i][j].loc_rank = all[i][j - 1].loc_rank;
            else
                all[i][j].loc_rank = j + 1;
            list.push_back(all[i][j]);
        }
    }
    sort(list.begin(), list.end(), cmp);
    list[0].glo_rank = 1;
    for (int i = 1; i < list.size(); i++){
        if(list[i].score == list[i-1].score)
            list[i].glo_rank = list[i - 1].glo_rank;
        else
            list[i].glo_rank = i + 1;
    }
    //输出
    printf("%d\n", list.size());
    for (int i = 0; i < list.size(); i++){
        printf("%013lld %d %d %d\n", list[i].no, list[i].glo_rank, list[i].place, list[i].loc_rank);
    }
    system("PAUSE");
    return 0;
}