#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../ft_printf.h"
#define TEST(S, A, B, C, D) s = S;	printf("Test %s", s); if (printf(s, A, B, C, D) != ft_printf(s, A, B, C, D)) { printf(("Wrong return value !\n")); err++;}

int	ft_close(void)
{
	close(1);
	return (42);
}

int	main(void)
{
	char	*s;
	void	*p1;
	void	*p2;
	void	*p3;
	void	*p4;
	int		err;

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
	printf("\n\nReturn value errors : %d\n", err);

	free(p1);
	free(p2);
	free(p3);
	free(p4);
}
