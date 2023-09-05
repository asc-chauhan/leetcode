class Solution {
public:
    bool isPalindrome(int x) {
        long long rev = 0;
        int temp = x;
        if (x < 0)
            return false;
        else
        {
            while(temp != 0)
            {
                int a = temp%10;
                rev = rev*10 + a;
                temp = temp/10;
            }
            return(x == rev);
        }
    }
};