#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

int swap_bytes(int input)
{
    int output;
    byte_pointer in = (byte_pointer)&input;
    byte_pointer out = (byte_pointer)&output;

    for (int i = 0; i < sizeof(int); i++) {
        out[i] = in[sizeof(int) - i - 1];
    }

    return output;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("An integer argument is needed to run this program.\nPlease try again.\n");
        return 1;
    }

    int input = (int)strtol(argv[1], NULL, 0);
    int output = swap_bytes(input);

    printf("%#x\n", output);
}
