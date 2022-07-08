// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        
        int start=0;
        int maxLen=0;
        
        int i=0;
        
        while(i<n){
            
            int l=i,r=i;
            
            //Find middle element of a palindrome
            while(r<n-1&&s[r]==s[r+1]){
                r++;
            }
            
            i=r+1;
            
            //Expand from middle element
            while(r<n-1&&l>0&&s[l-1]==s[r+1]){
                r++;
                l--;
            }
            
            int currLen=r-l+1;
            if(currLen>maxLen){
                start=l;
                maxLen=currLen;
            }
            
        }
        
        return s.substr(start,maxLen);
    }
};