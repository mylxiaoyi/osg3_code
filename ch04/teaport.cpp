#include <GL/glut.h>
#include <osg/Drawable>
#include <osg/Geode>
#include <osgViewer/Viewer>

class TeaportDrawable : public osg::Drawable {
public:
    TeaportDrawable(float size = 1.0f) : _size(size) {}
    TeaportDrawable(const TeaportDrawable& copy, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) : osg::Drawable(copy, copyop), _size(copy._size) {}

    META_Object(osg, TeaportDrawable);

    virtual osg::BoundingBox computeBoundingBox() const;
    virtual void drawImplementation(osg::RenderInfo&) const;

protected:
    float _size;
};

osg::BoundingBox TeaportDrawable::computeBoundingBox() const {
    osg::Vec3 min(-_size, -_size, -_size), max(_size, _size, _size);
    return osg::BoundingBox(min, max);
}

void TeaportDrawable::drawImplementation(osg::RenderInfo &) const {
    glFrontFace(GL_CW);
    glutSolidTeapot(_size);
    glFrontFace(GL_CCW);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);

    osg::ref_ptr<osg::Geode> root = new osg::Geode;
    root->addDrawable(new TeaportDrawable(1.0f));

    osgViewer::Viewer viewer;
    viewer.setSceneData(root.get());

    return viewer.run();
}
