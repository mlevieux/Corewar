#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


unsigned char		*cut_nbr(int nbr) // cree un tab de 4 char   
{
	unsigned char *tab;
	int diviseur;
	int	a;
	int b;

	diviseur = 2147483648;

	tab = (unsigned char *)malloc(sizeof (char) * 5);
	if (!tab)
		printf("malloc error\n");
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	a = 128;
	b = 8;
	while (b > 0)
	{
		tab[0] += ((nbr / diviseur) * a);
		printf("%d %d\n", nbr, diviseur);
		nbr %= diviseur;
		diviseur /= 2;
		a /= 2;
		b --;
	}
	a = 128;
	b = 8;
	while (b > 0)
	{
		tab[1] += -((nbr / diviseur) * a);
		printf("%d %d\n", nbr, diviseur);
		nbr %= diviseur;
		diviseur /= 2;
		a /= 2;
		b --;
	}
	a = 128;
	b = 8;
	while (b > 0)
	{
		tab[2] += -((nbr / diviseur) * a);
		printf("%d %d\n", nbr, diviseur);
		nbr %= diviseur;
		diviseur /= 2;
		a /= 2;
		b --;
	}
	a = 128;
	b = 8;
	while (b > 0)
	{
		tab[3] += -((nbr / diviseur) * a);
		printf("%d %d\n", nbr, diviseur);
		nbr %= diviseur;
		diviseur /= 2;
		a /= 2;
		b --;
	}
	return (tab);
}

int		main(void)
{
	int			fd;

	if ((fd = open("toto.cor", O_WRONLY, 0644)) == -1)
		printf(" error open\n");

	int b = 3401123;
	unsigned char* a;
	
	a = cut_nbr(3401123);
	write (fd, &b, 4);
	write (fd, &a[0], 1);
	write (fd, &a[1], 1);
	write (fd, &a[2], 1);
	write (fd, &a[3], 1);
	write (fd, &a[4], 1);
	if (close(fd) != 0)
		printf("close_error_.cor");
}
