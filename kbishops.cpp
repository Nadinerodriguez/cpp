#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c, int n) {
   for (int i = 0; i < c; ++i)
      if ((q[c]/n - q[i]/n) == abs(q[c]%n - q[i]%n))
         return false;
   return true;
}
int kbishops(int n, int k) {
   int* q = new int[k];
   q[0] = 0;
   int c = 0, solutions = 0;
   while (c >= 0) {
      ++c;
      if (c == k) {
         ++solutions;
         --c;
      }
      else
         q[c] = q[c-1];
      while (c >= 0) {
         ++q[c];
         if (q[c] == n*n)
            --c;
         else if (ok(q, c, n))
            break;
      }
   }
   delete [] q;
   return solutions;
}

