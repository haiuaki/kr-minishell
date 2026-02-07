#include "exec_run.h"

void	ft_execute(t_mini *mini, t_cmd *cmd)
{
	char	*pathcheck;

	if (!cmd || !cmd->cmd || !cmd->cmd[0])
		exit(0);
	pathcheck = cmd_path_center(mini, cmd);
	if (!pathcheck)
	{
		exec_exit(mini->exit_status ? mini->exit_status : 127);
	}
	// if (mini->cmd_paths)
	// {
	//  	mini->exit_status = 127;
	//  	return ;
	// }
	// if (im_directory(mini, pathcheck))
	// {
	// 	exec_exit(mini->exit_status ? mini->exit_status : 126);
	// }
	execve(pathcheck, cmd->cmd, mini->env); // 주소를 찾아가서(=참조해서 // 인자가 미니의 주소) 컨텐츠를 .으로 열어보는 행위 자체가 화살표다
	free(pathcheck);
	perror(cmd->cmd[0]);
	if (errno == ENOENT)
		exit(127);
	exit(126);
}