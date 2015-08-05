/*
 * This is the third version
 * make the program accept argments as QUEEN_SIZE
 * Simpilfy the sentences in line 65
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
        bool taken = false;
        int j = 0;
        for(j = result[i] + 1; j < QUEEN_SIZE; j++)
        {
            if(check_valid(result, i, j))
            {
                result[i] = j;
                valided = true;
                i++;
                break;
            }
            //when j is equal to QUEEN_SIZE, we can not get into the for circle
            taken = true;
             if(j >= QUEEN_SIZE - 1)
            {
                assert(valided == false);

                taken = true;
                //if(i == 0)
                    //goto out;
                //result[i] = -1;
                //--i;
                break;
            }
        }
        if(valided == false)
        {
            if(taken != true)
            {
                std::cout<<"Error: ";
                std::cout<<j<<": ";
                for(int index_i = 0; index_i < QUEEN_SIZE; index_i++)
                {
                    std::cout<<result[index_i]<<" ";
                }
                std::cout<<std::endl;
            }
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
out:
    std::cout<<num_result<<std::endl;
    return 0;
}
