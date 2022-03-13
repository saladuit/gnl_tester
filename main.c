/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   main.c                                          |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/13 18:27:37 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/03/13 21:35:29 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <assert.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "gnl_tester.h"

static void	test_error(void)
{
	assert(get_next_line(-42) == NULL && "test_error()");
}

static void	test_empty(char *file_name)
{
	int fd;
	char *result;

	fd = open(file_name, O_RDONLY);
	result = get_next_line(fd);
	assert(result == NULL && *file_name);
}

static void	test_files(char *file_name)
{
	char *result;
	char *expected;
	size_t linecapp;
	int fd;
	FILE *in_file;
	ssize_t k;

	if (!file_name)
	{
		printf("File does not exist!\n");
		return ;
	}
	in_file = fopen(file_name, "r");
	fd = open(file_name, O_RDONLY);
	while ((k = getline(&expected, &linecapp, in_file)) > 0)
	{
		result = get_next_line(fd);
		assert(strcmp(result, expected)  == 0 && *file_name);
	}
	close(fd);
	fclose(in_file);
}

int	main(void)
{
	int i;
	char *file_names[6] =
	{
		"empty.txt" ,
		"newline.txt" ,
		"4_char.txt" ,
		"7_char.txt" ,
		"1024_char.txt" ,
		"2048_char.txt"
	};
	test_error();
	i = 0;
	test_empty(file_names[i++]);
	while (i < 6)
	{
		test_files(file_names[i]);
		i++;
	}
	/*if (BONUS)*/
		/*test_bonus(file_names);*/
	return (0);
}
