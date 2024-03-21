#include <Python.h>
#include <object.h>
#include <bytesobject.h>
#include <listobject.h>
#include <stdio.h>

/**
 * print_python_bytes - Prints information about a Python bytes object
 * @p: Pointer to the Python bytes object
 */
void print_python_bytes(PyObject *p);

/**
 * print_python_list - Prints information about a Python list object
 * @p: Pointer to the Python list object
 */
void print_python_list(PyObject *p)
{
    Py_ssize_t size, allocated, i;
    PyObject *item;

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
        item = PyList_GET_ITEM(p, i);
        printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);

        if (PyBytes_Check(item))
            print_python_bytes(item);
    }
}

/**
 * print_python_bytes - Prints information about a Python bytes object
 * @p: Pointer to the Python bytes object
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

    printf("  first %ld bytes: ", (size < 10) ? size + 1 : 10);
    for (i = 0; i < ((size < 10) ? size : 10); i++)
        printf("%02x ", (unsigned char)str[i]);
    printf("\n");
}
