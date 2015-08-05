/*
 * This is the second version, I remove the unneed vector start and a lot of sentences relate to it.
 * I also remove some comments which help me easy debug.
 * Also, I make the program can define the QUEEN_SIZE in compile time, but it seems not be the best choice
 *
 */
#include<iostream>
#include<vector>
#include<cassert>

//const int QUEEN_SIZE = 9;
#ifndef QUEEN_SIZE
#define QUEEN_SIZE 8
#endif

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
            i = i - 1;
            for(int index_i = i + 1; index_i < QUEEN_SIZE; index_i++)
            {
                result[index_i] = -1;
            }
        }
        if(result[QUEEN_SIZE - 1] != -1)
        {
            print_result(result);
            //to start next turn
            result[QUEEN_SIZE - 1] = -1;
            num_result++;
            //reduce the i++ in valided judgement
            --i;
            //then goto the previous line
            --i;
        }
    }
    std::cout<<num_result<<std::endl;
    return 0;
}
