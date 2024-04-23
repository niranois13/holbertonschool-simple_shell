#include <stdlib.h>

/**
 * update_exit_status - Function that changes the return status.
 * @status: the new status we want to return after exit
 * Return: void
 */
int update_exit_status(int flag_status)
{
    if (flag_status == EXIT_SUCCESS)
	{
    	flag_status = 2;
    }
	else
		flag_status = EXIT_SUCCESS;

	return (flag_status);
}
