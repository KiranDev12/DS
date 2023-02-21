#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int adj_matrix[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];

// Function to add an edge to the graph
void add_edge(int u, int v) {
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;
}

// Function to implement DFS
void dfs(int v, int n) {
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for (i = 0; i < n; i++) {
        if (adj_matrix[v][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

// Function to implement BFS
void bfs(int start, int n) {
    int queue[MAX_SIZE], front = 0, rear = -1;
    int i, node;
    visited[start] = 1;
    queue[++rear] = start;
    while (front <= rear) {
        node = queue[front++];
        printf("%d ", node);
        for (i = 0; i < n; i++) {
            if (adj_matrix[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

// Function to print the adjacency matrix
void print_matrix(int n) {
    int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, choice, u, v, start;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add edge\n");
        printf("2. Depth-First Search\n");
        printf("3. Breadth-First Search\n");
        printf("4. Print adjacency matrix\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the vertices to connect: ");
                scanf("%d %d", &u, &v);
                add_edge(u, v);
                break;
            case 2:
                printf("Enter the start vertex: ");
                scanf("%d", &start);
                printf("DFS Traversal: ");
                dfs(start, n);
                printf("\n");
                for (int i = 0; i < n; i++) {
                    visited[i] = 0;
                }
                break;
            case 3:
                printf("Enter the start vertex: ");
                scanf("%d", &start);
                printf("BFS Traversal: ");
                bfs(start, n);
                printf("\n");
                for (int i = 0; i < n; i++) {
                    visited[i] = 0;
                }
                break;
            case 4:
                print_matrix(n);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
