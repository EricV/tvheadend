/*
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MKTS_H__
#define MKTS_H__

typedef struct mk_ts mk_ts_t;

struct mk_ts_pat_pmt {
  uint8_t pat_ts[188];
  uint8_t pmt_ts[188];
};

struct streaming_start;
struct dvr_entry;

mk_ts_t *mk_ts_create(const char *filename,
                      const struct streaming_start *ss,
                      const struct dvr_entry *de);

int mk_ts_build_pat_pmt(struct mk_ts_pat_pmt* buffer, const struct streaming_start* ss, int pmt_pid, int pcr_pid);

void mk_ts_write(mk_ts_t *mkr, const streaming_tsbuf_t *tsbuf);

void mk_ts_close(mk_ts_t *mkr);

#endif // MKTS_H__
