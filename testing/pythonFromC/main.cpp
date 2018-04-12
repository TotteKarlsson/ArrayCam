
#include <Python.h>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


int main()
{
    char* myPath = "C:\\\\pDisk\\\\ArrayCam\\\\testing\\\\pythonFromC\\\\scripts";

    PyObject *pName, *pModule, *pDict, *pFunc;
    PyObject *pArgs, *pValue;

    string moduleName("pure_embedding");
    string functionName("execute");

    vector<string> args;
    args.push_back("2");
    args.push_back("45");

    Py_Initialize();

	PyRun_SimpleString("import sys");
    stringstream cmd;
    cmd << "sys.path.append(\"" << myPath << "\")";

	PyRun_SimpleString(cmd.str().c_str());

	Py_SetProgramName(Py_DecodeLocale("TjolaHey", NULL));
    PyRun_SimpleString("print (sys.path)");
    pName = PyUnicode_DecodeFSDefault(moduleName.c_str());

    /* Error checking of pName left out */
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (!pModule)
    {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", moduleName.c_str());
        return 1;
    }

    pFunc = PyObject_GetAttrString(pModule, functionName.c_str());

    /* pFunc is a new reference */
    if (pFunc && PyCallable_Check(pFunc))
    {
        pArgs = PyTuple_New(args.size());
        for (int i = 0; i < args.size(); ++i)
        {
            pValue = PyLong_FromLong(atoi(args[i].c_str()));
            if (!pValue)
            {
                Py_DECREF(pArgs);
                Py_DECREF(pModule);
                fprintf(stderr, "Cannot convert argument\n");
                return 1;
            }

            /* pValue reference stolen here: */
            PyTuple_SetItem(pArgs, i, pValue);
        }

        pValue = PyObject_CallObject(pFunc, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL)
        {
            printf("Result of call: %ld\n", PyLong_AsLong(pValue));
            Py_DECREF(pValue);
        }
        else
        {
            Py_DECREF(pFunc);
            Py_DECREF(pModule);
            PyErr_Print();
            fprintf(stderr,"Call failed\n");
            return 1;
        }
    }
    else
    {
        if (PyErr_Occurred())
        {
            PyErr_Print();
        }
        fprintf(stderr, "Cannot find function \"%s\"\n", functionName);
    }
    Py_XDECREF(pFunc);
    Py_DECREF(pModule);
    Py_Finalize();

    return 0;
}
