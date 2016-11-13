__global__ void perceptron(float *trainingdata, float *weights, int *n){
	const int i = threadIdx.x;
	for(int j = 0; j < n; j++){
		float result = dot(trainingdata[i][0],weights)
	}
}

__device__ float dot(float *a, float *b, int *n){
	float out = 0.0;
	for(int i = 0; i<n; i++){
		out += a[i] * b[i];
	}
	return out;
}