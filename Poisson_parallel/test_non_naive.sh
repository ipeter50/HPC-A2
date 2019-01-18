#!/bin/bash
#BSUB -o sockets.out
#BSUB -q hpcintro
#BSUB -n 24

for t in  1 2 4 6 8 10 12 14 16 18 20 22 24;
do
	
	export OMP_NUM_THREADS=$t
	export OMP_SCHEDULE=static
	export OMP_PROC_BIND=true 
	export OMP_PLACES=sockets 
	./poisson.suncc 2500 500
	
done
