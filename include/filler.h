#ifndef _FILLER_
# define _FILLER_

#include "../libft/libft.h"

typedef struct	 s_point {
	int x;
	int y;
} 						t_point;

typedef struct s_map {
	t_point				size;
	char				**shape;
}					t_map;

typedef struct s_piece {
	t_point				size;
	char				**shape;
}					t_piece;

typedef struct s_filler {
	t_map 		  *map;
	char 			player;
	char 			enemy;	
}					t_filler;

# define LOG "./filler.log"
# define LOGN logM("\n",1, 0);


t_piece *get_piece();
t_map 	*get_map();
void ft_delete(char **words);
char get_player(char *enemy);
void 	logM(char *message, int length, int exitFlag);

#endif