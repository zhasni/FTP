/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 18:07:17 by zhasni            #+#    #+#             */
/*   Updated: 2015/05/12 18:05:24 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H

# include <sys/param.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <netdb.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <fcntl.h>

# include "libft/libft.h"

typedef struct			s_env
{
	char				**path;
	char				**bkp;
	char				*oldpwd;
	char				**arg;
	char				*home;
	char				*pwd;
	int					len;
	int					client_socket;
	char				*tmp;
}						t_env;

void					ft_get_env(t_env *env, char **envp);
char					*ft_get_line_env(t_env *env, char *key);
char					*ft_my_join(char const *s1, char const *s2);
char					*ft_my_join2(char const *s1, char const *s2);
char					*ft_check_path(t_env *env, char *line);
char					*ft_fork(t_env *env, char *line);
int						ft_check_slash(t_env *env, char *line);
char					*ft_strtri(char const *s);

char					*redirection_sortie(t_env *env, char *line);

void					handle_signal(int signo);
char					*ft_check_path(t_env *env, char *line);
void					ft_prompt(t_env *env, char **envp);
void					ft_putchar_color_fd(char *color, char c, int fd);
void					ft_putstr_color_fd(char *color, char *str, int fd);
void					ft_putendl_color_fd(char *color, char *str, int fd);
char					*ft_strtri(char const *s);
char					*ft_my_join(char const *s1, char const *s2);
char					**ft_strsplit(char const *s, char c);
int						get_next_line(int const fd, char **line);
char					*ft_mallocat(char const *s1, char const *s2);
char					*ft_write_stock(char **line, char *src);
int						ft_isprint(int c);
int						ft_check_build(char *line, t_env *env);
int						ft_strcmp(const char *s1, const char *s2);
void					ft_get_env(t_env *env, char **envp);
char					*ft_strdup(const char *s);
int						ft_tablen(char **tab);
void					ft_error(char *line, t_env *env);
int						ft_env(t_env *env, char **cmd);
void					ft_cd(char *line, t_env *env);
char					*ft_get_line_env(t_env *env, char *key);
int						ft_replace_line_env(t_env *env, char *key,
							char *newpath);
char					*ft_strsub(char const *s, unsigned int start,
							size_t len);
int						ft_check_cd(char *line, t_env *env);
void					ft_cd_minus(t_env *env, char *line);
void					ft_cd_home(t_env *env);
void					ft_cd_tilde(t_env *env, char **cdtab);
int						ft_exit(char *s);
char					*ft_delete_tilde(char **cdtab);
int						ft_setenv(char *line, t_env *env);
int						ft_check_line_env(t_env *env, char *key);
void					ft_add_line(t_env *env, char *key, char *arg);
void					ft_delete_line(t_env *env, char *key);
int						ft_unsetenv(char *line, t_env *env);
void					ft_resize_tab(t_env *env);
char					*ft_tolowerstr(char *str);
void					ft_error_setenv(int n, t_env *env);
void					ft_error_cd(char *line, int n, t_env *env);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_cd_bis(char *tmp, char **cdtab, t_env *env);
void					ft_error_cd_bis(char *line, int n, t_env *env);
char					*ft_epur_str(char *src);
void					ft_cd_slash(t_env *env, char *arg);
int						ft_str_check(char *str);
int						ft_str_check_error(char *str);
int						ft_get(t_env *env, char *str);
char					*ft_put(char *str);
char					*ft_check_filename(char *txt, int *i);
void					usage(char *str);
void					ft_setenv_bis(char **tmp, t_env *env, int ret, int len);
void					ft_cd_ter(char *tmp, char *newpath, t_env *env);
void					ft_cd_tilde_bis(t_env *env, char *newpath, char *tmp2);
char					*ft_check_get(char *tmp, char *txt, int *flag);
void					ft_getfile(char *txt);
int						create_client(char *addr, int port);
int						ft_prompt_bis(int server_socket, char *str);
char					**ft_check_tab(char **tab);
void					ft_check_quit(char *buf, int server_socket);
int						ft_prompt_bis(int server_socket, char *str);
int						ft_check_put(char *buf, int server_socket);
int						ft_putfile(char *txt);
int						ft_check_putfile(char *buf);
void					ft_pre_fork(t_env *env, int client_socket, char *buf);
void					ft_init(t_env *env, char **envp);
void					ft_loop_server(t_env *env, int client_socket);
int						create_server(int port);
void					ft_client_socket(t_env *env, int *client_socket,
							int sock);
char					*redirection_sortie(t_env *env, char *line);

#endif
