/*
 * Copyright 2012 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

/*
 * This class gathers together all the test cases for the gr-filter
 * directory into a single test suite.  As you create new test cases,
 * add them here.
 */

#include "qa_albertasat.h"
#include "qa_my_header.h"
#include "qa_uhf_header.h"
#include "qa_CRC16_Block.h"

CppUnit::TestSuite *
qa_albertasat::suite()
{
  CppUnit::TestSuite *s = new CppUnit::TestSuite("albertasat");
  s->addTest(gr::albertasat::qa_my_header::suite());
  s->addTest(gr::albertasat::qa_uhf_header::suite());
  s->addTest(gr::albertasat::qa_CRC16_Block::suite());

  return s;
}
