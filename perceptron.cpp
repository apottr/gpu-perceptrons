#include <iostream>
#include <iomanip>
#include <vector>

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))
#define UNIT_STEP(input) ((input < 0.0) ? (0.0) : (1.0))

int render(float *input,int length=0){
	if(length != 0){
		for(var i = 0; i<length; i++){
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(input);
		}
		std::cout << "\n";
	}else{
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(input) << "\n";
	}
	return 0;
}

float dot(float *a, float *b, int n){
	float out = 0.0;
	for(int i = 0; i<n; i++){
		out += a[i] * b[i];
	}
	return out;
}

float array_adjust(float *weights, int length, float *adjustment, int adj_length=0){
	if(adj_length != 0){
		for(int j = 0; j < adj_length; j++){
			for(int i = 0; i < length; i++){
				weights[i] += adjustment[j];
			}
		}
}

float perceptron(float (*trainingdata)[2][3], float *weights, int generations, int input_length, int training_length){
	//const int i = threadIdx.x;
	float output = 0.0;
	float eta = 0.2;

	for(int j = 0; j < generations; j++){
		float result = dot(trainingdata[0][0],weights,input_length);
		render(result);
		if(UNIT_STEP(result) != trainingdata[0][1]){
			array_adjust(weights,3,(() * -1.0))
		}else{
			array_adjust(weights,3,())
		}
		output += result;
	}
	return output;
}

float test_perceptron(float *weights, float **testingdata, int length, int w_length){
	for(int i = 0; i<length; i++){
		float result = dot(testingdata[i],weights,w_length);
		render(testing_data[i],w_length);
		render(result);
	}
}

int main(){
	float training_data[4][2][3] = {
		{{1.0,0.0,1.0},0.0},
		{{1.0,1.0,1.0},1.0},
		{{0.0,1.0,1.0},0.0},
		{{0.0,0.0,1.0},0.0}
	};
	float testing_data[][] = {
		{1.0,0.0,1.0},
		{0.0,0.0,1.0},
		{1.0,1.0,1.0},
		{0.0,1.0,1.0}
	};
	float weights[] = {0.0,0.0,0.0};
	perceptron(training_data,weights,1,ARRAY_SIZE(weights),ARRAY_SIZE(training_data));
	test_perceptron(weights,testing_data,4);
	return 0;
}