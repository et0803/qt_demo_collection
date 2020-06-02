/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/


#include "webpage.h"
#include "webview.h"
#include <QAuthenticator>
#include <QMessageBox>

WebPage::WebPage(QWebEngineProfile *profile, QObject *parent)
    : QWebEnginePage(profile, parent)
{
    connect(this, &QWebEnginePage::authenticationRequired, this, &WebPage::handleAuthenticationRequired);
    connect(this, &QWebEnginePage::proxyAuthenticationRequired, this, &WebPage::handleProxyAuthenticationRequired);

}

void WebPage::triggerAction(QWebEnginePage::WebAction action, bool checked)
{
    if(action==CopyImageToClipboard)
        QMessageBox::information(0,"title","copy image",QMessageBox::Cancel);

    QWebEnginePage::triggerAction(action,checked);
}

bool WebPage::certificateError(const QWebEngineCertificateError &error)
{
    //QWidget *mainWindow = view()->window();
//    QWidget *mainWindow = XPublicData::myBrower;
//    if (error.isOverridable()) {
//        QDialog dialog(mainWindow);
//        dialog.setModal(true);
//        dialog.setWindowFlags(dialog.windowFlags() & ~Qt::WindowContextHelpButtonHint);
//        Ui::CertificateErrorDialog certificateDialog;
//        certificateDialog.setupUi(&dialog);
//        certificateDialog.m_iconLabel->setText(QString());
//        QIcon icon(mainWindow->style()->standardIcon(QStyle::SP_MessageBoxWarning, 0, mainWindow));
//        certificateDialog.m_iconLabel->setPixmap(icon.pixmap(32, 32));
//        certificateDialog.m_errorLabel->setText(error.errorDescription());
//        dialog.setWindowTitle(tr("Certificate Error"));
//        return dialog.exec() == QDialog::Accepted;
//    }

    //QMessageBox::critical(mainWindow, tr("Certificate Error"), error.errorDescription());
    return false;
}

void WebPage::javaScriptAlert(const QUrl &securityOrigin, const QString &msg)
{
    emit jsAlert(securityOrigin,msg);
}

void WebPage::handleAuthenticationRequired(const QUrl &requestUrl, QAuthenticator *auth)
{
    //QWidget *mainWindow = view()->window();
//    QWidget *mainWindow = XPublicData::myBrower;
//    QDialog dialog(mainWindow);
//    dialog.setModal(true);
//    dialog.setWindowFlags(dialog.windowFlags() & ~Qt::WindowContextHelpButtonHint);

//    Ui::PasswordDialog passwordDialog;
//    passwordDialog.setupUi(&dialog);

//    passwordDialog.m_iconLabel->setText(QString());
//    QIcon icon(mainWindow->style()->standardIcon(QStyle::SP_MessageBoxQuestion, 0, mainWindow));
//    passwordDialog.m_iconLabel->setPixmap(icon.pixmap(32, 32));

//    QString introMessage(tr("Enter username and password for \"%1\" at %2")
//                         .arg(auth->realm()).arg(requestUrl.toString().toHtmlEscaped()));
//    passwordDialog.m_infoLabel->setText(introMessage);
//    passwordDialog.m_infoLabel->setWordWrap(true);

//    if (dialog.exec() == QDialog::Accepted) {
//        auth->setUser(passwordDialog.m_userNameLineEdit->text());
//        auth->setPassword(passwordDialog.m_passwordLineEdit->text());
//    } else {
//        // Set authenticator null if dialog is cancelled
//        *auth = QAuthenticator();
//    }
}

void WebPage::handleProxyAuthenticationRequired(const QUrl &, QAuthenticator *auth, const QString &proxyHost)
{
    //QWidget *mainWindow = view()->window();
//    QWidget *mainWindow = XPublicData::myBrower;
//    QDialog dialog(mainWindow);
//    dialog.setModal(true);
//    dialog.setWindowFlags(dialog.windowFlags() & ~Qt::WindowContextHelpButtonHint);

//    Ui::PasswordDialog passwordDialog;
//    passwordDialog.setupUi(&dialog);

//    passwordDialog.m_iconLabel->setText(QString());
//    QIcon icon(mainWindow->style()->standardIcon(QStyle::SP_MessageBoxQuestion, 0, mainWindow));
//    passwordDialog.m_iconLabel->setPixmap(icon.pixmap(32, 32));

//    QString introMessage = tr("Connect to proxy \"%1\" using:");
//    introMessage = introMessage.arg(proxyHost.toHtmlEscaped());
//    passwordDialog.m_infoLabel->setText(introMessage);
//    passwordDialog.m_infoLabel->setWordWrap(true);

//    if (dialog.exec() == QDialog::Accepted) {
//        auth->setUser(passwordDialog.m_userNameLineEdit->text());
//        auth->setPassword(passwordDialog.m_passwordLineEdit->text());
//    } else {
//        // Set authenticator null if dialog is cancelled
//        *auth = QAuthenticator();
//    }
}