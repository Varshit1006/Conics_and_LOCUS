#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"



void saveMat (double **mat , char *str, int m , int n){
  FILE *fp;
  fp = fopen(str,"w");
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      fprintf(fp , "%lf",mat[i][j]);
    }
    fprintf(fp ,"\n");
  }
  fclose(fp);
}
//end function

//Function for saving a value to .dat file
void saveValue(char *str,double a){
  FILE *fp;
fp = fopen(str,"w");
fprintf(fp, "%lf",a );
fclose(fp);
}
//end function


//Linspace function
double **linspace(double a, double l, int m)
{
//Variable declarations
double d, **ap;
int i,j;

ap = createMat(m,1);

//Common difference
d = (l-a)/(m-1);

 for(i=0;i<1;i++)
 {
  for(j=0;j<m;j++)
  {
ap[j][i] = a+j*d;

  }
 }
//Returning the address of the first memory block
return ap;
}
//End linspace function


double **meshgrid(int len, int begin, double addX, int addY)
{
  double ** ret = createMat(len, len);
  for (int i=0; i<len; i++)
    for (int j=0; j<len; j++){
      ret[i][j] = begin + i*addY + j*addX;
    }
  return ret;
}


double rootofeqn1(double a,double b,double c){
    double root1;
    double det;
    det=sqrt((b*b)-4*a*c);
        root1 =(((-b)+det)/(2*a));
        return root1;
    }

double rootofeqn2(double a,double b,double c){
    double root2;
    double det;
    det=sqrt((b*b)-4*a*c);
        root2 =(((-b)-det)/(2*a));
        return root2;
    }


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
    
    double F = -16;
    printf("%f\n",F );
    saveValue("F.dat",F);


    double p = 1;
    double q = -(V[0][0]+V[1][1])/16;
    double r = ((V[0][0])*(V[1][1]) - (V[0][1])*(V[1][0]))/256;
    
    double r1 = rootofeqn1(p,q,r);
    printf("%f\n", r1 );

    double r2 = rootofeqn2(p,q,r);
    printf("%f\n", r2 );

    double a = sqrt(1/r1);
    saveValue("a.dat",a);
    printf("%f\n\n",a);
    
    double b = sqrt(1/r2);
    saveValue("b.dat",b);
    printf("%f",b);
    
    double **theta = linspace(0,2*(22/7),100);
    saveMat(theta,"theta.dat",100,1);

	return 0;
 }	
