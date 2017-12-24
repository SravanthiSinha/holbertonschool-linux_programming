#include <Python.h>
#include <stdio.h>
#include <string.h>

#define DOUBLE(op) (((PyFloatObject *)(op))->ob_fval)
void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);
void print_python_float(PyObject *p);

/**
 * print_python_float - print some basic info about Python FLoat objects
 * @p: python object
 * Return: nothing
 **/
void print_python_float(PyObject *p)
{
	char *float_str;

	printf("[.] float object info\n");
	if (!PyFloat_Check(p))
		printf("  [ERROR] Invalid Float Object\n");
	else
	{
		float_str = PyOS_double_to_string(DOUBLE(p),
						  'r', 0, Py_DTSF_ADD_DOT_0, NULL);
		if (!float_str)
			printf("  value: %.16G\n", DOUBLE(p));
		else
		{
			printf("  value: %s\n", float_str);
			PyMem_Free(float_str);
		}
	}
	fflush(stdout);
}

/**
 * print_string - prints characters of a string if its ascii else prints as '?'
 * @s: string to be printed
 * Return: nothing
 **/
void print_string(char *s)
{
	size_t i;

	i = 0;
	while (s && s[i] != '\0')
	{
		if (isascii(s[i]))
		{
			putchar(s[i]);
		} else
		{
			putchar('?');
		}
		i++;
	}
}

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
		printf("  trying string: ");
		print_string(s);
		putchar('\n');
		if (l >= 10)
			l = 10;
		else
			l++;
		printf("  first %lu bytes: ", l);
		for (i = 0; i < l; i++)
		{
			printf("%02x", s[i] & 0xff);
			if (i + 1 < l)
				putchar(' ');
		}
		putchar('\n');
	}
	fflush(stdout);
}

/**
 * print_python_list - print some basic info about Python lists
 * @p: python object
 **/
void print_python_list(PyObject *p)
{
	Py_ssize_t listsize, i;
	PyObject *item;

	if (!PyList_Check(p))
		printf("  [ERROR] Invalid List Object\n");
	else
	{
		printf("[*] Python list info\n");
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
			else if (strcmp(item->ob_type->tp_name, "float") == 0)
				print_python_float(item);
		}
	}
	fflush(stdout);
}
