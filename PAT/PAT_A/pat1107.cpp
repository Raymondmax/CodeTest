/**
When register on a social network, you are always asked to specify your hobbies in order to find some potential friends with the same hobbies. A "social cluster" is a set of people who have some of their hobbies in common. You are supposed to find all the clusters.

Input Specification:

Each input file contains one test case. For each test case, the first line contains a positive integer N (<=1000), the total number of people in a social network. Hence the people are numbered from 1 to N. Then N lines follow, each gives the hobby list of a person in the format:

Ki: hi[1] hi[2] ... hi[Ki]

where Ki (>0) is the number of hobbies, and hi[j] is the index of the j-th hobby, which is an integer in [1, 1000].

Output Specification:

For each case, print in one line the total number of clusters in the network. Then in the second line, print the numbers of people in the clusters in non-increasing order. The numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
Sample Output:
3
4 3 1

分析：简单的并查集问题。
*/
#include <iostream>  
#include <vector>  
#include <algorithm>  
#include <queue>  
#include <set>  
using namespace std;  
  
struct node{  
    vector<int> sons;  
};  
vector<node> hobby(1001);  
  
vector<int> par;  
vector<int> Rank;  
vector<int> num;  
  
void init(int n){  
    par.resize(n);  
    Rank.resize(n,0);  
    num.resize(n);  
    int i;  
    for(i=0; i<n; i++){  
        par[i] = i;   
        num[i] = 1;   
    }  
      
}  
  
int find(int x){  
    if(x==par[x]){  
        return x;  
    }  
    return par[x] = find(par[x]);  
}  
  
bool same(int a, int b){  
    if(find(a) == find(b)){  
        return true;  
    }else{  
        return false;  
    }  
}  
  
int maxNum;  
  
bool cmp(int a, int b){  
    return a>b;  
}  
  
void unite(int a, int b){  
    int x = find(a);  
    int y = find(b);  
    if(x==y){  
        return ;  
    }  
    maxNum--;  
    if(Rank[x]<Rank[y]){  
        par[x] = y;  
        num[y] += num[x];  
    }else{  
        par[y] = x;  
        num[x] += num[y];  
        if(Rank[x] == Rank[y]){  
            Rank[x]++;  
        }  
    }  
}  
  
  
int main(int argc, char** argv) {  
    int N;  
    scanf("%d",&N);  
    init(N);  
    int tmp, id, i;  
    maxNum = N;  
   
    for(i=0; i<N; i++){  
        scanf("%d:",&tmp);  
        for(int j=0; j<tmp; j++){  
            scanf("%d",&id);  
            hobby[id].sons.push_back(i);  
        }  
    }  
   
    for(i=0; i<=1000; i++){  
        if(hobby[i].sons.size()!=0){  
            int a = hobby[i].sons[0];  
            for(int j=1; j<hobby[i].sons.size(); j++){  
                int b = hobby[i].sons[j];  
                unite(a,b);  
             }            
         }            
     }    
    set<int> s;  
    for(i=0; i<N; i++){  
        int fa = find(i);  
        s.insert(fa);  
    }  
    set<int>::iterator it = s.begin();  
    vector<int> final;  
    for(; it!=s.end(); it++){  
        int fa = find(*it);  
        final.push_back(num[fa]);  
    }  
      
    printf("%d\n",maxNum);  
    sort(final.begin(), final.end(), cmp);  
    for(i=0; i<final.size(); i++){  
        if(i==0){  
            printf("%d",final[i]);  
        }else{  
            printf(" %d",final[i]);  
        }  
    }  
    printf("\n");  
    return 0;  
} 
