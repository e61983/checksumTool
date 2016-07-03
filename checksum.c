#include <stdio.h>
#include <stdint.h>

enum{
    SUCCESS,
    MISSING_FILENAME,
    FILE_MAYBE_NOT_EXIST
}e_clac_status;

/**
 * @brief Program Entry
 *
 * @param argc
 * @param argv[]
 *  target file will passthouth with parameter into this program
 * @return
 *  return program status
 * @retval
 * refer: enum e_clac_status
 */

int main(int argc, const char *argv[]) {

    /* user will input the filename. we check this file is exist realy.
     * if not, we will resopne some message. */
    if( 1 >= argc ){
        printf("Please input the filename.\n");
        return MISSING_FILENAME;
    }

    FILE* f_target = NULL;
    if(NULL == (f_target=fopen(argv[1], "rb"))){
        printf("The file \"%s\" maybe not exist.\n",argv[1]);
        return FILE_MAYBE_NOT_EXIST;
    }

    /* calculating checksum */

    int i_readforsum = EOF;
    uint32_t checksum = 0;
    while (EOF !=(i_readforsum = fgetc(f_target))){
        checksum += i_readforsum;
    }
    fclose(f_target);

    printf("0x%x\n",checksum);

    return SUCCESS;
}
