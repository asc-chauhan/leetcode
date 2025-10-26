class Solution {
public:
    bool isBalanced(int num){
        vector<int> freq(10);

        while(num > 0){
            int digit = num % 10;
            freq[digit]++;
            num = num / 10;
        }

        for(int digit = 0; digit<10; digit++){
            if(freq[digit] > 0 && freq[digit] != digit){
                return false;
            }
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for(int num = n+1; num<=1224444; num++){
            if(isBalanced(num)){
                return num;
            }
        }
        return -1;
    }
};