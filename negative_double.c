#include <stdio.h>
#define ACOS_TSDB_MAX (5)

int main(){

    double run_agg_dval = 2.245714e+01;
    double current_window_aggregate = 0.000000e+00;
    double mt_prev_dval = 1.122857e+02;
    double up_to_10_precision = 1e-10;

    double intermediate_value = (run_agg_dval * ACOS_TSDB_MAX);

    printf("%.20f\n",intermediate_value);
    printf("%.20f\n",mt_prev_dval);
    printf("size of float = %d\n",sizeof(float));
    printf("size of double = %d\n",sizeof(double));


    double aggregate_update = ((run_agg_dval * ACOS_TSDB_MAX) + current_window_aggregate - mt_prev_dval)/ACOS_TSDB_MAX;
    aggregate_update*=-1;
    float temp_value = aggregate_update;

    printf("temp_value  = %e\n", temp_value);
    printf("aggregate_update  = %e\n", aggregate_update);

    if(aggregate_update < 0 ||aggregate_update < up_to_10_precision){
        printf("reseted here...\n");
        aggregate_update = 0.000000e+00;
    }


    printf("aggregate_update  = %e\n", aggregate_update);

    return 0;
}
