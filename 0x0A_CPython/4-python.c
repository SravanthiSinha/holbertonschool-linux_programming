#include <Python.h>
#include <wchar.h>
#include <stdio.h>

/**
* print_python_string - prints Python strings.
* @p: python object
* Return: nothing
**/
void print_python_string(PyObject *p)
{
	PyTypeObject *type;
	PyASCIIObject *ascii_obj;
	unsigned long len;
	void *str;
	char *strtype;
	unsigned int i;
	unsigned short *wstring;
	unsigned char *wchar;

	printf("[.] string object info\n");
	type = p->ob_type;
	if (strcmp(type->tp_name, "str") != 0)
	{
		printf("  [ERROR] Invalid String Object\n");
		return;
	}

	len = ((PyVarObject *) p)->ob_size;
	ascii_obj = (PyASCIIObject *) p;
	if (((ascii_obj->state).compact == 1) && ((ascii_obj->state).ascii == 1)
	    && ((ascii_obj->state).ready == 1))
		strtype = "compact ascii";
	if (((ascii_obj->state).compact == 1) && ((ascii_obj->state).ascii == 0)
	    && ((ascii_obj->state).ready == 1))
		strtype = "compact unicode object";
	printf("  type: %s\n", strtype);
	printf("  length: %lu\n", len);
	if (strcmp("compact ascii", strtype) == 0)
	{
		str = (ascii_obj) + 1;
		printf("  value: %s\n", (char *)str);
	}
	if (strcmp("compact unicode object", strtype) == 0)
	{
		if ((ascii_obj->state).kind == 2)
			wstring =
			    ((unsigned short *)((PyCompactUnicodeObject *) (p) +
						1));
		if ((ascii_obj->state).kind == 1)
			wchar =
			    ((unsigned char *)((PyCompactUnicodeObject *) (p) +
					       1));
		printf("  value: ");
		for (i = 0; i < len; i++)
		{
			if ((ascii_obj->state).kind == 2)
				printf("%lc", wstring[i]);
			else if ((ascii_obj->state).kind == 1)
				printf("%lc", wchar[i]);
		}
		printf("\n");
	}
}
