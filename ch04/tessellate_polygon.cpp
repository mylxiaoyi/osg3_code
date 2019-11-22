#include <osg/Geode>
#include <osg/Geometry>
#include <osgUtil/Tessellator>
#include <osgViewer/Viewer>

int main(int argc, char **argv) {
    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    vertices->push_back(osg::Vec3(0.0f, 0.0f, 0.0f));
    vertices->push_back(osg::Vec3(2.0f, 0.0f, 0.0f));
    vertices->push_back(osg::Vec3(2.0f, 0.0f, 1.0f));
    vertices->push_back(osg::Vec3(1.0f, 0.0f, 1.0f));
    vertices->push_back(osg::Vec3(1.0f, 0.0f, 2.0f));
    vertices->push_back(osg::Vec3(2.0f, 0.0f, 2.0f));
    vertices->push_back(osg::Vec3(2.0f, 0.0f, 3.0f));
    vertices->push_back(osg::Vec3(0.0f, 0.0f, 3.0f));

    osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
    normals->push_back(osg::Vec3(0.0f, -1.0f, 0.0f));

    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
    geom->setVertexArray(vertices.get());
    geom->setNormalArray(normals);
    geom->setNormalBinding(osg::Geometry::BIND_OVERALL);
    geom->addPrimitiveSet(new osg::DrawArrays(GL_POLYGON, 0, 8));

    osgUtil::Tessellator tessellator;
    tessellator.retessellatePolygons(*geom);

    osg::ref_ptr<osg::Geode> root = new osg::Geode;
    root->addDrawable(geom.get());

    osgViewer::Viewer viewer;
    viewer.setSceneData(root.get());

    return viewer.run();
}
