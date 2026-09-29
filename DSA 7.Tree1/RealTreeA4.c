#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left,*right;
};

struct node* newNode(int item) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = item;
    n->left = n->right = NULL;
    return n;
}

struct node* insert(struct node* root, int item) {
    if (root == NULL) return newNode(item);
    if (item < root->data) root->left = insert(root->left, item);
    else if (item > root->data) root->right = insert(root->right, item);
    return root;
}

void postorder(struct node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("\n");

    struct node* root = NULL;
    for (int i = 0; i < n; i++) root = insert(root, arr[i]);

    postorder(root);
    printf("\n");

    free(arr);
    return 0;
}
