#include <fcntl.h>
#include <unistd.h>









int		main(void)
{
	int			fd;

	if ((fd = open("toto.cor", O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
		printf(" error open\n");

	int a = 1;
	while (a)
	{
		a = calcul_size();
		write(fd, &a, 1);
	}

	if (close(fd) != 0)
		printf("close_error_.cor");
}
