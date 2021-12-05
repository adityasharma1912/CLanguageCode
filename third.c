#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//#include <linux/stddef.h>
typedef char acos_mon_cms_bitmap_t;
#define ACOS_MON_CMS_ELEMENT_SIZE  (sizeof(cms_element_size_t))
#define ACOS_MON_CMS_FIND_MASK_BIT_COUNT        (sizeof(acos_mon_cms_bitmap_t) * 8)         // Please keep it always power of 2 so that bitops can be used
#define ACOS_MON_CMS_FIND_MASK_IDX_MAX          (ACOS_MON_CMS_FIND_MASK_BIT_COUNT - 1)

typedef struct acos_mon_entity{
    int type;
    int name;
    int deleted;
}acos_mon_entity_t;

void mprint(char *str){
    printf("%s\n",str);
}
int main(){
    float std_deviation = 12.323;
    acos_mon_entity_t *mon_entity = (acos_mon_entity_t *)malloc(sizeof(acos_mon_entity_t));
    free(mon_entity);
    mon_entity = NULL;
    if(mon_entity){
        printf("mon entity exists with value = 0x%x\n",mon_entity);
        if(mon_entity->deleted){
            mprint("mon entity deleted");
        }else{
            mprint("mon entity not deleted");
        }
    }else{
        mprint("mon entity doesn't exist");
    }


    printf("Aditya  -- pid = %d and parent pid = %d\n",getpid(),getppid());
    printf("ACOS_MON_CMS_FIND_MASK_IDX_MAX = %d",ACOS_MON_CMS_FIND_MASK_IDX_MAX);
    printf("std_deviation = %.2f",std_deviation);
    return 0;
}
