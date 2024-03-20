#include <Python.h>

/**
 * print_python_list - Function prints basic info about Python lists.
 * @p: pointer to a Python object
 */
void print_python_list(PyObject *p)
{
	long int size = PyList_Size(p);
	long int alloc = ((PyListObject *)p)->allocated;
	int i;

	printf("[*] Python list info\n");
	printf("[*] Size of Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", alloc);

	for (i = 0; i < size; i++)
	{
		printf("Element %d: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
	}
}

/**
 * print_python_bytes - Function prints basic info about Python bytes objects.
 * @p: pointer to a Python object
 */
void print_python_bytes(PyObject *p)
{
	long int size;
	int i;
	char *trying_str = NULL;

	printf("[.] bytes object info\n");

	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	size = PyBytes_Size(p);
	trying_str = PyBytes_AsString(p);

	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", trying_str);
	printf("  first %ld bytes: ", size + 1 < 10 ? size + 1 : 10);

	for (i = 0; i < size + 1 && i < 10; i++)
	{
		printf("%02hhx%s", trying_str[i],
				i + 1 < size + 1 && i + 1 < 10 ? " " : "\n");
	}

	if (i < 10)
	{
		printf("\n");
	}
}
