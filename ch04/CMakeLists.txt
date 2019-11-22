add_executable(simple_objects simple_objects.cpp)
target_link_libraries(simple_objects osg osgViewer)

add_executable(colord_quad colord_quad.cpp)
target_link_libraries(colord_quad osg osgViewer)

add_executable(octahedron octahedron.cpp)
target_link_libraries(octahedron osg osgViewer osgUtil)

add_executable(tessellate_polygon tessellate_polygon.cpp)
target_link_libraries(tessellate_polygon osg osgViewer osgUtil)

add_executable(collect_triangle_faces collect_triangle_faces.cpp)
target_link_libraries(collect_triangle_faces osg osgViewer osgUtil)

add_executable(teaport teaport.cpp)
target_link_libraries(teaport osg osgViewer osgUtil GL glut)
