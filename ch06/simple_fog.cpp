#include <osg/Fog>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

int main(int argc, char **argv) {
    osg::ref_ptr<osg::Fog> fog = new osg::Fog;
    fog->setMode(osg::Fog::LINEAR);
    fog->setStart(500.0);
    fog->setEnd(2500.0);
    fog->setColor(osg::Vec4(1.0, 1.0, 0.0, 1.0));

    osg::ref_ptr<osg::Node> model = osgDB::readNodeFile("lz.osg");
    model->getOrCreateStateSet()->setAttributeAndModes(fog.get());

    osgViewer::Viewer viewer;
    viewer.setSceneData(model.get());

    return viewer.run();
}
