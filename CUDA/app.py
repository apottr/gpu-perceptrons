import pycuda.autoinit
import pycuda.driver as drv
import numpy

from pycuda.compiler import SourceModule

mod = SourceModule(open("perceptron.cu").read())

supervised_set = [
	[array([0,0,1]),1],
	[array([0,1,1]),0],
	[array([1,0,1]),0],
	[array([1,1,1]),1]
]

perceptron = mod.get_function("perceptron")

weights = numpy.random.randn(3).astype(numpy.float32)

end_weights = numpy.zeros_like(weights)

perceptron()