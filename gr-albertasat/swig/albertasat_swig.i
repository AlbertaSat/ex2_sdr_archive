/* -*- c++ -*- */

#define ALBERTASAT_API
#define DIGITAL_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "albertasat_swig_doc.i"

#pragma SWIG nowarn=325,454
%{
#include "albertasat/my_header.h"
#include "albertasat/uhf_header.h"
%}

%include "albertasat/my_header.h"
%include "my_header.i"
%include "albertasat/uhf_header.h"
%include "uhf_header.i"
