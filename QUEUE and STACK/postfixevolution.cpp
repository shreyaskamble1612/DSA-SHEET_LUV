//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int applyOperator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}
    
    bool isOperator(char op){
        return(op=='+'||op=='-'||op=='*'||op=='/');
    }
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int>myStack;
        
        for(int i=0;i<S.size();i++){
            if(isdigit(S[i])){
                myStack.push(S[i] - '0'); 
            }
            else if(isOperator(S[i])){
                int temp1=myStack.top();
                myStack.pop();
                int temp2=myStack.top();
                myStack.pop();
                myStack.push(applyOperator(temp2,temp1,S[i]));
            }
        }
        return myStack.top();
        
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends