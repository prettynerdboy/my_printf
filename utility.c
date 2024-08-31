/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soaoki <soaoki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:53:21 by soaoki            #+#    #+#             */
/*   Updated: 2024/08/31 10:17:07 by soaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static size_t	get_digits(unsigned int n)
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

char	*unsigned_itoa(unsigned int  n)
{
	char			*str_num;
	size_t			digits;
	unsigned long	num;

	num = n;
	digits = get_digits(n);
	str_num = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str_num)
		return (NULL);
	*(str_num + digits) = 0;
	while (digits--)
	{
		*(str_num + digits) = num % 10 + '0';
		num = num / 10;
	}
	return (str_num);
}

static char change_alpha(unsigned int h)
{
	if (h == 10)
		return ('A');
	else if (h == 11)
		return ('B');
	else if (h == 12)
		return ('C');
	else if (h == 13)
		return ('D');
	else if (h == 14)
		return ('E');
	else if (h == 15)
		return ('F');
	else
		return (0);
}

static size_t  get_hexlen(unsigned int h)
{
	size_t hex_len;
	hex_len = 0;

	while (h)
	{
		h = h / 16;
		hex_len++;
	}
	return(hex_len);
}
char *hexnum(char *string,unsigned int base, size_t len)
{
	unsigned int mod;
	int i;
	i = 0;
	string[len]='\0';
	while (base)
	{
		mod = base % 16;
		if (mod >= 10)
			string[len-(1+i)]=change_alpha(mod);
		else if (mod < 10)
		 	string[len-(1+i)]=mod+'0';
		base = base/16;
		i ++;
	}
	return (string);
}

char	*change_hexnum(unsigned int h)
{
	size_t 	hex_len;
	char	*str;

	if (h == 0)
	{
		str = (char *) malloc(2 * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	hex_len = get_hexlen(h);
	str = malloc((hex_len + 1) * sizeof(char));
	if (str == NULL) 
		return (NULL);
	str = hexnum(str, h, hex_len);
	return (str);
}

//test unsigned itoa
// int main(void)
// {
// 	unsigned int i;
// 	unsigned long b;
// 	unsigned int c;
// 	i=4294967295;
// 	b=4294967296;
// 	c=0;
// 	printf("%s\n",unsigned_itoa(i));
// 	printf("%s\n",unsigned_itoa(b));
// 	printf("%s\n",unsigned_itoa(c));
// }


//test change_hexnum
int main(void)
{
	printf("%s\n",change_hexnum(0));
	printf("%s\n",change_hexnum(9));
	printf("%s\n",change_hexnum(15));
	printf("%s\n",change_hexnum(16));
	printf("%s\n",change_hexnum(88888));
	
	printf("%s\n",change_hexnum(4294967295));
	return(0);
}
