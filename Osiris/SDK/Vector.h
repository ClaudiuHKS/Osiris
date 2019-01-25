#pragma once

struct Vector final {
    constexpr Vector& operator=(const float* array) noexcept
    {
        x = array[0];
        y = array[1];
        z = array[2];
        return *this;
    }

    constexpr Vector& operator+(const Vector& v) noexcept
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    constexpr Vector& operator+=(const Vector& v) noexcept
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    constexpr Vector& operator-(const Vector& v) noexcept
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    constexpr auto operator-(const Vector& v) const noexcept
    {
        return Vector{ x - v.x, y - v.y, z - v.z };
    }

    constexpr Vector& operator/=(float div) noexcept
    {
        x /= div;
        y /= div;
        z /= div;
        return *this;
    }

    float length() const noexcept
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    float length2D() const noexcept
    {
        return std::sqrt(x * x + y * y);
    }

    void normalize() noexcept
    {
        x = std::isfinite(x) ? std::remainderf(x, 360.0f) : 0.0f;
        y = std::isfinite(z) ? std::remainderf(z, 360.0f) : 0.0f;
        z = 0.0f;
    }

    float x, y, z;
};
