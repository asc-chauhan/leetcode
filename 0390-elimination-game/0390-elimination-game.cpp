// class Solution {
// public:
//     int lastRemaining(int n) {
//         int start=1,diff=1,no=n;
//         bool left2right=true;
//         while(no>1){
//             if(left2right||no%2==1)
//                 start+=diff;
//             diff*=2;
//             no/=2;
//             left2right=!left2right;
//         }
//         return start;
//     }
// };

class Solution {
public:
    int f(int n) {
        if (n <= 2) return n - 1;
        if (n % 2 == 1) return n - 2 - 2 * f((n-1)/2);
        else return n - 1 - 2 * f(n/2);
    }
    int lastRemaining(int n) {
        return f(n) + 1;
    }
};