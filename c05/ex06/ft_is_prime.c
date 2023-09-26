int ft_is_prime(int nb){
	if(nb < 2)
		return 0;
	int i = 2;
	
	while (i*2 <= nb){
		if(nb%i == 0)
			return 0;
		i++;
	}
	return 1;
}
