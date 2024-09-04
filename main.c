#include <stdio.h>

int test(int ftp_value,int p_value)
{
	if(ftp_value == p_value)
	{
		printf("\x1b[32m");
		printf("OK\n");
		printf("\x1b[39m");
	}
	else
	{
		printf("\x1b[31m");
		printf("ko\n");
		printf("\x1b[39m");
	}
	printf("\n");
	return(0);
}

int main (void)
{
	//format,outputtest
	int i=printf("%d\n",ft_printf("thisissimpletest\n"));
	int b=printf("%d\n",printf("thisissimpletest\n"));
	test(i,b);
	
	//%ctest
	i = printf("%d\n",ft_printf("chartest=%c\n",'c'));
	b = printf("%d\n",printf("chartest=%c\n",'c'));
	test(i,b);
	
	//%stest
	i = printf("%d\n",ft_printf("stringtest=%s\n","perfect"));
	b = printf("%d\n",printf("stringtest=%s\n","perfect"));
	test(i,b);
	i = printf("%d\n",ft_printf("NULL=%s\n",(char *)NULL));
	b = printf("%d\n",printf("NULL=%s\n",(char *)NULL));
	test(i,b);
   
	//%dtest
	i = printf("%d\n",ft_printf("intmax=%d\n",2147483647));
	b = printf("%d\n",printf("intmax=%d\n",2147483647));
	test(i,b);
	i = printf("%d\n",ft_printf("intmin=%d\n",-2147483648));
	b = printf("%d\n",printf("intmin=%d\n",-2147483648));
	test(i,b);
	i = printf("%d\n",ft_printf("zero=%d\n",0));
	b = printf("%d\n",printf("zero=%d\n",0));
	test(i,b);
	i = printf("%d\n",ft_printf("intmax=%i\n",2147483647));
	b = printf("%d\n",printf("intmax=%i\n",2147483647));
	test(i,b);
	i = printf("%d\n",ft_printf("intmin=%i\n",-2147483648));
	b = printf("%d\n",printf("intmin=%i\n",-2147483648));
	test(i,b);
	i = printf("%d\n",ft_printf("zero=%i\n",0));
	b = printf("%d\n",printf("zero=%i\n",0));
	test(i,b);
	i = printf("%d\n",ft_printf("intmin=%d\n",-2147483648));
	b = printf("%d\n",printf("intmin=%d\n",-2147483648));
	test(i,b);
	
	//%utest
	i = printf("%d\n",ft_printf("unsigned_max=%u\n",4294967295));
	b = printf("%d\n",printf("unsigned_max=%u\n",4294967295));
	test(i,b);
	i = printf("%d\n",ft_printf("unsigned_min=%u\n",0));
	b = printf("%d\n",printf("unsigned_min=%u\n",0));
	test(i,b);

	//%x&Xtest
	i = printf("%d\n",ft_printf("unsigned_max hex is %x\n",4294967295));
	b = printf("%d\n",printf("unsigned_max hex is %x\n",4294967295));
	test(i,b);
	i = printf("%d\n",ft_printf("unsigned_min hex is %x\n",0));
	b = printf("%d\n",printf("unsigned_min hex is %x\n",0));
	test(i,b);
	i = printf("%d\n",ft_printf("unsigned_max Hex is %X\n",4294967295));
	b = printf("%d\n",printf("unsigned_max Hex is %X\n",4294967295));
	test(i,b);
	i = printf("%d\n",ft_printf("unsigned_min Hex is %X\n",0));
	b = printf("%d\n",printf("unsigned_min Hex is %X\n",0));
	test(i,b);
	
	//%ptest
	i = printf("%d\n",ft_printf("i's ptr=%p\n",&i));
	b = printf("%d\n",printf("i's ptr=%p\n",&i));
	test(i,b);
	i = printf("%d\n",ft_printf("b's ptr=%p\n",&b));
	b = printf("%d\n",printf("b's ptr=%p\n",&b));
	test(i,b);
	i = printf("%d\n",ft_printf("i's ptr=%p\n",NULL));
	b = printf("%d\n",printf("i's ptr=%p\n",NULL));
	test(i,b);
	
	//w%test
	i = printf("%d\n",ft_printf("%%\n"));
	b = printf("%d\n",printf("%%\n"));
	test(i,b);
	
	//only%test
	i = printf("%d\n",ft_printf("%\n"));
	b = printf("%d\n",printf("%\n"));
	test(i,b);
	
	return(0);
}