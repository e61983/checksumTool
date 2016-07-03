#include <stdio.h>
#include <stdint.h>

/**
 * @brief Program Entry
 *
 * @param argc
 * @param argv[]
 *  target file will passthouth with parameter into this program
 * @return
 *  return program status
 * @retval
 *  0 - Success
 *  1 - Fail
 * @return
 */
int main(int argc, const char *argv[]) {

    /* user will input the filename. we check this file is exist realy.
     * if not, we will resopne some message. */
    if( 1 >= argc ){
        printf("Please input the filename.\n");
        return 1;
    }

    FILE* f_target = NULL;
    if(NULL == (f_target=fopen(argv[1], "rb"))){
        printf("The file \"%s\" maybe not exist.\n",argv[1]);
        return 2;
    }

    uint32_t checksum = 0;

    int i_readforsum = EOF;
    while (EOF !=(i_readforsum = fgetc(f_target))){
        checksum += i_readforsum;
    }
    fclose(f_target);
    printf("0x%x\n",checksum);

}
