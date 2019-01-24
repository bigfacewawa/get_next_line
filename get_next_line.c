#include "get_next_line.h"

int        nlstr(int fd, char **line, char *str[]) //函数的输入是1）文件描述符fd 2)字符串数组地址 3）一个指针数列
{
    char    buff[BUFF_SIZE + 1];//创建一个比（一次读出字符数）多一的char数组，这个数组用于存放一次性读出的字符串
    char    *nlstr;
    char    *tmp;
    int     numRead;

    while ((numRead = read(fd, buff, BUFF_SIZE)) > 0) //r是一次read出来的字符串
    {
        buff[numRead] = '\0';//在读出来的字符串结尾加'\0'
        str[fd] = ft_strjoin_del(str[fd], buff, 1); //把新读出来的字符串 和 原来的字符串 合并在一起,因为是生成一个新的str地址和内存，所以需要把原来指针的地址指向null，内存free掉，注意这是一个新函数在libft里面，最后的数字1意思是把第一个参数地址上的内容free到，且该地址指向null。
        // char * ft_strjoin(char const *s1, char const *s2);
        // Description
        // Allocates (with malloc(3)) and returns a “fresh” string end- ing with ’\0’, result of the concatenation of s1 and s2. If the allocation fails the function returns NULL.
        // Param. #1
        // The prefix string.
        // Param. #2
        // The suffix string.
        // Return value
        // The “fresh” string result of the concatenation of the 2 strings.
        if (ft_strchr(str[fd], '\n'))  //这个函数是返回一个指针，指向第一次出现'\n'的位置。如果这个指针存在，则跳出这个循环。（即检查字符串里有没有回车，有回车的话就跳出循环）
            break ;
    }
    if (numRead < 0)//read 为负的时候，即错误情况，返回-1
        return (-1);
    tmp = str[fd]; //把之前相加的字符串指针（地址）给临时指针
    str[fd] = NULL; //让之前的字符串指针指向NULL
    if ((nlstr = ft_strchr(tmp, '\n')))// nlstr指向之前相加的字符串第一次出现回车的地方，即'\n'的地址（如果存在的话）
    {
        *nlstr = '\0'; //把第一次出现回车的地方改成字符串结尾
        str[fd] = ft_strdup(nlstr + 1); //把出现'\n'之后的后面一位开始地址个字符串数组指针
    }
    *line = ft_strdup(tmp);//把之前相加的字符串指针（确保里面是没有回车的内容，如果有的话那个回车的位置也被字符串结尾符号所替代了）给输入参数的地址
    ft_strdel(&tmp);

    if (numRead == 0 && **line == 0 && !str[fd]) //当read到文件结尾，并且line指向的东西没有任何内容,并且字符串指针也指向null.后面两个条件是read到文件结尾时自动会产生的，因为在get_next_line里str[fd]被强制定为'\0',
        return (0);
    return (1);
}


int        get_next_line(int fd, char **line)
{
    static char    *str[FD_SIZE]; //创建一个string array,f[fd]用于指向各个文件中读取的string.它的size是系统的fd limit - 2,因为fd是从3开始，1是standard output,2是error output.

    if (fd < 0 || line == NULL || fd > FD_SIZE || BUFF_SIZE <= 0)
        return (-1);  // -1 代表产生错误的情况，分别为fd小于0，line指针指向地址NULL,fd超过系统最大fd,BUFF_SIZE没有或者为负（即read无法读出字符）

    if (!str[fd]) // 如果str[fd]指针不存在（即指向null），则创建只有结尾‘\0’的str，让str[fd]指向这个‘\0’的地址。
        str[fd] = ft_strnew(0);//这一步确保了没有一个str[fd],都有地址。
    return (nlstr(fd, line, str));//这样的话就能把输入文件里的fd,line（str array),以及一个声明了的指针数组放入函数nlstr处理。
}
