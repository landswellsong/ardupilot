/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "AP_ADSB.h"

class AP_ADSB_Backend
{
public:
    // constructor. This incorporates initialization as well.
    AP_ADSB_Backend(AP_ADSB &_frontend);


    virtual void init() = 0;

    virtual void update() = 0;

    // handle mavlink messages
    virtual void handle_msg(const mavlink_channel_t chan, const mavlink_message_t &msg) {}


    // send static and dynamic data to ADSB transceiver
    virtual void send_configure(const mavlink_channel_t chan) = 0;
    virtual void send_dynamic_out(const mavlink_channel_t chan) = 0;

protected:

    // references
    AP_ADSB &frontend;


    // semaphore for access to shared frontend data
    //HAL_Semaphore _sem;

private:

};
