#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: Demodulation
# Author: Thomas
# Description: FSK Receiver
# Generated: Tue Feb 11 19:36:34 2020
##################################################


if __name__ == '__main__':
    import ctypes
    import sys
    if sys.platform.startswith('linux'):
        try:
            x11 = ctypes.cdll.LoadLibrary('libX11.so')
            x11.XInitThreads()
        except:
            print "Warning: failed to XInitThreads()"

from gnuradio import analog
from gnuradio import blocks
from gnuradio import digital
from gnuradio import eng_notation
from gnuradio import filter
from gnuradio import gr
from gnuradio import wxgui
from gnuradio.eng_option import eng_option
from gnuradio.fft import window
from gnuradio.filter import firdes
from gnuradio.wxgui import fftsink2
from grc_gnuradio import wxgui as grc_wxgui
from optparse import OptionParser
import math
import wx


class top_block(grc_wxgui.top_block_gui):

    def __init__(self):
        grc_wxgui.top_block_gui.__init__(self, title="Demodulation")
        _icon_path = "/usr/share/icons/hicolor/32x32/apps/gnuradio-grc.png"
        self.SetIcon(wx.Icon(_icon_path, wx.BITMAP_TYPE_ANY))

        ##################################################
        # Variables
        ##################################################
        self.samp_rate = samp_rate = 4e6
        self.centre_freq = centre_freq = 140e6
        self.centering_constant = centering_constant = 0
        self.baud_rate = baud_rate = 100

        ##################################################
        # Blocks
        ##################################################
        self.wxgui_fftsink2_0 = fftsink2.fft_sink_c(
        	self.GetWin(),
        	baseband_freq=centre_freq,
        	y_per_div=10,
        	y_divs=10,
        	ref_level=0,
        	ref_scale=2.0,
        	sample_rate=samp_rate,
        	fft_size=1024,
        	fft_rate=15,
        	average=False,
        	avg_alpha=None,
        	title='FFT Plot',
        	peak_hold=True,
        )
        self.Add(self.wxgui_fftsink2_0.win)
        self.low_pass_filter_1 = filter.fir_filter_fff(100, firdes.low_pass(
        	1, samp_rate, baud_rate, baud_rate/2, firdes.WIN_HAMMING, 6.76))
        self.low_pass_filter_0 = filter.fir_filter_ccf(1, firdes.low_pass(
        	1, samp_rate, 50e3, 10e3, firdes.WIN_HAMMING, 6.76))
        self.digital_clock_recovery_mm_xx_0 = digital.clock_recovery_mm_ff(16.66, 0.01, 0, 0.1, 0.01)
        self.digital_binary_slicer_fb_0 = digital.binary_slicer_fb()
        self.blocks_file_source_0 = blocks.file_source(gr.sizeof_gr_complex*1, '/home/thomas/Successful_received', False)
        self.blocks_file_sink_3 = blocks.file_sink(gr.sizeof_float*1, '4M_baudrate_finder', False)
        self.blocks_file_sink_3.set_unbuffered(False)
        self.blocks_file_sink_2 = blocks.file_sink(gr.sizeof_char*1, '4M_bits', False)
        self.blocks_file_sink_2.set_unbuffered(False)
        self.blocks_file_sink_1 = blocks.file_sink(gr.sizeof_float*1, '4M_filtered_demod', False)
        self.blocks_file_sink_1.set_unbuffered(False)
        self.blocks_add_const_vxx_0 = blocks.add_const_vff((centering_constant, ))
        self.analog_quadrature_demod_cf_0 = analog.quadrature_demod_cf(1)

        ##################################################
        # Connections
        ##################################################
        self.connect((self.analog_quadrature_demod_cf_0, 0), (self.blocks_file_sink_3, 0))
        self.connect((self.analog_quadrature_demod_cf_0, 0), (self.low_pass_filter_1, 0))
        self.connect((self.blocks_add_const_vxx_0, 0), (self.blocks_file_sink_1, 0))
        self.connect((self.blocks_add_const_vxx_0, 0), (self.digital_clock_recovery_mm_xx_0, 0))
        self.connect((self.blocks_file_source_0, 0), (self.low_pass_filter_0, 0))
        self.connect((self.blocks_file_source_0, 0), (self.wxgui_fftsink2_0, 0))
        self.connect((self.digital_binary_slicer_fb_0, 0), (self.blocks_file_sink_2, 0))
        self.connect((self.digital_clock_recovery_mm_xx_0, 0), (self.digital_binary_slicer_fb_0, 0))
        self.connect((self.low_pass_filter_0, 0), (self.analog_quadrature_demod_cf_0, 0))
        self.connect((self.low_pass_filter_1, 0), (self.blocks_add_const_vxx_0, 0))

    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate
        self.wxgui_fftsink2_0.set_sample_rate(self.samp_rate)
        self.low_pass_filter_1.set_taps(firdes.low_pass(1, self.samp_rate, self.baud_rate, self.baud_rate/2, firdes.WIN_HAMMING, 6.76))
        self.low_pass_filter_0.set_taps(firdes.low_pass(1, self.samp_rate, 50e3, 10e3, firdes.WIN_HAMMING, 6.76))

    def get_centre_freq(self):
        return self.centre_freq

    def set_centre_freq(self, centre_freq):
        self.centre_freq = centre_freq
        self.wxgui_fftsink2_0.set_baseband_freq(self.centre_freq)

    def get_centering_constant(self):
        return self.centering_constant

    def set_centering_constant(self, centering_constant):
        self.centering_constant = centering_constant
        self.blocks_add_const_vxx_0.set_k((self.centering_constant, ))

    def get_baud_rate(self):
        return self.baud_rate

    def set_baud_rate(self, baud_rate):
        self.baud_rate = baud_rate
        self.low_pass_filter_1.set_taps(firdes.low_pass(1, self.samp_rate, self.baud_rate, self.baud_rate/2, firdes.WIN_HAMMING, 6.76))


def main(top_block_cls=top_block, options=None):

    tb = top_block_cls()
    tb.Start(True)
    tb.Wait()


if __name__ == '__main__':
    main()
