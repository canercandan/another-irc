/*
** server.h for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Wed Apr 16 14:48:23 2008 julian kirtz
** Last update Sat Apr 26 22:27:09 2008 julian kirtz
*/

#ifndef __SERVER_H__
#define __SERVER_H__

#define MAX_FD			64
#define MAX_LISTEN		128
#define MAX_PORT		6

#define FD_FREE			0
#define FD_CLIENT		1
#define	FD_SERVER		2

#define TIMEOUT_SELECT		10

#define CLIENT_READ_BUF_SIZE	512
#define CLIENT_WRITE_BUF_SIZE	CLIENT_READ_BUF_SIZE
#define CLIENT_WRITE_BUF_LINE	10

#define CRLF			"\r\n"
#define SP			' '

#define SERVER_CFG_FILE		"server.cfg"
#define PORT_ITEM		"PORT"
#define KEY_ITEM		"KEY"

#define MAX_NICK_LEN		9
#define MAX_CHAN_LEN		50
#define MAX_CMD_PARAMS		15
#define MAX_SERVER_NAME_LEN	63
#define MAX_HOST_NAME_LEN	255

#define ERROR			"ERROR"
#define ERR_NONICKNAMEGIVEN	"431"
#define ERR_ERRONEUSNICKNAME	"432"
#define ERR_NICKNAMEINUSE	"433"
#define ERR_ALREADYREGISTRED	"462"
#define ERR_NEEDMOREPARAMS	"461"
#define ERR_NOSUCHCHANNEL	"403"
#define ERR_BADCHANNELKEY	"475"

#define RPL_WELCOME		"001"
#define RPL_YOURHOST		"002"
#define RPL_CREATED		"003"
#define RPL_MYINFO		"004"
#define RPL_LUSERCLIENT		"251"
#define RPL_LUSEROP		"252"
#define RPL_LUSERUNKNOWN	"253"
#define RPL_LUSERCHANNELS	"254"
#define RPL_LUSERME		"255"
#define RPL_NOTOPIC		"331"
#define RPL_NAMREPLY		"353"
#define RPL_ENDOFNAMES		"366"

#define ERROR_FORMAT		"ERROR :Closing Link: %s (Quit: %s)"
#define RPL_NOTOPIC_FORMAT	"%s :No topic is set"
#define RPL_NAMREPLY_FORMAT	"= %s %s"
#define RPL_ENDOFNAMES_FORMAT	"%s :End of NAMES list"

typedef void		(*fct)();

typedef struct		s_list
{
  void			*data;
  struct s_list		*next;
}			t_list;

typedef struct		s_command
{
  char			*cmd;
  void			(*func)();
}			t_command;

typedef struct		s_reply
{
  char			*rpl;
  int			(*func)();
}			t_reply;

typedef struct		s_message
{
  char			*prefix;
  char			*command;
  char			*param[MAX_CMD_PARAMS];
  char			param_count;
}			t_message;

typedef struct		s_client
{
  char			buffer_read[CLIENT_READ_BUF_SIZE];
  char			buffer_write[CLIENT_WRITE_BUF_LINE][CLIENT_WRITE_BUF_SIZE];
  int			buffer_offset;
  char			nick[MAX_NICK_LEN + 1];
  char			*username;
  int			mode;
  char			*realname;
  char			registered;
  char			keyed;
  t_list		*channel;
}			t_client;

typedef struct		s_channel
{
  char			name[MAX_CHAN_LEN + 1];
  int			mode;
  int			limit;
  char			*banmask;
  char			*key;
  char			*topic;
  t_list		*client;
}			t_channel;

typedef struct		s_server
{
  char			name[MAX_SERVER_NAME_LEN + 1];
  char			hostname[MAX_HOST_NAME_LEN + 1];
  char			fd_type[MAX_FD];
  t_client		client[MAX_FD];
  fct			fct_read[MAX_FD];
  fct			fct_write[MAX_FD];
  int			port[MAX_PORT];
  char			ip;
  struct timeval	timeout;
  int			fd_max;
  fd_set		fd_read;
  fd_set		fd_write;
  char			*key;
  t_list		*channel;
}			t_server;

void		add_client_to_chan(t_server *serv, int fd, t_channel *chan);
void		cfg_ip(void *foo);
void		cfg_key(char **key);
void		cfg_port(int *port);
void		cfg_timeout();
void		client_socket_read(t_server *server, int fd);
void		client_socket_write(t_server *serv, int fd);
void		cmd_join(t_server *serv, int fd, t_message *msg);
void		cmd_nick(t_server *serv, int fd, t_message *msg);
void		cmd_pass(t_server *serv, int fd, t_message *msg);
void		cmd_quit(t_server *serv, int fd, t_message *msg);
void		cmd_user(t_server *serv, int fd, t_message *msg);
int		count_nb_port(int *port);
t_channel	*create_chan(t_server *serv, char *name);
void		create_server(t_server *serv);
void		delete_client(t_server *serv, int fd);
void		do_command(t_server *serv, int fd, t_message *msg);
void		extract_params(char **amsg, t_message *msg);
t_channel	*get_chan(t_list *chanlist, char *chan_name);
void		get_next_message(char *buffer, char *amsg, int *offset);
void		init_all_fd(t_server *serv);
char		is_digit(char c);
char		is_letter(char c);
char		is_special(char c);
char		*load_values_from_file(char *item, char *file);
void		offset_to_next_value(int *offset, char *str, char sep);
void		protocol_interpreter(t_server *serv, int fd);
void		read_all_fd(t_server *serv);
void		reply_error(t_server *serv, int fd, t_message *msg);
void		reply_notopic(t_server *serv, int fd, int index, void *chan);
void		reply_response(t_server *serv, int fd, char *numeric, void *info);
void		server_socket_read(t_server *serv, int fd);

#endif
