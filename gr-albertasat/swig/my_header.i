%template(my_header_sptr) boost::shared_ptr<gr::albertasat::my_header>;
%pythoncode %{
my_header_sptr.__repr__ = lambda self: "<my_header>"
my_header = my_header .make;
%}
