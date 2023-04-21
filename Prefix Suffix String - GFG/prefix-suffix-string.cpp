//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

struct Node{
    Node* link[26];
    bool flag=false;
    
    bool isThere(char ch)
    {
        return (link[ch-'a']!=NULL);
    }
    void put(char ch, Node* node)
    {
        link[ch-'a']=node;
    }
    
    Node* get(char ch)
    {
        return link[ch-'a'];
    }
    
    void makeEnd()
    {
        flag=true;
    }
    
    bool isEnd()
    {
        return flag;
    }
};

class Solution{
private:
Node* root= new Node();
public:
    bool match(string str,int n)
    {
        Node* node=root;
        for(int i=0;i<n;i++)
        {
            if(!node->isThere(str[i]))return false;
            node=node->get(str[i]);
        }
    }
    bool match2(string str,int n)
    {
        Node* node=root;
        for(int i=n-1;i>=0;i--)
        {
            if(!node->isThere(str[i]))return false;
            node=node->get(str[i]);
        }
        return true;
    }
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        for(auto str: s1)
        {
            Node* node=root;
            int n=str.length();
            for(int i=0;i<n;i++)
            {
                if(!node->isThere(str[i]))
                {
                    node->put(str[i],new Node());
                }
                node=node->get(str[i]);
            }
            
            node->makeEnd();
            node=root;
            for(int i=n-1;i>=0;i--)
            {
                if(!node->isThere(str[i]))
                {
                    node->put(str[i],new Node());
                }
                node=node->get(str[i]);
            }
        }
        
        
        
        int ans=0;
        for(auto str: s2)
        {
            int n=str.length();
            if(match(str,n) || match2(str,n))ans++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends