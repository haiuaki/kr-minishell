void create_child(t_pipex *px, char **argv, char **envp, t_pipex id)
{
	px->pid[id] = fork();
	if (px->pid[id] < 0)
		msg_error(px, "fork error");
	if (px->pid[i] == 0)
		run_child(*px, argv, envp);
}

void	set_child(t_pipex parent, char **av, char **envp, t_pipex id)
// 이걸 t_cmd cmd, mini 로 바꿔야
{
	
	copy_pipex(&px, &parent);
	px.cmd[뭐꼬] = NULL;
	px.cmd_args[뭐꼬] = NULL; // 파싱에서 이미 받아오나?
	if (px[id].infile < 0)
	{
		close(px.tube[0]);
		close(px.tube[1]);
		pipex_free(&px);
		pipex_free(&parent);
		exit(1);
	}
	setup_fds(&px, 1);
	close_fds(cmd, mini);
	run_child(&parent, &px, av[2], envp)
}

setup_fds(&px, 1)
{
	if (pipeline 에서 i > 0)
		ft_dup2(pipefd[i - 1][0], STDIN_FILENO);
	if (cmd[i].fd_in != -1)
		ft_dup2(cmd[i].fd_in, STDIN_FILENO);
	// 2) 출력 연결
	if (i < nmbr_cmd - 1)
		dup2(pipefd[i][1], STDOUT_FILEND);
	if (cmd[i].fd_out != -1)
		dup2(cmd[i].fd_out, 1);
	if (pipeline 에서 i < n_cmd - 1)
		ft_dup2(pipefd[i][1], STDOUT_FILENO)
}

close_fds(t_cmd cmd, mini)
{
	// 3) 클로즈
	모든 pipefd[*][0/1] close
	redir 용 오픈한 fd 도 dup2 했으면 클로즈
	히어독 fd 도 dup2 후 클로즈
}

void	run_child(t_pipex *parent, t_pipex *px, t_mini *mini)
{
	px->cmd_args = ft_split(arg, ' ');
	if (!px->cmd_args || !px->cmd_args[0])
		child_error(parent, px);
	if (ft_strchr(px->cmd_args[0], '/'))
	{
		px->cmd = ft_strdup(px->cmd_args[0]);
		if (!px->cmd || access(px->cmd, X_OK) == -1)
			child_error(parent, px);
	}
	else
	{
		px->cmd = get_cmd(px->cmd_paths, px->cmd_args[0]);
		if (!px->cmd)
			child_error(parent, px);
	}
	do_bi(if_bi(cmd, mini))
	else PATH 탐색 실행파일 경로 결정
	if (cmd[i].cmd[0] "/" 큰 따옴표인지 뭔지는 기재 방식 확인하기)
		excve(path, argv, ini->env)
	if (cmd[i].cmd[0] !!! "/")
		ft_split (PATH) 후보 경로들 만들고
		exceve
	exceve(path, mini->argv, mini->env);
	pipex_free(px);
	pipex_free(parent);
	perror("execve");
	exit(127);
}

int parent_process (t_cmd cmd, mini)
{
	int	i = 0;
	int	j = 0;
	while (cmd[i])
	{
		ft_시그널 // 프롬프트 대기 중
		while (cmd[j].cmd .. 끝까지 읽다가 // {"echo", "hello", NULL} 이거 내부를 읽다가)
		{
			if (heredoc 찾으면)
				ft_dup2(fd(heredoc 만들어 둔 거), STDIN_FILENO);
			j++;
		}
		j = 0;
		if (nbr_cmd > 1)
		{
			i = 0;
			ft_bzero(&px, sizeof(t_pipex));
			while (i < nbr_cmd - 1)
			{
				create_child(px, argv, envp, i)
				// 이 함수는 pipe nbr_cmd - 1 개 생성
				// pipefd[k][2] 생성 동적 할당
				if (pid = child process)
					set_child(cmd, mini);
			}
		}
		while (each pipe for created child process i < nbr_cmd - 1)
			close (pipefd 모두)
		waitpid(px.pid1..., NULL, 0);
		while (each pipe for created child process)
			close_pipe(&px);
		while (each child process)
			모든 pid waitpid(pid, &status, 0)
		mini->exit_status = wait_child(마지막 애의 &px)
		open_files(&px, argv, argc);
		do_bi(is_bi(cmd, mini));
		if (pipe(px.tube) < 0)
			msg_error(&px, ERR_PIPE);
		get_cmd_paths(&px, envp);
		// $? 가 해당 가ㅄ으로 확장
		i++;
	}
}