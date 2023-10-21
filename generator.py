import numpy as np
from random import seed
import copy, random
import time
import subprocess

types = ["insertionsort.cpp", "mergesort.cpp",
         "qsort.cpp", "nlognqsort.cpp",
         "heapsort.cpp", "stringsort.cpp",
         "stringbinsearchsort.cpp", "skiplistsort.cpp"]

def logging_time(original_fn):
    def wrapper_fn(*args, **kwargs):
        start_time = time.time()
        result = original_fn(*args, **kwargs)
        elapsed_time = (time.time() - start_time) * 1e3
        print("WorkingTime[{}]: {:.5f} ms".format(original_fn.__name__, elapsed_time))
        return result
    return wrapper_fn

@logging_time
def run_sort(command, input_data):
    subprocess.run(command, input=input_data, text=True, stdout=subprocess.PIPE, shell=True)

compile_command = f"g++ {types[0]} -o test"
subprocess.run(compile_command, shell=True)
exec_command  = ".\\test"
input_data = "3 10 9 8"
run_sort(exec_command, input_data)