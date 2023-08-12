#include<iostream>
#include<queue>

using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree (node* root) {

    cout << "Enter the data : " ;
    int data;
    cin >> data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data for the left of " << data << endl;
    root -> left = buildTree(root -> left);

    cout << " Enter data for the right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;

}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        
        if(temp == NULL) {
            //purana wala level complete traverse ho chuka hai
            //so for changing the line
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else {
            cout << temp -> data << "  ";
            if(temp -> left) {
                q.push(temp -> left);
            }

            if(temp -> right) {
                q.push(temp -> right);
            }
        }
    }
}

void inorder(node* root) {
    //base case
    if(root == NULL) {
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void preorder(node* root) {
    //base case
    if(root == NULL){
        return;
    }

    cout << root -> data << "  ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(node* root){
    //base case
    if(root == NULL) {
        return;
    }

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << "  ";
}

void buildFromLevelOrder(node* &root) {
    queue<node*> q;
    int data;

    cout << " enter Data for root node : " ;
    cin >> data;

    root = new node(data);
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter the left node for " << temp -> data;
        int leftData;
        cin >>  leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter the right node for " << temp -> data;
        int rightData;
        cin >>  rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }
    }
}

int main() {

    node* root = NULL;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    /*root = buildTree(root);

    cout << "Printing the binary tree " << endl;
    levelOrderTraversal(root);

    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;

    postorder(root);
    cout << endl;*/

    return 0;
}