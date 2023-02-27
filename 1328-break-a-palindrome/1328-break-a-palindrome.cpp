class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.length()==1)return "";
        int n=palindrome.length();
        bool odd=(n%2==0)?false:true;
        for(int i=0;i<n;i++)
        {
            if(!odd)
            {
                if(palindrome[i]!='a')
                {
                    palindrome[i]='a';
                    return palindrome;
                }
            }
            else
            {
                if(palindrome[i]!='a' and n/2!=i)
                {
                    palindrome[i]='a';
                    return palindrome;
                }
            }
        }
        
        palindrome[n-1]='b';
        return palindrome;
    }
};