/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     rekols <rekols@foxmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#ifndef DFONTMANAGER_H
#define DFONTMANAGER_H

#include "signalmanager.h"

#include <QThread>
#include <QModelIndex>

class DFontManager : public QThread
{
    Q_OBJECT

public:
    enum Type { Install, ReInstall, UnInstall, HalfwayInstall};
    enum InstallStatus {InstallSuccess, HalfwayInstallSuccess, Failed};
    enum CacheStatus {CacheNow, CacheLater, NoNewFonts};
    static DFontManager *instance();
    DFontManager(QObject *parent = nullptr);
    ~DFontManager();

    void setType(Type type);
    void setInstallFileList(const QStringList &list);
    void setReInstallFile(const QString &reinstFile, const QString &sysFile);
    void setUnInstallFile(const QStringList &filePath);

    void setSystemFontCount(int systemFontCount);

    void setIsWaiting(bool value);

    bool getIsWaiting() const;
    void doCache();



    void setCacheStatus(const CacheStatus &CacheStatus);

private slots:
    void handleInstallOutput();
    void handleReInstallOutput();
    void handleUnInstallOutput();
    void handleProcessFinished(int exitCode);

signals:
    void batchInstall(const QString &filePath, const double &percent);
    void installPositionChanged(const QString &instPath);
    void reinstalling();
    void uninstalling();
    void installFinished(int state, QStringList fileList);
    void reInstallFinished(int state, QStringList fileList);
    void reinstallFinished();
    void uninstallFinished();
    void uninstallFontFinished(const QStringList &uninstallIndex);
    void showFloatingMessage(int totalCount);
    void popUninstallDialog();

protected:
    void run();

private:
    bool doCmd(const QStringList &arguments);
    void handleInstall(bool isHalfwayInstall = false);
    void handleUnInstall();
    void handleReInstall();
    void doInstall(const QStringList &fileList, bool reinstal = false);
    void doReInstall(const QStringList &fileList);
    void doUninstall(const QStringList &fileList);

private:
    SignalManager *m_signalManager = SignalManager::instance();
    QStringList m_instFileList;
    QStringList m_installOutList;
    QStringList m_uninstFile;
    QString m_reinstFile;
    QString m_sysFile;
    Type m_type;
    CacheStatus m_CacheStatus;
    int m_systemFontCount = 0;
    bool isWaiting = false;
};

#endif
