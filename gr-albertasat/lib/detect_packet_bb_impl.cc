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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "detect_packet_bb_impl.h"

namespace gr {
  namespace albertasat {

    detect_packet_bb::sptr
    detect_packet_bb::make()
    {
      return gnuradio::get_initial_sptr
        (new detect_packet_bb_impl());
    }

    /*
     * The private constructor
     */
    detect_packet_bb_impl::detect_packet_bb_impl()
      : gr::sync_block("detect_packet_bb",
              gr::io_signature::make(1, 1, sizeof(char)),
              gr::io_signature::make(1, 1, sizeof(char)))
    {
      set_history(6);
    }

    /*
     * Our virtual destructor.
     */
    detect_packet_bb_impl::~detect_packet_bb_impl()
    {
    }

    int
    detect_packet_bb_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const unsigned char* in = (const unsigned char*) input_items[0];
      const unsigned char* out = (const unsigned char*) output_items[0];
      for(int i = 0; i<6; i++){
        printf("%X\n", in[i]);
        //std::cout<< std::hex<<in[i]<<endl;
      }
      printf("\n");

      //if((in[0] == in[1] == in[2] == in[3] == in[4] == '0xAA') && (in[5] == '0x7E'))
      if((in[0] == 0xC2) && (in[1] == 0xAA) && (in[2] == 0xC2) && (in[3] == 0xAA) && (in[4] == 0xC2) && (in[5] == 0xAA)){
        printf("GOT IT\n");
        add_item_tag(0, nitems_written(0), pmt::mp("detect_tag"), pmt::PMT_T);
      }
      // Do <+signal processing+>
      memcpy((void*)out, (const void*)in, 1);

      // Tell runtime system how many output items we produced.
      return 1;
    }

  } /* namespace albertasat */
} /* namespace gr */
