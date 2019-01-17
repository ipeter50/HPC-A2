#include <stdio.h>
#include <stdlib.h>

#include "omp.h"
#include "datatools.h"
#include "utils.h"
#include "jacobi.h"



int
main(int argc, char *argv[]) {

	double te, ts;

	double **Uk, **Uk1, **F;
	
	int N = 10;
	
	double threshold = 0.0;
	int max_iter = 10000;

	int i, j;
	
	
	

	if ( argc >=2 ) N = atoi(argv[1]);
	
	if ( argc >=3 ) max_iter = atoi(argv[2]);

	if ( argc >=4 ) threshold = atof(argv[3]);
	

	Uk = malloc_2d(N+2,N+2);
    	Uk1 = malloc_2d(N+2,N+2);
	F = malloc_2d(N+2,N+2);
	
		
	
	init_matrices(Uk, Uk1, F, N);
	
	ts = omp_get_wtime();
	
	printf("jacobi");
	
			
	jacobi(Uk, Uk1, F, N, max_iter, threshold);
	

	te = omp_get_wtime() - ts;
	printf("\nTime: %f\n", te);

	//display_mat(F, N);
	//display_mat(Uk1, N);
    
	free_2d(Uk);
	free_2d(Uk1);
	free_2d(F);


	return(0);
}



