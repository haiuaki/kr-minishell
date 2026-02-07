#include "exec_run.h"

void	free_path(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
void	cleanup_paths(t_mini *mini)
{
	if (mini->cmd_paths)
	{
		free_path(mini->cmd_paths);
		mini->cmd_paths = NULL;
	}
	if (mini->paths)
	{
		free(mini->paths);
		mini->paths = NULL;
	}
}

void	cleanup_all(t_mini *mini)
{
	int	i;

	i = 0;
	if (!mini)
		return ;
	while (i < mini->nbr_cmd)
	{
		free_path(mini->cmd_array[i].cmd);
		mini->cmd_array[i].cmd = NULL;
		if (mini->cmd_array[i].fd_in >= 0)
			ft_close(&mini->cmd_array[i].fd_in);
		if (mini->cmd_array[i].fd_out >= 0)
			ft_close(&mini->cmd_array[i].fd_out);
		pipex_free(mini, i);
		i++;
	}
	cleanup_paths(mini);
}