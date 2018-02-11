#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float (*product_matrix(float (*M)[2], float m[2][2]))[2];
float (*generation_matrice(char t,float p))[2];

int main()
{
	int i,j,k=0;
	char a[301];
	for(int l=0;l<301;l++)
	{
		a[l]=0;
	} 
	float b[300];
	const char s[2] = "-";
	char *p;

	float(*c)[2];
	float (*MF)[2] = new float[2][2]; 
	MF[0][0] = 1;
	MF[0][1]=0;
	MF[1][0]=0;
	MF[1][1] = 1;
	
	//vv JB Qt
	/* */
	FILE *fp;
	fp = fopen("toto","r");
	/* */

	printf("Construisez une chaine optique:\n");
	//gets(a);
	fgets(a,300,fp); // ajout JB Qt
	printf("aa = %s\n",a);

	printf("Caractetisez chaque element:\n");
	p= strtok(a, s);
	while( p!= NULL ) 
	{
		printf("%s=",p);
		scanf("%f",&b[i]);
		i++;
		p= strtok(NULL, s);
	}
	for(j=0,k=0;a[j]!=0;j+=3,k++)
	{
		c=generation_matrice(a[j],b[k]);
		printf("%c\n",a[j]);
		printf("%.2f %.2f\n%.2f %.2f\n",c[0][0],c[0][1],c[1][0],c[1][1]);
		MF=product_matrix(c, MF);
	}
	printf("Matrice de tansfert finale:\n");
	printf("%8.4f %8.4f\n%8.4f %8.4f\n",MF[0][0],MF[0][1],MF[1][0],MF[1][1]);
	fclose(fp); // JB Qt
}


float (*generation_matrice(char t,float p))[2]
{
	float (*M)[2]= new float[2][2];
	if(t=='L')
	{ 
		M[0][0] = 1;
		M[0][1]=0;
		M[1][0]=-1/p;
		M[1][1] = 1;
	}
	else if(t=='D')
	{
		M[0][0] = 1;
		M[0][1]=p;
		M[1][0]=0;
		M[1][1] = 1;
	}
	else if(t=='S')
	{
		M[0][0] = 1;
		M[0][1]=0;
		M[1][0]=-2/p;
		M[1][1] = 1;
	}
	return M;
} 

float (*product_matrix(float (*M)[2], float m[2][2]))[2]
{
	float (*c)[2]= new float[2][2];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			c[i][j]=0;
			for(int k=0;k<2;k++)
			{
				c[i][j]+=*(*(M+i)+k)*m[k][j];
			}
		}
	}
	return c;
}

