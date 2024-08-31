#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int	n;
	int				minus_flag;
	int				i;

	n = 0;
	minus_flag = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\v') || (str[i] == '\f'))
		str++;
	i++;
	if (*str == '-')
	{
		minus_flag = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
		n = n * 10 + (*str++ - '0');
	if (minus_flag)
		n *= -1;
	return ((int)n);
}

static size_t	get_digits(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str_num;
	size_t		digits;
	long int	num;

	num = n;
	digits = get_digits(n);
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	str_num = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str_num)
		return (NULL);
	*(str_num + digits) = 0;
	while (digits--)
	{
		*(str_num + digits) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(str_num + 0) = '-';
	return (str_num);
}

int ft_printf(const char *format, ...)
{
	char	*str;
	va_list ap;
	char	c;
	char	*s;
	int		d;
	unsigned 	u;
	str = (char *)format;

	va_start(ap,format);

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
			{
				c = va_arg(ap,int);
				ft_putchar_fd(c , 1);
			}
			if (*str == 's')
			{
				s = va_arg(ap,char *);
				ft_putstr_fd(s,1);
			}
			if (*str == 'd' || *str == 'i')
			{
				d = va_arg(ap,int);
				ft_putstr_fd(ft_itoa(d),1);
			}
			if (*str=='u')
			{
				u = va_arg(ap,unsigned int);
				ft_putstr_fd(unsigned_itoa(u),1);
			}
			str++;
		}
		else 
		{
			ft_putchar_fd(*str,1);
			str++;
		}
	}
	va_end(ap);
	write(1,"\n",1);
	return(0);//本当は出力文字数を出す。
}

int main (void)
{
    char t[10]="test";
	char r='r';
	int i;
	int *iptr;
	int b;
	i=1234;
	iptr=&i;
	b=89;
	unsigned long u;
	u=4294967295;
	ft_printf("%u",u);
	// printf("%p\n",iptr);
	// printf("%p\n",&i);
	
	// ft_printf("test%d%c%dtest",i,r,b);
	// ft_printf("thisis%s",t);
    // printf("thisis%s\n",t);
	// // printf("thisis%S",t);
	// printf("return=%d\n",printf("hello"));
	// printf("flag-filed\n");
	// printf("[%10d]\n", 1);
	// printf("[%10c]\n", 'a');
	// printf("\n");

	// printf("flag-minus\n");
	// printf("[%10d]\n", 1);
	// printf("[%-10d]\n", 1);	
	// printf("[%10f]\n", 1.0);
	// printf("[%-10f]\n", 1.0);
	// printf("[%10s]\n", "1234");	 
	// printf("[%-10s]\n", "1234");
	// printf("\n");
	// printf("flag-zero\n");
	// printf("[%10d]\n", 1);	
	// printf("[%010d]\n", 1);	
	// printf("[%10f]\n", 1.0);
	// printf("[%010f]\n", 1.0);
	// printf("\n");
	// printf("flag-plus\n");
	// printf("[%+d]\n", 1);
	// printf("[%d]\n", -1);
	// printf("[%+d]\n", -1);	
	// printf("[%+f]\n", 1.0);	
	// printf("[%+f]\n", -1.0);

}

