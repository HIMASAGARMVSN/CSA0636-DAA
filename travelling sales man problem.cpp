#include <stdio.h>
#include <limits.h>

#define MAX_N 15 // Maximum number of cities.

int n; // Number of cities.
int cost[MAX_N][MAX_N]; // Cost matrix.
int dp[1 << MAX_N][MAX_N]; // Dynamic programming table.

int tsp(int mask, int pos) {
  if (mask == (1 << n) - 1) {
    return cost[pos][0];
  }

  if (dp[mask][pos] != -1) {
    return dp[mask][pos];
  }

  int min_cost = INT_MAX;
  for (int i = 0; i < n; i++) {
    if ((mask & (1 << i)) == 0) {
      int new_cost = tsp(mask | (1 << i), i) + cost[pos][i];
      if (new_cost < min_cost) {
        min_cost = new_cost;
      }
    }
  }

  dp[mask][pos] = min_cost;
  return min_cost;
}

int main() {
  printf("Enter the number of cities: ");
  scanf("%d", &n);

  printf("Enter the cost matrix (%d x %d):\n", n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &cost[i][j]);
    }
  }

  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = -1;
    }
  }

  int min_cost = tsp(1, 0);
  printf("Minimum cost for the Traveling Salesman Problem: %d\n", min_cost);

  return 0;
}
