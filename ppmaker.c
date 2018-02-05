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
    strcat(buffer, "510 510\n");
    strcat(buffer, "255\n");
    write(ppm_file, buffer, strlen(buffer));

    // print out each pixel
    int x, y;
    for(y = 0; y < 510; y++) {
        for(x = 0; x < 510; x++) {
            sprintf(buffer, "%d %d %d ", x/2, y/2, (x + y) / 4);
            write(ppm_file, buffer, strlen(buffer));
        }
        write(ppm_file, "\n", 1);
    }

    close(ppm_file);
    return 0;
}
