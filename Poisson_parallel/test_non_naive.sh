#!/bin/bash 
#BSUB -q hpcintro
#BSUB -n 24

for t in 1 2 4 6 8 10 12 14 16 18 20 22 24;
do
	
	OMP_NUM_THREADS=$t 
	OMP_SCHEDULE=dynamic ./poisson.suncc 1000 10000
	
done
