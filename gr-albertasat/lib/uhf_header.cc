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
#include <albertasat/uhf_header.h>

#define UHF_HEADER_DEBUG 1

namespace gr {
  namespace albertasat {

    // The default header is defined by the EnduroSat manual. The only variable part is the
    // Data Field 1 value, which we set to 0
    uint8_t default_header[7] = {0xAA, 0xAA, 0xAA, 0xAA, 0xAA, DEFAULT_SYNC_WORD, 0x00};

    uhf_header::uhf_header(
      const std::string &len_tag_key,
      const std::string &num_tag_key,
      const int bits_per_byte)
    :    digital::packet_header_default (HEADER_SIZE_BITS,
      len_tag_key, num_tag_key, bits_per_byte)
    {
      // find the number of bytes needed to hold the fixed fields for a
      // given d_bits_per_byte
      float field_bytes = (float) (HEADER_SIZE_BITS);
      // calc the full header length in bytes
      d_header_len = (long) ceil (field_bytes / (float) d_bits_per_byte);
    }

    uhf_header::~uhf_header()
    {
    }

    uhf_header::sptr
    uhf_header::make(
      const std::string &len_tag_key,
      const std::string &num_tag_key,
      const int bits_per_byte)
    {
      return uhf_header::sptr (
        new uhf_header(len_tag_key, num_tag_key, bits_per_byte));
    }

    bool
    uhf_header::header_formatter (
      long payload_len,
      unsigned char *out,
      const std::vector<gr::tag_t> &tags)
    {

      if (payload_len < 0 || payload_len > MAX_PAYLOAD_BYTES)
      {
        throw std::length_error("Payload length must be in [0,128] bytes.");
      }

      // Find the packet number. We don't actually use it, but leave this here
      // to show how to deal with tags.
      long packet_number = -1;
      for (unsigned i = 0; i < tags.size (); i++)
      {
        if (tags[i].key == d_num_tag_key)
        {
          packet_number = pmt::to_long (tags[i].value);
        }
      }
      if (UHF_HEADER_DEBUG)
      {
        printf ("after num_tag_key search. d_slot_packet_number = %lx\n", packet_number);
      }

      // There is only one thing to set in the packet header and that's
      // Data Field 1, which is the length of Data Field 2 aka the payload
      // length.
      default_header[6] = payload_len;

      // Copy the header to the output buffer
      memcpy(out, default_header, sizeof(default_header) / sizeof(default_header[0]));

      if (UHF_HEADER_DEBUG)
      {
        printf ("payload_len = %ld\n", payload_len);
        printf ("d_header_len = %ld\n", d_header_len);
        printf ("d__bits_per_byte = %d\n", d_bits_per_byte);
        printf ("Header : ");
        for (int i = 0; i < sizeof(default_header) / sizeof(default_header[0]); i++) {
          printf("0x%02X ",out[i]);
        }
        printf("\n");
      }


      return true;
    }

    bool
    uhf_header::header_parser (
      const unsigned char *header,
      std::vector<tag_t> &tags)
    {
      // @TBD not yet implemented
      return true;
    }

  } /* namespace albertasat */
} /* namespace gr */

