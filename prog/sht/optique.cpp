#include<stdio.h>
#include<math.h>

void write_gnuplot(float f,float d, float h,float d2, float h2){

FILE *fptr;
float dm,hm;

dm = fabs(d);

if (fabs(d2)>fabs(d)){
	dm = fabs(d2);	
}

hm = fabs(h);

if (fabs(h2)>fabs(h)){
	hm = fabs(h2);	
}

fptr = fopen("out.gnu","w");

fprintf(fptr,"unset key\n"); 
fprintf(fptr,"set xrange [%.2f:%.2f]  \n",-1.2*dm,+1.2*dm);
fprintf(fptr,"set yrange [%.2f:%.2f] \n" ,-1.2*hm,+1.2*hm);
fprintf(fptr,"set xzeroaxis lt -1 lw +1.5 \n");

fprintf(fptr,"set arrow from 0,0 to 0,%.2f  lw +1.5 \n",1.20*hm);
fprintf(fptr,"set arrow from 0,0 to 0,%.2f  lw +1.5 \n",-1.20*hm);

fprintf(fptr,"set arrow from %.2f,0 to %.2f,%.2f nohead lw +1.5  linecolor rgb 'red'  \n",-d,-d,h);
fprintf(fptr,"set arrow from %.2f,0 to %.2f,%.2f nohead lw +1.5  linecolor rgb 'blue' \n",d2,d2,h2);

fprintf(fptr,"set arrow from %.2f,%.2f to 0,0  nohead lw +1.5  linecolor rgb 'green' \n",-d,h);
fprintf(fptr,"set arrow from 0,0 to %.2f,%.2f  nohead lw +1.5  linecolor rgb 'green' \n",d2,h2);

fprintf(fptr,"set arrow from %.2f,%.2f to  0,%.2f    nohead lw +1.5  linecolor rgb 'green' \n",-d,h,h);
fprintf(fptr,"set arrow from 0,%.2f    to  %.2f,%.2f    nohead lw +1.5  linecolor rgb 'green' \n",h,d2,h2);

fprintf(fptr,"set label 1 'F1'  at %.2f,-0.2 \n",-f);
fprintf(fptr,"set label 2 'F2' at %.2f,-0.2 \n",+f);
fprintf(fptr,"set label 3 '' at %.2f,0.0 point pointtype 2 \n",-f);
fprintf(fptr,"set label 4 '' at %.2f,0.0 point pointtype 2 \n",+f);

fprintf(fptr,"set label 'A1'  at %.2f,-0.2 \n" , -d+0.1  );
fprintf(fptr,"set label 'A2'  at %.2f,-0.2  \n" , +d2+0.1 );

fprintf(fptr,"set label 'B1'   at  %.2f,%.2f \n",-d+0.1,h);
fprintf(fptr,"set label 'B2' at  %.2f,%.2f \n",d2+0.1,h2);

fprintf(fptr,"set grid \n");
fprintf(fptr,"plot 0 with lines lw +1.5  linecolor rgb 'black' \n");
fprintf(fptr,"pause -1 \n");

fclose(fptr);

}

int main()

{

float f,d,h,d2,h2,g;
int i,j;

void write_gnuplot(float f,float d,float h,float d2,float h2);

printf("PROGRAMME OPTIQUE GEOMETRIQUE \n");
printf("-Entrer la valeur du foyer f =");
scanf("%f",&f);
printf("-Entrer la position horizontale en d = ");
scanf("%f",&d);
printf("-Entrer la hauteur de l objet en h = ");
scanf("%f",&h);

d2 = 1./(1./f-1./d);
g  = -d2/d;
h2 = -h*d2/d;

printf("RESULTAT\n");
printf("-> Hauteur de l image = %.2f \n",h2);
printf("-> Distance de l image par rapport a la lentille = %.2f \n",d2);
printf("-> Grossissement = %.2f \n",g);

// ecrire un fichier resultat
// fichier de sortie .dat qui s'ouvre avec gnuplot
write_gnuplot(f, d, h, d2, h2);
int test;
scanf("%d",&test);

return(0);

}
