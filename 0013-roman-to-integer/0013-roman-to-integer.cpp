class Solution {
public:
    int romanToInt(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'C')
            {    
                if(s[i+1] == 'M')
                {
                    count = count + 900;
                    i++;
                    continue;
                }
                else if(s[i+1] == 'D')
                {
                    count = count + 400;
                    i++;
                    continue;
                }
                else
                    count = count + 100;
            }    

            else if(s[i] == 'X')
            {
                if(s[i+1] == 'C')
                {
                    count = count + 90;
                    i++;
                    continue;
                }
                else if(s[i+1] == 'L')
                {
                    count = count + 40;
                    i++;
                    continue;
                }
                else
                    count = count + 10;
            }

            else if(s[i] == 'I')
            {
                if(s[i+1] == 'V')
                {
                    count = count + 4;
                    i++;
                    continue;
                }
                else if(s[i+1] == 'X')
                {
                    count = count + 9;
                    i++;
                    continue;
                }
                else
                    count = count + 1;
            }
            else if(s[i] == 'M')
                count = count + 1000;
            else if(s[i] == 'D')
                count = count + 500;
            else if(s[i] == 'L')
                count = count + 50;
            else
                count = count + 5;
        }
        return count;
    }
};