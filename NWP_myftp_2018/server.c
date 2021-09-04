/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdio.h>
#include <netdb.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/wait.h>

char* my_strcat(char* av, char* av2)
{
    int i = strlen(av);
    int j = strlen(av2);
    char* res = malloc(sizeof(char) * i + j + 1);
    int a = 0;

    for (;av[a];a++) {
        res[a] = av[a];
    }
    for (int b = 0;av2[b];a++, b++) {
        res[a] = av2[b];
    }
    return (res);
}

int	cnt_word(char *str, char delim)
{
    int	i = 0;
    int	cnt = 0;

    while (str[i]) {
        if (str[i] == delim)
        cnt++;
        i++;
    }
    if (str[0] != delim)
        cnt++;
    return (cnt);
}

char **my_strtowordtab(char *array, char delim)
{
    char **tab;
    int i = 0;
    int m = 0;
    int e = 0;

    if ((tab = malloc(sizeof(char *) * (cnt_word(array, delim) + 1))) == NULL)
        return (NULL);
    while (e < cnt_word(array, delim)) {
        if ((tab[e] = malloc(sizeof(char) + strlen(array))) == NULL)
            return (NULL);
        while (array[i] == delim)
            i++;
        while (array[i] != delim && array[i])
            tab[e][m++] = array[i++];
        tab[e][m] = '\0';
        m = 0;
        e++;
        i++;
    }
    tab[e] = NULL;
    return (tab);
}

char *fill_help()
{
    char *str = "USER <SP> <username> <CRLF>   : Specify user for \
authentication\
            PASS <SP> <password> <CRLF>   : Specify password for authentication\
            CWD  <SP> <pathname> <CRLF>   : Change working directory\
            CDUP <CRLF>                   : Change working directory to \
parent directory\
            QUIT <CRLF>                   : Disconnection DELE <SP> \
<pathname> <CRLF>   : Delete file on the server\
            PWD  <CRLF>                   : Print working directory\
            PASV <CRLF>                   : Enable \"passive\" mode for \
data transfer\
            PORT <SP> <host-port> <CRLF>  : Enable \"active\" mode for \
data transfer\
            HELP [<SP> <string>] <CRLF>   : List available commands\
            NOOP <CRLF>                   : Do nothing\
            (the following are commands using data transfer )\
            RETR <SP> <pathname> <CRLF>   : Download file from server to client\
            STOR <SP> <pathname> <CRLF>   : Upload file from client to server\
            LIST [<SP> <pathname>] <CRLF> : List files in the \
current working directory";
    return (str);
}

char *line_manage(char *str, int second_sock, char *path)
{
    char *pwd = malloc(sizeof(char) * 500);
    char *string;
    static int d = 0;
    char *help = fill_help();
    char **tab = my_strtowordtab(str, ' ');

    if (strncmp(tab[0], "USER", 4) == 0) {
        if (strncmp(tab[1], "Anonymous", 9) == 0)
            return ("331\n");
        else
            return ("331\n");
    }
    if (strncmp(tab[0], "PASS", 4) == 0) {
        if (!tab[1]) {
            d = 1;
            return ("230\n");
        }
        else if (strlen(tab[1]) <= 4) {
            d = 1;
            return ("230\n");
        }
        else
            return ("530\n");
    }
    if (d == 1) {
        if (strncmp(tab[0], "CWD", 3) == 0) {
            if (path == NULL)
                return ("550\n");
            if (chdir(path) != 0)
                return ("550\n");
            else
                return ("250\n");
        }
        if (strncmp(tab[0], "NOOP", 4) == 0)
            return ("200\n");
        if (strncmp(tab[0], "STOR", 4) == 0)
            return ("150\n");

        if (strncmp(tab[0], "PASV", 4) == 0)
            return ("227\n");
        if (strncmp(tab[0], "RETR", 4) == 0)
            return ("150\n");
        if (strncmp(tab[0], "LIST", 4) == 0)
            return ("425\n");
        if (strncmp(tab[0], "DELE", 4) == 0) {
            chdir(path);
            printf("%s\n", tab[1]);
            remove(tab[1]);
            return ("250\n");
        }
        if (strncmp(tab[0], "PORT", 4) == 0)
            return ("200\n");
        if (strncmp(tab[0], "PWD", 3) == 0) {
            if (chdir(path) != 0)
                return ("550\n");
            getcwd(pwd, 500);
            string = my_strcat("257 ", pwd);
            string = my_strcat(string, "\n");
            return (string);
        }
        if (strncmp(tab[0], "HELP", 4) == 0) {
            string = my_strcat("214 ", help);
            string = my_strcat(string, "\n");
            return (string);
        }
        if (strncmp(tab[0], "CDUP", 4) == 0)
            return ("200\n");
        if (strncmp(tab[0], "QUIT", 4) == 0) {
            return ("221\n");
        }
    }
    else
        return ("500 Fail unknow command\n");
}

void in_the_while(char *nstr, char *str, int second_sock, char **argv)
{
    nstr = line_manage(str, second_sock, argv[2]);
    if (strncmp(nstr, "221", 3) == 0) {
        write(second_sock, nstr, strlen(nstr));
        shutdown(second_sock, SHUT_RDWR);
        close (second_sock);
        exit(0);
    }
    write(second_sock, nstr, strlen(nstr));
}

void server(char **argv, fd_set fds, int sock, struct sockaddr_in addresses)
{
    size_t a = 0;
    int second_sock = 0;
    char *nstr = "aaa";
    char *str = NULL;
    struct sockaddr_in client;
    int add = sizeof(addresses);
    FILE *input = 0;

    bind(sock, (struct sockaddr *)&addresses, sizeof(addresses));
    listen(sock, 42);
    FD_SET(sock, &fds);
    while (1) {
        second_sock = accept(sock,(struct sockaddr*)&client,(socklen_t*)&add);
        if (fork() == 0) {
            input = fdopen(second_sock, "r");
            FD_SET(second_sock, &fds);
            write(second_sock, "220\n", 4);
            while (getline(&str, &a ,input) != 0)
                in_the_while(nstr, str, second_sock, argv);
            close(second_sock);
        }
    }
}

int main(int argc, char **argv)
{
   int sock = 0;
   fd_set fds;
   struct sockaddr_in addresses;
   int lisner = 0;

    if (argc != 3 || chdir(argv[2]) != 0)
        return (84);
    FD_ZERO(&fds);
    lisner = atoi(argv[1]);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    addresses.sin_family = AF_INET;
    addresses.sin_addr.s_addr = INADDR_ANY;
    addresses.sin_port = htons(lisner);
    server(argv, fds, sock, addresses);
}
