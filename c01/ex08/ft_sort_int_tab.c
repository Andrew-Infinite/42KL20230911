void ft_sort_int_tab(int *tab, int size){
	int i;
	int end;

	end = size;
	while(--end>0)
	{
		i=0;
		while(++i<=end)
		{
			if(tab[i-1]>tab[i])
			{
				int temp = tab[i-1];
				tab[i-1] = tab[i];
				tab[i] = temp;
			}
		}
	}
}
