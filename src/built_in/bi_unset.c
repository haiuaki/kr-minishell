/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juljin <juljin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:27:18 by juljin            #+#    #+#             */
/*   Updated: 2026/01/27 17:58:31 by juljin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Implementation of the built-in command `unset` */
void	bi_unset(char *str, t_env **env_head)
{
	t_env	*tmp;
	t_env	*prev;
	size_t	len;

	if (!str)
		return ;
	tmp = *env_head;
	prev = NULL;
	len = ft_strlen(str);
	while (tmp)
	{
		if (len == ft_strlen(tmp->key) && ft_strncmp(tmp->key, str, len) == 0)
		{
			if (prev)
				prev->next = tmp->next;
			else
				*env_head = tmp->next;
			free_env_node(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
/*
int	main(int ac, char *av[], char *envp[])
{
	t_env	*env_copy;
	t_env	*new_node;

	(void)ac;
	(void)av;
	env_copy = copy_env(envp);
	if (!env_copy)
		return (1);
	new_node = malloc(sizeof(t_env));
	new_node->key = ft_strdup("HELLO");
	new_node->value = NULL;
	new_node->next = NULL;
	printf("\n/////////////////// [BEFORE DELETION] ///////////////////\n");
	env_add_back(&env_copy, new_node);
	bi_env(env_copy);
	bi_unset("HELLO", &env_copy);
	printf("\n/////////////////// [AFTER DELETION] ///////////////////\n");
	bi_env(env_copy);
	return (0);
}
*/