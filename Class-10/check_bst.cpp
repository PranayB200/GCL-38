#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

TreeNode *insert(TreeNode *root, int val) {

    if (root == NULL) {
        return new TreeNode(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }

    return root;
}

bool check_bst_util(TreeNode *root, int low, int upper) {

    if (root == NULL) {
        return true;
    }

    if (root->data < low or root->data > upper) {
        return false;
    }

    return check_bst_util(root->left, low, root->data - 1) and check_bst_util(root->right, root->data + 1, upper);
}

bool check_bst(TreeNode *root) {
    return check_bst_util(root, -10000, 10000);
}

int main() {

    TreeNode* root = new TreeNode(45);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 35);

    cout << check_bst(root) << endl;

    root->right->right->data = 69;
    cout << check_bst(root);
}
