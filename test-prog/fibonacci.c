/*
MIO - Info - 12/01/18
Exercice 2 : Suite de fibonacci et nombre d'or
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float fibo(int n);
void ecrit(char * flnm, int n, const int tt[n], const float xx[n],const float yy[n]);

int main(void)
{
	int n=50;
	int i=1;
	float tau, eps;
	eps = 1e-6;
	tau = (1+sqrt(5))/2;
	printf("tau = %f\n", tau);
	int tabn[n]; float tabsol[n], tabeps[n];
	while(fabs(tau-fibo(i+1)/fibo(i)) > eps)
	{
		tabn[i-1] = i;
		tabsol[i-1] = fibo(i+1)/fibo(i);
		tabeps[i-1] = tau-fibo(i+1)/fibo(i);
		i++;
	}
	n=i-1;
	printf("Convergence en %d recurrence\n", n);
	printf("tau_rec = %f\n", tabsol[n-1]);
	ecrit("fibonacci.dat", n, tabn, tabsol, tabeps);
	return EXIT_SUCCESS;
}

float fibo(int n)
{
	if( n==1 || n==2) return 1;
	else return fibo(n-1)+fibo(n-2);
}

void ecrit(char * flnm, int n, const int tt[n], const float xx[n],const float yy[n])
{
	FILE *fp=NULL;
	fp = fopen (flnm,"w");
	fprintf(fp,"N\tValeur\tEcart\n");
	for(int i=0;i<n;i++)
	{
		fprintf(fp,"%d\t%f\t%f\n", tt[i], xx[i],yy[i]);
	}	
	printf("%s a ete cree\n", flnm);
	fclose (fp);
}
