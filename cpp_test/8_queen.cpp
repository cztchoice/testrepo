/*
 * This is the 4th version
 * Use stack fucntion instead of [] in vector, found it much easy to understand
 * and easy to write, because it's so straight-forward
 * 
 */
#include<iostream>
#include<vector>
#include<cassert>
#include<cstdlib>


int QUEEN_SIZE = 5;

void print_result(std::vector<int> result)
{
    assert(result.size() == QUEEN_SIZE);
    std::cout<<"Queen result:"<<std::endl;
    for(int i = 0; i < QUEEN_SIZE; i++)
    {
        for(int j = 0; j < QUEEN_SIZE; j++)
        {
            if(result[i] == j)
                std::cout<<"+ ";
            else
                std::cout<<"- ";
        }
        std::cout<<std::endl;
    }
}

//to make this function right, the first result.size()-1 elements must be valid
//and the last element of the result vector is the only element to check if it is valid
bool check_valid(std::vector<int> result)
{
    int a = result.size() - 1;
    int b = result.back();
    for(int i = 0; i < result.size() - 1; i++)
    {
        //assert(result[i] < QUEEN_SIZE);
        if(b - result[i] == 0 || b - result[i] == a - i || (b - result[i] == i - a))
            return false;
    }
    return true;
}
int main(int argc, char *argv[])
{
    if(argc >= 2)
        QUEEN_SIZE = atoi(argv[1]);
    std::vector<int> result;

    /*//test the new check_valid function
    result.push_back(0);
    //result.push_back(2);
    //result.push_back(4);
    //result.push_back(1);
    //result.push_back(3);

    std::cout<<check_valid(result)<<std::endl;
    result.clear();*/

    int num_result = 0;
    //Initialized with -1 on the first location
    result.push_back(0);
    while(!result.empty())
    {
        if(result.back() >= QUEEN_SIZE)
        {
            result.pop_back();
            if(result.empty()){
                break;
            }
            else{
                ++result.back();
            }
            //continue;
        }
        else if(check_valid(result))
        {
            if(QUEEN_SIZE == result.size())
            {
                print_result(result);
                result.pop_back();
                /*std::cout<<"after pop_back"<<std::endl;
                for(int local_i = 0; local_i < result.size(); local_i++)
                {
                    std::cout<<result[local_i]<<" ";
                }
                std::cout<<std::endl;*/
                //++result.back();
                //If you want be more secure, use follow sentences,
                //but the empty() status will not happen,
                //because the result.size() here is equal to QUEEN_SIZE
                //As for QUEEN_SIZE=1, it does make sense
                if(result.empty()){
                    break;
                }
                else{
                    ++result.back();
                }
                //result.back() = result.back() + 1;
                /*std::cout<<"after ++result.back()"<<std::endl;
                for(int local_i = 0; local_i < result.size(); local_i++)
                {
                    std::cout<<result[local_i]<<" ";
                }
                std::cout<<std::endl;*/
                ++num_result;
                //std::cout<<num_result<<std::endl;
                //continue;
            }
            else
            {
                result.push_back(0);
            }
        }
        else{
            ++result.back();
            //continue;
            //std::cout<<"after else ++result.back()"<<std::endl;
            //for(int local_i = 0; local_i < result.size(); local_i++)
            //{
                //std::cout<<result[local_i]<<" ";
            //}
            //std::cout<<std::endl;
        }
    }
    std::cout<<num_result<<std::endl;
    return 0;
}
