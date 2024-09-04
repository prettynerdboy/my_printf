/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:31:49 by anakin            #+#    #+#             */
/*   Updated: 2024/09/04 11:43:49 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int check_id( const char *id,va_list ap)
{
	if (*id == 'c')
		return(print_char(va_arg(ap,int)));
	if (*id == 's')
		return(print_str(va_arg(ap,char *)));
	if (*id == 'd' || *id == 'i')
		return(print_num(va_arg(ap,int),*id));
	if (*id == 'u')
		return(print_num(va_arg(ap,unsigned int),*id));
	if (*id == 'x' ||*id == 'X' )
		return(print_hexnum(va_arg(ap,unsigned int),*id));
	if (*id =='p')
		return(print_ptr(va_arg(ap,void *)));
	if (*id =='%')
		return(print_char('%'));
	return(1);
}

int ft_printf(const char *format, ...)
{
	size_t len;
	size_t count;
	va_list ap;

	va_start(ap,format);
	len=0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len=len+check_id(format,ap);
			format++;
		}
		else 
		{
			count =print_format(format, '%');
			format=format+count;
			len=len + count;
		}
	}
	va_end(ap);
	return((int)len);
}

//メインの関数じゃなくて識別子を処理する関数毎で引数の出力を処理する
// 識別子毎の関数の戻り値は出力した文字数にする。
//%の後に％がくれば出力する。何もなければ出力しない。
//%の後に何もないときに本家のprintfはエラーで１を返してるがどう実装するか。→check_id関数の最後をreturn(１)にして解決。