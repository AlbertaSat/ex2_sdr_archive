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


#ifndef INCLUDED_ALBERTASAT_UHF_HEADER_H
#define INCLUDED_ALBERTASAT_UHF_HEADER_H

#include <vector>

#include <gnuradio/tags.h>
#include <gnuradio/digital/api.h>
#include <gnuradio/digital/packet_header_default.h>

#include <boost/enable_shared_from_this.hpp>

#include <albertasat/api.h>

#define BITS_PER_HEADER_BYTE 1 // 2GFSK modulation
#define DEFAULT_LEN_TAG_KEY "packet_len"
#define DEFAULT_NUM_TAG_KEY "slot_packet_num"

#define PACKET_PREAMBLE_BITS        40 // 5 bytes
#define PACKET_SYNC_BITS             8 // 1 byte
#define PACKET_DATA_FIELD_1_BITS     8 // 1 byte
#define PACKET_DATA_FIELD_2_BITS  1024 // 128 bytes, max
#define PACKET_CRC16_BITS           16 // 2 bytes

#define HEADER_SIZE_BITS \
    PACKET_PREAMBLE_BITS + \
    PACKET_SYNC_BITS + \
    PACKET_DATA_FIELD_1_BITS
#define HEADER_SIZE_BYTES ((HEADER_SIZE_BITS) / 8)

#define MAX_PAYLOAD_BYTES 128

#define DEFAULT_SYNC_WORD 0x7E

namespace gr {
  namespace albertasat {

    /*!
     * @brief A utility for the UHF header.
     *
     * @details It is based on the @p gr-digital packet_header_default to ensure
     * compatibility with other GNU Radio packet header blocks.
     *
     * The @p packet_header_default functionality is mostly ignored as we need
     * to support the header as defined by EnduroSat.
     *
     * @see <***** put a ref here >
     *
      * \dot
      * digraph html {
      *   packet [shape=none, margin=0, label=<
      *   <TABLE BORDER="0" CELLBORDER="1" CELLSPACING="0" CELLPADDING="4">
      *   <TR>
      *   <TD ROWSPAN="1">Preamble 40 bits {0xAA, 0xAA, 0xAA, 0xAA, 0xAA}</TD>
      *   <TD ROWSPAN="1">Sync Word 8 bits {0x7E}</TD>
      *   <TD ROWSPAN="1">Data Field 1 8 bits</TD>
      *   <TD ROWSPAN="1">Data Field 2 [0, 1024] bits</TD>
      *   <TD ROWSPAN="1">CRC16 16 bits</TD>
      *   </TR>
      *   </TABLE>>];
      * }
      * \enddot
     */
    class ALBERTASAT_API uhf_header : public gr::digital::packet_header_default
    {
    public:

      /**
       * @brief A public shared pointer type.
       */
      typedef boost::shared_ptr<uhf_header> sptr;

      ~uhf_header();

      /*!
       * @brief Returns a pointer to a new @p uhf_header object that can build a
       * UHF packet header from a tagged stream or received packet.
       *
       * @details See constructor below.
       */
     static sptr make(
       const std::string &len_tag_key = DEFAULT_LEN_TAG_KEY,
       const std::string &num_tag_key = DEFAULT_NUM_TAG_KEY,
       const int bits_per_byte = BITS_PER_HEADER_BYTE);

     /*!
      * \brief Header formatter. Encodes the header information in the given tags into bits and places them into \p out
      *
      *
      * Uses the following header format:
      * - Bit 0: Reserved; always set to zero
      * - Bits 1-12: The payload length in bytes (what was stored in the tag with key \p len_tag_key)
      * - Bits 13-24: A code indicating the modulation-FEC scheme used for the payload
      * - Bits 25-47: If a TDMA scheme is employed, the LSB of the 64-bit slot number for this packet,
      *   otherwise a packet number that increments each time this method is invoked.
      *   (slot/packet number stored in the tag with key \p num_tag_key)
      * - Bits 48-63: 16-bit CRC
      *
      * If the header is used for a TDMA scheme, then the formatter expects to find in the \p tags
      * a tag with the key num_tag_key and a tag value corresponding to the slot number. Otherwise,
      * as explained just above, the formatter increments the current packet number and places
      * the result in the header.
      *
      * @param payload_len The number of bytes in the payload
      * @param out Pointer to an byte array that contains the formatted packet header on return
      * @param tags Vector of tags
      */
     bool
     header_formatter (
       long payload_len,
       unsigned char *out,
       const std::vector<tag_t> &tags);

     /*!
      * \brief Header parser. Inverse function to header_formatter().
      *
      * Reads the bit stream in \p header and writes a corresponding tag into \p tags.
      *
      * @param header Pointer to the input header bytes
      * @param tags Vector of tags
      */
     bool
     header_parser (const unsigned char *header, std::vector<tag_t> &tags);

    private:
     uhf_header(
       const std::string &len_tag_key,
       const std::string &num_tag_key,
       const int bits_per_byte);

    };

  } // namespace albertasat
} // namespace gr

#endif /* INCLUDED_ALBERTASAT_UHF_HEADER_H */
