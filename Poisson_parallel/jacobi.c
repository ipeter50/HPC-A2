#include "jacobi.h"
#include "utils.h"

void
jacobi(double **Uk, double **Uk1, double **F, int N, int max_iter, double threshold){

	int k=0;

	double d = 1000; 

	double delta_squared = 1.0/(N+2) * 1.0/(N+2);
	double h = 1.0/4;

	while(k<max_iter && d>threshold){
		if(k%2 == 0){
			d = update_jacobi(Uk, Uk1, F, N, delta_squared, h); 
		}
		else{
			d = update_jacobi(Uk1, Uk, F, N, delta_squared, h); 
		}
		k = k+1;
	}
	//d = update_jacobi(Uk, Uk1, F, N); // just to retrieve the last iteration
	printf("\nNorm: %f \nk: %d", d, k);	

}


double 
update_jacobi(double **Uk, double **Uk1, double **F, int N, double delta_squared, double h){
	int i,j;

	
	
	double tmp, tmp1;
	double norm=0.0;
	#pragma omp parallel for shared(N, Uk, Uk1, F, h, delta_squared) private(tmp, tmp1, i, j) reduction(+:norm)
	for(j=1;j<N+1;j++){
		for(i=1;i<N+1;i++){
			tmp = h*(Uk[i+1][j] + Uk[i-1][j] + Uk[i][j+1] + Uk[i][j-1] +  delta_squared * F[i][j]);
			tmp1 = tmp - Uk[i][j];
			norm +=  tmp1 * tmp1;
			Uk1[i][j] = tmp;
		}
	}
	return norm;

}