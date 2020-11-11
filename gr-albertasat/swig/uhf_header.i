/* -*- c++ -*- */

%template(uhf_header_sptr) boost::shared_ptr<gr::albertasat::uhf_header>;
%pythoncode %{
uhf_header_sptr.__repr__ = lambda self: "<uhf_header>"
uhf_header = uhf_header .make;
%}

