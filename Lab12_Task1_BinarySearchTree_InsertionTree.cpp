#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *insert(TreeNode *node, int data)
{
    if (node == NULL)
    {
        TreeNode *newNode = new TreeNode();
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else
    {
        node->right = insert(node->right, data);
    }
    return node;
}

void InorderTraversal(TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }
    InorderTraversal(node->left);
    cout << node->data << " ";
    InorderTraversal(node->right);
}
void search(TreeNode *node, int data)
{
    if (node == NULL)
    {
        cout << "Element not found" << endl;
        return;
    }
    if (node->data == data)
    {
        cout << "Element found" << endl;
        return;
    }
    if (data < node->data)
    {
        search(node->left, data);
    }
    else
    {
        search(node->right, data);
    }
}

int main()
{
    TreeNode *root = NULL;
    int data;

    cout << "Enter numbers to inssert" << endl;
    while (true)
    {
        cin >> data;
        if (data == -1)
        {
            break;
        }
        root = insert(root, data);
    }

    cout << "Inorder Traversal: ";
    InorderTraversal(root);
    cout << endl;

    cout << "Enter number to search: ";
    cin >> data;
    search(root, data);
    return 0;
}
