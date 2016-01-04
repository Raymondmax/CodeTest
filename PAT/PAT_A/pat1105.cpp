/**
This time your job is to fill a sequence of N positive integers into a spiral matrix in non-increasing order. A spiral matrix is filled in from the first element at the upper-left corner, then move in a clockwise spiral. The matrix has mrows and n columns, where m and n satisfy the following: m*n must be equal to N; m>=n; and m-n is the minimum of all the possible values.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N. Then the next line contains N positive integers to be filled into the spiral matrix. All the numbers are no more than 104. The numbers in a line are separated by spaces.

Output Specification:

For each test case, output the resulting matrix in m lines, each contains n numbers. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.

Sample Input:
12
37 76 20 98 76 42 53 95 60 81 58 93
Sample Output:
98 95 93
42 37 81
53 20 76
58 60 76

分析： 把矩阵一圈圈的分解，进行赋值，然后输出。 
*/
#include <iostream>  
#include <vector>  
#include <algorithm>  
#include <cmath>  
using namespace std;  
  
bool cmp(int a, int b){  
    return a>b;  
}  
  
int main(int argc, char** argv) {  
    int N;  
    scanf("%d",&N);  
    if(N==0){  
        printf("0\n");  
        return 0;  
    }  
       
    int i,t,j;  
    vector<int> vec;  
    for(i=0; i<N; i++){  
        scanf("%d",&t);  
        vec.push_back(t);  
    }  
    sort(vec.begin(), vec.end(), cmp);  
    int m, n;  
    int minDiff = 9999999;  
    for(i=1; i<=N; i++){  
        for(j=i; j<=N; j++){  
            if(i*j>N){  
                break;  
            }  
            if(i*j==N && (j-i)<minDiff){  
                m=j;   
                n=i;  
                minDiff=(j-i);  
            }  
        }  
    }     
   
    if(m==N || n==1){  
        for(i=0; i<vec.size(); i++)  
        cout<<vec[i]<<endl;  
        return 0;         
    }   
      
    vector<vector<int> > matrix;  
    matrix.resize(m+2, vector<int>(n+2,0));  
  
    int row, col;  
    int rowLow=0, rowHigh=m+1;  
    int colLeft=0, colRight=n+1;  
    int index = 0;  
      
    while (true){  
        //从左到右   
        i = rowLow + 1;  
        for (int j = colLeft + 1; j<colRight && i<rowHigh; j++){  
            matrix[i][j] = vec[index++];  
        }  
        if (index == N) break;  
      
        //从上到下   
        j = colRight - 1;  
        i++;  
        for (; i<rowHigh && j>colLeft; i++){  
            matrix[i][j] = vec[index++];  
        }  
        if (index == N) break;  
      
        //从右到左   
        i = rowHigh - 1;  
        j--;  
        for (; j>colLeft && i>rowLow; j--){  
            matrix[i][j] = vec[index++];  
        }  
        if (index == N) break;  
      
        //从下到上   
        i--;  
        j = colLeft + 1;  
        for (; i>rowLow + 1 && j<colRight; i--){  
            matrix[i][j] = vec[index++];  
        }  
      
        rowLow++; rowHigh--;  
        colLeft++; colRight--;  
        if (rowLow >= rowHigh || colLeft >= colRight){  
            break;  
        }  
    }  
      
    for(i=1; i<=m; i++){  
        for(j=1; j<=n; j++){  
            if(j==1)  
                printf("%d", matrix[i][j]);  
            else  
                printf(" %d", matrix[i][j]);  
        }  
        cout<<endl;  
    }     
    return 0;  
}  
