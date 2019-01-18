#!/bin/bash 
#BSUB -q hpcintro
#BSUB -o naive_500.out
#BSUB -n 24

for t in 1 2 4 6 8 10 12 14 16 18 20 22 24;
do
	
	OMP_NUM_THREADS=$t ./poisson_naive.suncc 500 10000
	
done
