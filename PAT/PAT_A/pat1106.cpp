/**
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the lowest price a customer can expect from some retailers.

Input Specification:

Each input file contains one test case. For each case, The first line contains three positive numbers: N (<=105), the total number of the members in the supply chain (and hence their ID's are numbered from 0 to N-1, and the root supplier's ID is 0); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:

Ki ID[1] ID[2] ... ID[Ki]

where in the i-th line, Ki is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID's of these distributors or retailers. Kj being 0 means that the j-th member is a retailer. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the lowest price we can expect from some retailers, accurate up to 4 decimal places, and the number of retailers that sell at the lowest price. There must be one space between the two numbers. It is guaranteed that the all the prices will not exceed 1010.

Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0
Sample Output:
1.8362 2


分析:构建树，找出层数最低的叶子节点，即题目所求。简单题。
*/
#include <iostream>  
#include <vector>  
#include <algorithm>  
#include <queue>  
#include <cmath>  
using namespace std;  
  
struct node{  
    node(){  
        fa = -1;  
    }  
    int fa, level;  
    vector<int> son;  
};  
vector<node> vec;  
int N;  
double P,r;  
  
int main(int argc, char** argv) {  
    scanf("%d%lf%lf",&N,&P,&r);   
    vec.resize(N);  
    int i, num, id;  
    vector<int> retailer;  
    for(i=0; i<N; i++){  
        scanf("%d",&num);  
        if(num==0){  
            retailer.push_back(i);  
        }  
        for(int j=0; j<num; j++){  
            scanf("%d",&id);  
            vec[i].son.push_back(id);  
            vec[id].fa = i;  
        }  
    }  
    int root=0;   
    queue<int> que;  
    vec[root].level =1;  
    int level;  
    que.push(root);  
    while(!que.empty()){  
        int f = que.front();  
        level = vec[f].level;  
        for(i=0; i<vec[f].son.size(); i++){  
            int t = vec[f].son[i];  
            vec[t].level = level+1;  
            que.push(t);  
        }     
        que.pop();  
    }  
    double minPrice = 10000000005;  
    int cnt = 0;  
    for(i=0; i<retailer.size(); i++){  
        int t = retailer[i];  
        level = vec[t].level;  
        double price = P*pow(1+r/100.0,level-1);  
        if(price < minPrice){  
            minPrice = price;  
            cnt = 1;  
        }else if(price == minPrice){  
            cnt++;  
        }  
    }  
    printf("%.4lf %d\n",minPrice, cnt);  
    return 0;  
}  
