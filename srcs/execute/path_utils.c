#include "exec_run.h"

char	*find_path(t_mini *mini)
{
	int	i;
	i = 0;
	if (!mini->env)
		return (NULL);
	while (mini->env[i])
	{
		if (ft_strncmp(mini->env[i], "PATH=", 5) == 0)
			return (mini->env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*get_cmd(t_mini *mini, t_cmd *cmd)
{
	int		i;
	char	*tmp;
	char	*full;
	i = 0;

	if (!mini || !mini->cmd_paths || !cmd || !cmd->cmd || !cmd->cmd[0])
		return (NULL);
	while (mini-> cmd_paths[i])
	{
		tmp = ft_strjoin(mini->cmd_paths[i], "/");
		if (!tmp)
			return (NULL);
		full = ft_strjoin(tmp, cmd->cmd[0]);
		free(tmp);
		if (!full)
			return (NULL);
		if (access(full, X_OK) == 0)
			return (full); // caller to free
		free(full);
		i++;
	}
	return (NULL);
}

void	get_cmd_paths(t_mini *mini)
{
	char	*env_path;

	if (mini->cmd_paths)
		return ;
	env_path = find_path(mini);
	if (!env_path)
		msg_error(mini, "PATH not found");
	mini->paths = ft_strdup(env_path);
	if (!mini->paths)
		msg_error(mini, "malloc error on PATH copy");
	mini->cmd_paths = ft_split(mini->paths, ':');
	if (!mini->cmd_paths)
		msg_error(mini, "malloc error on PATH split");
}
// !!!! cmd->cmd[0] 에 / 가 들어있을 경우 PATH 탐색 없이 그 경로로 바로 검사

char	*cmd_path_center(t_mini *mini, t_cmd *cmd)
{
	int	i;
	char *path;
	char	*whole;

	i = 0;
	if (!mini || !cmd || !cmd->cmd || !cmd->cmd[0] || !*cmd->cmd[0])
	{
		mini->exit_status = 0;
		return (NULL);
	}
	if (im_bi(mini))
		return (mini->exit_status = 0, NULL); // 빌트인 있고 파이프 없으면 패런트 실행 둘다 있으면 차일드 실행 처럼 엑섹으로 빼던가
	if (ft_strchr(cmd->cmd[0], '/'))
	{
		if (access(cmd->cmd[0], F_OK) != 0)
		{
			mini->exit_status = 127;
			return (NULL);
		}
		if (access(cmd->cmd[0], X_OK) != 0)
		{
			mini->exit_status = 126;
			return (NULL);
		}
		return (ft_strdup(cmd->cmd[0]));
	}
	get_cmd_paths(mini);
	if (!mini->cmd_paths)
		return (mini->exit_status = 127, NULL);
	i = 0;
	while (mini->cmd_paths[i])
	{
		path = ft_strjoin(mini->cmd_paths[i], "/");
		if (!path)
			return (NULL);
		whole = ft_strjoin(path, cmd->cmd[0]);
		free(path);
		if (!whole)
			return (NULL);
		if (access(whole, X_OK) == 0)
		{
			if (im_directory(mini, whole))
			{
				mini->exit_status = 126;
				free(whole);
				return (NULL);
			}
			if (permission_ok(mini, whole) == 0)
				return (whole);
			free(whole);
			return (mini->exit_status = 126, NULL);
		}
		free(whole);
		i++;
	}
	return (mini->exit_status = 127, NULL);
}
