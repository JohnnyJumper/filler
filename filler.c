#include "./include/filler.h"

static t_filler *init_filler() {
	t_filler 	*filler;

	filler = malloc(sizeof(t_filler));
	filler->player = get_player(&filler->enemy);

	logM("enemy->player = ", -1, 0);
	logM(&filler->enemy, 1, 0);
	logM("\nplayer = ", -1, 0);
	logM(&filler->player, 1, 0);
	LOGN
	return filler;
}

int 	main()
{

	t_filler		*filler;
	t_piece		  *piece;	

	filler = init_filler();

	while (1) {
		filler->map = get_map();
		piece = get_piece();
		break ;
	}
	logM("end of logs\n", -1, 1);
	return (0);
}