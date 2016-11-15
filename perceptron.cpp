#include <iostream>
#include <iomanip>
#include <cstdlib>

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))
#define UNIT_STEP(input) ((input < 0.0) ? (0.0) : (1.0))

void render_array(double *input,int length){
	for(int i = 0; i<length; i++){
		std::cout << std::fixed << std::setprecision(1) << input[i] << ", ";
	}
	std::cout << "\n";
}

void render_double(double input){
	std::cout << std::fixed << std::setprecision(1) << input << "\n";
}

double dot(double *a, double *b, int n){
	double out = 0.0;
	for(int i = 0; i<n; i++){
		out += a[i] * b[i];
	}
	return out;
}

void weights_adjust(double *weights, int length, double *adjustment, double eta, int toggle_sign=0){
	for(int i = 0; i < length; i++){
		if(toggle_sign == 0){
			weights[i] += adjustment[i] * eta;
		}else{
			weights[i] -= adjustment[i] * eta;
		}
	}
}

void perceptron(double (*trainingdata)[2][3], double *weights, int generations, int input_length, int training_length){
	//const int i = threadIdx.x;
	double eta = 0.2;

	for(int j = 0; j < generations; j++){
		int term = 0 + (std::rand() % (int)(training_length - 1));
		double result = dot(trainingdata[term][0],weights,input_length);

		if(UNIT_STEP(result) != *trainingdata[term][1]){
			weights_adjust(weights,3,trainingdata[term][0],eta,1); //second step: training data
		}else{
			weights_adjust(weights,3,trainingdata[term][0],eta); //second step: training data
		}
	}
}

void test_perceptron(double *weights, double (testingdata)[][3], int length, int w_length){
	render_array(weights,3);
	for(int i = 0; i<length; i++){
		double result = dot(testingdata[i],weights,w_length);
		render_array(testingdata[i],w_length);
		render_double(result);
		render_double(UNIT_STEP(result));
	}
}

int main(){
	double training_data[4][2][3] = {
		{{1.0,0.0,1.0},0.0},
		{{1.0,1.0,1.0},1.0},
		{{0.0,1.0,1.0},0.0},
		{{0.0,0.0,1.0},0.0}
	};
	double testing_data[4][3] = {
		{1.0,0.0,1.0},
		{0.0,0.0,1.0},
		{1.0,1.0,1.0},
		{0.0,1.0,1.0}
	};
	double weights[] = {0.0,0.0,0.0};
	render_array(training_data[0][0],3);
	render_array(training_data[1][0],3);
	render_array(training_data[2][0],3);
	render_array(training_data[3][0],3);
	std::cout << "\n";
	perceptron(training_data,weights,100,ARRAY_SIZE(weights),ARRAY_SIZE(training_data));
	test_perceptron(weights,testing_data,4,3);
	std::cout << "\n"; 
	render_array(testing_data[0],3);
	render_array(testing_data[1],3);
	render_array(testing_data[2],3);
	render_array(testing_data[3],3);
	return 0;
}