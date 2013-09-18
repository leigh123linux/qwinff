/*  QWinFF, a graphical frontend for ffmpeg
 *
 *  Copyright (C) 2011-2013 Timothy Lin <lzh9102@gmail.com>
 *
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

#ifndef NOTIFICATIONSERVICE_H
#define NOTIFICATIONSERVICE_H

#include <QString>

class NotifyLevel
{
public:
    enum {
        INFO = 0,
        WARNING,
        CRITICAL
    };
};

class NotificationService
{
public:

    virtual ~NotificationService();

    /** Send notification
     *  @note Any implementation of this function should not block.
     */
    virtual void send(QString title, QString message) = 0;

    /** Send notification with an image
     *  @note Any implementation of this function should not block.
     */
    virtual void send(QString title, QString message, int level) = 0;

    /** Determine whether the notification service is available.
     */
    virtual bool serviceAvailable() const = 0;
};

#endif // NOTIFICATIONSERVICE_H
