/*
** my_irc.h for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Apr 26 16:56:56 2008 caner candan
** Last update Sun Apr 27 17:09:43 2008 caner candan
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
** Select description's values
*/
# define FD_FREE	0
# define FD_CLIENT	1
# define FD_SERVER	2

# define TIMEOUT_SELECT	10

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
}		t_cnt;

/*
** Socket's functions
*/
int	create_socket(t_cnt *cnt);
int	listen_from_server(void *xml, t_cnt *c);

/*
** Main's functions
*/
void	about(void *btn, void *xml);

/*
** User list functions
*/
void	init_user_list(void *view);
void	insert_user_to_list(void *view, char *user, int status);

/*
** Mesg list functions
*/
void	init_mesg_list(void *view);
void	insert_mesg_to_list(void *view, char *date, char *user, char *mesg);
void	send_mesg(void *btn, void *xml);

/*
** Treeview's functions
*/
void	create_column(void *view, int type, char *title, int width);

/*
** Connect widget functions
*/
void	connect_btn_login(void *xml);
void	connect_btn_dialog(void *xml);
void	widget_connected(void *xml, char *elm, char *action, void (*f)());

/*
** Dialog's functions
*/
void	init_dialog(void *btn, void *xml);
int	connect_to_server(void *xml);

/*
** Login's functions
*/
void	error_login(void *xml, char *mesg);

/*
** Entry's functions
*/
int	check_entry(void *xml, char *entry, char *value);

#endif /* !__MY_IRC_H__ */
