#include <Python.h>
#include <object.h>
#include <listobject.h>
#include <bytesobject.h>

/**
 * print_python_list - Function prints basic info about Python lists.
 * @p: A pointer to a Python object (expected to be a PyListObject).
 */
void print_python_list(PyObject *p)
{
    long int size = PyList_Size(p);
    int alloc = ((PyListObject *)p)->allocated;
    int i;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %d\n", alloc);

    for (i = 0; i < size; i++)
    {
        printf("Element %d: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
    }
}

/**
 * print_python_bytes - Prints basic info about Python bytes objects.
 * @p: A pointer to a Python object (expected to be a PyBytesObject).
 */
void print_python_bytes(PyObject *p)
{
    char *trying_str;
    long int size;
    int i;

    printf("[.] bytes object info\n");

    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    printf("  size: %ld\n", size);

    trying_str = (char *)PyBytes_AsString(p);
    printf("  trying string: %s\n", trying_str);

    printf("  first %ld bytes:", (size < 10) ? size + 1 : 10);
    for (i = 0; i < ((size < 10) ? size : 10); i++)
        printf(" %02hhx", (unsigned char)trying_str[i]);

    printf("\n");
}
