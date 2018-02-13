#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>


/* COULEUR*/
void couleur(float lambda){
	float i;
	i = 1e-9f;
	FILE *fpoutcol;
	fpoutcol=fopen("out1","w");

	if ((lambda >= 380*i) && (lambda <= 430*i)){
		fprintf(fpoutcol,"   VIOLET\n");}
		//printf("   VIOLET\n");}
	if((lambda >= 431*i) && (lambda <= 450*i)){
		fprintf(fpoutcol,"   INDIGO\n");}
		//printf("   INDIGO\n");}
	if((lambda >= 451*i) && (lambda <= 500*i)){
		fprintf(fpoutcol,"   BLEU\n");}
		//printf("   BLEU\n");}
	if((lambda >= 501*i) && (lambda <= 520*i)){
		fprintf(fpoutcol,"   CYAN\n");}
		//printf("   CYAN\n");}
	if((lambda >= 521*i) && (lambda <= 565*i)){
		fprintf(fpoutcol,"   VERT\n");}
		//printf("   VERT\n");}
	if((lambda >= 566*i) && (lambda <= 590*i)){
		fprintf(fpoutcol,"   JAUNE\n");}
		//printf("   JAUNE\n");}
	if((lambda >= 591*i) && (lambda <= 625*i)){
		fprintf(fpoutcol,"   ORANGE\n");}
		//printf("   ORANGE\n");}
	if((lambda >= 626*i) && (lambda <= 740*i)){
		fprintf(fpoutcol,"   ROUGE\n");}
		//printf("   ROUGE\n");}
	if(lambda <= 380*i){
		fprintf(fpoutcol,"   UV\n");}
		//printf("   UV\n");}
	if(lambda >= 740*i){
		fprintf(fpoutcol,"   INFRAROUGE\n");}
		//printf("   INFRAROUGE");}
	return;}


	/* POSITION SPECTRALE*/
void position_spectrale(float lambda, float tau)
{
	float c,h,E0,q,pi;
	float nu,k,E;
	double dnu,dk;
	float dlambda;
	//printf("Temps de propagation de l'onde (en s): ");
	//scanf("%f",&tau);

	pi = 3.14;
	h = 6.63e-34;
	c = 3e8;
	q = 1.6e-19f;

	nu = (c/lambda);
	k = (1/lambda)*1e-2;
	E0 = h*nu;
	E = (E0/q);
	dnu = (1/tau);
	dlambda = (-(lambda*dnu)/nu);
	dk = (dnu/c)*1e-2;

	FILE *fpout;
	fpout = fopen("out","w");
	fprintf(fpout, "Fréquence : %3.2e Hz\nNombre d'onde k : %5.2e 1/cm\nEnergie : %3.2f eV\n",nu,k,E);
	//printf("     Fréquence : %3.2e Hz\n     Nombre d'onde k : %5.2e 1/cm\n     Energie : %3.2f eV\n",nu,k,E);
	fprintf(fpout, "Largeur spectrale en longueur d'onde : %3.2e nm \nLargeur spectrale en fréquence : %2.1e Hz\nVariation nombre d'onde dk : %3.2e 1/cm\n",dlambda,dnu,dk);
	//printf("     Largeur spectrale en longueur d'onde : %3.2e nm \n     Largeur spectrale en fréquence : %2.1e Hz\n     Variation nombre d'onde dk : %3.2e 1/cm\n",dlambda,dnu,dk);
	fclose(fpout);
	return;
}


/* PROGRAMME PRINCIPAL*/
int main(void)
{
	int test;
	float lambda, tau;
	FILE *fp; // JB Qt
	fp = fopen("par","r"); //JB Qt
	//printf("Longueur d'onde (en nm):  ");
	//scanf("%f",&lambda);
	fscanf(fp,"%lg %lg",&lambda, &tau);
	couleur(lambda);
	//position_spectrale(lambda);
	position_spectrale(lambda,tau);
	scanf("%d\n");
	fclose(fp);
	exit(EXIT_SUCCESS);
}
