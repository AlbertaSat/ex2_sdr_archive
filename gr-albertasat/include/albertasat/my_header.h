#ifndef INCLUDED_ALBERTASAT_MY_HEADER_H
    #define INCLUDED_ALBERTASAT_MY_HEADER_H

    #include <albertasat/api.h>
    #include <boost/enable_shared_from_this.hpp>

    namespace gr {
      namespace albertasat {

        /*!
         * \brief <+description+>
         *
         */
        class ALBERTASAT_API my_header
        : public boost::enable_shared_from_this<gr::albertasat::my_header>
        {
        public:
          typedef boost::shared_ptr<my_header> sptr;

          ~my_header();

         static sptr make();

         int foo();

        private:
          my_header();
        };

      } // namespace albertasat
    } // namespace gr

    #endif /* INCLUDED_ALBERTASAT_MY_HEADER_H */
