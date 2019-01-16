#include <stdio.h>
#include <stdlib.h>

#include "omp.h"



int
main(int argc, char *argv[]) {

    double te, ts;

    ts = omp_get_wtime();	

    

    te = omp_get_wtime() - ts;
    printf("%f\n", te);
    
	
    return(0);
}
