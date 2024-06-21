#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("flie missing\n");
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("file couldnt be opened\n ");
        return 1;
    }
    uint8_t buffer[512];
    char filename[10];
    int filecount = 0;
    FILE *img = NULL;

    while (fread(buffer, 1, 512, f) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            if ((buffer[3] & 0xf0) == 0xe0)
            {
                if (img != NULL)
                {
                    fclose(img);
                }
                sprintf(filename, "%03i.jpg", filecount++);
                img = fopen(filename, "w");
                if (img == NULL)
                {
                    printf("file error\n");
                    return 1;
                }
            }
        }
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(f);
    return 0;
}
