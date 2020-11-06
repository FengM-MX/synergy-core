#include "OSXKeyboardGroups.h"

const OSXKeyboardGroups& OSXKeyboardGroups::operator=(CFArrayRef&& src)
{
    if (src != m_groups.get()){
        m_groups = std::move(src);
    }

    return (*this);
}

TISInputSourceRef OSXKeyboardGroups::getSource(SInt32 index) const
{
    return (TISInputSourceRef)CFArrayGetValueAtIndex(m_groups.get(), index);
}

CFDataRef OSXKeyboardGroups::getSourceProperty(SInt32 index, const CFStringRef property) const
{
    TISInputSourceRef resource = getSource(index);
    return (CFDataRef)TISGetInputSourceProperty(resource, property);
}

SInt32 OSXKeyboardGroups::size() const
{
    SInt32 size {0};

    if (m_groups.get()){
        size = CFArrayGetCount(m_groups.get());
    }

    return size;
}
