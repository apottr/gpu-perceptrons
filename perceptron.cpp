#include <iostream>
#include <iomanip>
using namespace std;

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

float dot(float *a, float *b, size_t n);
float perceptron(float *trainingdata, float *weights, int n);
int render(float input);

int main(){
	float test_one[] = {2.0,2.0,2.0,2.0};
	float test_two[] = {1.0,1.0,1.0,1.0};
	render(dot(test_one,test_two,ARRAY_SIZE(test_one)));
	return 0;
}

int render(float input){
	cout << std::fixed << std::setprecision(1) << input << "\n";
	return 0;
}

float dot(float *a, float *b, size_t n){
	float out = 0.0;
	for(int i = 0; i<n; i++){
		out += a[i] * b[i];
	}
	return out;
}

float perceptron(float *trainingdata, float *weights, int generations){
	//const int i = threadIdx.x;
	size_t arr_length = ARRAY_SIZE(trainingdata);
	float output = 0.0;
	for(int j = 0; j < generations; j++){
		float result = dot(trainingdata,weights,arr_length);
		output += result;
	}
	return output;
}
