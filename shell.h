#ifndef _SHELL_H
#define _SHELL_H

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

#define HISTORY_FILE  ".simple_shell_history"
#define HISTORY_MAX   4096

#define UNUSED(x) (void)(x)

#define BUFFER_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define FLUSH_BUFFER -1
#define READ_BUF_SIZE 1024

/***** command chaining *****/
#define CMD_NORMAL 0
#define OR_CMD		1
#define AND_CMD		2
#define CHAIN_CMD	3


/** number convert */
#define CONVERT_TO_LOWERCASE	1
#define CONVERT_TO_UNSIGNED	2

/* 1 for system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0


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
 * @argc: argument count
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
 *
 */
typedef struct pass_info
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int error_numb;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *my_alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int read_file;
	int history_count;
} shell_info;


#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct my_builtin - struct containing a builtin string
 * and related function
 * @type: builtin command flag
 * @func: the function
 */

typedef struct my_builtin
{
	char *type;
	int (*func)(shell_info *);
} my_builtin_table;


/* buit_in_env */
int built_in_env(shell_info *info);
char *get_env_var(shell_info *info, const char *name);
int pop_env_list(shell_info *info);
int set_my_env_var(shell_info *info);
int unset_my_env_var(shell_info *info);
int set_environ(shell_info *info, char *var, char *value);


/* string */
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *start_hays_need(const char *haystack, const char *needle);
int _putchar(char c);
char *_strdup(const char *str);
void _puts(char *str);
char *_strcpy(char *dest, char *src);

/** exit built-in, that exits the shell **/
int exit_shell(shell_info *info);

/** builtin command cd  **/
int _cd(shell_info *info);

/** help menu **/
int helper(shell_info *info);

/* commen remover */
void erase_comments(char *buf);

/** error printers **/
void puts_error(char *str);
int putchar_error(char c);
int atoi_overflow(char *s);
void print_error(shell_info*, char *);

/** write to files */
int put_cfd(char c, int fd);
int put_sfd(char *str, int fd);
int print_dec(int num, int fd);

/* utilities **/
int _atoi(char *s);
int _isalpha(int c);
int is_delim(char c, char *d_str);
char *convert_num(long int num, int base, int flags);

/* interactive mode */
int interactive_mode(shell_info *info);



/* get line */
ssize_t read_buffer(shell_info *info, char *buf, size_t *i);
int get_line(shell_info *info, char **ptr, size_t *len);
ssize_t get_input(shell_info *info);
ssize_t input_buffer(shell_info *info, char **buf, size_t *len);
void sig_int_handler(__attribute__((unused))int sig);

/*** get shell info ***/
void clear_shell_info(shell_info *info);
void free_shell_info(shell_info *info, int abc);
void set_shell_info(shell_info *info, char **av);

/** chain **/
int is_chain(shell_info *info, char *buf, size_t *ptr);
void chain_chk(shell_info *info, char *buf, size_t *ptr, size_t j, size_t len);

/** substitute alias vars string **/
int substitute_vars(shell_info *info);
int substitute_string(char **old, char *new);
int substitute_alias(shell_info *info);


/** path utils  **/
int is_regular_file(shell_info *info, char *path);
char *get_sgmnt_without_colon(const char *inputString, int start, int end);
char *path_finder(shell_info *info, char *inputString, char *cmd);

/*** get environ ***/
char **fetch_environ(shell_info *info);
int set_environ(shell_info *info, char *var, char *val);
int unset_environ(shell_info *info, char *var);

/** lists **/
list_t *add_node(list_t **head, const char *str, int num);
list_t *add_node_end(list_t **head, const char *str, int num);
int remove_node_at_idx(list_t **head, unsigned int index);
ssize_t fetch_node_idx(list_t *head, list_t *node);
list_t *start_node_with(list_t *node, char *prefix, char c);


/*** exit_str ***/
char *_strncpy(char *dest, char *src, int n);
char *_strchr(char *s, char ch);
char *_strncat(char *dest, char *src, int n);

/** list_list **/
size_t list_length(const list_t *head);
char **list_str(list_t *h);
size_t print_list(const list_t *h);
size_t print_list_string(const list_t *head);
void free_list(list_t **h_ptr);

/** memory utils **/
void *resize_mem(void *p_mem, unsigned int old_size, unsigned int new_size);
char *my_memset(char *mem, char b, unsigned int n_byte);
void free_string_array(char **ptr);
int buf_free(void **ptr);

/** alias history biultin **/
int show_history(shell_info *info);
int remove_alias(shell_info *info, char *str);
int create_alias(shell_info *info, char *str);
int print_alias(list_t *node);
int see_alias(shell_info *info);


/** history file **/
int recode_history(shell_info *info);
int read_hist(shell_info *info);
int create_history_list(shell_info *info, char *buf, int linecount);
char *fetch_history_file(shell_info *info);
int write_hist(shell_info *info);


/*** shell loop **/
int my_shell(shell_info *info, char **av);
int discover_builtin(shell_info *info);
void discover_cmd(shell_info *info);
void fork_shell_cmd(shell_info *info);

/** string tokenizer **/
char **stringToWords(char *str, char *d_str);


/** main.c **/
int main(int ac, char **av);


#endif
