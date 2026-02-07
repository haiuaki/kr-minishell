// file_utils.c
#include "exec_run.h"

int	im_directory(t_mini *mini, char *pathcheck)
{
	struct stat buf;

	if (stat(pathcheck, &buf) == -1)
		return (0);
	return (S_ISDIR(buf.st_mode));
}

int	permission_ok(t_mini *mini, char *pathcheck)
{
	struct stat buf;

	if (stat(pathcheck, &buf) == -1)
	{	
		return (0);
	}
	return (S_IRWXU & buf.st_mode);
}
int	does_exist(t_mini *mini, char *pathcheck)
{
	struct stat buf;

	if (stat(pathcheck, &buf) == 0)
		return (1);
	return (0);
}

void	ft_close(t_mini mini, int *fd)
{
	if (fd && *fd >= 0)
	{
		close(*fd);
		*fd = -1;
		msg_error(mini, "close");
	}
}