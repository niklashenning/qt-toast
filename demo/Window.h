#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include "../src/Toast.h"


class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget* parent = nullptr);
    ~Window();

private slots:
    void updateStaticSettings();
    void showPresetToast();
    void showCustomToast();

private:
    QGridLayout* m_gridLayout;
    QWidget* m_centralWidget;
    QSpinBox* m_maximumOnScreenSpinbox;
    QSpinBox* m_spacingSpinbox;
    QSpinBox* m_offsetXSpinbox;
    QSpinBox* m_offsetYSpinbox;
    QCheckBox* m_alwaysOnMainScreenCheckbox;
    QComboBox* m_positionDropdown;
    QPushButton* m_updateButton;
    QComboBox* m_presetDropdown;
    QPushButton* showPresetToastButton;
    QSpinBox* m_durationSpinbox;
    QLineEdit* m_titleInput;
    QLineEdit* m_textInput;
    QSpinBox* m_borderRadiusSpinbox;
    QCheckBox* m_showIconCheckbox;
    QComboBox* m_iconDropdown;
    QSpinBox* m_iconSizeSpinbox;
    QCheckBox* m_showDurationBarCheckbox;
    QCheckBox* m_resetOnHoverCheckbox;
    QComboBox* m_closeButtonSettingsDropdown;
    QSpinBox* m_minWidthSpinbox;
    QSpinBox* m_maxWidthSpinbox;
    QSpinBox* m_minHeightSpinbox;
    QSpinBox* m_maxHeightSpinbox;
    QSpinBox* m_fadeInDurationSpinbox;
    QSpinBox* m_fadeOutDurationSpinbox;
    QPushButton* m_customToastButton;

    QGroupBox* createStaticSettingsGroup();
    QGroupBox* createToastPresetGroup();
    QGroupBox* createToastCustomGroup();
};