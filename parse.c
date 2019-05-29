#include "filler.h"

static char **get_actual_piece(int height) {
	int counter;
	char **piece;
	char *line;

	piece = ft_memalloc(sizeof(char *) * height + 1);
	counter = 0;
	logM("\ngetting my piece\n\n", -1, 0);
	while (counter < height) {
		ft_get_next_line(0, &line);
		piece[counter++] = ft_strdup(line);
		logM(piece[counter - 1], -1, 0);
		LOGN
		ft_strdel(&line);
	}
	return piece;
}

static char **get_actual_map(int height) {
	char 		**map;
	int 		  counter;
	char 		*line;

	counter = 0;
	map = ft_memalloc(sizeof(char *) * height + 1);
	ft_get_next_line(0, &line);
	ft_strdel(&line);
	while (counter < height) {
		ft_get_next_line(0, &line);
		map[counter++] = ft_strdup(&line[4]);
		ft_strdel(&line);
	}
	return map;
}

t_piece *get_piece() {
	t_piece			 *piece;
	char 			  *line;
	char			  **words;

	piece = malloc(sizeof(t_piece));
	ft_get_next_line(0, &line);
	words = ft_strsplit(line, ' ');
	piece->size.y = ft_atoi(words[1]);
	piece->size.x = ft_atoi(words[2]);
	ft_delete(words);

	piece->shape = get_actual_piece(piece->size.y);
	return piece;
}

t_map 	*get_map() {

	t_map		*fresh;
	char 		  *line;
	char 			**words;

	fresh = malloc(sizeof(t_map));
	while(1) {
		ft_get_next_line(0, &line);
		if (ft_strnstr(line, "Plateau", 8)) {

			words = ft_strsplit(line, ' ');
			fresh->size.y = ft_atoi(words[1]);
			fresh->size.x = ft_atoi(words[2]);

			logM("\nmap Size:\nheight = ", -1, 0);
			logM(ft_itoa(fresh->size.y), -1, 0);
			logM("\nwidth = ", -1, 0);
			logM(ft_itoa(fresh->size.x), -1, 0);
			LOGN

			ft_delete(words);
			fresh->shape = get_actual_map(fresh->size.y);
			return fresh;
		}
		ft_strdel(&line);
	}
}

char get_player(char *enemy) {
	char *line;

	line = NULL;	
	while(1) {
		ft_get_next_line(0, &line);
		if (!line)
			break ;
		if (ft_strnstr(line, "$$$ exec p", 10)) {
			*enemy = line[10] == '1' ? 'X' : 'O';
			ft_strdel(&line);
			return *enemy == 'X' ? 'O' : 'X';
		}
		ft_strdel(&line);
	}
	return '?';
}