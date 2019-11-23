#include <osg/Texture2D>
#include <osg/Geometry>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

int main(int argc, char **argv) {
    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    vertices->push_back(osg::Vec3(-0.5, 0.0, -0.5));
    vertices->push_back(osg::Vec3(0.5, 0.0, -0.5));
    vertices->push_back(osg::Vec3(0.5, 0.0, 0.5));
    vertices->push_back(osg::Vec3(-0.5, 0.0, 0.5));

    osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
    normals->push_back(osg::Vec3(0.0, -1.0, 0.0));

    osg::ref_ptr<osg::Vec2Array> texcoords = new osg::Vec2Array;
    texcoords->push_back(osg::Vec2(0.0, 0.0));
    texcoords->push_back(osg::Vec2(0.0, 1.0));
    texcoords->push_back(osg::Vec2(1.0, 1.0));
    texcoords->push_back(osg::Vec2(1.0, 0.0));

    osg::ref_ptr<osg::Geometry> quad = new osg::Geometry;
    quad->setVertexArray(vertices.get());
    quad->setNormalArray(normals.get());
    quad->setNormalBinding(osg::Geometry::BIND_OVERALL);
    quad->setTexCoordArray(0, texcoords.get());
    quad->addPrimitiveSet(new osg::DrawArrays(GL_QUADS, 0, 4));

    osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D;
    osg::ref_ptr<osg::Image> image = osgDB::readImageFile("lz.rgb");
    texture->setImage(image.get());

    osg::ref_ptr<osg::Geode> root = new osg::Geode;
    root->addDrawable(quad.get());
    root->getOrCreateStateSet()->setTextureAttributeAndModes(0, texture.get());

    osgViewer::Viewer viewer;
    viewer.setSceneData(root.get());

    return viewer.run();
}
