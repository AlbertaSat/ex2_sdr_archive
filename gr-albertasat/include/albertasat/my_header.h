/* -*- c++ -*- */
/* 
 * Copyright 2020 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


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

