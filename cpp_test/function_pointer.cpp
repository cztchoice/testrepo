#include <iostream>
#include <vector>

using namespace std;
int max(int a, int b){
	return (a > b) ? a : b;
}
int min(int a, int b){
	return (a < b) ? a : b;
}

int main(int argc, char *argv[]) {
	int (*p)(int, int) = &min;
	vector<int (*)(int, int)> fp(2);
	int (*pa[2])(int, int) = {&max, &min};
	fp[0] = &max;
	fp[1] = &min;
	cout<<fp[1](1, 2)<<endl;
	cout<<pa[0](1, 2)<<endl;
}