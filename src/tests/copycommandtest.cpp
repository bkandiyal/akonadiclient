/*
 * Copyright (C) 2014  Bhaskar Kandiyal <bkandiyal@gmail.com>
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

#include "../abstractcommand.h"
#include "../commandrunner.h"
#include "copycommandtest.h"
#include <copycommand.h>

#include <akonadi/control.h>
#include <akonadi/qtest_akonadi.h>


#include <QtCore/QtDebug>

using namespace Akonadi;

QTEST_AKONADIMAIN(CopyCommandTest, NoGUI)

void CopyCommandTest::initTestCase()
{
    AkonadiTest::checkTestIsIsolated();
    Control::start();
}

void CopyCommandTest::testCollectionCopy()
{
    int ret;

    const char *args[4] = {
        "akonadiclient",
        "copy",
        "/res1/foo",
        "/res2" 
    };

    KCmdLineArgs *parsedArgs = getParsedArgs(4, args);

    CopyCommand *command = new CopyCommand(this);
    ret = command->init(parsedArgs);
    QCOMPARE(ret, 0);

    QSignalSpy spy(command, SIGNAL(finished(int)));
    QMetaObject::invokeMethod(command, "start", Qt::QueuedConnection);
    while(spy.count() == 0)
        QTest::qWait(200);
    QVERIFY(spy.takeFirst().at(0) == 0);
}

void CopyCommandTest::testItemCopy()
{
    QVERIFY(true);
}