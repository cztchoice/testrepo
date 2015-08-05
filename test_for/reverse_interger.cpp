#include<iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        int result = 0;
        if(x < 0){
            neg = true;
            x = -1 * x;
        }
        while(x != 0){
            result = result * 10 + x % 10;
            x = x / 10;
        }
        if(neg){
            result = result * -1;
        }
        return result;
    }
};

int main(int argc, char const* argv[])
{
    int a;
    cin>>a;
    Solution solution;
    cout<<solution.reverse(a)<<endl;
    return 0;
}
