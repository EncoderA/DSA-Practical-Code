#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
};
struct Node* newNode(int key){
    Node *t = new Node;
    t->data = key;
    t->left = t->right = NULL;
    return t;
}
struct Node* insert(struct Node *node,int key){
    if(!node) {
        return newNode(key);
    }
    if(key < node->data){
        node->left = insert(node->left,key);
    }else{
        node->right = insert(node->right,key);
    }
    return node;
}
struct Node* search(struct Node *root,int key){
    if(!root && root->data == key){
        return root;
    }
    if(key > root->data) search(root->right,key);
    search(root->left,key);
    return root;
}
void display(struct Node *root){
    if(!root) {
        return;
    }
    display(root->left);
    cout << root->data << "  ";
    display(root->right);
}
int main(){
    Node *root = newNode(19);
    insert(root,13);
    insert(root,7);
    
    display(root);
    return 0;
}