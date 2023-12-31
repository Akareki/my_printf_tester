#include <stdio.h>
#include <stdlib.h>
#include "../ft_printf.h"
#define TEST(S, A, B, C, D) s = S;	printf("Test %s", s); if (printf(s, A, B, C, D) != ft_printf(s, A, B, C, D)) { printf(("-----------------------Wrong return value !---------------------------\n")); err++;}

int	main(void)
{
	char	*s;
	void	*p1;
	void	*p2;
	void	*p3;
	void	*p4;
	int		err;
	int		A = 0;
	int		B = 0;
	int		C = 0;
	int		D = 0;

	err = 0;
	printf("\n=====NO CONVERSION TEST=====\n\n");
	s = "";
	printf("Test empty string\n", s);
	if (printf(s) != ft_printf(s))
		printf(("Wrong return value !\n"));
	s = NULL;
	printf("Test NULL string\n", s);
	if (printf(s) != ft_printf(s))
		printf(("Wrong return value !\n"));
	s = "Coucou\n";
	printf("Test %s", s);
	if (printf(s) != ft_printf(s))
		printf(("Wrong return value !\n"));
	s = "qwertyuiopasdfghjklzxcvbnm,./;''<>?:1234567890	\n";
	printf("Test %s", s);
	if (printf(s) != ft_printf(s))
		printf(("Wrong return value !\n"));
	printf("\n=====CONVERSION : %%c=====\n\n");
	TEST("%c\n", 'a', 0, 0, 0);
	TEST("%c\n", ' ', 0, 0, 0);
	TEST("%c%c\n", '1', '2', 0, 0);
	TEST("One char : %c\n", 'c', 0, 0, 0);
	TEST("Char >>> %c <<<Char\n", 'c', 0, 0, 0);
	TEST("One %c and another %c\n", 'a', '5', 0, 0);
	printf("\n=====CONVERSION : %%s=====\n\n");
	TEST("%s\n", "blabla", 0, 0, 0);
	TEST("Empty string : %s\n", "", 0, 0, 0);
	TEST("NULL string : %s\n", NULL, 0, 0, 0);
	TEST("NULL stringS : %s %s %s\n", NULL, NULL, NULL, 0)
	TEST("%s %s\n", "un", "deux", 0, 0);
	TEST("One : %s and two %s\n", "ichi", "ni", 0, 0);
	printf("\n=====CONVERSION : %%d=====\n\n");
	TEST("%d\n", 123, 0, 0, 0);
	TEST("%d %d\n", 123, 456, 0, 0);
	TEST("%d + %d = %d\n", 5468, 231354, 876843185, 0);
	TEST("Int max : %d \n", 2147483647, 0, 0, 0);
	TEST("Int min : %d\n", -2147483648, 0, 0, 0);
	printf("\n=====CONVERSION : %%i=====\n\n");
	TEST("%i\n", 123, 0, 0, 0);
	TEST("%i %i\n", 123, 456, 0, 0);
	TEST("%i + %i = %i\n", 5468, 231354, 876843185, 0);
	TEST("Int max : %i \n", 2147483647, 0, 0, 0);
	TEST("Int min : %i\n", -2147483648, 0, 0, 0);
	printf("\n=====CONVERSION : %%u=====\n\n");
	TEST("%u\n", 123, 0, 0, 0);
	TEST("%u %u\n", 123, 456, 0, 0);
	TEST("%u + %u = %u\n", 5468, 231354, 876843185, 0);
	TEST("Int max : %u \n", 4294967295, 0, 0, 0);
	TEST("Int min : %u\n", 0, 0, 0, 0);
	printf("\n=====CONVERSION : %%x=====\n\n");
	TEST("%x\n", 123, 0, 0, 0);
	TEST("%x %x\n", 123, 456, 0, 0);
	TEST("%x + %x = %x\n", 5468, 231354, 876843185, 0);
	TEST("Int max : %x \n", 4294967295, 0, 0, 0);
	TEST("Int min : %x\n", 0, 0, 0, 0);
	printf("\n=====CONVERSION : %%X=====\n\n");
	TEST("%X\n", 123, 0, 0, 0);
	TEST("%X %X\n", 123, 456, 0, 0);
	TEST("%X + %X = %X\n", 5468, 231354, 876843185, 0);
	TEST("Int max : %X \n", 4294967295, 0, 0, 0);
	TEST("Int min : %X\n", 0, 0, 0, 0);
	printf("\n=====CONVERSION : %%%%=====\n\n");
	TEST("%%\n", 0, 0, 0, 0);
	TEST("%%%%%%%%%%%%%%%%\n", 0, 0, 0, 0);
	TEST("Gimme some %% : %%%%%%%%%%%%%%%%%%%%\n", 0, 0, 0, 0);
	printf("\n=====CONVERSION : %%p=====\n\n");
	TEST("NULL ptr : %p\n", NULL, 0, 0, 0);
	p1 = malloc(16);
	TEST("Malloced ptr : %p\n", p1, 0, 0, 0);
	p2 = malloc(16);
	p3 = malloc(16);
	p4 = malloc(16);
	TEST("Several ptrs : %p %p %p %p\n", p1, p2, p3, p4);
	printf("\n=====MIXED CONVERSIONS=====\n\n");
	TEST("%s %c %d %u\n", "Hello", 'U', -256, 1024);
	TEST("%x %X %p\n", 4096, 8192, p1, 0);
	TEST("%d%% of %s are %c\n", 42, "mallocs", '0', 0);
	TEST("Oops all NULL : %s %p %s %p\n", NULL, NULL, NULL, NULL)
	printf("\n\n ++++++++++ FINISHED MANDATORY PART ++++++++++\n");
	printf("Return value errors : %d\n\n\n", err);
	printf("++++++++++ BONUS PART ++++++++++\n\n");
	printf("\n=====CONVERSION : %%c=====\n\n");
	TEST("%10c\n", 'A', 0, 0, 0);
	TEST("%-10c\n", 'A', 0, 0, 0);
	TEST("%0c\n", 'A', 0, 0, 0);
	TEST("%-0c\n", 'A', 0, 0, 0);
	printf("\n=====CONVERSION : %%s=====\n\n");
	TEST("%.s\n", "bla", B, C, D);
	TEST("%.5s\n", "1234567890", B, C, D);
	TEST("%10.5s\n", "1234567890", B, C, D);
	TEST("%-.s\n", "bla", B, C, D);
	TEST("%-.5s\n", "1234567890", B, C, D);
	TEST("%-10.5s\n", "1234567890", B, C, D);
	TEST("%-7.2s%5.1s\n", "1234567890", "abcdef", C, D);
	TEST("%-7.2s%5.1s%-3.2\n", "1234567890", "abcdef", ",./<>?", D);
	TEST("%.6s|\n", NULL, B, C, D);
	TEST("%.3s|\n", NULL, B, C, D);
	TEST("%10.6s|\n", NULL, B, C, D);
	TEST("%10.3s|\n", NULL, B, C, D);
	printf("\n=====CONVERSION : %%d=====\n\n");
	TEST("%+d\n", 12345, B, C, D);
	TEST("% d\n", 12345, B, C, D);
	TEST("%-10d\n", 12345, B, C, D);
	TEST("%10d\n", 12345, B, C, D);
	TEST("%1d\n", 12345, B, C, D);
	TEST("%10.7d\n", 12345, B, C, D);
	TEST("%7.10d\n", 12345, B, C, D);
	TEST("%10d\n", -12345, B, C, D);
	TEST("%1d\n", -12345, B, C, D);
	TEST("%10.7d\n", -12345, B, C, D);
	TEST("%7.10d\n", -12345, B, C, D);
	TEST("%7.40d\n", -2147483648, B, C, D);
	TEST("%+10d\n", 12345, B, C, D);
	TEST("%+1d\n", 12345, B, C, D);
	TEST("%+10.7d\n", 12345, B, C, D);
	TEST("%+7.10d\n", 12345, B, C, D);
	TEST("%+10d\n", -12345, B, C, D);
	TEST("%+1d\n", -12345, B, C, D);
	TEST("%+10.7d\n", -12345, B, C, D);
	TEST("%+7.10d\n", -12345, B, C, D);
	TEST("%+7.40d\n", -2147483648, B, C, D);
	TEST("%-10d\n", 12345, B, C, D);
	TEST("%-1d\n", 12345, B, C, D);
	TEST("%-10.7d\n", 12345, B, C, D);
	TEST("%-7.10d\n", 12345, B, C, D);
	TEST("%-10d\n", -12345, B, C, D);
	TEST("%-1d\n", -12345, B, C, D);
	TEST("%-10.7d\n", -12345, B, C, D);
	TEST("%-7.10d\n", -12345, B, C, D);
	TEST("%-7.40d\n", -2147483648, B, C, D);
	TEST("% 10d\n", 12345, B, C, D);
	TEST("% 1d\n", 12345, B, C, D);
	TEST("% 10.7d\n", 12345, B, C, D);
	TEST("% 7.10d\n", 12345, B, C, D);
	TEST("% 10d\n", -12345, B, C, D);
	TEST("% 1d\n", -12345, B, C, D);
	TEST("% 10.7d\n", -12345, B, C, D);
	TEST("% 7.10d\n", -12345, B, C, D);
	TEST("% 7.40d\n", -2147483648, B, C, D);
	TEST("%.0d\n", 0, B, C, D);
	TEST("%10.0d|\n", 0, B, C, D);
	TEST("%-+010.15d|\n", 456, B, C, D);
	printf("\n=====CONVERSION : %%i=====\n\n");
	TEST("%10i\n", 12345, B, C, D);
	TEST("%1i\n", 12345, B, C, D);
	TEST("%10.7i\n", 12345, B, C, D);
	TEST("%7.10i\n", 12345, B, C, D);
	TEST("%10i\n", -12345, B, C, D);
	TEST("%1i\n", -12345, B, C, D);
	TEST("%10.7i\n", -12345, B, C, D);
	TEST("%7.10i\n", -12345, B, C, D);
	TEST("%7.40i\n", -2147483648, B, C, D);
	TEST("%+10i\n", 12345, B, C, D);
	TEST("%+1i\n", 12345, B, C, D);
	TEST("%+10.7i\n", 12345, B, C, D);
	TEST("%+7.10i\n", 12345, B, C, D);
	TEST("%+10i\n", -12345, B, C, D);
	TEST("%+1i\n", -12345, B, C, D);
	TEST("%+10.7i\n", -12345, B, C, D);
	TEST("%+7.10i\n", -12345, B, C, D);
	TEST("%+7.40i\n", -2147483648, B, C, D);
	TEST("%-10i\n", 12345, B, C, D);
	TEST("%-1i\n", 12345, B, C, D);
	TEST("%-10.7i\n", 12345, B, C, D);
	TEST("%-7.10i\n", 12345, B, C, D);
	TEST("%-10i\n", -12345, B, C, D);
	TEST("%-1i\n", -12345, B, C, D);
	TEST("%-10.7i\n", -12345, B, C, D);
	TEST("%-7.10i\n", -12345, B, C, D);
	TEST("%-7.40i\n", -2147483648, B, C, D);
	TEST("% 10i\n", 12345, B, C, D);
	TEST("% 1i\n", 12345, B, C, D);
	TEST("% 10.7i\n", 12345, B, C, D);
	TEST("% 7.10i\n", 12345, B, C, D);
	TEST("% 10i\n", -12345, B, C, D);
	TEST("% 1i\n", -12345, B, C, D);
	TEST("% 10.7i\n", -12345, B, C, D);
	TEST("% 7.10i\n", -12345, B, C, D);
	TEST("% 7.40i\n", -2147483648, B, C, D);
	TEST("%.0i\n", 0, B, C, D);
	TEST("%10.0i|\n", 0, B, C, D);
	TEST("%-+010.15i|\n", 456, B, C, D);
	printf("\n=====CONVERSION : %%u=====\n\n");
	TEST("%+u\n", 12345, B, C, D);
	TEST("% u\n", 12345, B, C, D);
	TEST("%-10u\n", 12345, B, C, D);
	TEST("%10u\n", 12345, B, C, D);
	TEST("%1u\n", 12345, B, C, D);
	TEST("%10.7u\n", 12345, B, C, D);
	TEST("%7.10u\n", 12345, B, C, D);
	TEST("%+10u\n", 12345, B, C, D);
	TEST("%+1u\n", 12345, B, C, D);
	TEST("%+10.7u\n", 12345, B, C, D);
	TEST("%+7.10u\n", 12345, B, C, D);
	TEST("%-10u\n", 12345, B, C, D);
	TEST("%-1u\n", 12345, B, C, D);
	TEST("%-10.7u\n", 12345, B, C, D);
	TEST("%-7.10u\n", 12345, B, C, D);
	TEST("% 10u\n", 12345, B, C, D);
	TEST("% 1u\n", 12345, B, C, D);
	TEST("% 10.7u\n", 12345, B, C, D);
	TEST("% 7.10u\n", 12345, B, C, D);
	TEST("% 7.40u\n", 2147484000, B, C, D);
	printf("\n=====CONVERSION : %%x=====\n\n");
	TEST("%+x\n", 12345, B, C, D);
	TEST("% x\n", 12345, B, C, D);
	TEST("%-10x\n", 12345, B, C, D);
	TEST("%10x\n", 12345, B, C, D);
	TEST("%1x\n", 12345, B, C, D);
	TEST("%10.7x\n", 12345, B, C, D);
	TEST("%7.10x\n", 12345, B, C, D);
	TEST("%+10x\n", 12345, B, C, D);
	TEST("%+1x\n", 12345, B, C, D);
	TEST("%+10.7x\n", 12345, B, C, D);
	TEST("%+7.10x\n", 12345, B, C, D);
	TEST("%-10x\n", 12345, B, C, D);
	TEST("%-1x\n", 12345, B, C, D);
	TEST("%-10.7x\n", 12345, B, C, D);
	TEST("%-7.10x\n", 12345, B, C, D);
	TEST("% 10x\n", 12345, B, C, D);
	TEST("% 1x\n", 12345, B, C, D);
	TEST("% 10.7x\n", 12345, B, C, D);
	TEST("% 7.10x\n", 12345, B, C, D);
	TEST("% 7.40x\n", 2147484000, B, C, D);
	TEST("%#+x\n", 12345, B, C, D);
	TEST("%# x\n", 12345, B, C, D);
	TEST("%#-10x\n", 12345, B, C, D);
	TEST("%#10x\n", 12345, B, C, D);
	TEST("%#1x\n", 12345, B, C, D);
	TEST("%#10.7x\n", 12345, B, C, D);
	TEST("%#7.10x\n", 12345, B, C, D);
	TEST("%#+10x\n", 12345, B, C, D);
	TEST("%#+1x\n", 12345, B, C, D);
	TEST("%#+10.7x\n", 12345, B, C, D);
	TEST("%#+7.10x\n", 12345, B, C, D);
	TEST("%#-10x\n", 12345, B, C, D);
	TEST("%#-1x\n", 12345, B, C, D);
	TEST("%#-10.7x\n", 12345, B, C, D);
	TEST("%#-7.10x\n", 12345, B, C, D);
	TEST("%# 10x\n", 12345, B, C, D);
	TEST("%# 1x\n", 12345, B, C, D);
	TEST("%# 10.7x\n", 12345, B, C, D);
	TEST("%# 7.10x\n", 12345, B, C, D);
	TEST("%# 7.40x\n", 2147484000, B, C, D);
	printf("\n=====CONVERSION : %%X=====\n\n");
	TEST("%+X\n", 12345, B, C, D);
	TEST("% X\n", 12345, B, C, D);
	TEST("%-10X\n", 12345, B, C, D);
	TEST("%10X\n", 12345, B, C, D);
	TEST("%1X\n", 12345, B, C, D);
	TEST("%10.7X\n", 12345, B, C, D);
	TEST("%7.10X\n", 12345, B, C, D);
	TEST("%+10X\n", 12345, B, C, D);
	TEST("%+1X\n", 12345, B, C, D);
	TEST("%+10.7X\n", 12345, B, C, D);
	TEST("%+7.10X\n", 12345, B, C, D);
	TEST("%-10X\n", 12345, B, C, D);
	TEST("%-1X\n", 12345, B, C, D);
	TEST("%-10.7X\n", 12345, B, C, D);
	TEST("%-7.10X\n", 12345, B, C, D);
	TEST("% 10X\n", 12345, B, C, D);
	TEST("% 1X\n", 12345, B, C, D);
	TEST("% 10.7X\n", 12345, B, C, D);
	TEST("% 7.10X\n", 12345, B, C, D);
	TEST("% 7.40X\n", 2147484000, B, C, D);
	TEST("%#+X\n", 12345, B, C, D);
	TEST("%# X\n", 12345, B, C, D);
	TEST("%#-10X\n", 12345, B, C, D);
	TEST("%#10X\n", 12345, B, C, D);
	TEST("%#1X\n", 12345, B, C, D);
	TEST("%#10.7X\n", 12345, B, C, D);
	TEST("%#7.10X\n", 12345, B, C, D);
	TEST("%#+10X\n", 12345, B, C, D);
	TEST("%#+1X\n", 12345, B, C, D);
	TEST("%#+10.7X\n", 12345, B, C, D);
	TEST("%#+7.10X\n", 12345, B, C, D);
	TEST("%#-10X\n", 12345, B, C, D);
	TEST("%#-1X\n", 12345, B, C, D);
	TEST("%#-10.7X\n", 12345, B, C, D);
	TEST("%#-7.10X\n", 12345, B, C, D);
	TEST("%# 10X\n", 12345, B, C, D);
	TEST("%# 1X\n", 12345, B, C, D);
	TEST("%# 10.7X\n", 12345, B, C, D);
	TEST("%# 7.10X\n", 12345, B, C, D);
	TEST("%# 7.40X\n", 2147484000, B, C, D);
	printf("\n=====CONVERSION : %%p=====\n\n");
	TEST("%30p\n", p1, B, C, D);
	TEST("%30.16p\n", p1, B, C, D);
	TEST("%-30p\n", p1, B, C, D);
	TEST("%-30.16p\n", p1, B, C, D);
	TEST("%.6p\n", NULL, B, C, D);
	TEST("%.3p\n", NULL, B, C, D);
	TEST("%10.6p\n", NULL, B, C, D);
	TEST("%10.3p\n", NULL, B, C, D);
	printf("\n=====CONVERSION : %%%%=====\n\n");
	TEST("%30%\n", p1, B, C, D);
	TEST("%-30%\n", p1, B, C, D);
	TEST("%-30.16%\n", p1, B, C, D);
	printf("\n\n\n++++++++++FINISHED BONUS PART++++++++++\n");
	printf("Return value errors : %d\n\n\n", err);



	free(p1);
	free(p2);
	free(p3);
	free(p4);
}
