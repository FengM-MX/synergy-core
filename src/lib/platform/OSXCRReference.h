/*
 * synergy -- mouse and keyboard sharing utility
 * Copyright (C) 2013-2016 Symless Ltd.
 *
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file LICENSE that should have accompanied this file.
 *
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

template<typename T>
class CFReference
{
    T m_reference {nullptr};

public:
    CFReference(T reference) noexcept
    {
        m_reference = reference;
    }

    T get() const{
        return m_reference;
    }

    void release() noexcept
    {
        if (m_reference){
            CFRelease(m_reference);
            m_reference = nullptr;
        }
    }

    CFReference(const CFReference<T>& src) = delete;
    CFReference<T>& operator=(const CFReference<T>& src) = delete;

    CFReference(CFReference<T>&& src) = delete;
    CFReference<T>& operator=(CFReference<T>&& src) = delete;

    CFReference<T>& operator=(T&& src) noexcept
    {
        if (m_reference != src){
            release();
            m_reference = src;
            src = nullptr;
        }

        return *this;
    }

    ~CFReference() noexcept
    {
        release();
    }
};

