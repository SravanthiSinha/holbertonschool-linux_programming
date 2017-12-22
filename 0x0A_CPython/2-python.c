#include <Python.h>
#include <stdio.h>
#include <string.h>

void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);

/**
* print_python_bytes - print some basic info about Python bytes objects
* @p: python object
* Return: nothing
**/
void print_python_bytes(PyObject *p)
{
	char *s;
	Py_ssize_t l, i;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
		printf("  [ERROR] Invalid Bytes Object\n");
	else
	{
		l = ((PyVarObject *) p)->ob_size;
		printf("  size: %lu\n", l);
		s = ((PyBytesObject *) p)->ob_sval;
		printf("  trying string: %s\n", s);
		if (l > 10)
			l = 10;
		else
			l++;
		printf("  first %lu bytes: ", l);
		for (i = 0; i < l - 1; i++)
			printf("%02x ", s[i] & 0xff);
		printf("%02x\n", s[l - 1] & 0xff);
	}
}

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
		printf("  [ERROR] Invalid List Object\n");
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
			if (strcmp(item->ob_type->tp_name, "bytes") == 0)
				print_python_bytes(item);
		}
	}
}
