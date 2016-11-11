import pycuda.autoinit
import pycuda.driver as drv
import numpy

from pycuda.compiler import SourceModule

mod = SourceModule(file here)

supervised_set = [
	[array([0,0,1]),1],
	[array([0,1,1]),0],
	[array([1,0,1]),0],
	[array([1,1,1]),1]
]

train = mod.get_function("train")

weights = numpy.random.randn(400).astype(numpy.float32)

