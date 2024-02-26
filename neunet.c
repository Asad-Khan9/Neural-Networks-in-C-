#define NEUNET_IMPLEMENTATION
#include "neunet.h"
#include <time.h>

typedef struct {
    Mat a0; 
    Mat w1, b1, a1;
    Mat w2, b2, a2;
} Xor;

float cost(Xor m, Mat ti, Mat to){
    assert(ti.rows == to.rows);
    size_t n = ti.rows;
    for(size_t i = 0; i < n; ++i){

    }

}

float forward_xor(Xor m){

    // mat_dot(m.a1, m.a0, m.w1);
    mat_sum(m.a1, m.b1);
    mat_sig(m.a1);
    
    mat_dot(m.a2, m.a1, m.w2);
    mat_sum(m.a2, m.b2);
    mat_sig(m.a2);

    return *m.a1.es;
}

int main(void){
    srand(time(0)); 

    Xor m;

    m.a0  = mat_alloc(1,2);
    
    m.w1 = mat_alloc(2,2);
    m.b1 = mat_alloc(1,2);
    m.a1 = mat_alloc(1,2);

    m.w2 = mat_alloc(2,1);
    m.b2 = mat_alloc(1, 1);
    m.a2 = mat_alloc(1,1); 

    mat_rand(m.w1, 0, 1);
    mat_rand(m.b1, 0, 1);
    mat_rand(m.w2, 0, 1);
    mat_rand(m.b2, 0, 1);

for(size_t i = 0; i < 2; ++i){
    for(size_t j = 0; j < 2; ++j){
            
        MAT_AT(m.a0, 0, 0) = i;
        MAT_AT(m.a0, 0, 1) = j;
        forward_xor(m);
        float y = *m.a2.es;
        printf("%zu ^ %zu = %f\n", i, j, y);

    }
}

    return 0;
}
          