// nqueen.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int const NOQ = 20;//�ʺ�����
int stopVegas = 0;
int RUN = 1000;

int POSITION[NOQ+1];//��1--NOQ��NOQ�У�0�в���
int b[NOQ+1];//�����У���1--NOQ��NOQ�У�0�в���
int c[NOQ*2+1];//����Խ���135����2--NOQ*2��(NOQ*2-1)�У�0��1����
int d[NOQ*2+1];//����Խ���45����2--NOQ*2��(NOQ*2-1)�У�0��1����

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

//���ݷ���k�м��Ժ�,ֻ��һ����
void trace(int k)
{
	stepreal++;
	steprealfl++;
	if (k<1) k=1;
	//if (breakpoint==1) return;//�ս�ݹ��.
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
			if (k==NOQ)//�ɹ��ҵ�һ����
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

//LV�㷨
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
	int k = 0;//k���к�
	int nb = 0;

	do {		
		if (stopVegas==0) break;
		stepreal++;
		steprealfl++;
		nb = 0;
		for (int i=1; i<=NOQ; i++)//i���к�
		{
			steplv++;
			if (b[i]==0 && c[k+i]==0 && d[k-i+(NOQ+1)]==0)//δ��ͻ
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

//���ݷ���k�м��Ժ�,�����н�
void traceall(int k, int nq)
{
	if (k<1) k=1;
	//if (breakpoint==1) return;//�ս�ݹ��.
	for ( int j=1 ; j<=nq; j++ )
	{
		//if (breakpoint==1) return;
		if (b[j]==0 && c[k+j]==0 && d[k-j+(nq+1)]==0)
		{
			POSITION[k] = j;
			b[j] = 1;
			c[k+j] = 1;
			d[k-j+(nq+1)] = 1;
			if (k==nq)//�ɹ��ҵ�һ����
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
	double p = 0;//�ɹ��ҵ���ĸ���
	double s = 0;//�ɹ��ҵ������õĲ�����
	double e = 0;//ʧ�����õĲ�����
	double t = 0;//t = s+(1-p)*e/p�����ҵ�һ�ν�����Ҫ�Ĳ�����

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

