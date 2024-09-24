#include "utterchat.h"
#include <QListView>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>
#include <QLabel>
#include <QDebug>
#include <QPixmap>
#include <QAction>
#include <QStackedWidget>

UtterChat::UtterChat(QWidget *parent) : QMainWindow(parent)
{
    setupUI();  // Build the user interface
}

UtterChat::~UtterChat() {}

void UtterChat::setupUI()
{
    QIcon sendIcon(":images/send.png");
    QIcon searchIcon(":images/search.png");
    QPixmap logoPixmap(":/images/logoUtterchat.png");

    // Main widget and layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);  // Main layout for the whole window
    stackedWidget = new QStackedWidget(this);

    // *** LOGIN PAGE ***
    QWidget *loginPage = new QWidget(this);
    QVBoxLayout *loginLayout = new QVBoxLayout(loginPage);

    QLabel *logoLabel = new QLabel(this);
    logoLabel->setPixmap(logoPixmap.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));  // Scale the logo to fit the size
    logoLabel->setAlignment(Qt::AlignCenter);
    QLabel *loginLabel = new QLabel("Login", this);
    loginLabel->setAlignment(Qt::AlignCenter);  // Center the login label
    loginUsername = new QLineEdit(this);
    loginUsername->setMinimumWidth(300);
    loginUsername->setMinimumHeight(40);
    loginUsername->setPlaceholderText("Username");
    loginUsername->setAlignment(Qt::AlignCenter); // Center input text

    loginPassword = new QLineEdit(this);
    loginPassword->setPlaceholderText("Password");
    loginPassword->setMinimumWidth(300);
    loginPassword->setMinimumHeight(40);
    loginPassword->setEchoMode(QLineEdit::Password);
    loginPassword->setAlignment(Qt::AlignCenter); // Center input text

    loginButton = new QPushButton("Login", this);
    loginButton->setMinimumHeight(40);
    loginButton->setMinimumWidth(150);

    goToSignupButton = new QPushButton("Don't have an account? Signup", this);
    goToSignupButton->setMinimumHeight(40);
    goToSignupButton->setMinimumWidth(150);

    // Add a spacer to center the form vertically
    loginLayout->addStretch();
    loginLayout->addWidget(logoLabel, 0, Qt::AlignCenter);  // Add logo at the top and center it
    loginLayout->addWidget(loginLabel, 0, Qt::AlignCenter);  // Align center horizontally
    loginLayout->addWidget(loginUsername, 0, Qt::AlignCenter);
    loginLayout->addWidget(loginPassword, 0, Qt::AlignCenter);
    loginLayout->addWidget(loginButton, 0, Qt::AlignCenter);
    loginLayout->addWidget(goToSignupButton, 0, Qt::AlignCenter);
    loginLayout->addStretch();  // Add stretch at the end to center vertically

    // *** SIGNUP PAGE ***
    QWidget *signupPage = new QWidget(this);
    QVBoxLayout *signupLayout = new QVBoxLayout(signupPage);

    // Add the logo to the signup page
    QLabel *signUpLogoLabel = new QLabel(this);
    signUpLogoLabel->setPixmap(logoPixmap.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));  // Scale the logo to fit the size
    signUpLogoLabel->setAlignment(Qt::AlignCenter);

    QLabel *signupLabel = new QLabel("Sign Up", this);
    signupLabel->setAlignment(Qt::AlignCenter);  // Center the signup label

    signupUsername = new QLineEdit(this);
    signupUsername->setMinimumWidth(300);
    signupUsername->setMinimumHeight(40);
    signupUsername->setPlaceholderText("Username");
    signupUsername->setAlignment(Qt::AlignCenter); // Center input text

    signupPassword = new QLineEdit(this);
    signupPassword->setPlaceholderText("Password");
    signupPassword->setMinimumWidth(300);
    signupPassword->setMinimumHeight(40);
    signupPassword->setEchoMode(QLineEdit::Password);
    signupPassword->setAlignment(Qt::AlignCenter); // Center input text

    signupConfirmPassword = new QLineEdit(this);
    signupConfirmPassword->setPlaceholderText("Confirm Password");
    signupConfirmPassword->setMinimumWidth(300);
    signupConfirmPassword->setMinimumHeight(40);
    signupConfirmPassword->setEchoMode(QLineEdit::Password);
    signupConfirmPassword->setAlignment(Qt::AlignCenter); // Center input text

    signupButton = new QPushButton("Sign Up", this);
    signupButton->setMinimumHeight(40);
    signupButton->setMinimumWidth(150);

    goToLoginButton = new QPushButton("Already have an account? Login", this);
    goToLoginButton->setMinimumHeight(40);
    goToLoginButton->setMinimumWidth(150);

    // Add the widgets to the signup layout, including the logo
    signupLayout->addStretch();
    signupLayout->addWidget(signUpLogoLabel, 0, Qt::AlignCenter); // Add the logo here
    signupLayout->addWidget(signupLabel, 0, Qt::AlignCenter);     // Align center horizontally
    signupLayout->addWidget(signupUsername, 0, Qt::AlignCenter);
    signupLayout->addWidget(signupPassword, 0, Qt::AlignCenter);
    signupLayout->addWidget(signupConfirmPassword, 0, Qt::AlignCenter);
    signupLayout->addWidget(signupButton, 0, Qt::AlignCenter);
    signupLayout->addWidget(goToLoginButton, 0, Qt::AlignCenter);
    signupLayout->addStretch();

    // *** Only Add the Chat Page after Login ***
    QWidget *chatPage = new QWidget(this);  // Chat page is not accessible yet
    QHBoxLayout *chatLayout = new QHBoxLayout(chatPage);

    // Sidebar (left) - Chat List
    chatListView = new QListView(this);
    chatListView->setMaximumWidth(180);
    chatListView->setStyleSheet("background-color: #2e2e3e; color: #FFD700;");

    // Initialize the search bar
    QLineEdit *searchBar = new QLineEdit(this);
    QAction *searchAction = new QAction(searchIcon, "", this);
    searchBar->addAction(searchAction, QLineEdit::LeadingPosition);
    searchBar->setPlaceholderText("Search...");
    searchBar->setMaximumWidth(180);
    searchBar->setMinimumHeight(40);
    searchBar->setStyleSheet("background-color: #1e1e2e; color: #FFD700; padding: 5px;");

    // Create a vertical layout for sidebar (search + chat list)
    QVBoxLayout *sidebarLayout = new QVBoxLayout();
    sidebarLayout->addWidget(searchBar);
    sidebarLayout->addWidget(chatListView);

    // Main chat area
    chatArea = new QTextEdit(this);
    chatArea->setReadOnly(true);  // Messages are read-only
    chatArea->setStyleSheet("background-color: #1e1e2e; color: #FFD700; padding: 10px;");

    // Chat header (above the chat area)
    chatHeader = new QLabel("Chat With Linkan", this);
    chatHeader->setStyleSheet("background-color: #2e2e3e; color: #FFD700; padding: 10px; font-size: 18px;");
    chatHeader->setAlignment(Qt::AlignCenter);

    // Message input box and send button
    messageInput = new QLineEdit(this);
    messageInput->setMinimumHeight(40);
    messageInput->setPlaceholderText("Send a message...");
    sendButton = new QPushButton(this);
    sendButton->setIcon(sendIcon);
    sendButton->setMinimumHeight(40);
    sendButton->setMinimumWidth(70);
    sendButton->setStyleSheet("background-color: #FFD700; color: #1e1e2e;");

    // Layout for message input and send button
    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputLayout->addWidget(messageInput);
    inputLayout->addWidget(sendButton);

    // Add chat elements to the chat layout
    chatLayout->addLayout(sidebarLayout);  // Left side (chat list + search bar)
    chatLayout->addWidget(chatHeader);     // Chat header
    chatLayout->addWidget(chatArea);       // Chat area
    chatLayout->addLayout(inputLayout);    // Message input

    // Add login, signup, and chat pages to the stacked widget
    stackedWidget->addWidget(loginPage);
    stackedWidget->addWidget(signupPage);
    stackedWidget->addWidget(chatPage);

    mainLayout->addWidget(stackedWidget);

    // Set the main layout as the central widget
    setCentralWidget(centralWidget);

    // Set window properties
    setWindowTitle("Login / Signup");
    setMinimumSize(1000, 600);

    // Connect the login/signup switching logic
    connect(goToSignupButton, &QPushButton::clicked, this, &UtterChat::showSignupPage);
    connect(goToLoginButton, &QPushButton::clicked, this, &UtterChat::showLoginPage);

    // Connect the send button to the message sending logic
    connect(sendButton, &QPushButton::clicked, this, [this]() {
        QString message = messageInput->text();
        if (!message.isEmpty()) {
            chatArea->append("<b>Linkan333:</b> " + message);  // Display the message
            messageInput->clear();  // Clear the input field after sending
        }
    });
}

void UtterChat::showSignupPage() {
    stackedWidget->setCurrentIndex(1);
}

void UtterChat::showLoginPage() {
    stackedWidget->setCurrentIndex(0);
}
