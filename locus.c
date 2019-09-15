#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"

double **meshgrid(int len, int begin, double addX, int addY);
void saveMat(double** mat, char*str, double m, double n);

int main(){
	int len = 9;
	
	double **x = meshgrid(len,-2, 0.5, 0);
	saveMat(x, "meshX1.dat", len, len);
	
	double **y = meshgrid(len,-3, 1, 0);
	saveMat(y, "line.dat", 1, len);
	 
    double **V = createMat(2,2);
    V[0][0] = 9 ; V[0][1] = 0 ; V[1][0] = 0 ; V[1][1] = 8;
    print(V,2,2);
    printf("\n\n");
    saveMat(V, "V.dat", 2, 2);
     
    double **u = createMat(2,1);
    u[0][0] = 0 ; u[1][0] = 8 ;
    print(u,2,1);
    printf("\n\n");
    saveMat(u, "u.dat", 2, 1);
    
    double **O = createMat(2,1);
    O[0][0] = 0 ; O[1][0] = 0 ;
    print(O,2,1);
    printf("\n\n");
    saveMat(O, "O.dat", 2, 1);
    
    double **A = createMat(2,1);
    A[0][0] = 0 ; A[1][0] = 1 ;
    print(A,2,1);
    printf("\n\n");
    saveMat(A, "A.dat", 2, 1);
    
    double **F = createMat(1,1);
    F[0][0] = 16 ;
    print(F,1,1);
    printf("\n\n");
    saveMat(F, "F.dat", 1, 1);
    
void saveValue(char *str,double p)
 {	
	FILE *fp;
	fp = fopen(str,"w");
	fprintf(fp, "%lf ", p);
	fclose(fp);
 }
    
    //eigen value-a = sqrt(0.5*((V[0][0]+V[1][1])/3-sqrt((a*V[0][1]*V[1][0]) +(V[0][0]-V[1][1])(v[0][0]-V[1][1]))));
    //eigen value-b = sqrt(0.5*((V[0][0]+V[1][1])/3+sqrt((a*V[0][1]*V[1][0]) +(V[0][0]-V[1][1])(v[0][0]-V[1][1]))));
    double a = sqrt(V[1][1]/3);
    saveValue("a.dat",a);
    printf("%f\n\n",a);
    
    double b = sqrt(V[0][0]/3);
    saveValue("b.dat",b);
    printf("%f",b);

    theta("theta.dat",10000);

	return 0;
 }	
	
double **meshgrid(int len, int begin, double addX, int addY)
{
	double ** ret = createMat(len, len);
	for (int i=0; i<len; i++)
		for (int j=0; j<len; j++){
			ret[i][j] = begin + i*addY + j*addX;
		}
	return ret;
}

void saveMat(double** mat, char *str, double m, double n){
	FILE *fp;
	fp = fopen(str,"w");
	for (int i=0; i < m; i++){
		for (int j=0; j < n; j++){
			fprintf(fp, "%lf ", mat[i][j]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	
	
}	

