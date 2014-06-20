/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2014  Bhaskar <email>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "abstractcommandtest.h"

#include <kcmdlineargs.h>
#include <kaboutdata.h>

#include <QtDebug>

AbstractCommandTest::AbstractCommandTest()
{
    mAboutData = new KAboutData("akonadiclient", 0, ki18nc("@title program name", "Akonadi Client"),
                         "0.1",
                         ki18nc("@info:shell short description", "A command-line/shell client for Akonadi"),
                         KAboutData::License_GPL);
}

AbstractCommandTest::~AbstractCommandTest()
{

}

KCmdLineArgs* AbstractCommandTest::getParsedArgs(int argc, const char **argv)
{
    /*int argc = args.size();
    char **argv;
    argv = new char *[args.size() + 1];
    for(int i=0; i < args.size(); i++)
    {
        argv[i] = new char[args.at(i).length()];
        argv[i] = args.at(i).toLocal8Bit().data();
        qDebug() << argv[i];
    }*/

    KCmdLineArgs::init(argc, const_cast<char**>(argv), mAboutData);
    KCmdLineArgs::addStdCmdLineOptions(KCmdLineArgs::CmdLineArgNone);

    KCmdLineOptions options;
    options.add("!+command", ki18nc("@info:shell", "Command to execute"));
    options.add("+[options]", ki18nc( "@info:shell", "Options for command"));
    options.add("+[args]", ki18nc( "@info:shell", "Arguments for command"));
    options.add("", ki18nc("@info:shell",
                           "See '<application>%1</application> help'"
                           " for available commands"
                           "\n"
                           "See '<application>%1</application> help command'"
                           " for more information on a specific command.").subs("akonadiclient"));
    KCmdLineArgs::addCmdLineOptions(options);
    /*for(int i=0; i < args.size(); i++)
    {
        delete argv[i];
    }*/

    return KCmdLineArgs::parsedArgs();
}

KAboutData* AbstractCommandTest::getAboutData()
{
    return mAboutData;
}