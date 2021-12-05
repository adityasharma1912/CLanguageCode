#include <ume.h>

struct um_ctx *um_compile(const char **patterns){
    struct um_ctx *head = NULL;
    struct um_ctx *prev = NULL;
    int index = 0;
    while(patterns[index]!=NULL){
        struct um_ctx *node = (struct um_ctx *)malloc(sizeof(struct um_ctx));
        if(node == NULL){
            fprintf(stderr,"Error: Out of Memory Error\n");
            break;
        }
        memset(node, 0x0, sizeof(struct um_ctx));
        int pattern_str_len = strlen(patterns[index]) + 1; //adding one for NULL char
        node->pattern_str = (char *)malloc(sizeof(char) * pattern_str_len);
        if(node->pattern_str == NULL){
            fprintf(stderr,"Error: Out of Memory Error\n");
            break;
        }
        memset(node->pattern_str, 0x0, pattern_str_len);
	    strncpy(node->pattern_str, patterns[index], pattern_str_len);
        if(prev == NULL){
            head = node;
        } else {
            prev->next = node;
        }
        prev = node;
        index++;
    }

    //once compilation is finished, free the memory
    index = 0;
    while(patterns[index]!=NULL){
        free((void *)patterns[index]);
        index++;
    }
    if(patterns){
        free(patterns);
    }
    return head;
}

void um_free(struct um_ctx *ctx){
    struct um_ctx *itr = ctx;
    struct um_ctx *prev = NULL;
    while(itr!=NULL){
        if(itr->pattern_str){
            free(itr->pattern_str);
        }
        prev = itr;
        itr = itr->next;
        free(prev);
    }
}

bool um_match_helper(const char *url, const char *pattern){
    int url_length = strlen(url);
    int pattern_length = strlen(pattern);
    int url_index = 0, pattern_index = 0;
    int asterisk_index = -1, url_backtrack_index = -1;

    while (url_index < url_length) {
        if (pattern_index < pattern_length && 
           (pattern[pattern_index] == url[url_index])) {
            ++url_index;
            ++pattern_index;
        } else if (pattern_index < pattern_length && 
                   pattern[pattern_index] == '*') {
            asterisk_index = pattern_index;
            url_backtrack_index = url_index;
            ++pattern_index;
        } else if (asterisk_index == -1) {
            return false;
        } else {
            pattern_index = asterisk_index + 1;
            url_index = url_backtrack_index + 1;
            url_backtrack_index = url_index;
        }
    }

    for (int i = pattern_index; i < pattern_length; i++) {
        if (pattern[i] != '*') {
            return false;
        }
    }
    return true;
}

int um_match(const struct um_ctx *ctx, const char *url, bool *results){
    const struct um_ctx *itr = ctx;
    if(strlen(url) == 0 || url[0] == '/'){
        return -1;
    }
    int index = 0;
    while(itr!=NULL){
        results[index] = um_match_helper(url, itr->pattern_str);
        itr = itr->next;
        index++;
    }
    return 0;
}

int getLineCount(char *filename)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int counter = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        counter++;
    }

    fclose(fp);
    if (line)
        free(line);
    return counter;
}

char** readFile(char *filename)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;

    int totalLinesInFile = getLineCount(filename)+1;
    char **lines = (char **)malloc(sizeof(char *)*totalLinesInFile);
    if(lines == NULL){
        fprintf(stderr,"Error: Out of Memory Error\n");
        return NULL;
    }
    fp = fopen(filename, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        lines[count] = (char *)malloc(sizeof(char)*read);
        if(lines[count] == NULL){
            fprintf(stderr,"Error: Out of Memory Error\n");
            break;
        }
        memset(lines[count], 0x0, read);
        strncpy(lines[count], line, read);
        if(lines[count][read-1] == NEW_LINE_CHAR){
            lines[count][read-1] = NULL_CHAR;
        }
        count++;
    }
    lines[count] = NULL;

    fclose(fp);
    if (line)
        free(line);
    return lines;
}

int main(int ac, char **av){
    if(ac!=3){
        fprintf(stderr,"Usage:\n./ume <Patterns-File-Name> <URLs-File-Name>\n");
        exit(EXIT_FAILURE);
    }

    char *pattern_file_name = av[1];
    char *url_file_name = av[2];

    int pattern_count = getLineCount(pattern_file_name);
    int url_count = getLineCount(url_file_name);

    char **patterns = readFile(pattern_file_name);
    char **urls = readFile(url_file_name);

    if(patterns == NULL || urls == NULL){
        exit(EXIT_FAILURE);
    }

    int index = 0;
    struct um_ctx *head = um_compile((const char **)patterns);

    while(urls[index]!=NULL){
        bool *result = (bool *) malloc(sizeof(bool) * pattern_count);
        if(result == NULL){
            fprintf(stderr,"Error: Out of Memory Error\n");
            break;
        }
        memset(result, 0x0, sizeof(bool) * pattern_count);
        if(um_match(head, urls[index], result) == -1){
            fprintf(stderr,"Error while matching URL: %s\n", urls[index]);
            index++;
            continue;
        }
        printf("%s", urls[index]);
        for(int i = 0; i < pattern_count; i++){
            if(result[i] == true){
                printf(",%d",i);
            }
        }
        printf("\n");
        free(result);
        index++;
    }

    //free pattern's memory once done!
    um_free(head);

    // free URLs memory:
    index = 0;
    while(urls[index]!=NULL){
        free(urls[index]);
        index++;
    }
    if(urls!=NULL){
        free(urls);
    }
    return 0;
}
