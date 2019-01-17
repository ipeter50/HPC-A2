for t in 1 2 4 6 8 10 12 14 16
do
	for size in 1000
	do
		OMP_NUM_THREADS=$t 
		echo $t $size $(./poisson_naive.suncc $size)  >> res.dat
	done
done
