# ex2_sdr
AlbertaSat ground station software for modulation and demodulation.

Receiver built according to this guide --> https://nccgroup.github.io/RFTM/fsk_receiver.html
Transmitter built according to this guide --> https://nccgroup.github.io/RFTM/fsk_transmitter.html

These flowgraphs are configured to work with rtl-sdr USB dongles, so Osmocom Source/Sink blocks need to be added to gnu radio before using. Follow --> https://osmocom.org/projects/rtl-sdr/wiki/Rtl-sdr. Dependencies for the osmocom block are listed here --> https://formulae.brew.sh/formula/gr-osmosdr
