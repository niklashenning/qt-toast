# Qt Toast

C++ port of the [pyqttoast](https://github.com/niklashenning/pyqttoast) library (v1.2.0) - a fully customizable and modern toast notification library for Qt

![qt-toast](https://github.com/niklashenning/pyqt-toast/assets/58544929/c104f10e-08df-4665-98d8-3785822a20dc)


## Features
* Supports showing multiple toasts at the same time
* Supports queueing of toasts
* Supports 7 different positions
* Supports multiple screens
* Modern and fully customizable UI


## Usage

Include the `Toast.h` file, instantiate the `Toast`, and show the toast notification with the `show()` method:
```cpp
Toast* toast = new Toast(this);
toast->setDuration(8000);  // Hide after 8 seconds
toast->setTitle("Error! Cannot complete request.");
toast->setText("Please try again in a few minutes.");
toast->show();
```

> **IMPORTANT:** <br>An instance of `Toast` can only be shown **once**. If you want to show another one, even if the content is exactly the same, you have to create another instance.


## Example

Window.h
```cpp
#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include "Toast.h"


class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget* parent = nullptr);

private slots:
    void showToast();

private:
    QPushButton* m_button;
};
```

Window.cpp
```cpp
#include "Window.h"


Window::Window(QWidget* parent)
{
    // Add button and connect click event
    m_button = new QPushButton(this);
    m_button->setText("Show toast");
    connect(m_button, SIGNAL(clicked()), this, SLOT(showToast()));
}

void Window::showToast()
{
    // Shows a toast notification every time the button is clicked
    Toast* toast = new Toast(this);
    toast->setDuration(6000);  // Hide after 6 seconds
    toast->setTitle("Success! Confirmation email sent.");
    toast->setText("Check your email to complete signup.");
    toast->applyPreset(ToastPreset::SUCCESS);  // Apply style preset
    toast->show();
}
```

## Customization

* **Setting the position of the toasts (<u>static</u>):**
```cpp
Toast::setPosition(ToastPosition::BOTTOM_MIDDLE);  // Default: ToastPosition::BOTTOM_RIGHT
```
> **AVAILABLE POSITIONS:** <br> `BOTTOM_LEFT`, `BOTTOM_MIDDLE`, `BOTTOM_RIGHT`, `TOP_LEFT`, `TOP_MIDDLE`, `TOP_RIGHT`, `CENTER`


* **Setting a limit on how many toasts can be shown at the same time (<u>static</u>):**
```cpp
Toast::setMaximumOnScreen(5);  // Default: 3
```
> If you try to show more toasts than the maximum amount on screen, they will get added to a queue and get shown as soon as one of the currently showing toasts is closed.


* **Setting the vertical spacing between the toasts (<u>static</u>):**
```cpp
Toast::setSpacing(20);  // Default: 10
```


* **Setting the x and y offset of the toast position (<u>static</u>):**
```cpp
Toast::setOffset(30, 55);  // Default: 20, 45
```


* **Setting whether the toasts should always be shown on the main screen (<u>static</u>):**
```cpp
Toast::setAlwaysOnMainScreen(true);  // Default: false
```


* **Making the toast show forever until it is closed:**
```cpp
toast->setDuration(0);  // Default: 5000
```


* **Enabling or disabling the duration bar:**
```cpp
toast->setShowDurationBar(false);  // Default: true
```


* **Adding an icon:**
```cpp
toast->setIcon(ToastIcon::SUCCESS);  // Default: ToastIcon::INFORMATION
toast->setShowIcon(true);


// Or setting a custom icon:
toast->setIcon(QPixmap("path/to/your/icon.png"));
```
> **AVAILABLE ICONS:** <br> `SUCCESS`, `WARNING`, `ERROR`, `INFORMATION`, `CLOSE`


* **Setting the icon size:**
```cpp
toast->setIconSize(QSize(14, 14));  // Default: QSize(18, 18)
```


* **Enabling or disabling the icon separator:**
```cpp
toast->setShowIconSeparator(false);  // Default: true
```


* **Setting the close button alignment:**
```cpp
toast->setCloseButtonAlignment(ToastButtonAlignment::MIDDLE);  // Default: ToastButtonAlignment::TOP
```
> **AVAILABLE ALIGNMENTS:** <br> `TOP`, `MIDDLE`, `BOTTOM`


* **Enabling or disabling the close button:**
```cpp
toast->setShowCloseButton(false);  // Default: true
```


* **Customizing the duration of the fade animations (milliseconds):**
```cpp
toast->setFadeInDuration(100);   // Default: 250
toast->setFadeOutDuration(150);  // Default: 250
```


* **Enabling or disabling duration reset on hover:**

```cpp
toast->setResetDurationOnHover(false);  // Default: true
```


* **Making the corners rounded:**
```cpp
toast->setBorderRadius(3);  // Default: 0
```


* **Setting custom colors:**
```cpp
toast->setBackgroundColor(QColor("#292929"));       // Default: #E7F4F9
toast->setTitleColor(QColor("#FFFFFF"));            // Default: #000000
toast->setTextColor(QColor("#D0D0D0"));             // Default: #5C5C5C
toast->setDurationBarColor(QColor("#3E9141"));      // Default: #5C5C5C
toast->setIconColor(QColor("#3E9141"));             // Default: #5C5C5C
toast->setIconSeparatorColor(QColor("#585858"));    // Default: #D9D9D9
toast->setCloseButtonIconColor(QColor("#C9C9C9"));  // Default: #000000
```


* **Setting custom fonts:**
```cpp
toast->setTitleFont(QFont("Times", 10, QFont::Weight::Bold));
toast->setTextFont(QFont("Times", 10);
```


* **Applying a style preset:**
```cpp
toast->applyPreset(ToastPreset::ERROR);
```
> **AVAILABLE PRESETS:** <br> `SUCCESS`, `WARNING`, `ERROR`, `INFORMATION`, `SUCCESS_DARK`, `WARNING_DARK`, `ERROR_DARK`, `INFORMATION_DARK`


* **Setting toast size constraints:**
```cpp
// Minimum and maximum size
toast->setMinimumWidth(100);
toast->setMaximumWidth(350);
toast->setMinimumHeight(50);
toast->setMaximumHeight(120);

// Fixed size (not recommended)
toast->setFixedSize(QSize(350, 80));
```


**<br>Other customization options:**

| Option                     | Description                                                                     | Default                    |
|----------------------------|---------------------------------------------------------------------------------|----------------------------|
| `setFixedScreen()`         | Fixed screen where the toasts will be shown (static)                            | `nullptr`                     |
| `setIconSeparatorWidth()`  | Width of the icon separator that separates the icon and text section            | `2`                        |
| `setCloseButtonIcon()`     | Icon of the close button                                                        | `ToastIcon::CLOSE`          |
| `setCloseButtonIconSize()` | Size of the close button icon                                                   | `QSize(10, 10)`            |
| `setCloseButtonSize()`     | Size of the close button                                                        | `QSize(24, 24)`            |
| `setStayOnTop()`           | Whether the toast stays on top of other windows even when they are focused      | `true`                     |
| `setTextSectionSpacing()`  | Vertical spacing between the title and the text                                 | `8`                        |
| `setMargins()`             | Margins around the whole toast content                                          | `QMargins(20, 18, 10, 18)` |
| `setIconMargins()`         | Margins around the icon                                                         | `QMargins(0, 0, 15, 0)`    |
| `setIconSectionMargins()`  | Margins around the icon section (the area with the icon and the icon separator) | `QMargins(0, 0, 15, 0)`    |
| `setTextSectionMargins()`  | Margins around the text section (the area with the title and the text)          | `QMargins(0, 0, 15, 0)`    |
| `setCloseButtonMargins()`  | Margins around the close button                                                 | `QMargins(0, -8, 0, -8)`   |


## License
This software is licensed under the [MIT license](https://github.com/niklashenning/qt-toast/blob/master/LICENSE).
