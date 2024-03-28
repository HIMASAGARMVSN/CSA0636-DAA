#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure of a node in the binary search tree
struct node {
  int key;
  struct node *left;
  struct node *right;
};

// Function prototypes
struct node* newNode(int key);
struct node* optimalBST(int keys[], int frequencies[], int n);
struct node* constructOptimalBST(int cost[][5], int keys[], int i, int j);
void printBST(struct node* root);

// Function to create a new node in the binary search tree
struct node* newNode(int key) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Function to find the optimal binary search tree using dynamic programming
struct node* optimalBST(int keys[], int frequencies[], int n) {
  // Create a table to store the costs of optimal subtrees
  int cost[n][n];

  // Initialize the cost table
  for (int i = 0; i < n; i++) {
    cost[i][i] = frequencies[i]; // Base case when only one key is considered
  }

  // Fill the rest of the cost table using dynamic programming
  for (int l = 2; l <= n; l++) {
    for (int i = 0; i <= n - l; i++) {
      int j = i + l - 1;
      cost[i][j] = INT_MAX;

      // Calculate cost for subproblems from i to j
      for (int r = i; r <= j; r++) {
        int c = ((r > i) ? cost[i][r - 1] : 0) +
                ((r < j) ? cost[r + 1][j] : 0) +
                frequencies[r];
        if (c < cost[i][j]) {
          cost[i][j] = c;
        }
      }
    }
  }

  // Construct the optimal binary search tree using the cost table
  struct node* root = constructOptimalBST(cost, keys, 0, n - 1);
  return root;
}

// Function to construct the optimal binary search tree using the cost table
struct node* constructOptimalBST(int cost[][5], int keys[], int i, int j) {
  if (i > j) {
    return NULL;
  }

  // Find the root node of the optimal subtree
  int minCost = INT_MAX;
  int rootIndex = -1;
  for (int r = i; r <= j; r++) {
    if (cost[i][r - 1] + cost[r + 1][j] < minCost) {
      minCost = cost[i][r - 1] + cost[r + 1][j];
      rootIndex = r;
    }
  }

  // Create the root node
  struct node* root = newNode(keys[rootIndex]);

  // Construct the left and right subtrees recursively
  root->left = constructOptimalBST(cost, keys, i, rootIndex - 1);
  root->right = constructOptimalBST(cost, keys, rootIndex + 1, j);

  return root;
}

// Function to print the binary search tree
void printBST(struct node* root) {
  if (root == NULL) {
    return;
  }

  printBST(root->left);
  printf("%d ", root->key);
  printBST(root->right);
}

// Main function
int main() {
  int n;
  printf("Enter the number of keys: ");
  scanf("%d", &n);

  int keys[n], frequencies[n];
  printf("Enter the keys:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &keys[i]);
  }

  printf("Enter the frequencies:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &frequencies[i]);
  }

  // Find the optimal binary search tree
  struct node* root = optimalBST(keys, frequencies, n);

  // Print the optimal binary search tree
  printf("Optimal BST:\n");
  printBST(root);
  printf("\n");

  return 0;
}
