#ifndef MINITALK_H
# define MINITALK_H

# define _XOPEN_SOURCE 600
# define _POSIX_C_SOURCE 200112L

# include <signal.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
char	ft_putnbr(int n);
int		ft_atoi(const char *str);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

#endif