#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
int main() {
    int fd = shm_open("/test123", O_RDWR | O_CREAT, 0644);
    if (fd == -1) perror("shm_open failed");
    else printf("shm_open OK!\n");
    return 0;
}
