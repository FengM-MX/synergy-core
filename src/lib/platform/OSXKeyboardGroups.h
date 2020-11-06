#ifndef OSXKEYBOARDGROUPS_H
#define OSXKEYBOARDGROUPS_H

#include <Carbon/Carbon.h>
#include "OSXCRReference.h"

class OSXKeyboardGroups
{
    CFReference<CFArrayRef> m_groups {nullptr};

public:
    const OSXKeyboardGroups& operator=(CFArrayRef&& src);

    TISInputSourceRef getSource(SInt32 index) const;
    CFDataRef getSourceProperty(SInt32 index, const CFStringRef property) const;
    SInt32 size() const;
};

#endif // OSXKEYBOARDGROUPS_H
