
class Solution {
public:
    //""
    //"30000000000" -- to large, overflow
    //"  3000" -- spaces at the front
    //12345
    //5*10^0 + 4*10^1 + 3*10^2 + 2*10^3 
    int myAtoi(string str) {
        int len=str.length(),Sign=1;
        if(!len) return 0;
        int st=str.find_first_not_of(' ');
        long long sum=0;
        int i=st;
        if(str[i]=='-'){Sign=-1;i++;}
        else if(str[i]=='+')i++;
        for(;i<len&&str[i]<='9'&&str[i]>='0';i++){
            sum=10*sum+str[i]-'0';
            if(Sign*sum>INT_MAX) return INT_MAX;
            if(Sign*sum<INT_MIN) return INT_MIN;
    }
        return int(Sign*sum);
    }
    int myAtoi2(string str) {
        long long int r  = 0; //make sure it is 64bit
        int flag = 0;
        int j;
        int valid = 0;
        int flag2 = 99;
        int flag3 = 0;
        
        for (int i = 0; i < str.length(); i ++) {
            if (str[i] == '+') {
                flag = 0;
                str.erase(str.begin() + i);
                i --;
                
                if (flag2 == 99) {
                    flag2 = 0;
                }
                else if (!(flag2 == 99 || flag2 == 0))
                    return 0;
                    
                flag3 = 1;
            }
            else if (str[i] == '-') {
                flag = 1;
                str.erase(str.begin() + i);
                i --;
                
                if (flag2 == 99)
                    flag2 = 1;
                else if (flag2 != 99)
                    return 0;
                flag3 = 1;
            }
            else if (!(str[i] - '0' >= 0 && '9' - str[i] >= 0)){
                if (flag3 && str[i] == ' ')
                    return 0;
                else if (str[i] == ' ' && !flag3) {
                    str.erase(str.begin() + i);//O(n)
                    i --;
                }
                else {
                    str = str.substr(0, i++);
                    break;
                }
            }
            else
                valid = 1;
        }
        if (!valid)
            return 0;
            
        for(j = str.length() - 1; j >= 0; j--) {
            int t = str.length() - 1 - j;
            r += (str[j] - '0')*pow(10, t);
            if (flag) {
                long long int temp = -r;
                if (temp < numeric_limits<int>::min())
                    return numeric_limits<int>::min();
            }
            else {
                if (r > numeric_limits<int>::max())
                    return numeric_limits<int>::max();
            }
        }
        if (flag)
            return (int)-r;
        else
            return (int)r;
    }
};
