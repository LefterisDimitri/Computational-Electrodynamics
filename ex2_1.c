#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	FILE *fp11;
	FILE *fp;
	FILE *fp1;
	FILE *fp2;
	FILE *fp3;
	FILE *fp4;
	
	fp11 = fopen("0_1.dat","w");
	fp = fopen("20_1.dat","w");
	fp1 = fopen("40_1.dat","w");
	fp2 = fopen("60_1.dat","w");
	fp3 = fopen("80_1.dat","w");
	fp4 = fopen("100_1.dat","w");

	int i, j;
	int N=200;              
	int M=200;              

	double
	**u,
	**unew,
	*x,
	*t,
	dx,
	dt;



// Allocate memory

	u = (double**) malloc(N*sizeof(double*));
	for (int i = 0; i < N; i++)
		u[i] = (double*) malloc(M*sizeof(double));

	unew = (double**) malloc(N*sizeof(double*));
	for (int i = 0; i < N; i++)
		unew[i] = (double*) malloc(M*sizeof(double));

	x = (double*) malloc(N*sizeof(double));
	t = (double*) malloc(N*sizeof(double));

	// grid spacings
	dx = (1.0-0.0)/(N-1);   // 0 < x < 1
	dt = dx;

	// x and y grids
	for(i=0; i<N; i++) 
	{
		x[i] = 0.0 + i*dx;
	}

	for(j=0; j<M; j++) 
	{
		t[j] = 0.0 + j*dt;
	}

	// arxikopoihsh pinaka
	for(i=0; i<N; i++) 
	{
		for(j=0; j<M; j++) 
		{
			u[i][j] = 0.0;
			unew[i][j] = 0.0;
		}
	}

	// initial conditions u(xi,t0) --> u(i,0)
	for(i=0; i<N; i++) 
	{
		if(i >= 2 && i <= 6) 
		{
			u[i][0] = 1.0;
			unew[i][0] = 1.0;
		} 
		else if(i >= 7 && i <= 11) 
		{
			u[i][0] = -1.0;
			unew[i][0] = -1.0;
		} 
		else 
		{
			u[i][0] = 0.0;
			unew[i][0] = 0.0;
		}
	}
	
	// initial conditions u(xi,t1) --> u(i,1)
	for(i=0; i<N; i++) 
	{
		if(i >= 3 && i <= 7) 
		{
			u[i][1] = 1.0;
			//unew[i][1] = 1.0;
		} 
		else if(i >= 8 && i <= 12) 
		{
			u[i][1] = -1.0;
			//unew[i][1] = -1.0;
		} 
		else 
		{
			u[i][1] = 0.0;
			//unew[i][1] = 0.0;
		}
	}
	
	// bountary conditions u(xi,0) and u(xn,0)
	for(j=0; j<M; j++) 
	{
		u[0][j] = 0.0;
		u[N-1][j] = 0.0;
		//unew[0][j] = 0.0;
		//unew[N-1][j] = 0.0;
	}
	
	for(j=0; j<M; j++) 
	{
		for(i=0; i<N; i++) 
		{
			if(j == 0) 
			{
				fprintf(fp11,"%lf %lf \n", x[i], u[i][j]);
			}
		}
	}
	// iterative solution
		for(j=1; j<N-1; j++) 
		{
			for(i=1; i<M-1; i++) 
			{
				u[i][j+1] = dt*dt*(u[i+1][j] - 2.0*u[i][j] + u[i-1][j])/(dx*dx) + 2.0*u[i][j] - u[i][j-1];
			}
		}

		// reset uold for next iteration
		/*for(i=1; i<N-1; i++) 
		{
			for(j=1; j<M-1; j++) 
			{
				uold[i][j] = unew[i][j];
			}
		}*/


	for(j=0; j<M; j++) 
	{
		for(i=0; i<N; i++) 
		{
			if(j == 20) 
			{
				fprintf(fp,"%lf %lf \n", x[i], u[i][j]);
			}
			if(j == 40) 
			{
				fprintf(fp1,"%lf %lf \n", x[i], u[i][j]);
			}
			if(j == 60) 
			{
				fprintf(fp2,"%lf %lf \n", x[i], u[i][j]);
			}
			if(j == 80) 
			{
				fprintf(fp3,"%lf %lf \n", x[i], u[i][j]);
			}
			if(j == 100) 
			{
				fprintf(fp4,"%lf %lf \n", x[i], u[i][j]);
			}
		}
	}
	
	fclose(fp11);
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	return 0;
}


