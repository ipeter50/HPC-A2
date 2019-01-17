for t in 1 2 4 6 8 10 12 14 16
do
	for size in 10000
	do
		OMP_NUM_THREADS=$t 
		OMP_SCHEDULE=dynamic,50
		echo $t $size $(./mandelbrot $size)  >> res.dat
	done
done
