/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:19:25 by anakin            #+#    #+#             */
/*   Updated: 2024/09/04 12:16:13 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_str(const char *str)
{
	size_t	i;

	if (!str)
		{
			write(1, "(null)", 6);
			return (6);
		}
	i = ft_strlen(str);
	write(1, str, i);
	return (i);
}