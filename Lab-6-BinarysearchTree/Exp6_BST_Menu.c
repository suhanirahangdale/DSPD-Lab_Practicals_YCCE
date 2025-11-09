// Suhani rahangdale B-121
/*6	Implement Binary search tree(BST) with following Menu operations.
1.	Search an element in BST(Display NULL if not found, If found Display Found)
2.	Insert an element in BST
3.	Delete leaf element in BST
4.	Exit

	
*/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};
struct node* create(int val) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}
struct node* insert(struct node *root, int val) {
    if (root == NULL) return create(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}
void search(struct node *root, int key) {
    if (root == NULL) printf("NULL (Not Found)\n");
    else if (root->data == key) printf("Found\n");
    else if (key < root->data) search(root->left, key);
    else search(root->right, key);
}
struct node* deleteLeaf(struct node *root, int val) {
    if (root == NULL) return NULL;
    if (root->data == val && root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }
    root->left = deleteLeaf(root->left, val);
    root->right = deleteLeaf(root->right, val);
    return root;
}
void inorder(struct node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main() {
    struct node *root = NULL;
    int ch, val;
    do {
        printf("\n1.Insert\n2.Search\n3.Delete Leaf\n4.Display\n5.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &val); root = insert(root, val); break;
            case 2: printf("Enter element to search: "); scanf("%d", &val); search(root, val); break;
            case 3: printf("Enter leaf value to delete: "); scanf("%d", &val); root = deleteLeaf(root, val); break;
            case 4: inorder(root); printf("\n"); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (ch != 5);
    return 0;
}