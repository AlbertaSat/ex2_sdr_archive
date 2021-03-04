#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir="/home/dineth/ex2_sdr/gr-albertasat/lib"
export GR_CONF_CONTROLPORT_ON=False
export PATH="/home/dineth/ex2_sdr/gr-albertasat/build/lib":$PATH
export LD_LIBRARY_PATH="":$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
albertasat_qa_detect_packet_bb.cc 
