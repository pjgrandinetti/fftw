//
//  main.c
//  testfftw
//
//  Created by Philip Grandinetti on 3/28/21.
//

#include <stdio.h>
#include <fftw/fftw3.h>

int main(int argc, const char * argv[]) {
    int length = 1024;
    int dft_direction = FFTW_FORWARD;

//    fftwf_plan floatPlan = NULL;
//    fftwf_complex *floatArray = NULL;
//    if(floatArray == NULL) floatArray = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * length);
//    if(floatPlan == NULL) floatPlan = fftwf_plan_dft_1d((int) length, floatArray, floatArray, dft_direction, FFTW_ESTIMATE);
//    fftwf_execute(floatPlan);
//    if(floatPlan) fftwf_destroy_plan(floatPlan);

    fftw_plan plan = NULL;
    fftw_complex *array = NULL;
    if(array == NULL) array = (fftw_complex*) fftw_malloc(sizeof(fftwf_complex) * length);
    if(plan == NULL) plan = fftw_plan_dft_1d((int) length, array, array, dft_direction, FFTW_ESTIMATE);
    fftw_execute(plan);
    if(plan) fftw_destroy_plan(plan);

    printf("Hello, World!\n");
    return 0;
}
