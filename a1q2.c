#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc != 2) { 
        fprintf(stderr, "Error: Please provide the address of a file as an input.\n");
        return -1;
    }
    
    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'.\n", argv[1]);
        return -1;
    }
    
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    
    fclose(file);

    printf("The size of the file is %ld bytes.\n", file_size);
    
    return 0;
}
