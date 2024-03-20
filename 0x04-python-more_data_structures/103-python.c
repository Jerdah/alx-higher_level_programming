#include <Python.h>
#include <object.h>
#include <listobject.h>
#include <bytesobject.h>

/* Forward declaration */
void print_python_bytes(PyObject *p);

/**
 * print_python_list - Prints basic info about Python lists
 * @p: PyObject pointer to the Python list
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t size, allocated, i;
	PyObject *item;
	const char *type;

	printf("[*] Python list info\n");

	if (!PyList_Check(p))
	{
		printf("  [ERROR] Invalid List Object\n");
		return;
	}

	size = PyList_Size(p);
	allocated = ((PyListObject *)p)->allocated;
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", allocated);

	for (i = 0; i < size; i++)
	{
		item = PyList_GetItem(p, i);
		type = (item->ob_type)->tp_name;
		printf("Element %ld: %s\n", i, type);
		if (PyBytes_Check(item))
			print_python_bytes(item);
	}
}

/**
 * print_python_bytes - Prints basic info about Python bytes objects
 * @p: PyObject pointer to the Python bytes object
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, i;
	char *str;

	printf("[.] bytes object info\n");

	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	PyBytes_AsStringAndSize(p, &str, &size);
	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", str);

	if (size < 10)
		printf("  first %ld bytes: ", size + 1);
	else
		printf("  first 10 bytes: ");

	for (i = 0; i < (size < 10 ? size : 10); i++)
		printf("%02x ", (unsigned char)str[i]);

	printf("\n");
}
