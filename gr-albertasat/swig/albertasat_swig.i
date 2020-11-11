/* -*- c++ -*- */

#define ALBERTASAT_API
#define DIGITAL_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "albertasat_swig_doc.i"

#pragma SWIG nowarn=325,454

%{
#include "gnuradio/digital/packet_header_default.h"
#include "albertasat/my_header.h"
#include "albertasat/uhf_header.h"
%}

%include "gnuradio/digital/packet_header_default.h"
%include "albertasat/my_header.h"
%include "albertasat/uhf_header.h"

// Properly package up non-block objects
%include "my_header.i"
%include "uhf_header.i"
