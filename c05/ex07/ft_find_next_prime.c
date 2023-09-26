
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

int ft_find_next_prime(int nb){
	while (ft_is_prime(nb++)!=1);
	return nb-1;
}
