#pragma once

#include <deque>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGraphicsOpacityEffect>
#include <QtGui/QGuiApplication>
#include <QtGui/QScreen>
#include <QtCore/QTimer>
#include <QtCore/QFile>
#include <QtCore/QPropertyAnimation>
#include "Enums.h"


class Toast : public QDialog
{
    Q_OBJECT

public:
    Toast(QWidget* parent = nullptr);
    ~Toast();

    static int getMaximumOnScreen();
    static int getSpacing();
    static QPoint getOffset();
    static int getOffsetX();
    static int getOffsetY();
    static bool isAlwaysOnMainScreen();
    static QScreen* getFixedScreen();
    static ToastPosition getPosition();
    int getDuration();
    bool isShowDurationBar();
    QString getTitle();
    QString getText();
    QPixmap getIcon();
    bool isShowIcon();
    QSize getIconSize();
    bool isShowIconSeparator();
    int getIconSeparatorWidth();
    QPixmap getCloseButtonIcon();
    bool isShowCloseButton();
    QSize getCloseButtonIconSize();
    int getCloseButtonWidth();
    int getCloseButtonHeight();
    QSize getCloseButtonSize();
    ToastButtonAlignment getCloseButtonAlignment();
    int getFadeInDuration();
    int getFadeOutDuration();
    bool isResetDurationOnHover();
    bool isStayOnTop();
    int getBorderRadius();
    QColor getBackgroundColor();
    QColor getTitleColor();
    QColor getTextColor();
    QColor getIconColor();
    QColor getIconSeparatorColor();
    QColor getCloseButtonIconColor();
    QColor getDurationBarColor();
    QFont getTitleFont();
    QFont getTextFont();
    QMargins getMargins();
    QMargins getIconMargins();
    QMargins getIconSectionMargins();
    QMargins getTextSectionMargins();
    QMargins getCloseButtonMargins();
    int getTextSectionSpacing();
    int getCount();
    int getVisibleCount();
    int getQueuedCount();

    static void setMaximumOnScreen(int maximum);
    static void setSpacing(int spacing);
    static void setOffset(int x, int y);
    static void setOffsetX(int offsetX);
    static void setOffsetY(int offsetY);
    static void setAlwaysOnMainScreen(bool enabled);
    static void setFixedScreen(QScreen* screen);
    static void setPosition(ToastPosition position);
    static void reset();
    void setDuration(int duration);
    void setShowDurationBar(bool enabled);
    void setTitle(QString title);
    void setText(QString text);
    void setIcon(QPixmap icon);
    void setIcon(ToastIcon icon);
    void setShowIcon(bool enabled);
    void setIconSize(QSize size);
    void setShowIconSeparator(bool enabled);
    void setIconSeparatorWidth(int width);
    void setCloseButtonIcon(QPixmap icon);
    void setCloseButtonIcon(ToastIcon icon);
    void setShowCloseButton(bool enabled);
    void setCloseButtonIconSize(QSize size);
    void setCloseButtonSize(QSize size);
    void setCloseButtonWidth(int width);
    void setCloseButtonHeight(int height);
    void setCloseButtonAlignment(ToastButtonAlignment alignment);
    void setFadeInDuration(int duration);
    void setFadeOutDuration(int duration);
    void setResetDurationOnHover(bool enabled);
    void setStayOnTop(bool enabled);
    void setBorderRadius(int borderRadius);
    void setBackgroundColor(QColor color);
    void setTitleColor(QColor color);
    void setTextColor(QColor color);
    void setIconColor(QColor color);
    void setIconSeparatorColor(QColor color);
    void setCloseButtonIconColor(QColor color);
    void setDurationBarColor(QColor color);
    void setTitleFont(QFont font);
    void setTextFont(QFont font);
    void setMargins(QMargins margins);
    void setMarginLeft(int margin);
    void setMarginTop(int margin);
    void setMarginRight(int margin);
    void setMarginBottom(int margin);
    void setIconMargins(QMargins margins);
    void setIconMarginLeft(int margin);
    void setIconMarginTop(int margin);
    void setIconMarginRight(int margin);
    void setIconMarginBottom(int margin);
    void setIconSectionMargins(QMargins margins);
    void setIconSectionMarginLeft(int margin);
    void setIconSectionMarginTop(int margin);
    void setIconSectionMarginRight(int margin);
    void setIconSectionMarginBottom(int margin);
    void setTextSectionMargins(QMargins margins);
    void setTextSectionMarginLeft(int margin);
    void setTextSectionMarginTop(int margin);
    void setTextSectionMarginRight(int margin);
    void setTextSectionMarginBottom(int margin);
    void setCloseButtonMargins(QMargins margins);
    void setCloseButtonMarginLeft(int margin);
    void setCloseButtonMarginTop(int margin);
    void setCloseButtonMarginRight(int margin);
    void setCloseButtonMarginBottom(int margin);
    void setTextSectionSpacing(int spacing);
    void setFixedSize(QSize size);
    void setFixedSize(int width, int height);
    void setFixedWidth(int width);
    void setFixedHeight(int height);
    void applyPreset(ToastPreset preset);


public slots:
    void show();
    void hide();

signals:
    void closed();

protected:
    virtual void enterEvent(QEnterEvent* event) override;
    virtual void leaveEvent(QEvent* event) override;

private slots:
    void hide_();
    void fadeOut();
    void updateDurationBar();
    void deleteAndShowNextInQueue();

private:
    static int s_maximumOnScreen;
    static int s_spacing;
    static int s_offsetX;
    static int s_offsetY;
    static bool s_alwaysOnMainScreen;
    static QScreen* s_fixedScreen;
    static ToastPosition s_position;
    static std::deque<Toast*> s_currentlyShown;
    static std::deque<Toast*> s_queue;
    int m_duration;
    bool m_showDurationBar;
    QString m_title;
    QString m_text;
    QPixmap m_icon;
    bool m_showIcon;
    QSize m_iconSize;
    bool m_showIconSeparator;
    int m_iconSeparatorWidth;
    QPixmap m_closeButtonIcon;
    bool m_showCloseButton;
    QSize m_closeButtonIconSize;
    QSize m_closeButtonSize;
    ToastButtonAlignment m_closeButtonAlignment;
    int m_fadeInDuration;
    int m_fadeOutDuration;
    bool m_resetDurationOnHover;
    bool m_stayOnTop;
    int m_borderRadius;
    QColor m_backgroundColor;
    QColor m_titleColor;
    QColor m_textColor;
    QColor m_iconColor;
    QColor m_iconSeparatorColor;
    QColor m_closeButtonIconColor;
    QColor m_durationBarColor;
    QFont m_titleFont;
    QFont m_textFont;
    QMargins m_margins;
    QMargins m_iconMargins;
    QMargins m_iconSectionMargins;
    QMargins m_textSectionMargins;
    QMargins m_closeButtonMargins;
    int m_textSectionSpacing;
    int m_elapsedTime;
    bool m_fadingOut;
    bool m_used;
    QWidget* m_parent;
    QLabel* m_notification;
    QWidget* m_dropShadowLayer1;
    QWidget* m_dropShadowLayer2;
    QWidget* m_dropShadowLayer3;
    QWidget* m_dropShadowLayer4;
    QWidget* m_dropShadowLayer5;
    QGraphicsOpacityEffect* m_opacityEffect;
    QPushButton* m_closeButton;
    QLabel* m_titleLabel;
    QLabel* m_textLabel;
    QPushButton* m_iconWidget;
    QWidget* m_iconSeparator;
    QWidget* m_durationBarContainer;
    QWidget* m_durationBar;
    QWidget* m_durationBarChunk;
    QTimer* m_durationTimer;
    QTimer* m_durationBarTimer;

    void setupUI();
    void updatePositionXY();
    void updatePositionX();
    void updatePositionY();
    void updateStylesheet();
    QPoint calculatePosition();
    Toast* getPredecessorToast();
    static QImage recolorImage(QImage image, QColor color);
    static QPixmap getIconFromEnum(ToastIcon enumIcon);
    static void updateCurrentlyShowingPositionXY();
    static void updateCurrentlyShowingPositionX();
    static void updateCurrentlyShowingPositionY();
    static void showNextInQueue();

    static const int sc_updatePositionDuration;
    static const int sc_durationBarUpdateInterval;
    static const int sc_dropShadowSize;
    static const QColor sc_successAccentColor;
    static const QColor sc_warningAccentColor;
    static const QColor sc_errorAccentColor;
    static const QColor sc_informationAccentColor;
    static const QColor sc_defaultAccentColor;
    static const QColor sc_defaultBackgroundColor;
    static const QColor sc_defaultTitleColor;
    static const QColor sc_defaultTextColor;
    static const QColor sc_defaultIconSeparatorColor;
    static const QColor sc_defaultCloseButtonIconColor;
    static const QColor sc_defaultBackgroundColorDark;
    static const QColor sc_defaultTitleColorDark;
    static const QColor sc_defaultTextColorDark;
    static const QColor sc_defaultIconSeparatorColorDark;
    static const QColor sc_defaultCloseButtonIconColorDark;
};

