/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newchild.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 08:46:04 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/27 12:09:50 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_io_firstchild(t_envl *e)
{
	if (pipe(e->curr_pipe) == -1)
		error_msg_exit(e, "pipe");
	e->child_in = e->infile;
	e->child_out = e->curr_pipe[1];
}

void	set_io_middlechild(t_envl *e)
{
	if (pipe(e->curr_pipe) == -1)
		error_msg_exit(e, "pipe");
	e->child_in = e->prev_pipe[0];
	e->child_out = e->curr_pipe[1];
}

void	set_io_lastchild(t_envl *e)
{
	e->child_in = e->prev_pipe[0];
	e->child_out = e->outfile;
}

