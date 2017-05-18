class Solution {
public:
    int myAtoi(string str) {
        int sign=1, base=0, ind=0;
        while(str[ind] == ' ')  ind++;
        if(str[ind] == '+' || str[ind] =='-'){
            if(str[ind] =='-'){
                sign = -1;
            }
            ind++;
        }
        while(str[ind]<='9' && str[ind]>='0'){
            if(base > INT_MAX/10 || (base == INT_MAX/10 && str[ind] - '0' > 7)){
                return sign == 1? INT_MAX : INT_MIN;
            }
            base = 10 * base + str[ind] - '0';
            ind++;
        }
        return sign * base;
    }
};