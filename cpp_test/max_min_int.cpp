#include <iostream>
#include<climits>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
	cout<<INT_MAX<<endl;
	cout<<INT_MIN%10<<endl;
	int a = 3;
	cout<<-a<<endl;
	double dA = 11111;
	double dB = 0.3456;
	double dC = dA + dB;
	cout<<cout.precision()<<endl;
	//cout.precision(10);
	cout<<dC<<endl;
	printf("%lf\n", dC);
	cout<<isnormal(5.0 - 5.0)<<endl;
}