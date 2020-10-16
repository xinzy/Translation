#include "utils.h"

Utils::Utils()
{
}

bool Utils::isSoftwareRender()
{
    return QQuickWindow::sceneGraphBackend() == "software";
}
