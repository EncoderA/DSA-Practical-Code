#include<iostream>
#include<stack>
using namespace std;

int evaluationPrefix(string exp){
    stack<int> st;
    for(int i = exp.length()-1 ; i >= 0 ;i--){
        if(isdigit(exp[i])){
            st.push(exp[i] - '0');
        }else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            char c = exp[i];
            int e;
            switch (c)
            {
            case '+':
                e = op1 + op2;
                break;
            case '-':
                e = op1 - op2;
                break;
            case '*':
                e = op1 * op2;
                break;
            default:
                e = op1 / op2;
                break;
            }
            st.push(e);
        }
    }
    return st.top();
}

int evaluationPostfix(string exp){
    
    stack<int> st;
    for(int i = 0 ; i < exp.length() ;i++){
        if(isdigit(exp[i])){
            st.push(exp[i] - '0');
        }else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            char c = exp[i];
            int e;
            switch (c)
            {
            case '+':
                e = op2 + op1;
                break;
            case '-':
                e = op2 - op1;
                break;
            case '*':
                e = op2 * op1;
                break;
            default:
                e = op2 / op1;
                break;
            }
            st.push(e);
        }
    }
    return st.top();
}

int main(){
    cout << evaluationPrefix("*-44+34") << "\n";
    cout << evaluationPostfix("44-34+*") << "\n";

    return 0;
}