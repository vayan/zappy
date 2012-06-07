#ifndef __XFUNC_HH
#define __XFUNC_HH

#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>

typedef void (*sighandler_t)(int);

int             xclose(int d);
void            *xmalloc(unsigned int size);
sighandler_t    xsignal(int signum, sighandler_t handler);
int             xbind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int             xlisten(int sockfd, int backlog);
ssize_t         xsend(int sockfd, const void *buf, size_t len, int flags);

#endif