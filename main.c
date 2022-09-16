/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:53:29 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/16 18:28:25 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
open, close, read, write, malloc, free, perror, strerror, access, dup, dup2,
execve, exit, fork, pipe, unlink, wait, waitpid

./pipex file1 cmd1 cmd2 file2
< file1 cmd1 | cmd2 > file2

./pipex infile "ls -l" "wc -l" outfile
< infile ls -l | wc -l > outfile

./pipex infile "grep a1" "wc -w" outfile
< infile grep a1 | wc -w > outfile

fd[1] is write end
fd[2] is read end
*/
int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	int		pid1;
	int		pid2;

	(void)env;
	if (argc < 5)
		return (write(2, "Too few arguments.\n", 19));
	if (pipe(fd) == -1)
		error_pipe();
	pid1 = fork();
	if (pid1 == -1)
		error_fork();
	if (pid1 == 0)
	{
		printf("child\n");
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(argv[1], (char *const *)argv[2], NULL);
	}

	pid2 = fork();
	if (pid2 == -1)
		error_fork();
	if (pid2 == 0)
	{
		printf("child2\n");
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(argv[4], (char *const *)argv[3], NULL);
	}
	close(fd[0]);
	close(fd[1]);
	printf("%s\n", argv[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
