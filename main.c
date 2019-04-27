#include "fillit.h"
#include "libft/libft.h"
#include "define_boardsize.c"
#include "check_multiple_tetrimino.c"



int	main(int argc, char **argv)
{
	int ret;
	int a;
	int *nb;
	nb = &a;
	char ***array;
	char **board;
	int i = 0;
	int k = 0;

	if (argc)
	{
		array = store_tretrimino(argv[1], nb);
		if (array == NULL)
		{
			printf("ret = -1 error\n");//PRINT
			return (-1);
		}
		ret = check_tetrimino(array, nb);
		printf("ret = %d\n", ret);//PRINT
		
		board = define_boardsize (*nb);
			
		

	}
	return (0);
}
	
