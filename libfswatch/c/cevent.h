/* 
 * Copyright (C) 2014, Enrico M. Crisostomo
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef FSW__CEVENT_H
#  define FSW__CEVENT_H

#  include <ctime>

#  ifdef __cplusplus
extern "C"
{
#  endif

  /*
   * Each element of this enum represents a backend-agnostic change flag,
   * providing information about the different kind of changes an event refers
   * to.
   */
  enum fsw_event_flag
  {
    PlatformSpecific = 1,
    Created = 2,
    Updated = 4,
    Removed = 8,
    Renamed = 16,
    OwnerModified = 32,
    AttributeModified = 64,
    IsFile = 128,
    IsDir = 256,
    IsSymLink = 512,
    Link = 1024
  };

  /*
   * An file change event is represented as an instance of this struct where:
   *   - path is the path where the event was triggered.
   *   - evt_time the time when the event was triggered.
   *   - flags is an array of fsw_event_flag of size flags_num.
   *   - flags_num is the size of the flags array.
   */
  typedef struct fsw_cevent
  {
    char * path;
    time_t evt_time;
    fsw_event_flag * flags;
    unsigned int flags_num;
  } fsw_cevent;

  /*
   * A function pointer of type FSW_CEVENT_CALLBACK is used by the API as a
   * callback to provide information about received events.  The callback is
   * passed the following arguments:
   *   - events, a const pointer to a const array of events of type fsw_cevent.
   *   - event_num, the size of the *events array.
   */
  typedef void (*FSW_CEVENT_CALLBACK)(fsw_cevent const * const * const events,
    const unsigned int event_num);

#  ifdef __cplusplus
}
#  endif

#endif  /* FSW__CEVENT_H */

