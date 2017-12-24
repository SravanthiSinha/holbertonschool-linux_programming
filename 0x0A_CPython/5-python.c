#include <Python.h>
#include <limits.h>
#include <stdio.h>
#include <wchar.h>

/**
 * print_python_int - prints Python Integers.
 * @p: python object
 * Return: clongthing
 **/

void print_python_int(PyObject *p)
{
  PyLongObject *lng;
  PyVarObject *var;
  unsigned long clong, prev;
  long i, size;
  int neg = 0;

  if (!PyLong_Check(p))
  {
    puts("Invalid Int Object");
    return;
  }
  lng = (PyLongObject *)p;
  var = (PyVarObject *)p;
  clong = 0;
  size = var->ob_size;
  if (size < 0)
  {
    size *= -1;
    neg = 1;
  }
  for (i = size - 1; i >= 0; i--)
  {
    prev = clong;
    clong =
        (clong >> (8 * sizeof(long) - PyLong_SHIFT)) | (clong << PyLong_SHIFT);
    clong += (lng->ob_digit[i]);
    if (prev >= clong)
    {
      puts("C unsigned long int overflow");
      return;
    }
  }
  if (neg)
    printf("-");
  printf("%lu\n", clong);
  fflush(stdout);
}
