#include <irrlicht.h>

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main() {
    // Initialize Irrlicht
    auto device = createDevice(video::EDT_OPENGL, dimension2d<u32>(800, 600), 32, false, false, false, 0);

    if (!device) {
        return 1;
    }

    device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

    auto driver = device->getVideoDriver();
    auto smgr = device->getSceneManager();

    auto mesh = smgr->getMesh("./sponza.obj");
    if (!mesh) {
        device->drop();
        return 1;
    }
    auto node = smgr->addMeshSceneNode(mesh);

    if (node) {
        node->setMaterialFlag(EMF_LIGHTING, false);
    } else {
        device->drop();
        return 1;
    }

    smgr->addCameraSceneNodeFPS(nullptr, 100.f, 1.f);

    while(device->run()) {
        driver->beginScene(true, true, SColor(255,100,101,140));
        smgr->drawAll();
        driver->endScene();
    }

    device->drop();
    return 0;
}