#include <iostream>
#include <queue>

using namespace std;

// Define node of the tree
class node
{

public:
    int data;
    node *left;
    node *right;

    // constructor
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// insert a node in binary tree
node *buildTree(node *root)
{
    int value;
    cout << "Enter the value ";
    cin >> value;
    root = new node(value);

    if (value == -1)
        return NULL;

    cout << "Left value of " << value << endl;
    root->left = buildTree(root);

    cout << "Right value of " << value << endl;
    root->right = buildTree(root);

    return root;
}

// Level order traversal in binary tree
void levelOrderTraversal(node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL); // this line only for separtor to print like tree otherwise no need of this line

    while (!q.empty())
    {
        node *d = q.front();
        q.pop();

        if (d == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL); // if queue is not empty then enter one septartor again
        }
        else
        {
            cout << d->data << " ";
            if (d->left)
                q.push(d->left);

            if (d->right)
                q.push(d->right);
        }
    }
    cout << endl;
}

// Inorder traversal
void inoreder(node *root)
{
    if (root == NULL)
        return;

    // call for left part of tree
    inoreder(root->left);
    cout << root->data << " ";
    // call for right part of tree
    inoreder(root->right);
}

// preOrder traversal
void preOrder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    // call for left part of tree
    preOrder(root->left);
    // call for right part of tree
    preOrder(root->right);
}

// postOrder traversal
void postOrder(node *root)
{
    if (root == NULL)
        return;

    // call for left part of tree
    postOrder(root->left);
    // call for right part of tree
    postOrder(root->right);

    cout << root->data << " ";
}

// Morris Traversal in binary tree (T.c is O(n) but S.C is O(1)) but other traversal has time complexity is same but S.C is O(n)
void morrisTraversal(node* root){
    node* curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){ // curr->left not exist then do this
            cout<<curr->data<<" ";
            curr = curr->right;
        }else{
            node* prev = curr->left;
            while(prev->right != NULL && prev->right!=curr){ // until prev->right != NULL do this
                prev = prev->right;
            }

            if(prev->right == NULL){ // if prev->right is null then point prev->right to curr then update curr to left
                prev->right = curr;
                curr = curr->left;
            }else{ // then print curr ka data then update curr to right
                prev->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}

int main()
{

    node *root = NULL;

    root = buildTree(root);
    cout << endl;
    cout << "Level order traversal "<<endl;
    levelOrderTraversal(root);

    cout << "Inorder traversal of tree is ";
    inoreder(root);
    cout << endl;
    // 5 7 9 15 -1 -1 -1 10 -1 -1 9 5 -1 -1 10 -1 -1

    cout << "PreOrder traversal of tree is ";
    preOrder(root);
    cout << endl;

    cout << "PostOrder traversal of tree is ";
    postOrder(root);
    cout << endl;

    cout<<"Morris traversal of tree is ";
    morrisTraversal(root);
    return 0;
}