#include "client.h"

/**
 * err_n_die - variadic function to handle errors in the cliente
 *
 * @format: mandatory input
 * Return: nothing
 *
 */
void err_n_die(const char *format, ...)
{
	int errno_save;
	va_list ap;

	errno_save = errno;

	va_start(ap, format);
	vfprintf(stdout, format, ap);
	fprintf(stdout, "\n");
	fflush(stdout);

	if (errno_save != 0)
	{
		fprintf(stdout, "(errno = %d) : %s\n", errno_save, stderror(errno_save));
		fprintf(stdout, "\n");
		fflush(stdout);
	}
	va_end(ap);

	exit(1);

}
