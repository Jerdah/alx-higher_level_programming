#include <Python.h>
#include <stdio.h>

/**
 * print_python_bytes_info - Print information abut a Python bytes object
 * @p: Pointer to the Python bytes object
 */
void print_python_bytes_info(PyObject *p)
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

	printf("  trying string: ");
	int printable = 0;

	for (i = 0; i < size; i++)
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			printf("%c", str[i]);
			printable = 1;
		}

		else
		{
			printable = 0;
			break;
		}
	}
	if (!printable)
		printf("�");
	printf("\n");

	printf("  first %ld bytes:", (size + 1 < 10) ? size + 1 : 10);
	for (i = 0; i < ((size + 1 < 10) ? size + 1 : 10); i++)
	{
		if (i == size)
			printf(" 00");
		else
			printf(" %02x", (unsigned char)str[i]);
	}
	printf("\n");
}

/**
 * print_python_bytes - Print information about a Python bytes object
 * @p: Pointer to the Python bytes object
 */
void print_python_bytes(PyObject *p)
{
	print_python_bytes_info(p);
}

/**
 * print_python_list - Print information about a Python list object
 * @p: Pointer to the Python list object
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t size, i;
	PyObject *item;

	printf("[*] Python list info\n");

	size = PyList_Size(p);
	printf("[*] Size of the Python List = %ld\n", size);

	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < size; i++)
	{
		item = PyList_GetItem(p, i);
		printf("Element %ld: ", i);

		if (PyBytes_Check(item))
		{
			printf("bytes\n");
			print_python_bytes_info(item);
		}
		else if (PyFloat_Check(item))
			printf("float\n");
		else if (PyTuple_Check(item))
			printf("tuple\n");
		else if (PyList_Check(item))
			printf("list\n");
		else if (PyUnicode_Check(item))
			printf("str\n");
		else
			printf("%s\n", Py_TYPE(item)->tp_name);
	}
}
