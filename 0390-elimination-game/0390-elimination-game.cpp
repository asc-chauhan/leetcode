class Solution {
public:
    int lastRemaining(int n) {
        int start=1,diff=1,no=n;
        bool left2right=true;
        while(no>1){
            if(left2right||no%2==1)
                start+=diff;
            diff*=2;
            no/=2;
            left2right=!left2right;
        }
        return start;
    }
};