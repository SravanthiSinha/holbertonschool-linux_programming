#include <Python.h>
#include <stdio.h>

/**
* print_python_list - print some basic info about Python lists
* @p: python object
**/
void print_python_list(PyObject *p)
{
	Py_ssize_t listsize, i;
	PyObject *item;

	printf("[*] Python list info\n");
	if (!PyList_Check(p))
		printf("Invalid List Object\n");
	else
	{
		listsize = ((PyVarObject *) p)->ob_size;
		printf("[*] Size of the Python List = %lu\n", listsize);
		printf("[*] Allocated = %lu\n",
		       ((PyListObject *) p)->allocated);
		for (i = 0; i < listsize; i++)
		{
			item = ((PyListObject *) p)->ob_item[i];
			printf("Element %lu: %s\n", i, item->ob_type->tp_name);
		}
	}
}
