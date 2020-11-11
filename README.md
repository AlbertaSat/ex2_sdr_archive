# Software Defined Radio for Ex-Alta 2
This repo contains GNU Radio modules that support UHF receiver and transceiver and S band transceiver operation.


@TODO add to this as the project is built up.


------------------ Previous Readme doc ---------------------
The S band flowgraph is copied (will be adapted eventually) from the K2Sat Software Defined Radio (SDR) developed by Daniel Estévez and the K2Sat team which used a very similar ClydeSpace S band transmitter for image downlink, contained in the [gr-satellites project](https://github.com/daniestevez/gr-satellites). Changes to be made include: 
- Modifying data rate to 10 Mbps 
- Changes to Input source 
- Output packets to CSP/ZMQ

*You must have gr-satellites installed for these to run.* See its [documentation](https://gr-satellites.readthedocs.io/en/latest/installation.html) for instructions on installation.

The UHF Software Defined Radio will also likely use some blocks provided by gr-satellites.

## Example Decoding
Open up the [image receiver](apps/ex2_image_receiver.grc) flowgraph in the GNU Radio Companion and modify the paths for the [sample input](https://drive.google.com/file/d/1K6QL-l2AjZtcWA-4pOFsTMeyn3PUM74F/view) in the File Source block and the output path in the File Receiver block. Run the flowgraph. Then open the terminal, navigate to this repo's directory, and run:
```
./ex2_image_receiver.py
```
If that complains about a missing "satellites" module, try:
```
export PYTHONPATH=/usr/local/lib/python3/dist-packages/
```
Or similar command if your path is different. Then retry the decoder. You should see a GNU Radio graph depicting the QPSK demodulation. Once it finishes (~10 seconds), open the image file! It should look [like this](https://destevez.net/wp-content/uploads/2018/07/image_0.jpg).


## receiver.grc & transmitter.grc
#### These will soon be deprecated
Receiver built according to [this guide](https://nccgroup.github.io/RFTM/fsk_receiver.html)
Transmitter built according to [this guide](https://nccgroup.github.io/RFTM/fsk_transmitter.html)

These flowgraphs are configured to work with rtl-sdr USB dongles, so Osmocom Source/Sink blocks need to be added to gnu radio before using. Follow [the installation guide](https://osmocom.org/projects/rtl-sdr/wiki/Rtl-sdr). Dependencies for the osmocom block are listed [here](https://formulae.brew.sh/formula/gr-osmosdr).
