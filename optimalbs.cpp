#include <iostream>
using namespace std;

int sum(int freq[], int low, int high) {    
   int sum = 0;
   for (int k = low; k <=high; k++)
      sum += freq[k];
   return sum;
}

int minCostBST(int keys[], int freq[], int n) {
   int cost[n][n];

   for (int i = 0; i < n; i++)    
      cost[i][i] = freq[i];

   for (int length=2; length<=n; length++) {
      for (int i=0; i<=n-length+1; i++) {    
         int j = i+length-1;
         cost[i][j] = INT_MAX;    

         for (int r=i; r<=j; r++) {
           
            int c = ((r > i)?cost[i][r-1]:0)+((r < j)?cost[r+1][j]:0)+sum(freq, i, j);
            if (c < cost[i][j])
               cost[i][j] = c;
         }
      }
   }
   return cost[0][n-1];
}

int main() {
   int keys[] = {10, 12, 20};
   int freq[] = {34, 8, 50};
   int n = 3;
   cout << "Cost of Optimal BST is: "<< minCostBST(keys, freq, n);
}

