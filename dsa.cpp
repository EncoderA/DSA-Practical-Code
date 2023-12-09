#include<iostream>
#include <stack>
using namespace std;
 
// Function to return precedence of operators
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

bool isOperator(char x)
{
    switch (x) {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}
string infixToPostfix(string s)
{
 
        stack<char> st;
    string result;
 
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        // If the scanned character is
        // an operand, add it to output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'))
            result += c;
 
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');
 
        // If the scanned character is an ‘)’,
        // pop and add to output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
 
        // If an operator is scanned
        else {
            while (!st.empty()
                   && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
 
    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

string infixToPrefix(string s){
    string postexp = infixToPostfix(s);
    s = postexp;
    stack<string> st;
    string result = "";
    for(int i = 0 ;i<s.size();i++){
        if(isOperator(s[i])){
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            st.push(s[i] + op2 + op1);
        }else{
            st.push(string(1,s[i]));
        }
    }

    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    return result;
}
 

int main()
{
    string exp = "a+b-i";
 

    cout << infixToPostfix(exp) << "\n";
    cout << infixToPrefix(exp) << "\n";
   
    return 0;
}