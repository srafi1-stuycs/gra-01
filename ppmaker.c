#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

int main() {
    // create a file
    int ppm_file = open("basic.ppm", O_CREAT | O_WRONLY, 0644);

    // print out header data
    char buffer[256];
    buffer[0] = 0;
    strcat(buffer, "P3\n");
    strcat(buffer, "500 500\n");
    strcat(buffer, "255\n");
    write(ppm_file, buffer, strlen(buffer));

    // print out each pixel
    int x, y;
    for(y = 0; y < 500; y++) {
        for(x = 0; x < 500; x++) {
            strcpy(buffer, "0 255 0 ");
            write(ppm_file, buffer, strlen(buffer));
        }
        write(ppm_file, "\n", 1);
    }

    close(ppm_file);
    return 0;
}
