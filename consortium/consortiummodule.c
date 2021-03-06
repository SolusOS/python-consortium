/* -*- Mode: C; c-basic-offset: 4 -*- */
#include <Python.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* include this first, before NO_IMPORT_PYGOBJECT is defined */
#include <pygobject.h>

#include <pygtk/pygtk.h>

void pyconsortium_register_classes(PyObject *d);
void pyconsortium_add_constants(PyObject *module, const gchar *strip_prefix);
extern PyMethodDef pyconsortium_functions[];

DL_EXPORT(void)
initconsortium (void)
{
	PyObject *m, *d;

	init_pygobject();
	init_pygtk ();

	m = Py_InitModule ("consortium", pyconsortium_functions);
	d = PyModule_GetDict (m);

	pyconsortium_register_classes (d);
        pyconsortium_add_constants(m, "META_");
}
