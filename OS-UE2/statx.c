#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif 
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/stat.h>
#include <stdio.h>

size_t length(char *str)
{
    int i = 0;
    while (str[i] != 0)
        i++;
    return i;
}

void putstr(char *str)
{
    size_t len = length(str);
    if (write(1, str, len) != (ssize_t)len)
        exit(1);
}

static int	numlen(int n)
{
	int	len;

	len = (n <= 0);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
    int			len;
	char		str[len + 1];
	
	long int	nb;

	nb = n;
	len = numlen(n);
	str[len] = 0;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[--len] = '0';
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

int main(int ac, char **av)
{
    if (ac != 2)
        exit(1);
    struct statx buf;
    if (statx(0, av[1], AT_SYMLINK_NOFOLLOW, STATX_UID | STATX_GID, &buf) == -1) exit(1);
    putstr("UID: ");
    putstr(ft_itoa(buf.stx_uid));
    putstr(", GID: ");
    putstr(ft_itoa(buf.stx_gid));
    putstr("\n");
    if (statx(0, av[1], AT_SYMLINK_NOFOLLOW, STATX_SIZE, &buf) == -1) exit(1);
    putstr("Size: ");
    putstr(ft_itoa(buf.stx_size));
    putstr("\n");
    if (statx(0, av[1], AT_SYMLINK_NOFOLLOW, STATX_MODE, &buf) == -1) exit(1);
    putstr(ft_itoa(buf.stx_mode));
    putstr("\n");
}