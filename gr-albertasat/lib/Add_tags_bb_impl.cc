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

// This block identifies the start of the PDU and adds a tag to the beginning of the preamble
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "Add_tags_bb_impl.h"

namespace gr {
  namespace albertasat {

    Add_tags_bb::sptr
    Add_tags_bb::make()
    {
      return gnuradio::get_initial_sptr
        (new Add_tags_bb_impl());
    }

    /*
     * The private constructor
     */
    Add_tags_bb_impl::Add_tags_bb_impl()
      : gr::block("Add_tags_bb",
              gr::io_signature::make(1, 1, sizeof(char)),
              gr::io_signature::make(1, 1, sizeof(char)))
    {}

    /*
     * Our virtual destructor.
     */
    Add_tags_bb_impl::~Add_tags_bb_impl()
    {
    }

    void
    Add_tags_bb_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      ninput_items_required[0] = noutput_items;
    }

    int
    Add_tags_bb_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const unsigned char *in = (const unsigned char*) input_items[0]; // get pointer to input data storage
      const unsigned char *out = (const unsigned char*) output_items[0]; // get pointer to output data buffer

      memcpy((void*)out, (const void*)in, 1);
      // Do <+signal processing+>
      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (noutput_items);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace albertasat */
} /* namespace gr */
