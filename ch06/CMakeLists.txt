add_executable(polygon_modes polygon_modes.cpp)
target_link_libraries(polygon_modes osg osgDB osgViewer)

add_executable(lighting_glider lighting_glider.cpp)
target_link_libraries(lighting_glider osg osgDB osgViewer)

add_executable(simple_fog simple_fog.cpp)
target_link_libraries(simple_fog osg osgDB osgViewer)

add_executable(light_sources light_sources.cpp)
target_link_libraries(light_sources osg osgDB osgViewer)

add_executable(textures textures.cpp)
target_link_libraries(textures osg osgDB osgViewer)

add_executable(translucent translucent.cpp)
target_link_libraries(translucent osg osgDB osgViewer)

add_executable(cartoon_cow cartoon_cow.cpp)
target_link_libraries(cartoon_cow osg osgDB osgViewer)

add_executable(bezier_curve bezier_curve.cpp)
target_link_libraries(bezier_curve osg osgDB osgViewer)
