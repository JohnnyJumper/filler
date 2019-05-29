#include "filler.h"

void ft_delete(char **words) {
	char *word;

	word = *words++;
	while (word) {
		ft_strdel(&word);
		word = *words++;
	}
}


void 	logM(char *message, int length, int exitFlag) {
	static int logFd;

	if (!logFd) 
		logFd = open(LOG, O_CREAT | O_RDWR  | O_APPEND | O_TRUNC );	
	if (length == -1)
		write(logFd, message, ft_strlen(message));
	else 
		write(logFd, message, length);
	if (exitFlag)
		close(logFd);
}
