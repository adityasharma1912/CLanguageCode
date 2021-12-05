#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
typedef unsigned short u16;
typedef unsigned int u32;
typedef char u8;
typedef unsigned long u64;
int N = 400;
int x[6][3];

#define ZBAR_MON_TYPE_MAX 3
#define REFLECTION_TYPE_MAX 6
#define ZBAR_EPOCH_TSDB_SIZE 5
#define ZBAR_NORMAL_TSDB_SIZE 30

struct two{
    int a[23];
};


typedef struct zbar_truple_s {

    //keys
    u32 src_ip;
    u32 dst_ip;

    int *zbar_dst;

    u16 dst_port;
    u8   tsdb_idx;
    u8  epoch_tsdb_idx;
    int phase;

    //u8 age;//lifecycle management

    u32 reflection_total[REFLECTION_TYPE_MAX][ZBAR_MON_TYPE_MAX];
    u32 reflection_dropped[REFLECTION_TYPE_MAX][ZBAR_MON_TYPE_MAX];

    u64 ind_total[ZBAR_MON_TYPE_MAX];
    /*Value used to compare while sorting*/
    u64 ind_cmp_val[ZBAR_MON_TYPE_MAX];
    u64 last_jiffies;

    u32 epoch_ind_tsdb[ZBAR_MON_TYPE_MAX][ZBAR_EPOCH_TSDB_SIZE];

    u8 ind_band_idx[ZBAR_MON_TYPE_MAX];
    u8 slotted;
    int *_band_ind_prev[ZBAR_MON_TYPE_MAX];
    int *_band_ind_next[ZBAR_MON_TYPE_MAX];

    //continuously store last per sec values
    int *zbar_truple_next;
    u32 ind_tsdb[ZBAR_MON_TYPE_MAX][ZBAR_NORMAL_TSDB_SIZE];
} zbar_truple_t __attribute__((packed));;



struct one{
    u32 dst_ip;
    u16 dst_port;
    u8   tsdb_idx;
    u8 zbar_dst_lock;

    //stats about traffic to the service
   u64 ind_total[ZBAR_MON_TYPE_MAX];

    u32 reflection_total[REFLECTION_TYPE_MAX][ZBAR_MON_TYPE_MAX];
    u32 reflection_dropped[REFLECTION_TYPE_MAX][ZBAR_MON_TYPE_MAX];

    u64 src_min[ZBAR_MON_TYPE_MAX];
    u64 src_max[ZBAR_MON_TYPE_MAX];
    //224 bytes above here

    u32 epoch_ind_tsdb[ZBAR_EPOCH_TSDB_SIZE];

    //continuously store last per sec values
    /*3 * 30 * 4 = 360 bytes*/
    u32 ind_tsdb[ZBAR_MON_TYPE_MAX][ZBAR_NORMAL_TSDB_SIZE];

    struct two src_bucket_info_ind[ZBAR_MON_TYPE_MAX];

    int *src_qtr_list_ind_ptr[ZBAR_MON_TYPE_MAX];


    int *zbar_dst_next;

    //glid set
    u64 ind_threshold_computed[ZBAR_MON_TYPE_MAX];

 /*   u64 traffic_start_jiffies;
    u64 phase_start_jiffies;
    u64 idx_start_jiffies;
    u64 bad_source_threshold_value;

    u32 truple_count;
    u32 phase;
    u8 epoch_tsdb_idx;*/
};

struct nf9_hdr {
    u16 version;
    u16 rec_count;
    u32 sys_uptime_ms; /* time in msec since system boot */
    u32 export_time; /* Time in seconds since 0000 UTC 1970 */
    u32 sequence;
    u32 source_id;
} __attribute__((packed));

void func(int a){
    printf("Value of a in int = %d\n",a);
}

void func2(float a){
    printf("Value of a in float = %f\n",a);
}

struct person_info{
    char *name;
    int age;
};

void asm_cm_get_topn_lineage_from_obj_class(char *template_object_name, char *output){
    char *end = strstr(template_object_name, "-topn");
    printf("end string = %s diff = %d\n",end, end-template_object_name);
    strncpy(output, template_object_name+5, end-template_object_name-5);
    for(int i = 0; i < strlen(output); i++){
        if(output[i]=='_'){
            output[i] = '.';
        }
    }
    printf("--%s\n--",output);
    return;
}

int main(){
    int global_arr[N][N];
    int i = 0;
    int j = 0;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            global_arr[j][i]++;
        }
    }
    printf("sizeof = %d\n", sizeof(struct one));
    return 0;
}
