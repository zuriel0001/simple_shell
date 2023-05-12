#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

extern char **environ;

/**
 * struct list_str - singly linked list
 * @num: number of field
 * @str: string
 * @next: point to the next node
 */
typedef struct list_str
{
	int num;
	char *str;
	struct list_str *next;
} list_t;

/**
 * struct pass_info - struct that contains pseudo arguments to
 * to pass into a function
 * @arg: arguments
 * @argv: array of strings
 * @path: string path for current command to follow
 * @line_count: error count
 * @err_num: error code for exit()s
 * @linecount_flag: count line of inputs
 * @fname: file name of program
 * @env: copy of linked list local environ
 * @environ: modified copy of environ
 * @history: history node
 * @alias: alias node
 * @env_changed: true if environ changes
 * @status: return status of the last executed command
 * @cmd_buf: address of pointer to cmd
 * @cmd_buf_type: cmd buff type
 * @readfd: fd to read line input
 * @histcount: history count
 */
typedef struct pass_info
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;


/* buit_in_env */
int built_in_env(info_t *info);
char *get_env_var(info_t *info, const char *name);
int pop_env_list(info_t *info);
int set_my_env_var(info_t *info);
int unset_my_env_var(info_t *info);

#endif
