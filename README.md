# gnss-sdr-pvt-monitoring-client

Terminal-based utility that allows monitoring the [PVT](https://gnss-sdr.org/docs/sp-blocks/pvt/) block of GNSS-SDR in real-time.

It listens on the specified UDP port and prints the contents of the incoming serialized Monitor_Pvt objects.

**Build**
---

Go to the build directory:

    $ cd gnss-sdr-pvt-monitoring-client/build

Configure and build the application:

    $ cmake ../
    $ make


**Usage**
---

    $ ./gnss-sdr-pvt-monitoring-client <port>

Example:

    $ ./gnss-sdr-pvt-monitoring-client 1234


**Output**
---

```
TOW_at_current_symbol_ms: 422011780
                    week: 1758
                 RX_time: 422011.840000
         user_clk_offset: -0.007631
                   pos_x: 4171698.453954
                   pos_y: 872121.585337
                   pos_z: 4730011.268699
                   vel_x: 781.963661
                   vel_y: 797.741384
                   vel_z: -1136.002415
                  cov_xx: 416.330444
                  cov_yy: 21.824600
                  cov_zz: 142.106415
                  cov_xy: -28.060352
                  cov_yz: -10.148186
                  cov_zx: 169.965729
                latitude: 48.171480
               longitude: 11.808006
                  height: 533.768015
              valid_sats: 6
         solution_status: 5
           solution_type: 0
         AR_ratio_factor: 0.000000
      AR_ratio_threshold: 0.000000
                    gdop: 4.594884
                    pdop: 3.805421
                    hdop: 2.030742
                    vdop: 3.218279
```
