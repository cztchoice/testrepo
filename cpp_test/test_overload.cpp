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
        friend std::ostream& operator<< (std::ostream& out, const Point &cPoint);
        friend Point operator+ (Point& a, Point& b);
};

Point operator+ (Point& a, Point& b)
{
    Point result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}
std::ostream& operator<< (std::ostream& out, const Point &cPoint)
{
    out<<cPoint.x<<","<<cPoint.y;
}

int main(int argc, char* argv[])
{
    std::vector<Point> steps;
    steps.push_back(Point(0,1));
    steps.push_back(Point(1,1));

    Point a;
    Point b;


    Point test = steps[0] + steps[1];
    std::cout<<test<<std::endl;
    //std::cout<<(steps[0] + steps[1])<<std::endl;
    std::cout<<(a + b)<<std::endl;

    return 0;
}
