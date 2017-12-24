import ctypes

lib = ctypes.CDLL('./libPython.so')
lib.print_python_int.argtypes = [ctypes.py_object]
i = -1
lib.print_python_int(i)
i = 0
lib.print_python_int(i)
i = 1
lib.print_python_int(i)
i = 123456789
lib.print_python_int(i)
i = -123456789
lib.print_python_int(i)
i = 12345678901
lib.print_python_int(i)
i = 10304719833506056896
lib.print_python_int(i)
i = -9223372036854775808
lib.print_python_int(i)
i = 9223372036854775807
lib.print_python_int(i)
i = 18446744073709551615
lib.print_python_int(i)
i = -18446744073709551615
lib.print_python_int(i)
i = 18446744073709551616
lib.print_python_int(i)
i = "1"
lib.print_python_int(i)
