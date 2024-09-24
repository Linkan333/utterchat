#ifndef UTTERCHAT_H
#define UTTERCHAT_H

#include <QMainWindow>
#include <QListView>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QStackedWidget>

class UtterChat : public QMainWindow
{
    Q_OBJECT

public:
    explicit UtterChat(QWidget *parent = nullptr);
    ~UtterChat();

private slots:
    void showSignupPage();
    void showLoginPage();

private:
    QListView *chatListView;     // Sidebar for the list of chats
    QTextEdit *chatArea;         // Main chat area for displaying messages
    QLineEdit *messageInput;     // Input field for typing messages
    QPushButton *sendButton;     // Button to send messages
    QLabel *chatHeader;

    // Login Form
    QLineEdit *loginUsername;
    QLineEdit *loginPassword;
    QPushButton *loginButton;
    QPushButton *goToSignupButton;

    // Signup Form
    QLineEdit *signupUsername;
    QLineEdit *signupPassword;
    QLineEdit *signupConfirmPassword;
    QPushButton *signupButton;
    QPushButton *goToLoginButton;

    QStackedWidget *stackedWidget;

    // Header showing chat details

    void setupUI();              // Function to build the UI
};

#endif // UTTERCHAT_H
