#ifdef HAVE_CONFIG_H
    #include "config.h"
    #endif

    #include <gnuradio/io_signature.h>
    #include <albertasat/my_header.h>

    namespace gr {
      namespace albertasat {

        my_header::my_header()
        {
        }

        my_header::~my_header()
        {
        }

        my_header::sptr
        my_header::make()
        {
          return my_header::sptr (
    	      new my_header());
        }

        int
        my_header::foo()
        {
          return 17;
        }

      } /* namespace albertasat */
    } /* namespace gr */
