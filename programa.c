#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
  pid_t pid;
  int fd,m,n,dato;

  fd=creat("datos.txt", 777);
  pid = fork();

  //Proceso Padre
  if(pid > 0)
  {
    sleep(3);
    close(fd);
    fd = open("datos.txt", O_RDONLY);
    while (read(fd, &dato, sizeof(int)) == sizeof(int)) {
       printf("%d\n",dato);
    }
  }

  //Proceso hijo
  if (pid == 0)
  {
    for (dato = 1; dato <= 5; dato++) {
      write(fd, &dato, sizeof(int));
    }
  }
  return 0;
}
