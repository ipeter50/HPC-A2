for t in 1 2 4 8 16
do
	for size in 2000 4000 6000 8000 10000
	do
		OMP_NUM_THREADS=$t 
		OMP_SCHEDULE=dynamic,50
		echo $t $size $(./mandelbrot $size)  >> res.dat
	done
done
