#include "libft.h"

void    ft_putchar_fd(char c);
{
    write(1, &c, 1);
}

int main(void)
{
	ft_putchar_fd('c');
	return (0);
}
