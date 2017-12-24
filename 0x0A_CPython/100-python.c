#include <Python.h>
#include <stdio.h>
#include <wchar.h>

/**
 * print_python_int - prints Python Integers.
 * @p: python object
 * Return: nothing
 **/
void print_python_int(PyObject *p) {
  PyTypeObject *type;
  PyObject *str_repr;
  PyObject *pStr;

  type = p->ob_type;
  if (strcmp(type->tp_name, "int") != 0) {
    printf("  [ERROR] Invalid Int Object\n");
    return;
  }
  str_repr = PyObject_Repr(p);
  pStr = PyUnicode_AsEncodedString(str_repr, "utf-8", "Error ~");
  puts(((PyBytesObject *)pStr)->ob_sval);
}
