#include<iostream>
#include<stack>
using namespace std;

struct Node {
    char data;
    Node *left,*right;
};

struct Node* newNode(char key){
    Node *t = new Node;
    t->data = key;
    t->left = t->right = NULL;
    return t;
}

struct Node* postfixToExpression(string s){
    stack<Node*> st;
    Node *root = NULL;
    for(int i = 0;i < s.length();i++){
        if(s[i] >= 'a' && s[i] <= 'z' || s[i]  >= 'A' && s[i] <= 'Z'){
            st.push(newNode(s[i]));
        }else if(!st.empty()){
            Node *a = st.top();
            st.pop();
            Node *b = st.top();
            st.pop();
            root = newNode(s[i]);
            root->left = b;
            root->right = a;
            st.push(root);
            
        }
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return root;
}

void postorder(Node *root){

    if(!root) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "  ";
}

void inorder(Node *root){
    if(!root){
        return ;
    }

    inorder(root->left);
    cout << root->data <<" ";
    inorder(root->right);
}

int main(){
    string expr = "ab-cd+*";
    Node *root = postfixToExpression(expr);
    postorder(root);
    inorder(root);
    return 0;
}