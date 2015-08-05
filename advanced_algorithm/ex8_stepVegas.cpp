// nqueen.cpp : 定义控制台应用程序的入口点。
//
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int const NOQ = 20;//皇后数量
int stopVegas = 0;
int RUN = 1000;

int POSITION[NOQ+1];//用1--NOQ这NOQ行，0行不用
int b[NOQ+1];//代表列，用1--NOQ这NOQ列，0列不用
int c[NOQ*2+1];//代表对角线135，用2--NOQ*2这(NOQ*2-1)列，0和1不用
int d[NOQ*2+1];//代表对角线45，用2--NOQ*2这(NOQ*2-1)列，0和1不用

int successall=0;
int success=0;
int breakpoint=0;
long long step = 0;
long long steplv = 0;
long long stepreal = 0;
long long steplvreal = 0;
long long steprealfl = 0;
long long steprealfllv = 0;
long long steprealflsum = 0;
long long steprealsum = 0;
long long stepscsum = 0;
long long stepflsum = 0;

void print()
{
	for (int i = 1; i<=NOQ; i++)
	{
		cout<<POSITION[i]<<" ";
	}
	cout<<endl;
}

//回溯法解k行及以后,只找一个解
void trace(int k)
{
	stepreal++;
	steprealfl++;
	if (k<1) k=1;
	//if (breakpoint==1) return;//终结递归的.
	for ( int j=1 ; j<=NOQ; j++ )
	{
		//if (breakpoint==1) return;
		step++;
		if (b[j]==0 && c[k+j]==0 && d[k-j+(NOQ+1)]==0)
		{
			POSITION[k] = j;
			b[j] = 1;
			c[k+j] = 1;
			d[k-j+(NOQ+1)] = 1;
			if (k==NOQ)//成功找到一个解
			{
				success++;
				stepscsum += step;
				steprealsum += stepreal;
				step = 0;
				stepreal = 0;
				breakpoint=1;

				//print();
				
				return;
			}
			trace (k+1);
			if (breakpoint==1) return;
			//stepreal++;
			b[j] = 0;
			c[k+j] = 0;
			d[k-j+(NOQ+1)] = 0;
		}	
	}

	return;
}

//LV算法
int QueenLV(void)
{

	steplv = 0;

	for (int i=0; i<=NOQ; i++)
	{
		POSITION[i] = -1;
		b[i] = 0;
	}
	for (int i=0;i<=NOQ*2;i++)
	{
		c[i] = 0;
		d[i] = 0;
	}
	
	int j=0;
	int k = 0;//k是行号
	int nb = 0;

	do {		
		if (stopVegas==0) break;
		stepreal++;
		steprealfl++;
		nb = 0;
		for (int i=1; i<=NOQ; i++)//i是列号
		{
			steplv++;
			if (b[i]==0 && c[k+i]==0 && d[k-i+(NOQ+1)]==0)//未冲突
			{
				nb++;
				//srand( (unsigned)time( NULL ) );
				double randb;
				int ran;
				randb = ((double)rand()/RAND_MAX);
				ran = int(randb*nb);
				if  (ran==0) j=i;
			}
		}
		if (nb>0)
		{
			POSITION[k+1]=j;
			b[j] = 1;
			c[k+j] = 1;
			d[k-j+(NOQ+1)] = 1;
			k++;
		}	
	} while(!(nb==0 || k==stopVegas));
	if (!stopVegas) 
	{
		trace(1);
		return 1;
	}

	if (nb==0 && k!=0) return 0;
	if (nb>0)
	{
		//success++;
		//stepscsum += steplv;
		//steprealsum += stepreal;
		if (k != NOQ) trace(k+1);
		else 
		{
			success++;
			steprealsum += stepreal;
				
			//print();

		}
		return 1;
	}
	else
	{
		return 0;
	}
	

}

//回溯法解k行及以后,找所有解
void traceall(int k, int nq)
{
	if (k<1) k=1;
	//if (breakpoint==1) return;//终结递归的.
	for ( int j=1 ; j<=nq; j++ )
	{
		//if (breakpoint==1) return;
		if (b[j]==0 && c[k+j]==0 && d[k-j+(nq+1)]==0)
		{
			POSITION[k] = j;
			b[j] = 1;
			c[k+j] = 1;
			d[k-j+(nq+1)] = 1;
			if (k==nq)//成功找到一个解
			{
				successall++;
				//return;
			}

			traceall(k+1, nq);

			b[j] = 0;
			c[k+j] = 0;
			d[k-j+(nq+1)] = 0;
		}	
	}

	//return;
}


int main(int argc, char* argv[])
{
	double p = 0;//成功找到解的概率
	double s = 0;//成功找到解所用的步骤数
	double e = 0;//失败所用的步骤数
	double t = 0;//t = s+(1-p)*e/p，即找到一次解所需要的步骤数

	double duration;

	srand((unsigned)time(NULL));


	cout<<"sV	"<<"p	"<<"s		"<<"e	"<<"t	"<<"RUN	"<<"duaration"<<endl;

	for (stopVegas=NOQ;stopVegas>=0;stopVegas--)
	{
		success=0;
		breakpoint=0;
		step = 0;
		steplv = 0;
		stepreal = 0;
		steplvreal = 0;
		steprealfl = 0;
		steprealfllv = 0;
		steprealflsum = 0;
		steprealsum = 0;
		stepscsum = 0;
		stepflsum = 0;

        clock_t start = clock();
		for (int m=0; m<RUN; m++)
		{
			breakpoint = 0;
			step = 0;
			steplv = 0;
			stepreal = 0;
			steplvreal = 0;
			//steprealfl = 0;
			//cout<<endl;
			QueenLV();
		}
        clock_t end = clock();
		duration = (double)(end - start)/(success);

		p = (double)success/RUN;

		if (success != 0)
		{
			s = (double)steprealsum/success;
		}
		else 
		{
			s = -1;
		}
		if (steprealfl == steprealsum) e=0;
		else
		{
			if ( RUN-success!=0 )
			{
				e = (double)(steprealfl-steprealsum)/(RUN-success);
			}
		}
		t = s+(1-p)*e/p;

		cout<<stopVegas<<"	";
		cout<<p<<"	";
		cout<<s<<"		";
		cout<<e<<"	";
		cout<<t<<"	";
		cout<<RUN<<"	";
		cout<<duration<<endl;
	}

	return 0;
}

