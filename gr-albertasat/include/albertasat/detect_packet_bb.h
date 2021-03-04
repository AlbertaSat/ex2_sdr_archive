/* -*- c++ -*- */
/*
 * Copyright 2021 <+YOU OR YOUR COMPANY+>.
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


#ifndef INCLUDED_ALBERTASAT_DETECT_PACKET_BB_H
#define INCLUDED_ALBERTASAT_DETECT_PACKET_BB_H

#include <albertasat/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace albertasat {

    /*!
     * \brief <+description of block+>
     * \ingroup albertasat
     *
     */
    class ALBERTASAT_API detect_packet_bb : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<detect_packet_bb> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of albertasat::detect_packet_bb.
       *
       * To avoid accidental use of raw pointers, albertasat::detect_packet_bb's
       * constructor is in a private implementation
       * class. albertasat::detect_packet_bb::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace albertasat
} // namespace gr

#endif /* INCLUDED_ALBERTASAT_DETECT_PACKET_BB_H */
