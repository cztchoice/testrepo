#include<iostream>
#include<vector>
#include<cstdlib>

int BOARD_SIZE = 6;

class Point{
    public:
        int x;
        int y;
        int step;
        Point(int x = 0, int y = 0, int step = 0){
            this->x = x;
            this->y = y;
            this->step = step;
        }
        /*Point operator+(Point& a){
            Point result;
            result.x = a.x + this->x;
            result.y = a.y + this->y;
            return result;
        }*/
        friend std::ostream& operator<< (std::ostream& out, Point &cPoint);
        friend Point operator+ (const Point& a, const Point& b);
};

Point operator+ (const Point& a, const Point& b)
{
    Point result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}
std::ostream& operator<< (std::ostream& out, Point &cPoint)
{
    out<<cPoint.x<<","<<cPoint.y;
}

//The First result.size() - 1 elements must be valid
bool check_valid(std::vector<Point> result)
{
    if(result.back().x < 0 || result.back().x > BOARD_SIZE || result.back().y < 0 || result.back().y > BOARD_SIZE )
    {
        return false;
    }
    for(std::vector<Point>::iterator iter=result.begin(); iter == --result.end(); ++iter)
    {
        if((*iter).x == result.back().x && (*iter).y == result.back().y)
            return false;
    }
    return true;
}
bool check_valid(std::vector<Point> result, Point step)
{
    Point last = result.back() + step;
    if(last.x < 0 || last.x > BOARD_SIZE || last.y < 0 || last.y > BOARD_SIZE )
    {
        return false;
    }
    for(std::vector<Point>::iterator iter=result.begin(); iter != result.end(); ++iter)
    {
        if((*iter).x == last.x && (*iter).y == last.y)
            return false;
    }
    return true;
}

void print_result(std::vector<Point> result)
{
    for(std::vector<Point>::iterator iter = result.begin(); iter != result.end(); ++iter)
    {
        std::cout<<*iter<<" ";
    }
    std::cout<<std::endl;
}

int main(int argc, char* argv[])
{
    if(argc >= 2)
        BOARD_SIZE = atoi(argv[1]);
    std::vector<Point> steps;
    steps.push_back(Point(1, 2));
    steps.push_back(Point(2, 1));
    steps.push_back(Point(2, -1));
    steps.push_back(Point(1, -2));
    steps.push_back(Point(-1, -2));
    steps.push_back(Point(-2, -1));
    steps.push_back(Point(-2, 1));
    steps.push_back(Point(-1, 2));

    //std::vector<Point> test[1] = {Point(1, 2),};
    std::vector<Point> result;

    result.push_back(Point(0, 0));

    Point test = steps[0] + steps[1];
    std::cout<<test<<std::endl;
    //std::cout<<(steps[0] + steps[1])<<std::endl;

    /*while(!result.empty())
    {
        if(result.at(result.size() - 2).step >= BOARD_SIZE)
        {
            result.pop_back();
            ++result.back().step;
            continue;
        }
        else if(check_valid(result))
        {
            if(BOARD_SIZE * BOARD_SIZE == result.size())
            {
                break;
            }
            else{
                //New iteration from step 0
                result.back().step = 0;
                result.push_back(result.back() + steps[result.back().step]);
                continue;
            }

        }
        else{
            result.pop_back();
            ++result.back().step;
            result.push_back(result.back() + steps[result.back().step]);

        }

    }*/


    while(!result.empty())
    {
        //print_result(result);
        //std::cout<<"back().step: "<<result.back().step<<std::endl;
        if( BOARD_SIZE * BOARD_SIZE == result.size())
        {
            break;
        }
        else if(result.back().step >= BOARD_SIZE)
        {
            result.pop_back();
            if (result.empty()) {
                break;
            }
            ++result.back().step;
            continue;
        }
        else if(check_valid(result, steps[result.back().step]))
        {
            result.push_back(result.back()+ steps[result.back().step]);
            result.back().step = 0;
        }
        else
        {
            ++result.back().step;
            continue;
        }

    }
    if(result.empty())
        std::cout<<"No result!"<<std::endl;
    else{
        print_result(result);
    }
    return 0;
}
