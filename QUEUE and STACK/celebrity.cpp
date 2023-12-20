//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    
    private:
    
    bool knows(vector<vector<int> >& M, int a,int b,int n){
            if(M[a][b] == 1){
                return true;
            }else{
                return false;
            }
            
        }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        
        stack<int> st;
        
        for(int i=0;i<M.size();i++){
            st.push(i);
        }

        while(st.size()>1){
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            
            if(knows(M,first,second,n)){
                st.push(second);
            }else{
                st.push(first);
            }
            
            
        }
        int candidate = st.top();
        
        bool rowcheck = false;
        int zerocount=0;
        
        for(int i=0;i<n;i++){
            if(M[candidate][i] == 0){
                zerocount++;
            }
        }
        if(zerocount == n){
            rowcheck = true;
        }
        
        
        bool colcheck = false;
        int colum=0;
        for(int i=0;i<n;i++){
            if(M[i][candidate] == 1){
                colum++;
            }
        }
        if(colum == n-1){
            colcheck=true;
        }
        
        if(rowcheck && colcheck){
            return candidate;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends