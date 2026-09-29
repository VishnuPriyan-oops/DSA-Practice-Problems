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

void preorder(struct node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int size;
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

    printf("\n");

    struct node* root = NULL;
    for (int i = 0; i < size; i++) root = insert(root, arr[i]);

    preorder(root);
    printf("\n");

    free(arr);
    return 0;
}
