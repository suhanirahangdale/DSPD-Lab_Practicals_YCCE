//SuhaniRahangdale-IT-B-121
/*Write a program to insert Number of Nodes in the Binary Tree and Traverse in Inorder , Preorder and Post Order and  Search an element in Binary Tree(Display NULL if not found, If found Display Found)

	
*/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};
struct node* create(int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}
void inorder(struct node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
struct node* insert(struct node *root, int val) {
    if (root == NULL) return create(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
void search(struct node *root, int key) {
    if (root == NULL) printf("NULL (Not Found)\n");
    else if (root->data == key) printf("Found\n");
    else if (key < root->data) search(root->left, key);
    else search(root->right, key);
}
int main() {
    struct node *root = NULL;
    int n, val, key, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("\nInorder: "); inorder(root);
    printf("\nPreorder: "); preorder(root);
    printf("\nPostorder: "); postorder(root);
    printf("\n\nEnter element to search: ");
    scanf("%d", &key);
    search(root, key);
    return 0;
}