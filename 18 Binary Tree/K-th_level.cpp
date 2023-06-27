#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

// Output : 1 2 4 5 7 3 6
// Inorder : 4, 2,7,5,1,3,6
// Postorder : 4,7,5,2,6,3,1
class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
// Preorder Build of the Tree Root, Left, Right Tree
Node *buildTree()
{

    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    Node *n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void printPreorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}
void printInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void printRoot2LeafPaths(Node *root, vector<int> &path)
{

    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL and root->right == NULL)
    {
        // print the vector
        for (int node : path)
        {
            cout << node << "->";
        }
        cout << root->data << "->";
        cout << endl;
        return;
    }

    // rec case
    path.push_back(root->data);
    printRoot2LeafPaths(root->left, path);
    printRoot2LeafPaths(root->right, path);
    // backtracking
    path.pop_back();
    return;
}

vector<int> printKthLevel(Node *root, int k)
{
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int l = 0;
    cout << l << endl;
    while ((l < k) and (!q.empty()))
    {
        Node *current = q.front();
        if (current == NULL)
        {
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
                l++;
                cout << l << endl;
            }
        }
        else
        {
            q.pop();
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
    while (!q.empty())
    {
        Node *current = q.front();
        ans.push_back(current->data);
        cout << current->data << ", ";
        q.pop();
    }
    return ans;
}

int main()
{

    Node *root = buildTree();
    // printPreorder(root);
    // cout << endl;

    // printInorder(root);
    // cout << endl;

    // postOrder(root);
    // cout << endl;

    vector<int> path;
    printRoot2LeafPaths(root, path);

    printKthLevel(root, 2);
    return 0;
}