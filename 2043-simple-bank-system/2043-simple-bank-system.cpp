class Bank {
public:
    vector<long long> bank;
    int n;
    Bank(vector<long long>& balance) {
        bank.push_back(0);
        for(auto x: balance)
            bank.push_back(x);
        n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 > n || account2 > n || bank[account1] < money)
            return false;
        bank[account1] -= money;
        bank[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account > n)
            return false;
        bank[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > n || bank[account] < money)
            return false;
        bank[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */