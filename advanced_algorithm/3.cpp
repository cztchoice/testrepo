#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int nRow;
int *chessBoard;


bool queensLV(int stepVegas)
{
	int possiblePos;
	int nb;
	if (stepVegas == 0)
		return true;
	for (int k=0; k<stepVegas; k++) {
		nb = 0;
		for (int i=0; i<nRow; i++) {
			bool feasible = true;
			for (int j = 0; j < k; j++) {
				if (chessBoard[j] == i)
					feasible = false;
				if (chessBoard[j] - j == i - k)
					feasible = false;
				if (chessBoard[j] + j == i + k)
					feasible = false;
			}
			if (feasible) {
				nb++;
				int ran = (double)rand() / (RAND_MAX)*nb;  //产生的ran在0..nb-1之间
				if (ran == 0)
					possiblePos	= i;
			}
		}
		if (nb > 0) {
			chessBoard[k] = possiblePos;
		}
		else break;
	}
	return (nb > 0);
}


bool backtrace(int k)
{
	if (k == nRow)
		return true;
	for (int i = 0; i < nRow; i++) {
		bool feasible = true;
		for (int j = 0; j < k; j++) {
			if (chessBoard[j] == i)
				feasible = false;
			if (chessBoard[j] - j == i - k)
				feasible = false;
			if (chessBoard[j] + j == i + k)
				feasible = false;
		}
		if (feasible) {
			chessBoard[k] = i;
			if (backtrace(k+1))
				return true;
		}
	}
	return false;
}

#define LARGE_INTEGER long
int main()
{
	LARGE_INTEGER BegainTime ;    
	LARGE_INTEGER EndTime ;    
	LARGE_INTEGER Frequency ;    
	QueryPerformanceFrequency(&Frequency);    

	srand( (unsigned)time(NULL)) ;

	for (nRow=20; nRow<=20; nRow++) {
		chessBoard = new int[nRow];
		double minTime = 10000000;
		int bestStepVegas;
		for (int stepVegas=0; stepVegas<=nRow; stepVegas++) {
			double avgTime=0;
			for (int iterNum=0;iterNum<100;iterNum++) {
				QueryPerformanceCounter(&BegainTime) ;    
				for(;;) {
					if (queensLV(stepVegas))
						if (backtrace(stepVegas))
							break;
				}
				QueryPerformanceCounter(&EndTime) ;
				double time = 1.0*( EndTime.QuadPart - BegainTime.QuadPart )*1000000 / Frequency.QuadPart;
				avgTime+=time;
			}
			avgTime/=100;
			if (avgTime<minTime) {
				minTime = avgTime;
				bestStepVegas = stepVegas;
			}
		}
		cout<<"nRow= "<<nRow<<"  bestStepVegas= "<<bestStepVegas<<" minTime= "<<minTime<<"ms "<<endl;
		delete []chessBoard;
	}
	return 0;
}
