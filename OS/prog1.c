//ls-l

#include <stdio.h> 
#include <dirent.h> 
#include <sys/stat.h> 
#include <pwd.h> 
#include <grp.h> 
#include <time.h>

int main()
{
    DIR *d;
    struct dirent *de;
    struct stat buf;
    int i, j;
    char P[10] = "rwxrwxrwx", AP[10] = " ";
    struct passwd *p;
    struct group *g;
    struct tm *t;
    char time[26];
    d = opendir(".");
    readdir(d);
    readdir(d);
    while ((de = readdir(d)) != NULL)
    {
        stat(de->d_name, &buf);
        if(S_ISDIR(buf.st_mode))
            printf("d");
        else if (S_ISREG(buf.st_mode))
            printf("-");
        else if (S_ISCHR(buf.st_mode))
            printf("c");
        else if (S_ISBLK(buf.st_mode))
            printf("b");
        else if (S_ISLNK(buf.st_mode))
            printf("l");
        else if (S_ISFIFO(buf.st_mode))
            printf("p");
        else if (S_ISSOCK(buf.st_mode))
            printf("s");
        for(i=0,j=(1<<8);i<9;i++,j>>=1)
            AP[i] = (buf.st_mode & j) ? P[i] : '-';
        printf("%s", AP); 
        printf("%5d",buf.st_nlink);
        p=getpwuid(buf.st_uid);
        printf(" %.8s", p->pw_name); 
        g=getgrgid(buf.st_gid); 
        printf(" %-8.8s",g->gr_name); 
        printf(" %8d", buf.st_size);
        t=localtime(&buf.st_mtime); 
        strftime(time,sizeof(time),"%b %d %H:%M",t); 
        printf(" %s",time);
        printf(" %s\n", de->d_name);
    }
}


//cp

#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <errno.h> 
#include <sys/types.h> 
#include <unistd.h>

#define BUF_SIZE 8192 

int main(int argc, char* argv[]) {
    int input_fd, output_fd;   
     ssize_t ret_in, ret_out;   
     char buffer[BUF_SIZE];   

     if(argc != 3)
     { 
        printf ("Usage: cp file1 file2"); return 1;
     }
    input_fd = open (argv [1], O_RDONLY); 
    if (input_fd == -1) 
    { 
        perror ("open"); return 2;
    }

    output_fd = open(argv[2], O_WRONLY | O_CREAT, 0644); 
    if(output_fd == -1)
    { 
        perror("open"); return 3;
    }

    while((ret_in = read (input_fd, &buffer, BUF_SIZE)) > 0)
    { 
        ret_out = write (output_fd, &buffer, (ssize_t) ret_in); 
        if(ret_out != ret_in)
        { 
             perror("write"); return 4;
        }
    }
    close (input_fd); 
    close (output_fd);
    return (EXIT_SUCCESS);
} 

//mv

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    int link_result, unlink_result; /* Result codes for link() and unlink() */

    /* Check for correct number of arguments */
    if (argc != 3) {
        fprintf(stderr, "Usage: mv <source> <destination>\n");
        exit(1);
    }

    /* Use link() to create a hard link from the source file to the destination file */
    link_result = link(argv[1], argv[2]);
    if (link_result == -1) {
        perror("link error");
        exit(2);
    }

    /* Use unlink() to remove the source file */
    unlink_result = unlink(argv[1]);
    if (unlink_result == -1) {
        perror("unlink error");
        exit(3);
    }

    /* Success! */
    exit(0);
}


//rm

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    int output_fd;

    /* Check for correct number of arguments */
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(1);
    }

    /* Use the unlink() function to remove the source file */
    output_fd = unlink(argv[1]);
    if (output_fd == -1) {
        perror("unlink error");
        exit(3);
    }

    /* Success! */
    exit(0);
}
