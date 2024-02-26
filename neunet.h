#ifndef NEUNET_H_
#define NEUNET_H_
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <math.h>
#ifndef NEUNET_MALLOC
#include <stdlib.h>
#define NEUNET_MALLOC malloc 
#endif //NEUNET_MALLOC


#ifndef NEUNET_ASSERT
#include <assert.h>
#define NEUNET_ASSERT assert
#endif //NEUNET_ ASSERT

#define MAT_PRINT(m) mat_print(m, #m)

typedef struct{
    size_t rows;
    size_t cols;
    float *es;
} Mat;

#define MAT_AT(m, i, j) m.es[(i)*(m).cols + (j)]

Mat mat_alloc(size_t rows, size_t cols);
float rand_float();
void mat_rand(Mat m, float low, float high);
void mat_dot(Mat dst, Mat a, Mat b);
void mat_sum(Mat dst, Mat a);
void mat_print(Mat m, const char *name);
void mat_fill(Mat m, float x);
void mat_sig(Mat m);
float sigmoidf(float x);
#endif // NEUNET_H_

#ifdef NEUNET_IMPLEMENTATION

float sigmoidf(float x){
    return (1.f/1.f + expf(-x));
}


float rand_float(){
    return (float) rand() / (float) RAND_MAX;  
}

void mat_sig(Mat m){
      for(size_t i = 0; i <= m.rows; ++i){
        for(size_t j = 0; j <= m.cols; ++j){
            MAT_AT(m,i,j) = sigmoidf(MAT_AT(m,i,j));
        }
      }
}


Mat mat_alloc(size_t rows, size_t cols){
    Mat m;
    m.rows =  rows;
    m.cols =  cols;
    m.es = malloc(sizeof(*m.es)*rows*cols);
    NEUNET_ASSERT(m.es != NULL);
    memset(m.es, 0, sizeof(*m.es) * rows * cols);
    return m;
}

// [ 
//   1   2         3
//                 4
// ]
// 1x2 2x4
// 1x4

void mat_dot(Mat dst, Mat a, Mat b){
    NEUNET_ASSERT(a.cols == b.rows);
    size_t n = a.cols;
    NEUNET_ASSERT(dst.rows == a.rows);
    NEUNET_ASSERT(dst.cols == b.cols);
    for(size_t i = 0; i < dst.rows; ++i){
        for(size_t j = 0; j < a.cols; ++j){
            for(size_t k = 0; k < n; ++k){
                MAT_AT(dst, i, j) += MAT_AT(a, i, k) * MAT_AT(b, k, j);  //1 09
            }
        }

    }
}
void mat_sum(Mat dst, Mat a){
    NEUNET_ASSERT(dst.rows == a.rows);
    NEUNET_ASSERT(dst.cols == a.cols);
    for(size_t i = 0; i < dst.rows; ++i){
        for(size_t j = 0; j < a.cols; ++j){
            MAT_AT(dst,i, j) += MAT_AT(a, i, j);
        }
      
    }
}
//rows = 3
//cols = 4

//* * * *
//* * * *
//* * * *
void mat_print(Mat m, const char *name){

    printf("%s = [\n", name);
    for(size_t i = 0; i < m.rows; ++i){
        for(size_t j = 0; j < m.cols; ++j){
            printf("    %f", MAT_AT(m, i, j));
        }
        printf("\n"); 
    }
    printf("]\n"); 
    
    // (void) m;
}
void mat_rand(Mat m, float low, float high){
    for(size_t i = 0; i < m.rows; ++i){
        for(size_t j = 0; j < m.cols; ++j){
            MAT_AT(m,i,j) = rand_float() * (high-low) + low;   
        }   
    }

}

void mat_fill(Mat m, float x){
    for(size_t i = 0; i < m.rows; ++i){
        for(size_t j = 0; j < m.cols; ++j){
            MAT_AT(m,i,j) = x;   
        }   
    }
    
}
#endif //NEUNET_IMPLEMENTATION

