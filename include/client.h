/*
** my_irc.h for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Apr 26 16:56:56 2008 caner candan
** Last update Mon Apr 28 08:42:30 2008 caner candan
*/

#ifndef __MY_IRC_H__
# define __MY_IRC_H__

/*
** Return's values
*/
# ifndef TRUE
#  define TRUE	0
# endif /* !TRUE */
# ifndef FALSE
#  define FALSE -1
# endif /* !FALSE */

/*
** Mesg's values
*/
# define MESG_PASS	"pass %s"
# define MESG_NICK	"nick %s"
# define MESG_USER	"user %s %s %s %s"
# define MESG_PONG	"pong %s"
# define MESG_JOIN	"join %s"

# define MODE		"o"

# define RET_PING	"PONG"

/*
** RFC's values
*/
# define MAX_NICK_LEN		9
# define MAX_CHAN_LEN		50
# define MAX_CMD_PARAMS		15
# define MAX_SERVER_NAME_LEN	63
# define MAX_HOST_NAME_LEN	255
# define CLIENT_READ_BUF_SIZE	512

/*
** Main's defines
*/
# define DEBUG	1

/*
** String's values
*/
# define EMPTY		""
# define BCHAN		"#"
# define ENDLINE	"\r\n"
# define SP		' '

/*
** Gtk config
*/
# define DELETE_EVENT	"delete_event"
# define CLICKED	"clicked"
# define ACTIVATE	"activate"

/*
** Glade config
*/
# define XML_FILE	"client.glade"

# define ABOUT_WINDOW	"about"

# define USERS_VIEW	"userslist"
# define MESG_VIEW	"mesglist"

# define SCROLL_MESG	"scrolled_mesg"
# define SCROLL_USERS	"scrolled_users"

# define DIALOG_WINDOW	"dialog"
# define DIALOG_SEND	"dialog_send"
# define DIALOG_ABOUT	"dialog_about"
# define DIALOG_QUIT	"dialog_quit"
# define DIALOG_ENTRY	"dialog_entry"
# define DIALOG_REFRESH	"dialog_refresh"

# define LOGIN_WINDOW	"login"
# define LOGIN_HOST	"login_host"
# define LOGIN_PORT	"login_port"
# define LOGIN_CHAN	"login_chan"
# define LOGIN_NICK	"login_nick"
# define LOGIN_REAL	"login_real"
# define LOGIN_SIGNIN	"login_signin"
# define LOGIN_QUIT	"login_quit"
# define LOGIN_MESG	"login_mesg"

/*
** Error's messages
*/
# define ERR_FMT	"<b>Error: %s</b>"
# define ERR_SIGNIN	"Incorrect informations"
# define ERR_NICK	"Incorrect nickname"
# define ERR_CHAN	"Incorrect channel"

/*
** NULL
*/
# ifndef NULL
#  define NULL	0
# endif /* !NULL */

/*
** User list enum
*/
enum
  {
    USERS_LIST,
    STATUS_LIST,
    N_LIST
  };

/*
** Mesg list enum
*/
enum
  {
    DATE_MESG,
    USER_MESG,
    BODY_MESG,
    N_MESG
  };

/*
** Connect's structure
*/
typedef struct	s_cnt
{
  void		*host;
  void		*port;
  void		*chan;
  void		*nick;
  void		*real;
  int		socket;
  void		*xml;
}		t_cnt;

/*
** Messages' structure
*/
typedef struct	s_message
{
  char		*prefix;
  char		*command;
  char		*param[MAX_CMD_PARAMS];
  char		param_count;
}		t_message;

/*
** Messages functions structure
*/
typedef struct	s_fct
{
  char		*mesg;
  int		(*f)();
}		t_fct;

/*
** Global extern
*/
extern t_fct	gl_fct[];

/*
** Socket's functions
*/
int	create_socket(t_cnt *cnt);
int	send_to_server(t_cnt *cnt, char *mesg);
int	init_server(t_cnt *cnt);

/*
** Main's functions
*/
void	about(void *btn, t_cnt *cnt);

/*
** User list functions
*/
void	init_user_list(t_cnt *cnt);
void	insert_user_to_list(t_cnt *cnt, char *user, int status);

/*
** Mesg list functions
*/
void	init_mesg_list(t_cnt *cnt);
void	insert_mesg_to_list(t_cnt *cnt, char *date, char *user, char *mesg);
void	send_mesg(void *btn, t_cnt *cnt);
void	scrolled_window(t_cnt *cnt, void *scroll);

int	mesg_init(t_cnt *cnt, t_message *msg);

int	send_pong(t_cnt *cnt, t_message *msg);
int	send_list(t_cnt *cnt, t_message *msg);
int	send_chan(t_cnt *cnt, t_message *msg);

/*
** Treeview's functions
*/
void	create_column(void *view, int type, char *title, int width);

/*
** Connect widget functions
*/
void	connect_btn_login(t_cnt *cnt);
void	connect_btn_dialog(t_cnt *cnt);
void	widget_connected(t_cnt *cnt, char *elm, char *action, void (*f)());

/*
** Dialog's functions
*/
void	init_dialog(void *btn, t_cnt *cnt);
int	connect_to_server(t_cnt *cnt);

/*
** Login's functions
*/
void	error_login(void *xml, char *mesg);

/*
** Entry's functions
*/
int	check_entry(void *xml, char *entry, char *value);

/*
** Debug's functions
*/
void	debug(char *s);

/*
** String's functions
*/
char	*trim(char *s);
void	extract_msg(char *amsg, t_message *msg);

#endif /* !__MY_IRC_H__ */
