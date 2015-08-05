#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

int *var;
int *ptr;
int head;
int N;
int stepA=0, stepB=0, stepC=0, stepD=0;

void generateData(int n)
/* 产生两个n长度的数组，val[0..n-1]和ptr[0..n-1]，其中val[0..n-1]又随机数生成，每个值的大小在[1..3n]之间，ptr中存放的是
	val数组中相应数的后继位置值 */
{
	for (int i=0;i<n;i++) {
		 var[i] = (double)(rand()+1) / (RAND_MAX)*3*n ;
	}
	int *tempArray = new int[n];
	int *tempPtr = new int[n];
	for (int i=0;i<n;i++){
		tempArray[i] = var[i];
		tempPtr[i] = i;
	}
	for (int i=0;i<n-1;i++) {
		for (int j=n-1;j>i;j--) 
			if (tempArray[j]<tempArray[j-1]) {
				int temp = tempArray[j];
				tempArray[j] = tempArray[j-1];
				tempArray[j-1] = temp;
				int temp2 = tempPtr[j];
				tempPtr[j] = tempPtr[j-1];
				tempPtr[j-1] = temp2;
			}
	}
	head = tempPtr[0];
	for (int i=0;i<n-1;i++) {
		ptr[tempPtr[i]] = tempPtr[i+1];
	}
	ptr[tempPtr[n-1]]=-1;
	delete []tempArray;
	delete []tempPtr;
}

void destroyData()
{
	delete []var;
	delete []ptr;
}

void displayData(int n)
{
	ofstream out("ex6Data.txt");
	for (int i=0;i<n;i++)
		out<<var[i]<<" ";
	out<<endl;
	for (int i=0;i<n;i++)
		out<<ptr[i]<<" ";
	out<<endl;
	out.close();
}

int search(int x, int start, int &step)
{
	int i = start;
	while (x > var[i])
	{
		i = ptr[i];
		step++;
	} 
	return i;
}

int A(int x)
{
	stepA = 0;
	return search(x,head,stepA);
}

int D(int x)
{
	stepD = 0;
	int i = (double)rand() / (RAND_MAX)*N;
	int y = var[i];
	if (x == y) {
		stepD ++;
		return i;
	}
	else if (x < y)
		return search(x,head,stepD);
	else
		return search(x,ptr[i],stepD);
}

int B(int x)
{
	stepB = 0;
	int i = head;
	int max = var[i];
	for (int j=0; j<(int)sqrt((double)N);j++) {
		stepB++;
		int y = var[j];
		if (max<y && y <=x) {
			i = j;
			max = y;
		}
	}
	return search(x,i,stepB);
}

int C(int x)
{
	stepC = 0;
	int i = head;
	int max = var[i];
	int l = sqrt((double)N);
	int np = N/l;
	for (int j=0;j<np;j++) {
		stepC++;
		int ran = (double)rand() / (RAND_MAX)*l;  //产生的ran在0..l-1之间
		int y = var[ran];
		if (max<y && y<=x) {
			i = ran;
			max = y;
		}
	}
	return search(x,i,stepC);
}

void test(int x)
{
	ofstream out("ex6Result.txt");
	out<<"x: "<<x<<endl;
	out<<"A "<<"result: "<<A(x); out<<" step: "<<stepA<<" "<<endl;
	out<<"B "<<"result: "<<B(x); out<<" step: "<<stepB<<" "<<endl;
	out<<"C "<<"result: "<<C(x); out<<" step: "<<stepC<<" "<<endl;
	out<<"D "<<"result: "<<D(x); out<<" step: "<<stepD<<" "<<endl;
	out.close();
}

int main()
{
	int x;
	srand( (unsigned)time(NULL)) ;
	N = 10000;
	var = new int[N];
	ptr = new int[N];
	int totalA=0, totalB=0, totalC=0, totalD=0;
	int iterNum = 100;
	for(int i=0;i<iterNum;i++) {
		generateData(N);
		//displayData(N);
		x=var[(int)((double)rand() / (RAND_MAX)*N)] ;
		A(x); 
		B(x);
		C(x);
		D(x);
		totalA+=stepA;
		totalB+=stepB;
		totalC+=stepC;
		totalD+=stepD;
	}
	totalA/=iterNum;
	totalB/=iterNum;
	totalC/=iterNum;
	totalD/=iterNum;
	ofstream out("ex6Result.txt");
	out<<"Num: "<<N<<" step: "<<totalA<<" "<<endl;
	out<<"Num: "<<N<<" step: "<<totalB<<" "<<endl;
	out<<"Num: "<<N<<" step: "<<totalC<<" "<<endl;
	out<<"Num: "<<N<<" step: "<<totalD<<" "<<endl;
	out.close();
	destroyData();
	return 0;
}
