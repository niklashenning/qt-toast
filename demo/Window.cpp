#include "Window.h"


Window::Window(QWidget* parent)
{
	// Window settings
	setFixedSize(650, 360);
	setWindowTitle("Qt Toast Demo");

	// Create main layout
	m_gridLayout = new QGridLayout();
	m_gridLayout->addWidget(createStaticSettingsGroup(), 0, 0);
	m_gridLayout->addWidget(createToastPresetGroup(), 1, 0);
	m_gridLayout->addWidget(createToastCustomGroup(), 0, 1, 2, 1, Qt::AlignmentFlag::AlignTop);

	// Set layout
	m_centralWidget = new QWidget();
	m_centralWidget->setLayout(m_gridLayout);
	setCentralWidget(m_centralWidget);
	setFocus();
}

Window::~Window()
{
}

void Window::updateStaticSettings()
{
	Toast::setMaximumOnScreen(m_maximumOnScreenSpinbox->value());
	Toast::setSpacing(m_spacingSpinbox->value());
	Toast::setOffset(m_offsetXSpinbox->value(), m_offsetYSpinbox->value());
	Toast::setAlwaysOnMainScreen(m_alwaysOnMainScreenCheckbox->isChecked());

	QString position = m_positionDropdown->currentText();

	if (position == "BOTTOM_LEFT")
	{
		Toast::setPosition(ToastPosition::BOTTOM_LEFT);
	}
	else if (position == "BOTTOM_MIDDLE")
	{
		Toast::setPosition(ToastPosition::BOTTOM_MIDDLE);
	}
	else if (position == "BOTTOM_RIGHT")
	{
		Toast::setPosition(ToastPosition::BOTTOM_RIGHT);
	}
	else if (position == "TOP_LEFT")
	{
		Toast::setPosition(ToastPosition::TOP_LEFT);
	}
	else if (position == "TOP_MIDDLE")
	{
		Toast::setPosition(ToastPosition::TOP_MIDDLE);
	}
	else if (position == "TOP_RIGHT")
	{
		Toast::setPosition(ToastPosition::TOP_RIGHT);
	}
	else if (position == "CENTER")
	{
		Toast::setPosition(ToastPosition::CENTER);
	}
}

void Window::showPresetToast()
{
	Toast* toast = new Toast(this);
	toast->setDuration(rand() % 3001 + 2000);

	QString selectedPreset = m_presetDropdown->currentText();

	if (selectedPreset == "SUCCESS")
	{
		toast->setTitle("Success! Confirmation email sent.");
		toast->setText("Check your email to complete signup.");
		toast->applyPreset(ToastPreset::SUCCESS);
	}
	else if (selectedPreset == "SUCCESS_DARK")
	{
		toast->setTitle("Success! Confirmation email sent.");
		toast->setText("Check your email to complete signup.");
		toast->applyPreset(ToastPreset::SUCCESS_DARK);
	}
	else if (selectedPreset == "WARNING")
	{
		toast->setTitle("Warning! Passwords do not match.");
		toast->setText("Please confirm your password again.");
		toast->applyPreset(ToastPreset::WARNING);
	}
	else if (selectedPreset == "WARNING_DARK")
	{
		toast->setTitle("Warning! Passwords do not match.");
		toast->setText("Please confirm your password again.");
		toast->applyPreset(ToastPreset::WARNING_DARK);
	}
	else if (selectedPreset == "ERROR")
	{
		toast->setTitle("Error! Cannot complete request.");
		toast->setText("Please try again in a few minutes.");
		toast->applyPreset(ToastPreset::ERROR);
	}
	else if (selectedPreset == "ERROR_DARK")
	{
		toast->setTitle("Error! Cannot complete request.");
		toast->setText("Please try again in a few minutes.");
		toast->applyPreset(ToastPreset::ERROR_DARK);
	}
	else if (selectedPreset == "INFORMATION")
	{
		toast->setTitle("Info: Restart required.");
		toast->setText("Please restart the application.");
		toast->applyPreset(ToastPreset::INFORMATION);
	}
	else if (selectedPreset == "INFORMATION_DARK")
	{
		toast->setTitle("Info: Restart required.");
		toast->setText("Please restart the application.");
		toast->applyPreset(ToastPreset::INFORMATION_DARK);
	}

	toast->show();
}

void Window::showCustomToast()
{
	Toast* toast = new Toast(this);
	toast->setDuration(m_durationSpinbox->value());
	toast->setTitle(m_titleInput->text());
	toast->setText(m_textInput->text());
	toast->setBorderRadius(m_borderRadiusSpinbox->value());
	toast->setShowIcon(m_showIconCheckbox->isChecked());
	toast->setIconSize(QSize(m_iconSizeSpinbox->value(), m_iconSizeSpinbox->value()));
	toast->setShowDurationBar(m_showDurationBarCheckbox->isChecked());
	toast->setResetDurationOnHover(m_resetOnHoverCheckbox->isChecked());
	toast->setMinimumWidth(m_minWidthSpinbox->value());
	toast->setMaximumWidth(m_maxWidthSpinbox->value());
	toast->setMinimumHeight(m_minHeightSpinbox->value());
	toast->setMaximumHeight(m_maxHeightSpinbox->value());
	toast->setFadeInDuration(m_fadeInDurationSpinbox->value());
	toast->setFadeOutDuration(m_fadeOutDurationSpinbox->value());

	QString selectedIcon = m_iconDropdown->currentText();

	if (selectedIcon == "SUCCESS")
	{
		toast->setIcon(ToastIcon::SUCCESS);
	}
	else if (selectedIcon == "WARNING")
	{
		toast->setIcon(ToastIcon::WARNING);
	}
	else if (selectedIcon == "ERROR")
	{
		toast->setIcon(ToastIcon::ERROR);
	}
	else if (selectedIcon == "INFORMATION")
	{
		toast->setIcon(ToastIcon::INFORMATION);
	}
	else if (selectedIcon == "CLOSE")
	{
		toast->setIcon(ToastIcon::CLOSE);
	}

	QString selectedCloseButtonSetting = m_closeButtonSettingsDropdown->currentText();

	if (selectedCloseButtonSetting == "TOP")
	{
		toast->setCloseButtonAlignment(ToastButtonAlignment::TOP);
	}
	else if (selectedCloseButtonSetting == "MIDDLE")
	{
		toast->setCloseButtonAlignment(ToastButtonAlignment::MIDDLE);
	}
	else if (selectedCloseButtonSetting == "BOTTOM")
	{
		toast->setCloseButtonAlignment(ToastButtonAlignment::BOTTOM);
	}
	else if (selectedCloseButtonSetting == "DISABLED")
	{
		toast->setShowCloseButton(false);
	}

	toast->show();
}

QGroupBox* Window::createStaticSettingsGroup()
{
	QGroupBox* groupBox = new QGroupBox("Static Settings");

	m_maximumOnScreenSpinbox = new QSpinBox();
	m_maximumOnScreenSpinbox->setRange(1, 10);
	m_maximumOnScreenSpinbox->setValue(Toast::getMaximumOnScreen());
	m_maximumOnScreenSpinbox->setFixedHeight(24);

	m_spacingSpinbox = new QSpinBox();
	m_spacingSpinbox->setRange(0, 100);
	m_spacingSpinbox->setValue(Toast::getSpacing());
	m_spacingSpinbox->setFixedHeight(24);

	m_offsetXSpinbox = new QSpinBox();
	m_offsetXSpinbox->setRange(0, 500);
	m_offsetXSpinbox->setValue(Toast::getOffsetX());
	m_offsetXSpinbox->setFixedHeight(24);

	m_offsetYSpinbox = new QSpinBox();
	m_offsetYSpinbox->setRange(0, 500);
	m_offsetYSpinbox->setValue(Toast::getOffsetY());
	m_offsetYSpinbox->setFixedHeight(24);

	m_alwaysOnMainScreenCheckbox = new QCheckBox("Always on main screen");

	m_positionDropdown = new QComboBox();
	m_positionDropdown->addItems({ "BOTTOM_LEFT", "BOTTOM_MIDDLE",
		"BOTTOM_RIGHT", "TOP_LEFT", "TOP_MIDDLE", "TOP_RIGHT", "CENTER" });
	m_positionDropdown->setCurrentIndex(2);
	m_positionDropdown->setFixedHeight(24);

	m_updateButton = new QPushButton("Update");
	m_updateButton->setFixedHeight(32);
	connect(m_updateButton, SIGNAL(clicked()), this, SLOT(updateStaticSettings()));

	QFormLayout* formLayout = new QFormLayout();
	formLayout->addRow("Max on screen:", m_maximumOnScreenSpinbox);
	formLayout->addRow("Spacing::", m_spacingSpinbox);
	formLayout->addRow("Offset X:", m_offsetXSpinbox);
	formLayout->addRow("Offset Y:", m_offsetYSpinbox);
	formLayout->addRow("Position:", m_positionDropdown);

	QVBoxLayout* vboxLayout = new QVBoxLayout();
	vboxLayout->addLayout(formLayout);
	vboxLayout->addWidget(m_alwaysOnMainScreenCheckbox);
	vboxLayout->addWidget(m_updateButton);
	vboxLayout->addStretch(1);
	groupBox->setLayout(vboxLayout);

	return groupBox;
}

QGroupBox* Window::createToastPresetGroup()
{
	QGroupBox* groupBox = new QGroupBox("Toast Preset");

	m_presetDropdown = new QComboBox();
	m_presetDropdown->addItems({ "SUCCESS", "WARNING", "ERROR", "INFORMATION",
		"SUCCESS_DARK", "WARNING_DARK", "ERROR_DARK", "INFORMATION_DARK" });
	m_presetDropdown->setFixedHeight(26);

	showPresetToastButton = new QPushButton("Show preset toast");
	showPresetToastButton->setFixedHeight(32);
	connect(showPresetToastButton, SIGNAL(clicked()), this, SLOT(showPresetToast()));

	QVBoxLayout* vboxLayout = new QVBoxLayout();
	vboxLayout->addWidget(m_presetDropdown);
	vboxLayout->addWidget(showPresetToastButton);
	vboxLayout->addStretch(1);
	groupBox->setLayout(vboxLayout);

	return groupBox;
}

QGroupBox* Window::createToastCustomGroup()
{
	QGroupBox* groupBox = new QGroupBox("Custom Toast");

	m_durationSpinbox = new QSpinBox();
	m_durationSpinbox->setRange(0, 50000);
	m_durationSpinbox->setValue(5000);
	m_durationSpinbox->setFixedHeight(24);

	m_titleInput = new QLineEdit("Lorem ipsum dolor sit");
	m_titleInput->setFixedHeight(24);

	m_textInput = new QLineEdit("Lorem ipsum dolor sit amet consetetur");
	m_textInput->setFixedHeight(24);

	m_borderRadiusSpinbox = new QSpinBox();
	m_borderRadiusSpinbox->setRange(0, 20);
	m_borderRadiusSpinbox->setValue(2);
	m_borderRadiusSpinbox->setFixedHeight(24);

	m_showIconCheckbox = new QCheckBox("Show icon");

	m_iconDropdown = new QComboBox();
	m_iconDropdown->addItems({ "SUCCESS", "WARNING", "ERROR", "INFORMATION", "CLOSE" });
	m_iconDropdown->setFixedHeight(24);

	m_iconSizeSpinbox = new QSpinBox();
	m_iconSizeSpinbox->setRange(5, 50);
	m_iconSizeSpinbox->setValue(18);
	m_iconSizeSpinbox->setFixedHeight(24);

	m_showDurationBarCheckbox = new QCheckBox("Show duration bar");
	m_showDurationBarCheckbox->setChecked(true);

	m_resetOnHoverCheckbox = new QCheckBox("Reset duration on hover");
	m_resetOnHoverCheckbox->setChecked(true);

	m_closeButtonSettingsDropdown = new QComboBox();
	m_closeButtonSettingsDropdown->addItems({ "TOP", "MIDDLE", "BOTTOM", "DISABLED" });
	m_closeButtonSettingsDropdown->setFixedHeight(24);

	m_minWidthSpinbox = new QSpinBox();
	m_minWidthSpinbox->setRange(0, 1000);
	m_minWidthSpinbox->setFixedHeight(24);

	m_maxWidthSpinbox = new QSpinBox();
	m_maxWidthSpinbox->setRange(0, 1000);
	m_maxWidthSpinbox->setValue(1000);
	m_maxWidthSpinbox->setFixedHeight(24);

	m_minHeightSpinbox = new QSpinBox();
	m_minHeightSpinbox->setRange(0, 1000);
	m_minHeightSpinbox->setFixedHeight(24);

	m_maxHeightSpinbox = new QSpinBox();
	m_maxHeightSpinbox->setRange(0, 1000);
	m_maxHeightSpinbox->setValue(1000);
	m_maxHeightSpinbox->setFixedHeight(24);

	m_fadeInDurationSpinbox = new QSpinBox();
	m_fadeInDurationSpinbox->setRange(0, 1000);
	m_fadeInDurationSpinbox->setValue(250);
	m_fadeInDurationSpinbox->setFixedHeight(24);

	m_fadeOutDurationSpinbox = new QSpinBox();
	m_fadeOutDurationSpinbox->setRange(0, 1000);
	m_fadeOutDurationSpinbox->setValue(250);
	m_fadeOutDurationSpinbox->setFixedHeight(24);

	m_customToastButton = new QPushButton("Show custom toast");
	m_customToastButton->setFixedHeight(32);
	connect(m_customToastButton, SIGNAL(clicked()), this, SLOT(showCustomToast()));

	QFormLayout* formLayout = new QFormLayout();
	formLayout->addRow("Duration:", m_durationSpinbox);
	formLayout->addRow("Title:", m_titleInput);
	formLayout->addRow("Text:", m_textInput);

	QFormLayout* iconSizeLayout = new QFormLayout();
	iconSizeLayout->addRow("Icon size:", m_iconSizeSpinbox);

	QHBoxLayout* iconLayout = new QHBoxLayout();
	iconLayout->addWidget(m_showIconCheckbox);
	iconLayout->addWidget(m_iconDropdown);
	iconLayout->addLayout(iconSizeLayout);
	iconLayout->setContentsMargins(0, 5, 0, 3);

	QHBoxLayout* checkboxLayout = new QHBoxLayout();
	checkboxLayout->addWidget(m_showDurationBarCheckbox);
	checkboxLayout->addWidget(m_resetOnHoverCheckbox);
	checkboxLayout->setContentsMargins(0, 0, 0, 5);

	QHBoxLayout* doubleFormLayout1 = new QHBoxLayout();
	doubleFormLayout1->addWidget(new QLabel("Border radius:"));
	doubleFormLayout1->addWidget(m_borderRadiusSpinbox);
	doubleFormLayout1->addWidget(new QLabel("Close button:"));
	doubleFormLayout1->addWidget(m_closeButtonSettingsDropdown);

	QHBoxLayout* doubleFormLayout2 = new QHBoxLayout();
	doubleFormLayout2->addWidget(new QLabel("Min width:"));
	doubleFormLayout2->addWidget(m_minWidthSpinbox);
	doubleFormLayout2->addWidget(new QLabel("Max width:"));
	doubleFormLayout2->addWidget(m_maxWidthSpinbox);

	QHBoxLayout* doubleFormLayout3 = new QHBoxLayout();
	doubleFormLayout3->addWidget(new QLabel("Min height:"));
	doubleFormLayout3->addWidget(m_minHeightSpinbox);
	doubleFormLayout3->addWidget(new QLabel("Max height:"));
	doubleFormLayout3->addWidget(m_maxHeightSpinbox);

	QHBoxLayout* doubleFormLayout4 = new QHBoxLayout();
	doubleFormLayout4->addWidget(new QLabel("Fade in duration:"));
	doubleFormLayout4->addWidget(m_fadeInDurationSpinbox);
	doubleFormLayout4->addWidget(new QLabel("Fade out duration:"));
	doubleFormLayout4->addWidget(m_fadeOutDurationSpinbox);
	doubleFormLayout4->setContentsMargins(0, 0, 0, 3);

	QVBoxLayout* vboxLayout = new QVBoxLayout();
	vboxLayout->addLayout(formLayout);
	vboxLayout->addLayout(iconLayout);
	vboxLayout->addLayout(checkboxLayout);
	vboxLayout->addLayout(doubleFormLayout1);
	vboxLayout->addLayout(doubleFormLayout2);
	vboxLayout->addLayout(doubleFormLayout3);
	vboxLayout->addLayout(doubleFormLayout4);
	vboxLayout->addWidget(m_customToastButton);
	vboxLayout->addStretch(1);
	groupBox->setLayout(vboxLayout);

	return groupBox;
}
