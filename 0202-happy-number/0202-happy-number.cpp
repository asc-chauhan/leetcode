
class Solution {
private:
    int nextNumber(int n){
        int newNumber = 0;
        while(n!=0){
            int num = n%10;
            newNumber += num*num;
            n = n/10;
        }
        return newNumber;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n!=1 && !set.count(n)){
            set.insert(n);
            n = nextNumber(n);
        }
        return n==1;
    }
};

// class Solution {
// public:
//     int solve(int n) {
//         int sum = 0;
//         while(n > 0) {
// 			int r = n%10;
//             sum += r*r;
//             n /= 10;
//         }
//         return sum;
//     }
//     bool isHappy(int n) {
//         int slow = n, fast = n;
//         do {
//             slow = solve(slow);
//             fast = solve(solve(fast));
//             if(fast == 1) return 1;
//         } while(slow != fast);
//         return 0;
//     }
// };