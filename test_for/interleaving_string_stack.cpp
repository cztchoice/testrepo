#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool result = true;
        std::string::iterator s1_it = s1.begin();
        std::string::iterator s2_it = s2.begin();
        std::string::iterator s3_it = s3.begin();
        bool together = false;
        std::string::iterator temp_s1 = s1.begin();
        std::string::iterator temp_s2 = s2.begin();
        std::string::iterator temp_s3 = s3.begin();
        std::stack<std::string::iterator> temp_s;
        while(s3_it != s3.end()){
            if(*s1_it != *s3_it && *s2_it != *s3_it){
                if(temp_s.empty()){
                    return false;
                }
                else{
                    s3_it = temp_s.top();
                    temp_s.pop();
                    s2_it = temp_s.top();
                    temp_s.pop();
                    s1_it = temp_s.top();
                    temp_s.pop();
                    
                    //try s2_it
                    ++s2_it;
                    ++s3_it;
                    continue;
                }
            }
            else if(*s1_it == *s2_it){
                //This means *s1_it == *s2_it == *s3_it
                 
                temp_s.push(s1_it);
                temp_s.push(s2_it);
                temp_s.push(s3_it);
                
                //First time try ++s1_it, if it doesn't work try ++s2_it, in
                ++s1_it;
                ++s3_it;

            }
            else if(*s1_it == *s3_it){
                ++s1_it;
                ++s3_it;

            }
            else if(*s2_it == *s3_it){
                ++s2_it;
                ++s3_it;
            }//no else here, because there must be someone equal to *s3_it
        }
        if(s1_it == s1.end() && s2_it == s2.end() && s3_it == s3.end()){
            return true;
        }
        else{
            return false;
        }
        
    }
};
int main()
{
    string s1, s2, s3;
    cin>>s1>>s2>>s3;
    Solution solution;
    cout<<solution.isInterleave(s1, s2, s3)<<endl;
    return 0;
}
