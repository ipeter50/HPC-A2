#!/bin/bash
#BSUB -o mandelbrot.out
#BSUB -q hpcintro
#BSUB -n 24

for t in 1 2 4 6 8 10 12 14 16 18 20 22 24
do
	for size in 5000
	do
		OMP_NUM_THREADS=$t 
		OMP_SCHEDULE=dynamic,50
		./mandelbrot $size
	done
done
