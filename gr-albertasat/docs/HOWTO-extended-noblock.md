## GNU Radio HOWTO - extended `noblock` block based on `gr-digital` block

This HOWTO assumes that you have already gone through the `HOWTO-simple-noblock.md` example.

The objective here is to create a `noblock` block that extends the `gr-digital` `packet_header_default`. We do this because we want to use GNU Radio blocks that expect an object that looksl like the `packet_header_default` in terms of it's constructor and some specific methods. We will use this to make our own class that knows about the UHF radio packet header.

2. Add a new `noblock` block
   ```
   knud 23:39:13 $gr_modtool add uhf_header
   GNU Radio module name identified: albertasat
   ('sink', 'source', 'sync', 'decimator', 'interpolator', 'general', 'tagged_stream', 'hier', 'noblock')
   Enter block type: noblock
   Language (python/cpp): cpp
   Language: C++
   Block/code identifier: uhf_header
   Enter valid argument list, including default arguments:
   Add C++ QA code? [Y/n]
   Adding file 'lib/uhf_header.cc'...
   Adding file 'include/albertasat/uhf_header.h'...
   Adding file 'lib/qa_uhf_header.cc'...
   Adding file 'lib/qa_uhf_header.h'...
   Editing swig/albertasat_swig.i...
   Adding file 'grc/albertasat_uhf_header.xml'...
   Editing grc/CMakeLists.txt...
   knud 23:39:32 $
   ```
3. The next step is to make sure that `uhf_packet` will be known by `gnuradio-companion` (hereafter we'll say `GRC`). Since this is a `noblock`, we can't see it as a block in GRC and it won't be added to the `grc/CMakeLists.txt` file for installation. Make sure that in that file there is no reference to `uhf_header`.
4. Now we make the appropriate changes and addtions to the `swig` directory. `cd swig` and make the `albertasat_swig.i` file look like
   ```
   /* -*- c++ -*- */

   #define ALBERTASAT_API
   #define DIGITAL_API

   %include "gnuradio.i" // the common stuff

   //load generated python docstrings
   %include "albertasat_swig_doc.i"

   #pragma SWIG nowarn=325,454

   %{
   #include "albertasat/my_header.h"
   #include "albertasat/uhf_header.h"
   %}

   %include "albertasat/my_header.h"
   %include "albertasat/uhf_header.h"

   // Properly package up non-block objects
   %include "my_header.i"
   %include "uhf_header.i"
   ```
   We are telling SWIG about the C++ interface for `uhf_header` and a new pointer based interface in `uhf_header.i`. Note that we have to define the `DIGITAL_API` to let the make system know about the use of the `gr-digital` module.
5. Next we edit `CMakeLists.txt` to include `uhf_header.i`. At the bottom of the file, add `my_header.i` to the `install` block so it looks like this
   ```
   ########################################################################
   # Install swig .i files for development
   ########################################################################
   install(
       FILES
       albertasat_swig.i
       my_header.i
       uhf_header.i
       ${CMAKE_CURRENT_BINARY_DIR}/albertasat_swig_doc.i
       DESTINATION ${GR_INCLUDE_DIR}/albertasat/swig
   )
   ```
6. Add a new file to the `swig` directory named `uhf_header.i` with the contents
    ```
    /* -*- c++ -*- */

    %template(uhf_header_sptr) boost::shared_ptr<gr::albertasat::uhf_header>;
    %pythoncode %{
    uhf_header_sptr.__repr__ = lambda self: "<uhf_header>"
    uhf_header = uhf_header .make;
    %}
    ```
7. Finally, let's change the header file. `cd ..` and open `include/albertasat/uhf_header.h`. Make it look like the example `uhf_packet.h` in the `gr-albertasat/docs` directory.

   The main change between this example and the simple `noblock` example is that the `uhf_header` class inherits from the `packet_header_default` class defined in `gr-digital`.
8. Likewise, let's change the implementation file to look like the example `uhf_packet.cc` in the `gr-albertasat/docs` directory.
9. We can't compile just yet because the cmake system needs to know about the use of the `gr-digital` module. Do that by editting the top-level `CMakeLists.txt` file so that the `GR_REQUIRED` is set as below
   ```
   set(GR_REQUIRED_COMPONENTS RUNTIME DIGITAL PMT)
   find_package(Gnuradio "3.7.2" REQUIRED)
   ```
   We've added `DIGITAL` and `PMT`; the latter is needed because we will use GNU radio "tags".

10. Now do the usual GNU Radio module build
    ```
    mkdir build; cd build
    cmake ../
    make
    sudo make install
    sudo ldconfig
    ```
11. Time to test our `noblock`. Start an interactive `python2.7` session and do the following
    ```
    knud 22:48:59 $python2.7
    Python 2.7.17 (default, Sep 30 2020, 13:38:04)
    [GCC 7.5.0] on linux2
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import albertasat
    >>> dir(albertasat)
    ['BITS_PER_HEADER_BYTE', 'DEFAULT_LEN_TAG_KEY', 'DEFAULT_NUM_TAG_KEY', 'DEFAULT_SYNC_WORD', 'HEADER_SIZE_BITS', 'HEADER_SIZE_BYTES', 'MAX_PAYLOAD_BYTES', 'PACKET_CRC16_BITS', 'PACKET_DATA_FIELD_1_BITS', 'PACKET_DATA_FIELD_2_BITS', 'PACKET_PREAMBLE_BITS', 'PACKET_SYNC_BITS', '__builtins__', '__doc__', '__file__', '__name__', '__package__', '__path__', '_albertasat_swig', 'albertasat_swig', 'high_res_timer_epoch', 'high_res_timer_now', 'high_res_timer_now_perfmon', 'high_res_timer_tps', 'my_header', 'my_header_make', 'my_header_sptr', 'my_header_sptr_swigregister', 'my_header_swigregister', 'packet_header_default', 'packet_header_default_make', 'packet_header_default_swigregister', 'uhf_header', 'uhf_header_make', 'uhf_header_sptr', 'uhf_header_sptr_swigregister', 'uhf_header_swigregister']
    >>>
    ```
    We see that the `albertasat` module can be imported and contains the `my_header` and `uhf_header` classes, and also the `packet_header_default` class. Perfect!
12. The last thing to do is confirm this works in GRC. Open GRC and open the example in `gr-albertasat/examples/uhf_header_test.grc`. Check out the 3 import blocks. Notice that `digital` must be explicitly imported so that when it's referenced from `uhf_header` it can be found. Since `my_header` is imported, the variable `test_foo_function` yields a correct result. Likewise, the `test_header_len_function` variable has the correct header length in bits (7 bytes is 56 bits). 
