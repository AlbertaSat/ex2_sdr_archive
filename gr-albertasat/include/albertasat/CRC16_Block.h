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


#ifndef INCLUDED_ALBERTASAT_CRC16_BLOCK_H
#define INCLUDED_ALBERTASAT_CRC16_BLOCK_H

#include <albertasat/api.h>
#include <gnuradio/tagged_stream_block.h>

namespace gr {
  namespace albertasat {

    /*!
     * \brief <+description of block+>
     * \ingroup albertasat
     *
     */
    class ALBERTASAT_API CRC16_Block : virtual public gr::tagged_stream_block
    {
     public:
      typedef boost::shared_ptr<CRC16_Block> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of albertasat::CRC16_Block.
       *
       * To avoid accidental use of raw pointers, albertasat::CRC16_Block's
       * constructor is in a private implementation
       * class. albertasat::CRC16_Block::make is the public interface for
       * creating new instances.
       */
      static sptr make(const std::string& len_tag_key ="packet_len");
    };

  } // namespace albertasat
} // namespace gr

#endif /* INCLUDED_ALBERTASAT_CRC16_BLOCK_H */
