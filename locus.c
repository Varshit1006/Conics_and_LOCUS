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
double **linspace(double a,double l, int m)
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

//Function for creating ellipse
double **createEllipse(double a, double b,double** O, int len)
{
double** j = createMat(2,len);
double **theta = linspace(0, 2* M_PI,100);
for (int i=0;i<len;i++)
{
j[0][i] = *O[0] + a*cos(*theta[i]);
j[1][i] = *O[1] + b*sin(*theta[i]);
}
return j;
}
//End Function

//Function for scalar division
double**linallg_scalardiv(double**a,double k, int m, int n)
{
  int i,j;
  double**c;
  c=createMat(m,n);
    for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
      {
c[i][j]=a[i][j]/k;

      }}
      return c;
    

}
//End Function

//Function for Eigen values
double** eigval(double** A) {
double** ret = createMat(2,1);
double a = A[0][0], b = A[0][1];
double c = A[1][0], d = A[1][1];
double del = sqrt(((a+d)*(a+d)) - 4*((a*d)-(b*c)));
*ret[0] = ((a+d) - del) / 2.0;
*ret[1] = ((a+d) + del) / 2.0;
return ret;
}
//End function

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

    double **E = linallg_scalardiv(V,-F,2,2);

double** eig = eigval(E);

double a = 1/sqrt(*eig[1]);
double b = 1/sqrt(*eig[0]);

  //creating ellipse points
  double**ellipse = createEllipse(a, b, O, 100);
  saveMat(ellipse , "ellipse.dat",2,100);

return 0;
 }

