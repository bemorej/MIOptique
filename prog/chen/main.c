//
//  main.c
//  spectrometre
//
//  Created by 梁小美 on 2018/2/11.
//  Copyright © 2018年 梁小美. All rights reserved.
//
#define P 3.1415926
#define Y 0 // incertitude initiale
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

      int main(int argc, char **argv)
      {
        int n,i;//i pour nombre de mésures
        unsigned char z1=30,z2=241; //pour répresenter symbole spéciale
           float o_11,o_12,o_21,o_22,k,l; //pour présenter des valeure entrée
        float a=0,b=0,c,d=0,e=0,f,g,h,B;
        float p[30],q[30];
        float p_a,p_b,p_c;
        printf("veuiller entrer nombre des mésures N=");
        scanf("%d",&n);
        printf("\n");
        printf("veuiller entrer valeur l’angle du prisme A du fenêtre gauche et droite par ordre:\n");
        for (i=1;i<=n;i++)
           {printf("veuiller entrer valeur de %d fois mesures du fenêtre gauche et droite:",i);
           scanf("%f,%f,%f,%f",&o_11,&o_12,&o_21,&o_22);
           printf("\n");
           k=fabs(o_11-o_21);
           l=fabs(o_12-o_22);
           if(k>=180) k=360-k;
           if(l>=180) l=360-l;
           p[i]=P*(k+l)/(4.0*180);
           a+=p[i];
           }
           a=a/n;
           printf("veuiller entrer valeur de la déviation minimale du fenêtre gauche et droite:\n");
           for(i=1;i<=n;i++)
            {
             printf("veuiller entrer valeur de %d fois mesures du fenêtre gauche et droite:",i);
             scanf("%f,%f,%f,%f",&o_11,&o_12,&o_21,&o_22);
             printf("\n");
                k=fabs(o_11-o_21);
                l=fabs(o_12-o_22);
                if(k>=180) k=360-k;
                if(l>=180) l=360-l;
                 q[i]=P*(k+l)/(2.0*180);
                 b+=q[i];
             }
           b=b/n;
           c=sin((b+a)/2.0)/sin(a/2.0);
           printf("valeur moyenne de l'indice de réfraction n=%f",c);
           for(i=1;i<=n;i++)
            {
              d+=pow(p[i]-a,2.0);
                e+=pow(q[i]-b,2.0);
             }
            p_a=sqrt(d/n*(n-1));// écart type du angle A
            p_b=sqrt(e/n*(n-1));//écart type du la déviation minimale
            f=cos((a+b)/2.0)*p_b/(2*sin(a/2.0));
            g=sin(b/2.0)*p_a/(2*sin(a/2.0));
            p_c=sqrt(pow(f,2.0+pow(g,2.0)));//écart type de l'indice de réfraction
            switch(n)
            {
             case 2:B=12.7;break;
             case 3:B=4.30;break;
             case 4:B=3.18;break;
             case 5:B=2.78;break;
             case 6:B=2.57;break;
             case 7:B=2.45;break;
             case 8:B=2.36;break;
             case 9:B=2.31;break;
             case 10:B=2.26;break;
             case 15:B=2.14;break;
             case 20:B=2.09;break;
             default :B=1.96;
             }
            h=pow(p_c*B,2.0)+pow(Y,2.0);
            h=sqrt(h);
            printf("incertitude totale %c=%4.3f\n \n",z1,h);
            printf("résultat final de l'indice de réfraction vaut :n=%f%c%f",c,z2,h);

        return 0;
        }
