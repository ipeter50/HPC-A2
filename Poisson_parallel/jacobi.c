#include "jacobi.h"
#include "utils.h"

void
jacobi(double **Uk, double **Uk1, double **F, int N, int max_iter, double threshold){

	int i, j, k=0;

	double d, delta_squared, h, norm_tmp, norm;

	double **tmp; 
	
	delta_squared = 1.0/(N+2) * 1.0/(N+2);
	h = 1.0/4;
	
	d = 1000; 
	#pragma omp parallel shared(Uk, Uk1, F, N, max_iter, threshold, delta_squared, h, d, i, j, k) private(tmp, norm_tmp)
	{
	while(k<max_iter && d>threshold){
		norm = 0.0;
		#pragma omp for private(norm_tmp, i, j) reduction(+:norm) schedule(runtime)
		for(j=1;j<N+1;j++){
			for(i=1;i<N+1;i++){
				norm_tmp = h*(Uk[i+1][j] + Uk[i-1][j] + Uk[i][j+1] + Uk[i][j-1] +  delta_squared * F[i][j]);
				
				norm +=  (norm_tmp - Uk[i][j]) * (norm_tmp - Uk[i][j]);
				Uk1[i][j] = norm_tmp;
			}
		}	

		
		#pragma omp single
		{		
		tmp = Uk;
		Uk = Uk1;
		Uk1 = tmp;
		d = norm;
		k = k+1;
		}
	}

	}
	printf("\nNorm: %f \nk: %d", d, k);	

}


double 
update_jacobi(double **Uk, double **Uk1, double **F, int N, double delta_squared, double h){
	

	double norm;
	
	return norm;

}
