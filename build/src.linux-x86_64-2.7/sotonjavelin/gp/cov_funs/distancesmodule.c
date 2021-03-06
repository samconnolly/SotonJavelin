/* File: distancesmodule.c
 * This file is auto-generated with f2py (version:2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * See http://cens.ioc.ee/projects/f2py2e/
 * Generation date: Fri Sep 12 15:46:45 2014
 * $Revision:$
 * $Date:$
 * Do not edit this file directly unless you know what you are doing!!!
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "Python.h"
#include <stdarg.h>
#include "fortranobject.h"
#include <math.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *distances_error;
static PyObject *distances_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
/*need_typedefs*/

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif

#define rank(var) var ## _Rank
#define shape(var,dim) var ## _Dims[dim]
#define old_rank(var) (((PyArrayObject *)(capi_ ## var ## _tmp))->nd)
#define old_shape(var,dim) (((PyArrayObject *)(capi_ ## var ## _tmp))->dimensions[dim])
#define fshape(var,dim) shape(var,rank(var)-dim-1)
#define len(var) shape(var,0)
#define flen(var) fshape(var,0)
#define old_size(var) PyArray_SIZE((PyArrayObject *)(capi_ ## var ## _tmp))
/* #define index(i) capi_i ## i */
#define slen(var) capi_ ## var ## _len
#define size(var, ...) f2py_size((PyArrayObject *)(capi_ ## var ## _tmp), ## __VA_ARGS__, -1)

#define CHECKSCALAR(check,tcheck,name,show,var)\
  if (!(check)) {\
    char errstring[256];\
    sprintf(errstring, "%s: "show, "("tcheck") failed for "name, var);\
    PyErr_SetString(distances_error,errstring);\
    /*goto capi_fail;*/\
  } else 
#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
  PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
  fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif

#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif


/************************ See f2py2e/cfuncs.py: cfuncs ************************/
int f2py_size(PyArrayObject* var, ...)
{
  npy_int sz = 0;
  npy_int dim;
  npy_int rank;
  va_list argp;
  va_start(argp, var);
  dim = va_arg(argp, npy_int);
  if (dim==-1)
    {
      sz = PyArray_SIZE(var);
    }
  else
    {
      rank = PyArray_NDIM(var);
      if (dim>=1 && dim<=rank)
        sz = PyArray_DIM(var, dim-1);
      else
        fprintf(stderr, "f2py_size: 2nd argument value=%d fails to satisfy 1<=value<=%d. Result will be 0.\n", dim, rank);
    }
  va_end(argp);
  return sz;
}

static int int_from_pyobj(int* v,PyObject *obj,const char *errmess) {
  PyObject* tmp = NULL;
  if (PyInt_Check(obj)) {
    *v = (int)PyInt_AS_LONG(obj);
    return 1;
  }
  tmp = PyNumber_Int(obj);
  if (tmp) {
    *v = PyInt_AS_LONG(tmp);
    Py_DECREF(tmp);
    return 1;
  }
  if (PyComplex_Check(obj))
    tmp = PyObject_GetAttrString(obj,"real");
  else if (PyString_Check(obj) || PyUnicode_Check(obj))
    /*pass*/;
  else if (PySequence_Check(obj))
    tmp = PySequence_GetItem(obj,0);
  if (tmp) {
    PyErr_Clear();
    if (int_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
    Py_DECREF(tmp);
  }
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = distances_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}

static int double_from_pyobj(double* v,PyObject *obj,const char *errmess) {
  PyObject* tmp = NULL;
  if (PyFloat_Check(obj)) {
#ifdef __sgi
    *v = PyFloat_AsDouble(obj);
#else
    *v = PyFloat_AS_DOUBLE(obj);
#endif
    return 1;
  }
  tmp = PyNumber_Float(obj);
  if (tmp) {
#ifdef __sgi
    *v = PyFloat_AsDouble(tmp);
#else
    *v = PyFloat_AS_DOUBLE(tmp);
#endif
    Py_DECREF(tmp);
    return 1;
  }
  if (PyComplex_Check(obj))
    tmp = PyObject_GetAttrString(obj,"real");
  else if (PyString_Check(obj) || PyUnicode_Check(obj))
    /*pass*/;
  else if (PySequence_Check(obj))
    tmp = PySequence_GetItem(obj,0);
  if (tmp) {
    PyErr_Clear();
    if (double_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
    Py_DECREF(tmp);
  }
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = distances_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC(euclidean,EUCLIDEAN)(double*,double*,double*,int*,int*,int*,int*,int*,int*,int*);
extern void F_FUNC(geographic,GEOGRAPHIC)(double*,double*,double*,int*,int*,int*,int*,int*);
extern void F_FUNC_US(paniso_geo_rad,PANISO_GEO_RAD)(double*,double*,double*,int*,int*,int*,int*,double*,double*,int*,int*);
extern void F_FUNC_US(aniso_geo_rad,ANISO_GEO_RAD)(double*,double*,double*,int*,int*,int*,int*,double*,double*,int*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/********************************* euclidean *********************************/
static char doc_f2py_rout_distances_euclidean[] = "\
Function signature:\n\
  euclidean(d,x,y,[cmin,cmax,symm])\n\
Required arguments:\n"
"  d :  rank-2 array('d') with bounds (nx,ny)\n"
"  x : input rank-2 array('d') with bounds (nx,ndx)\n"
"  y : input rank-2 array('d') with bounds (ny,ndy)\n"
"Optional arguments:\n"
"  cmin := 0 input int\n"
"  cmax := -1 input int\n"
"  symm := 0 input int";
/* extern void F_FUNC(euclidean,EUCLIDEAN)(double*,double*,double*,int*,int*,int*,int*,int*,int*,int*); */
static PyObject *f2py_rout_distances_euclidean(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(double*,double*,double*,int*,int*,int*,int*,int*,int*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  double *d = NULL;
  npy_intp d_Dims[2] = {-1, -1};
  const int d_Rank = 2;
  PyArrayObject *capi_d_tmp = NULL;
  int capi_d_intent = 0;
  PyObject *d_capi = Py_None;
  double *x = NULL;
  npy_intp x_Dims[2] = {-1, -1};
  const int x_Rank = 2;
  PyArrayObject *capi_x_tmp = NULL;
  int capi_x_intent = 0;
  PyObject *x_capi = Py_None;
  double *y = NULL;
  npy_intp y_Dims[2] = {-1, -1};
  const int y_Rank = 2;
  PyArrayObject *capi_y_tmp = NULL;
  int capi_y_intent = 0;
  PyObject *y_capi = Py_None;
  int nx = 0;
  int ny = 0;
  int ndx = 0;
  int ndy = 0;
  int cmin = 0;
  PyObject *cmin_capi = Py_None;
  int cmax = 0;
  PyObject *cmax_capi = Py_None;
  int symm = 0;
  PyObject *symm_capi = Py_None;
  static char *capi_kwlist[] = {"d","x","y","cmin","cmax","symm",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOO|OOO:distances.euclidean",\
    capi_kwlist,&d_capi,&x_capi,&y_capi,&cmin_capi,&cmax_capi,&symm_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable d */
  ;
  capi_d_intent |= F2PY_INTENT_INPLACE;
  capi_d_tmp = array_from_pyobj(PyArray_DOUBLE,d_Dims,d_Rank,capi_d_intent,d_capi);
  if (capi_d_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(distances_error,"failed in converting 1st argument `d' of distances.euclidean to C/Fortran array" );
  } else {
    d = (double *)(capi_d_tmp->data);

  /* Processing variable symm */
  if (symm_capi == Py_None) symm = 0; else
    symm = (int)PyObject_IsTrue(symm_capi);
    f2py_success = 1;
  if (f2py_success) {
  /* Processing variable cmax */
  if (cmax_capi == Py_None) cmax = -1; else
    f2py_success = int_from_pyobj(&cmax,cmax_capi,"distances.euclidean() 2nd keyword (cmax) can't be converted to int");
  if (f2py_success) {
  /* Processing variable cmin */
  if (cmin_capi == Py_None) cmin = 0; else
    f2py_success = int_from_pyobj(&cmin,cmin_capi,"distances.euclidean() 1st keyword (cmin) can't be converted to int");
  if (f2py_success) {
  /* Processing variable nx */
  nx = shape(d,0);
  CHECKSCALAR(shape(d,0)==nx,"shape(d,0)==nx","hidden nx","euclidean:nx=%d",nx) {
  /* Processing variable ny */
  ny = shape(d,1);
  CHECKSCALAR(shape(d,1)==ny,"shape(d,1)==ny","hidden ny","euclidean:ny=%d",ny) {
  /* Processing variable y */
  y_Dims[0]=ny;
  capi_y_intent |= F2PY_INTENT_IN;
  capi_y_tmp = array_from_pyobj(PyArray_DOUBLE,y_Dims,y_Rank,capi_y_intent,y_capi);
  if (capi_y_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(distances_error,"failed in converting 3rd argument `y' of distances.euclidean to C/Fortran array" );
  } else {
    y = (double *)(capi_y_tmp->data);

  /* Processing variable x */
  x_Dims[0]=nx;
  capi_x_intent |= F2PY_INTENT_IN;
  capi_x_tmp = array_from_pyobj(PyArray_DOUBLE,x_Dims,x_Rank,capi_x_intent,x_capi);
  if (capi_x_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(distances_error,"failed in converting 2nd argument `x' of distances.euclidean to C/Fortran array" );
  } else {
    x = (double *)(capi_x_tmp->data);

  /* Processing variable ndy */
  ndy = shape(y,1);
  CHECKSCALAR(shape(y,1)==ndy,"shape(y,1)==ndy","hidden ndy","euclidean:ndy=%d",ndy) {
  /* Processing variable ndx */
  ndx = shape(x,1);
  CHECKSCALAR(shape(x,1)==ndx,"shape(x,1)==ndx","hidden ndx","euclidean:ndx=%d",ndx) {
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
      Py_BEGIN_ALLOW_THREADS
        (*f2py_func)(d,x,y,&nx,&ny,&ndx,&ndy,&cmin,&cmax,&symm);
      Py_END_ALLOW_THREADS
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  } /*CHECKSCALAR(shape(x,1)==ndx)*/
  /* End of cleaning variable ndx */
  } /*CHECKSCALAR(shape(y,1)==ndy)*/
  /* End of cleaning variable ndy */
  if((PyObject *)capi_x_tmp!=x_capi) {
    Py_XDECREF(capi_x_tmp); }
  }  /*if (capi_x_tmp == NULL) ... else of x*/
  /* End of cleaning variable x */
  if((PyObject *)capi_y_tmp!=y_capi) {
    Py_XDECREF(capi_y_tmp); }
  }  /*if (capi_y_tmp == NULL) ... else of y*/
  /* End of cleaning variable y */
  } /*CHECKSCALAR(shape(d,1)==ny)*/
  /* End of cleaning variable ny */
  } /*CHECKSCALAR(shape(d,0)==nx)*/
  /* End of cleaning variable nx */
  } /*if (f2py_success) of cmin*/
  /* End of cleaning variable cmin */
  } /*if (f2py_success) of cmax*/
  /* End of cleaning variable cmax */
  } /*if (f2py_success) of symm*/
  /* End of cleaning variable symm */
  if((PyObject *)capi_d_tmp!=d_capi) {
    Py_XDECREF(capi_d_tmp); }
  }  /*if (capi_d_tmp == NULL) ... else of d*/
  /* End of cleaning variable d */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/****************************** end of euclidean ******************************/

/********************************* geographic *********************************/
static char doc_f2py_rout_distances_geographic[] = "\
Function signature:\n\
  geographic(d,x,y,[cmin,cmax,symm])\n\
Required arguments:\n"
"  d :  rank-2 array('d') with bounds (nx,ny)\n"
"  x : input rank-2 array('d') with bounds (nx,2)\n"
"  y : input rank-2 array('d') with bounds (ny,2)\n"
"Optional arguments:\n"
"  cmin := 0 input int\n"
"  cmax := -1 input int\n"
"  symm := 0 input int";
/* extern void F_FUNC(geographic,GEOGRAPHIC)(double*,double*,double*,int*,int*,int*,int*,int*); */
static PyObject *f2py_rout_distances_geographic(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(double*,double*,double*,int*,int*,int*,int*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  double *d = NULL;
  npy_intp d_Dims[2] = {-1, -1};
  const int d_Rank = 2;
  PyArrayObject *capi_d_tmp = NULL;
  int capi_d_intent = 0;
  PyObject *d_capi = Py_None;
  double *x = NULL;
  npy_intp x_Dims[2] = {-1, -1};
  const int x_Rank = 2;
  PyArrayObject *capi_x_tmp = NULL;
  int capi_x_intent = 0;
  PyObject *x_capi = Py_None;
  double *y = NULL;
  npy_intp y_Dims[2] = {-1, -1};
  const int y_Rank = 2;
  PyArrayObject *capi_y_tmp = NULL;
  int capi_y_intent = 0;
  PyObject *y_capi = Py_None;
  int nx = 0;
  int ny = 0;
  int cmin = 0;
  PyObject *cmin_capi = Py_None;
  int cmax = 0;
  PyObject *cmax_capi = Py_None;
  int symm = 0;
  PyObject *symm_capi = Py_None;
  static char *capi_kwlist[] = {"d","x","y","cmin","cmax","symm",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOO|OOO:distances.geographic",\
    capi_kwlist,&d_capi,&x_capi,&y_capi,&cmin_capi,&cmax_capi,&symm_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable cmin */
  if (cmin_capi == Py_None) cmin = 0; else
    f2py_success = int_from_pyobj(&cmin,cmin_capi,"distances.geographic() 1st keyword (cmin) can't be converted to int");
  if (f2py_success) {
  /* Processing variable symm */
  if (symm_capi == Py_None) symm = 0; else
    symm = (int)PyObject_IsTrue(symm_capi);
    f2py_success = 1;
  if (f2py_success) {
  /* Processing variable d */
  ;
  capi_d_intent |= F2PY_INTENT_INPLACE;
  capi_d_tmp = array_from_pyobj(PyArray_DOUBLE,d_Dims,d_Rank,capi_d_intent,d_capi);
  if (capi_d_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(distances_error,"failed in converting 1st argument `d' of distances.geographic to C/Fortran array" );
  } else {
    d = (double *)(capi_d_tmp->data);

  /* Processing variable cmax */
  if (cmax_capi == Py_None) cmax = -1; else
    f2py_success = int_from_pyobj(&cmax,cmax_capi,"distances.geographic() 2nd keyword (cmax) can't be converted to int");
  if (f2py_success) {
  /* Processing variable nx */
  nx = shape(d,0);
  CHECKSCALAR(shape(d,0)==nx,"shape(d,0)==nx","hidden nx","geographic:nx=%d",nx) {
  /* Processing variable ny */
  ny = shape(d,1);
  CHECKSCALAR(shape(d,1)==ny,"shape(d,1)==ny","hidden ny","geographic:ny=%d",ny) {
  /* Processing variable y */
  y_Dims[0]=ny,y_Dims[1]=2;
  capi_y_intent |= F2PY_INTENT_IN;
  capi_y_tmp = array_from_pyobj(PyArray_DOUBLE,y_Dims,y_Rank,capi_y_intent,y_capi);
  if (capi_y_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(distances_error,"failed in converting 3rd argument `y' of distances.geographic to C/Fortran array" );
  } else {
    y = (double *)(capi_y_tmp->data);

  /* Processing variable x */
  x_Dims[0]=nx,x_Dims[1]=2;
  capi_x_intent |= F2PY_INTENT_IN;
  capi_x_tmp = array_from_pyobj(PyArray_DOUBLE,x_Dims,x_Rank,capi_x_intent,x_capi);
  if (capi_x_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(distances_error,"failed in converting 2nd argument `x' of distances.geographic to C/Fortran array" );
  } else {
    x = (double *)(capi_x_tmp->data);

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
      Py_BEGIN_ALLOW_THREADS
        (*f2py_func)(d,x,y,&nx,&ny,&cmin,&cmax,&symm);
      Py_END_ALLOW_THREADS
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  if((PyObject *)capi_x_tmp!=x_capi) {
    Py_XDECREF(capi_x_tmp); }
  }  /*if (capi_x_tmp == NULL) ... else of x*/
  /* End of cleaning variable x */
  if((PyObject *)capi_y_tmp!=y_capi) {
    Py_XDECREF(capi_y_tmp); }
  }  /*if (capi_y_tmp == NULL) ... else of y*/
  /* End of cleaning variable y */
  } /*CHECKSCALAR(shape(d,1)==ny)*/
  /* End of cleaning variable ny */
  } /*CHECKSCALAR(shape(d,0)==nx)*/
  /* End of cleaning variable nx */
  } /*if (f2py_success) of cmax*/
  /* End of cleaning variable cmax */
  if((PyObject *)capi_d_tmp!=d_capi) {
    Py_XDECREF(capi_d_tmp); }
  }  /*if (capi_d_tmp == NULL) ... else of d*/
  /* End of cleaning variable d */
  } /*if (f2py_success) of symm*/
  /* End of cleaning variable symm */
  } /*if (f2py_success) of cmin*/
  /* End of cleaning variable cmin */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/***************************** end of geographic *****************************/

/******************************* paniso_geo_rad *******************************/
static char doc_f2py_rout_distances_paniso_geo_rad[] = "\
Function signature:\n\
  paniso_geo_rad(d,x,y,ctrs,scals,[cmin,cmax,symm])\n\
Required arguments:\n"
"  d :  rank-2 array('d') with bounds (nx,ny)\n"
"  x : input rank-2 array('d') with bounds (nx,2)\n"
"  y : input rank-2 array('d') with bounds (ny,2)\n"
"  ctrs : input rank-1 array('d') with bounds (na)\n"
"  scals : input rank-1 array('d') with bounds (na)\n"
"Optional arguments:\n"
"  cmin := 0 input int\n"
"  cmax := -1 input int\n"
"  symm := 0 input int";
/* extern void F_FUNC_US(paniso_geo_rad,PANISO_GEO_RAD)(double*,double*,double*,int*,int*,int*,int*,double*,double*,int*,int*); */
static PyObject *f2py_rout_distances_paniso_geo_rad(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(double*,double*,double*,int*,int*,int*,int*,double*,double*,int*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  double *d = NULL;
  npy_intp d_Dims[2] = {-1, -1};
  const int d_Rank = 2;
  PyArrayObject *capi_d_tmp = NULL;
  int capi_d_intent = 0;
  PyObject *d_capi = Py_None;
  double *x = NULL;
  npy_intp x_Dims[2] = {-1, -1};
  const int x_Rank = 2;
  PyArrayObject *capi_x_tmp = NULL;
  int capi_x_intent = 0;
  PyObject *x_capi = Py_None;
  double *y = NULL;
  npy_intp y_Dims[2] = {-1, -1};
  const int y_Rank = 2;
  PyArrayObject *capi_y_tmp = NULL;
  int capi_y_intent = 0;
  PyObject *y_capi = Py_None;
  int nx = 0;
  int ny = 0;
  int cmin = 0;
  PyObject *cmin_capi = Py_None;
  int cmax = 0;
  PyObject *cmax_capi = Py_None;
  double *ctrs = NULL;
  npy_intp ctrs_Dims[1] = {-1};
  const int ctrs_Rank = 1;
  PyArrayObject *capi_ctrs_tmp = NULL;
  int capi_ctrs_intent = 0;
  PyObject *ctrs_capi = Py_None;
  double *scals = NULL;
  npy_intp scals_Dims[1] = {-1};
  const int scals_Rank = 1;
  PyArrayObject *capi_scals_tmp = NULL;
  int capi_scals_intent = 0;
  PyObject *scals_capi = Py_None;
  int na = 0;
  int symm = 0;
  PyObject *symm_capi = Py_None;
  static char *capi_kwlist[] = {"d","x","y","ctrs","scals","cmin","cmax","symm",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOOO|OOO:distances.paniso_geo_rad",\
    capi_kwlist,&d_capi,&x_capi,&y_capi,&ctrs_capi,&scals_capi,&cmin_capi,&cmax_capi,&symm_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable cmin */
  if (cmin_capi == Py_None) cmin = 0; else
    f2py_success = int_from_pyobj(&cmin,cmin_capi,"distances.paniso_geo_rad() 1st keyword (cmin) can't be converted to int");
  if (f2py_success) {
  /* Processing variable symm */
  if (symm_capi == Py_None) symm = 0; else
    symm = (int)PyObject_IsTrue(symm_capi);
    f2py_success = 1;
  if (f2py_success) {
  /* Processing variable ctrs */
  ;
  capi_ctrs_intent |= F2PY_INTENT_IN;
  capi_ctrs_tmp = array_from_pyobj(PyArray_DOUBLE,ctrs_Dims,ctrs_Rank,capi_ctrs_intent,ctrs_capi);
  if (capi_ctrs_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(distances_error,"failed in converting 4th argument `ctrs' of distances.paniso_geo_rad to C/Fortran array" );
  } else {
    ctrs = (double *)(capi_ctrs_tmp->data);

  /* Processing variable cmax */
  if (cmax_capi == Py_None) cmax = -1; else
    f2py_success = int_from_pyobj(&cmax,cmax_capi,"distances.paniso_geo_rad() 2nd keyword (cmax) can't be converted to int");
  if (f2py_success) {
  /* Processing variable d */
  ;
  capi_d_intent |= F2PY_INTENT_INPLACE;
  capi_d_tmp = array_from_pyobj(PyArray_DOUBLE,d_Dims,d_Rank,capi_d_intent,d_capi);
  if (capi_d_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(distances_error,"failed in converting 1st argument `d' of distances.paniso_geo_rad to C/Fortran array" );
  } else {
    d = (double *)(capi_d_tmp->data);

  /* Processing variable na */
  na = len(ctrs);
  CHECKSCALAR(len(ctrs)>=na,"len(ctrs)>=na","hidden na","paniso_geo_rad:na=%d",na) {
  /* Processing variable nx */
  nx = shape(d,0);
  CHECKSCALAR(shape(d,0)==nx,"shape(d,0)==nx","hidden nx","paniso_geo_rad:nx=%d",nx) {
  /* Processing variable ny */
  ny = shape(d,1);
  CHECKSCALAR(shape(d,1)==ny,"shape(d,1)==ny","hidden ny","paniso_geo_rad:ny=%d",ny) {
  /* Processing variable scals */
  scals_Dims[0]=na;
  capi_scals_intent |= F2PY_INTENT_IN;
  capi_scals_tmp = array_from_pyobj(PyArray_DOUBLE,scals_Dims,scals_Rank,capi_scals_intent,scals_capi);
  if (capi_scals_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(distances_error,"failed in converting 5th argument `scals' of distances.paniso_geo_rad to C/Fortran array" );
  } else {
    scals = (double *)(capi_scals_tmp->data);

  /* Processing variable y */
  y_Dims[0]=ny,y_Dims[1]=2;
  capi_y_intent |= F2PY_INTENT_IN;
  capi_y_tmp = array_from_pyobj(PyArray_DOUBLE,y_Dims,y_Rank,capi_y_intent,y_capi);
  if (capi_y_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(distances_error,"failed in converting 3rd argument `y' of distances.paniso_geo_rad to C/Fortran array" );
  } else {
    y = (double *)(capi_y_tmp->data);

  /* Processing variable x */
  x_Dims[0]=nx,x_Dims[1]=2;
  capi_x_intent |= F2PY_INTENT_IN;
  capi_x_tmp = array_from_pyobj(PyArray_DOUBLE,x_Dims,x_Rank,capi_x_intent,x_capi);
  if (capi_x_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(distances_error,"failed in converting 2nd argument `x' of distances.paniso_geo_rad to C/Fortran array" );
  } else {
    x = (double *)(capi_x_tmp->data);

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
      Py_BEGIN_ALLOW_THREADS
        (*f2py_func)(d,x,y,&nx,&ny,&cmin,&cmax,ctrs,scals,&na,&symm);
      Py_END_ALLOW_THREADS
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  if((PyObject *)capi_x_tmp!=x_capi) {
    Py_XDECREF(capi_x_tmp); }
  }  /*if (capi_x_tmp == NULL) ... else of x*/
  /* End of cleaning variable x */
  if((PyObject *)capi_y_tmp!=y_capi) {
    Py_XDECREF(capi_y_tmp); }
  }  /*if (capi_y_tmp == NULL) ... else of y*/
  /* End of cleaning variable y */
  if((PyObject *)capi_scals_tmp!=scals_capi) {
    Py_XDECREF(capi_scals_tmp); }
  }  /*if (capi_scals_tmp == NULL) ... else of scals*/
  /* End of cleaning variable scals */
  } /*CHECKSCALAR(shape(d,1)==ny)*/
  /* End of cleaning variable ny */
  } /*CHECKSCALAR(shape(d,0)==nx)*/
  /* End of cleaning variable nx */
  } /*CHECKSCALAR(len(ctrs)>=na)*/
  /* End of cleaning variable na */
  if((PyObject *)capi_d_tmp!=d_capi) {
    Py_XDECREF(capi_d_tmp); }
  }  /*if (capi_d_tmp == NULL) ... else of d*/
  /* End of cleaning variable d */
  } /*if (f2py_success) of cmax*/
  /* End of cleaning variable cmax */
  if((PyObject *)capi_ctrs_tmp!=ctrs_capi) {
    Py_XDECREF(capi_ctrs_tmp); }
  }  /*if (capi_ctrs_tmp == NULL) ... else of ctrs*/
  /* End of cleaning variable ctrs */
  } /*if (f2py_success) of symm*/
  /* End of cleaning variable symm */
  } /*if (f2py_success) of cmin*/
  /* End of cleaning variable cmin */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/*************************** end of paniso_geo_rad ***************************/

/******************************* aniso_geo_rad *******************************/
static char doc_f2py_rout_distances_aniso_geo_rad[] = "\
Function signature:\n\
  aniso_geo_rad(d,x,y,inc,ecc,[cmin,cmax,symm])\n\
Required arguments:\n"
"  d :  rank-2 array('d') with bounds (nx,ny)\n"
"  x : input rank-2 array('d') with bounds (nx,2)\n"
"  y : input rank-2 array('d') with bounds (ny,2)\n"
"  inc : input float\n"
"  ecc : input float\n"
"Optional arguments:\n"
"  cmin := 0 input int\n"
"  cmax := -1 input int\n"
"  symm := 0 input int";
/* extern void F_FUNC_US(aniso_geo_rad,ANISO_GEO_RAD)(double*,double*,double*,int*,int*,int*,int*,double*,double*,int*); */
static PyObject *f2py_rout_distances_aniso_geo_rad(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(double*,double*,double*,int*,int*,int*,int*,double*,double*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  double *d = NULL;
  npy_intp d_Dims[2] = {-1, -1};
  const int d_Rank = 2;
  PyArrayObject *capi_d_tmp = NULL;
  int capi_d_intent = 0;
  PyObject *d_capi = Py_None;
  double *x = NULL;
  npy_intp x_Dims[2] = {-1, -1};
  const int x_Rank = 2;
  PyArrayObject *capi_x_tmp = NULL;
  int capi_x_intent = 0;
  PyObject *x_capi = Py_None;
  double *y = NULL;
  npy_intp y_Dims[2] = {-1, -1};
  const int y_Rank = 2;
  PyArrayObject *capi_y_tmp = NULL;
  int capi_y_intent = 0;
  PyObject *y_capi = Py_None;
  int nx = 0;
  int ny = 0;
  int cmin = 0;
  PyObject *cmin_capi = Py_None;
  int cmax = 0;
  PyObject *cmax_capi = Py_None;
  double inc = 0;
  PyObject *inc_capi = Py_None;
  double ecc = 0;
  PyObject *ecc_capi = Py_None;
  int symm = 0;
  PyObject *symm_capi = Py_None;
  static char *capi_kwlist[] = {"d","x","y","inc","ecc","cmin","cmax","symm",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOOO|OOO:distances.aniso_geo_rad",\
    capi_kwlist,&d_capi,&x_capi,&y_capi,&inc_capi,&ecc_capi,&cmin_capi,&cmax_capi,&symm_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable cmin */
  if (cmin_capi == Py_None) cmin = 0; else
    f2py_success = int_from_pyobj(&cmin,cmin_capi,"distances.aniso_geo_rad() 1st keyword (cmin) can't be converted to int");
  if (f2py_success) {
  /* Processing variable symm */
  if (symm_capi == Py_None) symm = 0; else
    symm = (int)PyObject_IsTrue(symm_capi);
    f2py_success = 1;
  if (f2py_success) {
  /* Processing variable ecc */
    f2py_success = double_from_pyobj(&ecc,ecc_capi,"distances.aniso_geo_rad() 5th argument (ecc) can't be converted to double");
  if (f2py_success) {
  /* Processing variable inc */
    f2py_success = double_from_pyobj(&inc,inc_capi,"distances.aniso_geo_rad() 4th argument (inc) can't be converted to double");
  if (f2py_success) {
  /* Processing variable d */
  ;
  capi_d_intent |= F2PY_INTENT_INPLACE;
  capi_d_tmp = array_from_pyobj(PyArray_DOUBLE,d_Dims,d_Rank,capi_d_intent,d_capi);
  if (capi_d_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(distances_error,"failed in converting 1st argument `d' of distances.aniso_geo_rad to C/Fortran array" );
  } else {
    d = (double *)(capi_d_tmp->data);

  /* Processing variable cmax */
  if (cmax_capi == Py_None) cmax = -1; else
    f2py_success = int_from_pyobj(&cmax,cmax_capi,"distances.aniso_geo_rad() 2nd keyword (cmax) can't be converted to int");
  if (f2py_success) {
  /* Processing variable nx */
  nx = shape(d,0);
  CHECKSCALAR(shape(d,0)==nx,"shape(d,0)==nx","hidden nx","aniso_geo_rad:nx=%d",nx) {
  /* Processing variable ny */
  ny = shape(d,1);
  CHECKSCALAR(shape(d,1)==ny,"shape(d,1)==ny","hidden ny","aniso_geo_rad:ny=%d",ny) {
  /* Processing variable y */
  y_Dims[0]=ny,y_Dims[1]=2;
  capi_y_intent |= F2PY_INTENT_IN;
  capi_y_tmp = array_from_pyobj(PyArray_DOUBLE,y_Dims,y_Rank,capi_y_intent,y_capi);
  if (capi_y_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(distances_error,"failed in converting 3rd argument `y' of distances.aniso_geo_rad to C/Fortran array" );
  } else {
    y = (double *)(capi_y_tmp->data);

  /* Processing variable x */
  x_Dims[0]=nx,x_Dims[1]=2;
  capi_x_intent |= F2PY_INTENT_IN;
  capi_x_tmp = array_from_pyobj(PyArray_DOUBLE,x_Dims,x_Rank,capi_x_intent,x_capi);
  if (capi_x_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(distances_error,"failed in converting 2nd argument `x' of distances.aniso_geo_rad to C/Fortran array" );
  } else {
    x = (double *)(capi_x_tmp->data);

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
      Py_BEGIN_ALLOW_THREADS
        (*f2py_func)(d,x,y,&nx,&ny,&cmin,&cmax,&inc,&ecc,&symm);
      Py_END_ALLOW_THREADS
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  if((PyObject *)capi_x_tmp!=x_capi) {
    Py_XDECREF(capi_x_tmp); }
  }  /*if (capi_x_tmp == NULL) ... else of x*/
  /* End of cleaning variable x */
  if((PyObject *)capi_y_tmp!=y_capi) {
    Py_XDECREF(capi_y_tmp); }
  }  /*if (capi_y_tmp == NULL) ... else of y*/
  /* End of cleaning variable y */
  } /*CHECKSCALAR(shape(d,1)==ny)*/
  /* End of cleaning variable ny */
  } /*CHECKSCALAR(shape(d,0)==nx)*/
  /* End of cleaning variable nx */
  } /*if (f2py_success) of cmax*/
  /* End of cleaning variable cmax */
  if((PyObject *)capi_d_tmp!=d_capi) {
    Py_XDECREF(capi_d_tmp); }
  }  /*if (capi_d_tmp == NULL) ... else of d*/
  /* End of cleaning variable d */
  } /*if (f2py_success) of inc*/
  /* End of cleaning variable inc */
  } /*if (f2py_success) of ecc*/
  /* End of cleaning variable ecc */
  } /*if (f2py_success) of symm*/
  /* End of cleaning variable symm */
  } /*if (f2py_success) of cmin*/
  /* End of cleaning variable cmin */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/**************************** end of aniso_geo_rad ****************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"euclidean",-1,{{-1}},0,(char *)F_FUNC(euclidean,EUCLIDEAN),(f2py_init_func)f2py_rout_distances_euclidean,doc_f2py_rout_distances_euclidean},
  {"geographic",-1,{{-1}},0,(char *)F_FUNC(geographic,GEOGRAPHIC),(f2py_init_func)f2py_rout_distances_geographic,doc_f2py_rout_distances_geographic},
  {"paniso_geo_rad",-1,{{-1}},0,(char *)F_FUNC_US(paniso_geo_rad,PANISO_GEO_RAD),(f2py_init_func)f2py_rout_distances_paniso_geo_rad,doc_f2py_rout_distances_paniso_geo_rad},
  {"aniso_geo_rad",-1,{{-1}},0,(char *)F_FUNC_US(aniso_geo_rad,ANISO_GEO_RAD),(f2py_init_func)f2py_rout_distances_aniso_geo_rad,doc_f2py_rout_distances_aniso_geo_rad},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "distances",
  NULL,
  -1,
  f2py_module_methods,
  NULL,
  NULL,
  NULL,
  NULL
};
#endif

#if PY_VERSION_HEX >= 0x03000000
#define RETVAL m
PyObject *PyInit_distances(void) {
#else
#define RETVAL
PyMODINIT_FUNC initdistances(void) {
#endif
  int i;
  PyObject *m,*d, *s;
#if PY_VERSION_HEX >= 0x03000000
  m = distances_module = PyModule_Create(&moduledef);
#else
  m = distances_module = Py_InitModule("distances", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module distances (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module 'distances' is auto-generated with f2py (version:2).\nFunctions:\n"
"  euclidean(d,x,y,cmin=0,cmax=-1,symm=0)\n"
"  geographic(d,x,y,cmin=0,cmax=-1,symm=0)\n"
"  paniso_geo_rad(d,x,y,ctrs,scals,cmin=0,cmax=-1,symm=0)\n"
"  aniso_geo_rad(d,x,y,inc,ecc,cmin=0,cmax=-1,symm=0)\n"
".");
  PyDict_SetItemString(d, "__doc__", s);
  distances_error = PyErr_NewException ("distances.error", NULL, NULL);
  Py_DECREF(s);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++)
    PyDict_SetItemString(d, f2py_routine_defs[i].name,PyFortranObject_NewAsAttr(&f2py_routine_defs[i]));




/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"distances");
#endif

  return RETVAL;
}
#ifdef __cplusplus
}
#endif
