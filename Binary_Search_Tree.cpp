#include<bits/stdc++.h>
using namespace std;

/*
    Defination of binary Search Tree :
    For every node in a binary search tree maximum value of left sub tree must be less
    than current node && minimum value of right subtree must be greater than or equal
    to current node.
*/

// node of the binary search tree
class node{
    public:
    int data;
    node* left;
    node* right;

    // constructor
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};


// building a binary search tree (BST)
node* buildTree(node* root, int d){
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(root->data <= d){
        root->right = buildTree(root->right, d);
    }else{
        root->left = buildTree(root->left, d);
    }

    return root;
}
void insertNode(node* &root){
    int value; cin>> value;

    while(value != -1){
        root = buildTree(root, value);
        cin>> value;
    }

    return;
}

// inOrder traversal in BST
void inOrder(node* root){
    if(root== NULL) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
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

int main(){

    node* root = NULL;
    cout<<"Enter data for BST : ";
    insertNode(root);
    cout<<endl;

    // inOrder traversal function call
    cout<<"Indorder traversal of BST : ";
    inOrder(root);
    cout<<endl;

    // preOrder traversal function call
    cout<<"PreOrder traversal in BST ";
    preOrder(root);
    cout<<endl;

    // postOrder traversal functionn call
    cout<<"PostOrder traversal in BST : ";
    postOrder(root);
    cout<<endl;

    // Morris traversal function call
    cout<<"Morris traversal in BST : ";
    morrisTraversal(root);
    cout<<endl;

    return 0;
}