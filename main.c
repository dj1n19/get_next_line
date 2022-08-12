#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *line;
	printf("---------------\n");

	line = get_next_line(fd);
	printf(">>%s", line);
	line = get_next_line(fd);
	printf(">>%s", line);
	line = get_next_line(fd);
	printf(">>%s", line);
	printf("---------------\n");
	close(fd);
	check_leaks();
	return 0;
}
