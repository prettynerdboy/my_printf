/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:53:46 by anakin            #+#    #+#             */
/*   Updated: 2024/09/03 17:32:06 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_ptr(void *ptr)
{
    size_t len;
	len=write(1, "0x", 2);
	if (!ptr)
		return (print_hexnum(0, 'x') + len);
	return (print_hexnum((unsigned long)ptr, 'x') + len);
}


// #include <stdio.h>

// int main (void)
// {
//     int i=1;
//     int *ptr;
//     printf("%p\n",ptr);
//     printf("%p\n",&i);
//     print_ptr(ptr);
//     print_ptr(&i);
// }