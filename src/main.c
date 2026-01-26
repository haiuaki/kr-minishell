/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juljin <juljin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:58:50 by juljin            #+#    #+#             */
/*   Updated: 2026/01/26 15:14:16 by juljin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char *av[])
{
	char	*input;

	(void)av;
	if (ac != 1)
		return (printf(USAGE), 1);
	sig_parent_setup();
	while (1)
	{
		input = readline(PROMPT);
		if (!input)
			break ;
		add_history(input);
	}
	return (0);
}
