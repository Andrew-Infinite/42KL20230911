int index2dto1d(int x, int y)
	return y*10 + x;

int is_valid(char *map, int x, int y){
	int i;
	int j;

	i = -1;
	while(++i<x)
		if (map[index2dto1d(i,y)] == 1)
			return 0;
	i = x;
	j = y;
	while(--i>0 || --j>0 )
		if (map[index2dto1d(i,j)] == 1)
			return 0;
	i = x;
	j = y;
	while(++i<10 || --j>0)
		if (map[index2dto1d(i,j)] == 1)
			return 0;
	return 1;
}

int print_solution(char *map){
	int i = 0;
	while(i<100) 
		if(i%10)
	}
}

int ft_solver(char *map, int y){
	if(y >= 10){
		
	}

	int i = -1;
	while(++i < 10){
		if(is_valid(map,i,y)){
			ft_solver(map,y+1);
		}
	}
}

int ft_ten_queens_puzzle(void){
	int map[100];
	
}

