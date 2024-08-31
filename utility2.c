/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soaoki <soaoki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:11:32 by soaoki            #+#    #+#             */
/*   Updated: 2024/08/31 12:32:35 by soaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// static int	ft_toupper(int c)
// {
// 	if (c >= 97 && c <= 122)
// 	{
// 		return (c - 32);
// 	}
// 	else
// 		return (c);
// }

char *str_toupper(char *str)
{
    int i;

    i = 0;
    while(str[i] !='\0')
    {
        if(str[i]>='a' && str[i] <= 'z')
            str[i]=str[i]-32;
        i++;
    }
    return(str);
}
// #include <stdio.h>
// int main(void)
// {
//     char test[10]="a11b4cc";
//     printf("%s",str_toupper(test));
// }