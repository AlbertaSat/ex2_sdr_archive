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

 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif

 #include <string.h>

 #include <gnuradio/io_signature.h>
 #include <boost/crc.hpp>      // For CRC function
 #include <iostream>   // for std::cout
 #include <ostream>    // for std::endl
#include "CRC16_Block_impl.h"

namespace gr {
  namespace albertasat {

    CRC16_Block::sptr
    CRC16_Block::make(const std::string& len_tag_key)
    {
      return gnuradio::get_initial_sptr
        (new CRC16_Block_impl(len_tag_key));
    }

    /*
     * The private constructor
     */
    CRC16_Block_impl::CRC16_Block_impl(const std::string& len_tag_key)
      : gr::tagged_stream_block("CRC16_Block",
              gr::io_signature::make(1, 1, sizeof(char)),
              gr::io_signature::make(1, 1, sizeof(char)), len_tag_key)
    {}

    /*
     * Our virtual destructor.
     */
    CRC16_Block_impl::~CRC16_Block_impl()
    {
    }

    int
    CRC16_Block_impl::calculate_output_stream_length(const gr_vector_int &ninput_items)
    {
      int noutput_items = ninput_items[0] + 2;
      return noutput_items ;
    }

    int
    CRC16_Block_impl::work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const unsigned char* in = (const unsigned char*)input_items[0];
      unsigned char* out = (unsigned char*)output_items[0];
      size_t packet_length = ninput_items[0];
      uint16_t crc;

      // specify result here
      boost::crc_ccitt_type result;
      result.process_bytes(in, 6); // process the specified number of bytes in the input
      crc = result.checksum();
      std::cout << "CRC16 Result is = " << std::hex << crc << std::endl; // output result in hex form
      printf("\n");
      memcpy((void*)out, (const void*)in, packet_length);
      memcpy((void*)(out + packet_length),&crc, 2);
      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace albertasat */
} /* namespace gr */
