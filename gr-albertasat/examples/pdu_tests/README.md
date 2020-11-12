## pdu_tests examples

Various examples and tests to understand using protocol data units (PDUs).

### `gen_rand_pdus.grc`

Generate a fixed-size (128 bytes) PDU and display the byte values. Notice the `payload_len` tag is displayed in the Time Sink.

### `msg_test.grc`

Show how to generate messages with different periods and display.

### `my_header_test.grc`

Used to confirm the results from the HOWTO-simple-noblock describing how to make and test a simple noblock block.

### `uhf_header_test.grc`

Used to confirm the results from the HOWTO-extended-noblock describing how to make and test a noblock block based on the `gr-digital` `packet_header_default` class.

### `tx_packet_v01.grc`

Demonstrate how to generate PDUs, use the `uhf_header` block from the HOWTO-extended-noblock to create a header and prepend that to a PDU.
