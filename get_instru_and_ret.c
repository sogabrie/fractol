#include "fractol.h"

int	get_instru_and_ret()
{
	write(1, "\nPlease use this commands\n", 26);
	write(1, "--- Mandelbrod ---\n", 20);
	write(1, "---   Julian   ---\n", 20);
	write(1, "For Julian you can add parameters separated by space !ONLY SPACE!\n", 66);
	write(1, "For Example: 0.0 0.0 and -0.36 -0.66\n", 38);
	write(1, "!Please enter parameters correct in float type!\n", 49);
	write(1, "-> THANK YOU <-\n\n", 18);
	return (0);
}