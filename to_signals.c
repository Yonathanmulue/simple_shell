#include "shell.h"


/**
* handle_segfault - This is to handle seg
* @signo: we use this as num
*/
void handle_segfault(int signo __attribute__((unused)))
{
	exit(1);
}

