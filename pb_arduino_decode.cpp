/* pb_arduino_decode.cpp -- Helper functions to decode from an Arduino Stream
 *
 * 2013 Alejandro Morell Garcia <alejandro.morell@gmail.com>
 */

#include "pb_arduino_decode.h"

// Make library cross-compatiable
// with Arduino, GNU C++ for tests, and Spark.
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#include "Stream.h"
#elif defined(SPARK)
#include "application.h"
#include "spark_wiring_stream.h"
#endif


bool os_read(pb_istream_t *stream, uint8_t *buf, size_t count);

void pb_istream_from_stream(Stream &stream, pb_istream_t &istream) {
    istream.callback = &os_read;
    istream.state = &stream;
    istream.bytes_left = (size_t)-1;
#ifndef PB_NO_ERRMSG
    istream.errmsg = NULL;
#endif
}

bool os_read(pb_istream_t *stream, uint8_t *buf, size_t count) {
    Stream *s = static_cast<Stream *>(stream->state);
    while (count > 0) {
      size_t readCount = s->readBytes((char *)buf, count);
      count -= readCount;
    }
    return true;
}
