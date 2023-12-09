#include<iostream>
#include<stdlib.h>
using namespace std;

struct treeNode {
    int data;
    treeNode *left;
    treeNode *right;
};

treeNode *Insert(treeNode *node, int data){
    if(node==NULL){
        treeNode *temp;
        temp = new treeNode;
        temp -> data = data;
        temp -> left = temp -> right = NULL;
        return temp;
    }
    if(data > (node->data)){
        node->right = Insert(node->right, data);
    }
    else if(data < (node->data)){
        node->left = Insert(node->left, data);
    }
    return node;
}

treeNode* FindMin(treeNode *node){
    if(node==NULL){
        return NULL;
    }
    if(node->left){
        return FindMin(node->left);
    } else {
        return node;
    }
}

treeNode* FindMax(treeNode *node){
    if(node==NULL){
        return NULL;
    }
    if(node->right){
        return FindMax(node->right);
    }
    else {
        return node;
    }
}

treeNode *Deletee(treeNode *node, int data){
    treeNode *temp;
    if(node == NULL){
        cout<<"Element Not found";
    }
    else if(data < node->data){
        node->left = Deletee(node->left, data);
    } else if(data > node->data){
        node->right = Deletee(node->right, data);
    }
    else{
        if(node->right && node->left){
            temp = FindMin(node->right);
            node->data = temp->data;
            node->right = Deletee(node->right,temp->data);            
        } else {
            temp = node;
            if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;
            delete temp; // Use delete instead of free for C++
        }
    }
    return node;
}

void display(treeNode *root){
    if(root != NULL){
        display(root->left);
        cout<<" "<<root->data;
        display(root->right);
        cout<"\n";
    }
}

treeNode *Find(treeNode *node, int data){
    if(node==NULL){
        return NULL;
    }
    if(data > node->data){
        return Find(node->right, data);
    }
    else if(data < node->data){
        return Find(node->left, data);
    }
    else{
        return node;
    }
}

int main() {
    treeNode *root = NULL, *temp;
    int ch;

    while(1){
        cout<<"1.Insert\n2.Delete\n3.Search\n";
        cout<<"Enter Your Choice\n";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\nEnter Element to be inserted: ";
            cin>>ch;
            root=Insert(root,ch);
            cout<<"\nElements in BST are: \n";
            display(root);
            break;
        case 2:
            cout<<"\nEnter Element to be deleted: ";
            cin>>ch;
            root=Deletee(root,ch);
            cout<<"\nElements in BST are: \n";
            display(root);
            break;
        case 3:
            cout<<"\nEnter element to be searched: ";
            cin>>ch;
            temp = Find(root,ch);
            if(temp==NULL){
                cout<<"Element is not found \n";
            } else {
                cout<<"Element Found: "<<temp->data << endl;
            }
            break;
        default:
            cout<<"Invalid Choice\n";
            break;
        }
    }
    return 0;
}
