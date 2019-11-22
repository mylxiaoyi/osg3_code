#include <osg/Geode>
#include <osg/Geometry>
#include <osgViewer/Viewer>
#include <osg/TriangleFunctor>

#include <iostream>

struct FaceCollector {
    void operator() (const osg::Vec3& v1, const osg::Vec3& v2, const osg::Vec3& v3, bool) {
        std::cout << "Face vertices: " << v1.x() << " " << v1.y() << " " << v1.z()
                  << "; " << v2.x() << " " << v2.y() << " " << v2.z()
                  << "; " << v3.x() << " " << v3.y() << " " << v3.z() << std::endl;
    }
};

int main(int argc, char **argv) {
    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    vertices->push_back(osg::Vec3(0.0f, 0.0f, 0.0f));
    vertices->push_back(osg::Vec3(0.0f, 0.0f, 1.0f));
    vertices->push_back(osg::Vec3(1.0f, 0.0f, 0.0f));
    vertices->push_back(osg::Vec3(1.0f, 0.0f, 1.5f));
    vertices->push_back(osg::Vec3(2.0f, 0.0f, 0.0f));
    vertices->push_back(osg::Vec3(2.0f, 0.0f, 1.0f));
    vertices->push_back(osg::Vec3(3.0f, 0.0f, 0.0f));
    vertices->push_back(osg::Vec3(3.0f, 0.0f, 1.5f));
    vertices->push_back(osg::Vec3(4.0f, 0.0f, 0.0f));
    vertices->push_back(osg::Vec3(4.0f, 0.0f, 1.0f));

    osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
    normals->push_back(osg::Vec3(0.0f, -1.0f, 0.0));

    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
    geom->setVertexArray(vertices);
    geom->setNormalArray(normals);
    geom->setNormalBinding(osg::Geometry::BIND_PER_VERTEX);
    geom->addPrimitiveSet(new osg::DrawArrays(GL_QUAD_STRIP, 0, 10));

    osg::TriangleFunctor<FaceCollector> functor;
    geom->accept(functor);

    osg::ref_ptr<osg::Geode> root =new osg::Geode;
    root->addDrawable(geom.get());

    osgViewer::Viewer viewer;
    viewer.setSceneData(root.get());

    return viewer.run();
}
