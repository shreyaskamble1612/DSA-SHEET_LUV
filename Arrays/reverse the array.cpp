
//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    string reverseWord(string str)
    {
        // Your code goes here
        int s = 0;
        int e = str.size() - 1;
        char temp;
        while(e>s){
            // swap(str[s++],str[e--]);
            // s++;
            // e--;
            
            temp=str[s];
            str[s]=str[e];
            str[e]=temp;
            s++;
            e--;
            
            
            
        }
        
        return str;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends