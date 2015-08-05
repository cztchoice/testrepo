//#include<iostream>

class Solution {
public:
    double pow(double x, int n) {
#if 1
        double result = 1.0;
        bool neg = false;
        if(0 == n)
            return 1;
        if(n < 0){
            neg = true;
            n = -1 * n;
        }
        else if(1 == n)
            return x;
        else if(2 == n)
            return x*x;
        int half_n = n / 2;
        //std::cout<<half_n<<std::endl;
        if(n % 2){
            result *= x;
        }
        double half_result = this->pow(x, half_n);
        //std::cout<<half_result<<std::endl;
        result *= half_result;
        result *= half_result;
        
        if(neg){
            return 1.0/result;
        }
        else
            return result;
#else
        bool neg = false;
        int temp_n = n;
        int MAX_NUM = 64;
        if(0 == temp_n)
            return 1;
        else if(n < 0)
        {
            neg = true;
            temp_n = -1 * temp_n;
        }
        double result = 1.0;
        double *temp = new double[ MAX_NUM ];
        int *temp_index = new int[ MAX_NUM ];
        int i = 1;;
        int max = 0;
        temp[0] = x;
        temp_index[0] = 1;
        for (i = 1; i < MAX_NUM; i++) {
            temp[i] = 1.0;
            temp[i] = temp[i - 1] * temp[i - 1];
            temp_index[i] = temp_index[i - 1] * 2;
            if(temp_index[i] > temp_n){
                max = i - 1;
                break;
            }
        }
        while(max >= 0)
        {
            if(temp_n >= temp_index[max])
            {
                result *= temp[max];
                temp_n -= temp_index[max];
            }
            --max;

        }
        if(neg){
            return 1.0/result;
        }
        else
            return result;
#endif
    }
};
#include<iostream>
int main()
{
    double x;
    int n ;
    std::cin>>x>>n;
    Solution solution;
    std::cout<<solution.pow(x, n)<<std::endl;
    return 0;
}
