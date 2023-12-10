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
        cout << st.top() << " \n";
        st.pop();
    }
    return root;
}

struct Node * prefixToExpression(string s){
    stack<Node*> st;
    Node *root = NULL;
    for(int i = s.length()-1;i >= 0;i--){
        if(s[i] >= 'a' && s[i] <= 'z' || s[i]  >= 'A' && s[i] <= 'Z'){
            st.push(newNode(s[i]));
        }else if(!st.empty()){
            Node *a = st.top();
            st.pop();
            Node *b = st.top();
            st.pop();
            root = newNode(s[i]);
            root->left = a;
            root->right = b;
            st.push(root);
            
        }
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
void preorder(Node *root){
     if(!root) {
        return;
    }
    cout << root->data << "  ";
    postorder(root->left);
    postorder(root->right);
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
    Node *root2 = prefixToExpression(expr);
    postorder(root);
    cout << "\n";
    inorder(root);
    cout << "\n";
    preorder(root);
    cout << "prefix expression tree output : \n";
    inorder(root);
    cout << "\n";
    preorder(root);
    return 0;
}