#include <unistd.h>



int get_next_line(int fd)
{
	int			i;
	char		*buf;
    ssize_t		rc;
    char		*temp;
    char		*line;
    int			size;

	size = 1;
	line = malloc(1);
	line[0] = '\0';
	buf = malloc(sizeof(char));
    while (1)
	{
		i = 0;
		rc = read(fd, buf, 1);
		if (rc == 0)
			break ;
		size++;
		temp = malloc(sizeof(char) * size);
		while (line[i] != '\0')
		{
			temp[i] = line[i];
			i++;
		}
		temp[i] = '\0';
		free(line);
		line = temp;
	}
	free(buf);
	if(line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
