/*
 * Copyright (c) 2016 Mark Liversedge (liversedge@gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _GC_RChart_h
#define _GC_RChart_h 1

#include <RInside.h>
#include <QString>
#include <QDebug>
#include <string.h>

#include "GoldenCheetah.h"
#include "Context.h"
#include "Athlete.h"

class RCallbacks : public Callbacks {
    public:
        // see inst/includes/Callbacks.h for a list of all overrideable methods
        virtual void WriteConsole(const std::string& line, int type) {
            //qDebug()<<"Console>>" <<type<< QString::fromStdString(line);
            strings << QString::fromStdString(line);
        };

        virtual void ShowMessage(const char* message) {
            //qDebug()<<"M:" << QString(message);
            strings << QString(message);
        }

        virtual bool has_ShowMessage() { return true; }
        virtual bool has_WriteConsole() { return true; }

        QStringList &getConsoleOutput() {
            return strings;
        }
    private:
        QStringList strings;
};

class RChart : public GcChartWindow {

    public:
        RChart(Context *context);

    private:
        Context *context;
};


#endif
