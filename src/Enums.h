#pragma once


enum class ToastPreset
{
    SUCCESS,
    WARNING,
    ERROR,
    INFORMATION,
    SUCCESS_DARK,
    WARNING_DARK,
    ERROR_DARK,
    INFORMATION_DARK
};


enum class ToastIcon
{
    SUCCESS,
    WARNING,
    ERROR,
    INFORMATION,
    CLOSE
};


enum class ToastPosition
{
    BOTTOM_LEFT,
    BOTTOM_MIDDLE,
    BOTTOM_RIGHT,
    TOP_LEFT,
    TOP_MIDDLE,
    TOP_RIGHT,
    CENTER
};


enum class ToastButtonAlignment
{
    TOP,
    MIDDLE,
    BOTTOM
};