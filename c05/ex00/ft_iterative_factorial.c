int ft_iterative_factorial(int nb){
	if(nb<0)
		return 0;
	int i;
	int fac;

	i = 0;
	fac = 1;
	while(++i <= nb)
		fac = fac * i;
	return fac;
}
