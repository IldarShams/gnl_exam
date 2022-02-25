#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



char *get_next_line(int fd)
{
	int			i;
	char		*buf;
    ssize_t		rc;
    char		*temp;
    char		*line;
    int			size;

	size = 1;
	line = NULL;
	buf = malloc(sizeof(char));
    while (1)
	{
		i = 0;
		rc = read(fd, buf, 1);
		if (rc == 0)
			break ;
		size++;
		temp = malloc(sizeof(char) * size);
		while (line != NULL && i < size - 2)
		{
			temp[i] = line[i];
			i++;
		}
        temp[i] = buf[0];
		temp[i + 1] = '\0';
		free(line);
		line = temp;
	}
	free(buf);
	return (line);
}

int main()
{
    int fd;
    char *line;

    fd = open("./text.txt", O_RDONLY);

    while (line = get_next_line(fd))
    {
        printf("%s\n", line);
        free(line);
    }
}