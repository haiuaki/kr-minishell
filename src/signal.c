/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juljin <juljin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:28:29 by juljin            #+#    #+#             */
/*   Updated: 2026/01/26 14:32:30 by juljin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_signal;

static void	sigint_handler(int signal)
{
	g_signal = signal;
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	sig_parent_setup(void)
{
	t_sig	sigs;

	ft_bzero(&sigs, sizeof(t_sig));
	sigs.sa_int.sa_handler = &sigint_handler;
	sigaction(SIGINT, &sigs.sa_int, NULL);
	sigs.sa_quit.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sigs.sa_quit, NULL);
}
