// How C Extensions Work:
// PyInit_ModName passes mod_struct which references method_list which has a tuple for each function (which includes a pointer to the function itself)
// Here we have the 'SimpleMath' module which has two functions: addition & subtraction

#include <Python.h>

static PyObject *addition(PyObject *self, PyObject *args) {
    int num1 = 0;
    int num2 = 0;
    int bytes_copied = -1;

    if(!PyArg_ParseTuple(args, "ii", &num1, &num2)) {
        return NULL;
    }
    int sum = num1 + num2;
    return PyLong_FromLong(sum);
}

static PyObject *subtraction(PyObject *self, PyObject *args) {
    int num1 = 0;
    int num2 = 0;
    int bytes_copied = -1;

    if(!PyArg_ParseTuple(args, "ii", &num1, &num2)) {
        return NULL;
    }
    int difference = num1 - num2;
    return PyLong_FromLong(difference);
}

static PyMethodDef math_methods[] = {
    {"addition", addition, METH_VARARGS, "Simple integer addition"},
    {"subtraction", subtraction, METH_VARARGS, "Simple integer subtraction"},
};

static struct PyModuleDef math_module = {
    PyModuleDef_HEAD_INIT,
    "Math",
    "Some simple math functions",
    -1,
    math_methods
};

PyMODINIT_FUNC PyInit_SimpleMath(void) {
    return PyModule_Create(&math_module);
}