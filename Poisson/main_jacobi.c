#include <stdio.h>
#include <stdlib.h>

#include "omp.h"
#include "datatools.h"



int
main(int argc, char *argv[]) {

	double te, ts;

	double **A;
	
	int N = 10;
	int i, j;

	A = malloc_2d(10,10);
    
	
	ts = omp_get_wtime();	

    	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			A[i][j] = 2;
			printf("%f ", A[i][j]);
		}
		printf("\n");
	}

	te = omp_get_wtime() - ts;
	printf("%f\n", te);
    
	
	return(0);
}
