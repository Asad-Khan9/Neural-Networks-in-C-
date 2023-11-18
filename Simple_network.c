#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8}
};
#define train_count sizeof(train) / sizeof(train[0])
    // y = x*w
float rand_float(){ // to retrieve random values for weights and biases 
    return (float) rand()/ (float) RAND_MAX;
}
float cost(float w, float b){
    float result = 0.0f;
    for(size_t i = 0; i < train_count; ++i){
        float x = train[i][0];
        float y = x*w + b;
        float d = y - train[i][1]; // distance between the actual value and the predicted 
        result += d*d;
        //printf("actual %f, expected %f\n", y, train[i][1]); 
    }
    result /= train_count;
    return result;
}
int main(){
    srand(25);
    float result = 0;
    float w = rand_float()*10.0f;
    float b = rand_float()*5.0f;
    // float w = 1;

    float eps = 1e-3;
    float rate = 1e-3;

    printf("%f\n", cost(w, b));
    for (size_t i = 0; i < 10000; ++i){
        float c = cost(w, b);
        // gradient descent 
        float dw = (cost(w+eps, b) - c)/eps; //with respect to weights
        float db = (cost(w, b+eps) - c)/eps; // with respect to bias 
        w-= rate*dw;  // updating the weights after descent 
        b -= rate*db; // updating the biases after descent 

        
        if(i%50 == 0){  // printing the outputs at every 50th iteration
            printf("\ncost = %f, w = %f, b = %f \n", cost(w, b), w, b); 
        }
    }
    // final result 
    printf("-------------------------------");
    printf("\n%f, %f", w, b);
    return 0;
 }

