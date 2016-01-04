/**
Given a sequence of positive numbers, a segment is defined to be a consecutive subsequence. For example, given the sequence {0.1, 0.2, 0.3, 0.4}, we have 10 segments: (0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) (0.2) (0.2, 0.3) (0.2, 0.3, 0.4) (0.3) (0.3, 0.4) (0.4).

Now given a sequence, you are supposed to find the sum of all the numbers in all the segments. For the previous example, the sum of all the 10 segments is 0.1 + 0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N, the size of the sequence which is no more than 105. The next line contains N positive numbers in the sequence, each no more than 1.0, separated by a space.

Output Specification:

For each test case, print in one line the sum of all the numbers in all the segments, accurate up to 2 decimal places.

Sample Input:
4
0.1 0.2 0.3 0.4 
Sample Output:
5.00

分析：找规律，判断每个数出现的次数。

*/
#include <iostream>  
#include <string>  
#include <vector>  
#include <cmath>  
using namespace std;  
  
int main(int argc, char** argv) {  
    int n;  
    scanf("%d",&n);  
    int i;  
    double t, sum = 0;  
    vector<double> vec;  
    for(i=0; i<n; i++){  
        scanf("%lf",&t);  
        vec.push_back(t);  
    }  
   
    int len = vec.size();  
    for(i=0; i<vec.size(); i++){  
        sum += vec[i] * (i+1)*(len-i);  
    }  
    
    printf("%.2lf\n",sum);  
    return 0;  
}  
