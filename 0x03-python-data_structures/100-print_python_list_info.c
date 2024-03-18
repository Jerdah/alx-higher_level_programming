#include <Python.h>
#include <object.h>
#include <listobject.h>

/**
 * print_python_list_info - function prints basic info about a Python lists
 * @p: Pointer to the Python list object
 */
void print_python_list_info(PyObject *p)
{
    long int size = PyList_Size(p);
    int alloc = ((PyListObject *)p)->allocated;
    int i;

    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %d\n", alloc);

    for (i = 0; i < size; i++)
    {
        printf("Element %d: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
    }
}
