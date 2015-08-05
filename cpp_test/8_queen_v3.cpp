/*
 * This is the third version
 * make the program accept argments as QUEEN_SIZE
 * Simpilfy the sentences in line 65
 */
#include<iostream>
#include<vector>
#include<cassert>
#include<cstdlib>


int QUEEN_SIZE = 8;

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
int main(int argc, char *argv[])
{
    if(argc >= 2)
        QUEEN_SIZE = atoi(argv[1]);
    std::vector<int> result(QUEEN_SIZE, -1);
    int num_result = 0;
    for(int i = 0; i < QUEEN_SIZE; )
    {
        bool valided = false;
        for(int j = result[i] + 1; j < QUEEN_SIZE; j++)
        {
            if(check_valid(result, i, j))
            {
                result[i] = j;
                valided = true;
                i++;
                break;
            }
        }
        if(valided == false)
        {
            if(i == 0)
                break;
            result[i] = -1;
            --i;
            /*for(int index_i = i + 1; index_i < QUEEN_SIZE; index_i++)
            {
                result[index_i] = -1;
            }*/
        }
        if(result[QUEEN_SIZE - 1] != -1)
        {
            print_result(result);
            //to start next turn, the same as result[i - 1] = -1;
            //result[QUEEN_SIZE - 1] = -1;
            num_result++;
            //reduce the i++ in valided judgement
            --i;
            result[i] = -1;
            //then goto the previous line
            --i;
        }
    }
    std::cout<<num_result<<std::endl;
    return 0;
}
