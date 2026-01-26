/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juljin <juljin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:05:05 by juljin            #+#    #+#             */
/*   Updated: 2026/01/24 16:07:51 by juljin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_H
# define SIG_H

# include "includes.h"

/* ------------------------------- STRUCTURE -------------------------------- */

typedef struct s_sig
{
	struct sigaction	sa_int;
	struct sigaction	sa_quit;
	sigset_t			set;
}						t_sig;

/* --------------------------------- UTILS ---------------------------------- */

void	sig_parent_setup(void);

#endif