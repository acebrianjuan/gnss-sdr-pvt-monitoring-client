/*!
 * \file test_read.cc
 * \brief Terminal-based testing utility that listens on the specified udp
 * port and recovers incoming serialized Monitor_Pvt objects
 * \author Álvaro Cebrián Juan, 2019. acebrianjuan(at)gmail.com
 *
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2018  (see AUTHORS file for a list of contributors)
 *
 * GNSS-SDR is a software defined Global Navigation
 *          Satellite Systems receiver
 *
 * This file is part of GNSS-SDR.
 *
 * GNSS-SDR is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GNSS-SDR is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNSS-SDR. If not, see <https://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------
 */

#include "monitor_pvt_udp_source.h"
#include <boost/lexical_cast.hpp>
#include <chrono>
#include <iostream>
#include <ncurses.h>
#include <thread>

int main(int argc, char* argv[])
{
    try
        {
            // Check command line arguments.
            if (argc != 2)
                {
                    // Print help.
                    std::cerr << "Usage: gnss-sdr-pvt-monitoring-client <port>" << std::endl;
                    return 1;
                }

            unsigned short port = boost::lexical_cast<unsigned short>(argv[1]);
            Monitor_Pvt_Udp_Source udp_source(port);

            initscr();  // Initialize ncurses.
            printw("Listening on port %d UDP...\n", port);
            refresh();  // Update the screen.

            udp_source.print_variable_names_column();

            while (true)
                {
                    udp_source.print_values_column();
                }
        }
    catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            return 1;
        }

    return 0;
}
