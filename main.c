#include "ft_printf.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define PURPLE "\x1b[35m"
#define WHITE "\x1B[37m"

int	main(void)
{
	char			c;
	char 			*str1; 
	int				n;
	int				a;
	int				b;
	int				d;
	int				lol;
	int				*ptr;
	unsigned int	num;

	//Printing the char
	c = 'x';
	printf(PURPLE "------------ Printing a character -----------\n");
	printf(RED "Original Printf: %c\n", c);
	ft_printf(YELLOW "My printf: %c\n", c);
	//Printing the string
	str1 = "We are printing the string";
	printf(PURPLE "------------ Printing a string -----------\n");
	printf(RED "Original Printf: %s\n", str1);
	ft_printf(YELLOW "My printf: %s\n", str1);
	//Printing the numbers
	n = 1234567;
	printf(PURPLE "----------- Printing a number -------------\n");
	printf(RED "Original Printf: %d\n", n);
	ft_printf(YELLOW "My printf: %d\n", n);
	// Printing the percentage
	printf(PURPLE "---------- Printing a percentage ----------\n");
	printf(RED "Original Printf: %%\n");
	ft_printf(YELLOW "My printf: %%\n");
	//Printing the hexadecimal --- Test 1 -- More than 16
	a = 36453;
	b = 0;
	d = 6;
	printf(PURPLE "---------- Printing a hexadecimal ----------\n");
	printf(RED "Original Printf - Small x: %x\n", a);
	printf(RED "Original Printf - Big X: %X\n", a);
	ft_printf(YELLOW "My printf: Small x: %x\n", a);
	ft_printf(YELLOW "My printf: Big X: %X\n", a);
	// ----- Test 2 for 0
	printf(WHITE "- Test 2 - 0 -\n");
	printf(RED "Original Printf - Small x: %x\n", b);
	printf(RED "Original Printf - Big X: %X\n", b);
	ft_printf(YELLOW "My printf: Small x: %x\n", b);
	ft_printf(YELLOW "My printf: Big X: %X\n", b);
	// ----- Test 3 for less 9
	printf(WHITE "- Test 3 - less than 9 -\n");
	printf(RED "Original Printf - Small x: %x\n", d);
	printf(RED "Original Printf - Big X: %X\n", d);
	ft_printf(YELLOW "My printf: Small x: %x\n", d);
	ft_printf(YELLOW "My printf: Big X: %X\n", d);
	//Printing a pointer expression
	lol = 12345;
	ptr = &lol;
	// char st
	printf(PURPLE "---------- Printing a pointer ----------\n");
	printf(RED "Original Printf: %p\n", ptr);
	ft_printf(YELLOW "My printf: %p\n", ptr);
	//Printing a %u
	num = 3000000000;
	printf(PURPLE "---------- Printing a unsigned long ----------\n");
	printf(RED "Original Printf: %u\n", num);
	ft_printf(YELLOW "My printf: %u\n", num);
	return (0);
}