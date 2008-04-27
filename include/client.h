/*
** my_irc.h for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Apr 26 16:56:56 2008 caner candan
** Last update Sun Apr 27 11:32:56 2008 caner candan
*/

#ifndef __MY_IRC_H__
# define __MY_IRC_H__

/*
** Main's defines
*/
# define DEBUG	1

# define EMPTY	""

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
** Button's functions
*/
void	connect_btn_login(void *xml);
void	connect_btn_dialog(void *xml);

/*
** Dialog's functions
*/
void	init_dialog(void *btn, void *xml);

/*
** Login's functions
*/


#endif /* !__MY_IRC_H__ */
