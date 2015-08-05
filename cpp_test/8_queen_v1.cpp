/* 
 * This version is the first version that give the right answer to n-queen question
 * But it's not the best one, this is the first station I got to the most effecient solution.
 * Good Luck!!
 * By Chen Zhitao
 * 2013/10/23
 */
#include<iostream>
#include<vector>
#include<cassert>

const int QUEEN_SIZE = 8;

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

bool check_valid(std::vector<int> result, int a, int b)
{
    for(int i = 0; i < a; i++)
    {
        //maybe need %QUEEN_SIZE ?
        if(b - result[i] == 0 || b - result[i] == a - i || (b - result[i] == i - a))
            return false;
    }
    return true;
}
int main()
{
    std::vector<int> result(QUEEN_SIZE, -1);
    std::vector<int> start(QUEEN_SIZE);
    int num_result = 0;
    for(int i = 0; i < QUEEN_SIZE; )
    {
        bool valided = false;
        for(int j = start[i]; j < QUEEN_SIZE; j++)
        {
            if(check_valid(result, i, j))
            {
                result[i] = j;
                start[i] = j + 1;
                valided = true;
                i++;
                break;
            }
        }
        if(valided == false)
        {
            if(i == 0)
                break;
            i = i - 1;
            start[i] = result[i] + 1;
            for(int index_i = i + 1; index_i < QUEEN_SIZE; index_i++)
                start[index_i] = 0;
            /*std::cout<<"Start:\t";
            for(int i_temp = 0; i_temp < QUEEN_SIZE; i_temp++)
            {
                std::cout<<start[i_temp]<<" ";
            }
            std::cout<<std::endl;
            std::cout<<"Result:\t";
            for(int i_temp = 0; i_temp < QUEEN_SIZE; i_temp++)
            {
                std::cout<<result[i_temp]<<" ";
            }
            std::cout<<std::endl;*/
        }
        if(result[QUEEN_SIZE - 1] != -1)
        {
            print_result(result);
            //to start next turn
            result[QUEEN_SIZE - 1] = -1;
            //start[QUEEN_SIZE - 1] = 0;
            num_result++;
            //std::cout<<i<<std::endl;
            if(i == 0)
                break;
            //reduce the i++ in valided judgement
            --i;
            //i.e. start[QUEEN_SIZE - 1] = -1
            start[i] = 0;
            --i;
            start[i] = result[i] + 1;
        }
    }
    std::cout<<num_result<<std::endl;
    //result[0] = 0;
    //result[1] = 1;
    //result[2] = 2;
    //result[3] = 3;
    //result[4] = 4;
    //result[5] = 5;
    //result[6] = 6;
    //result[7] = 7;
    //print_result(result);
    return 0;
}
