add_executable(add_models_to_scene_graph add_models_to_scene_graph.cpp)
target_link_libraries(add_models_to_scene_graph osg osgViewer osgDB)

add_executable(transformation transformation.cpp)
target_link_libraries(transformation osg osgViewer osgDB)

add_executable(switch_normal switch_normal.cpp)
target_link_libraries(switch_normal osg osgViewer osgDB)

add_executable(lod lod.cpp)
target_link_libraries(lod osg osgViewer osgDB osgUtil)

add_executable(proxyload proxyload.cpp)
target_link_libraries(proxyload osg osgViewer osgDB)

add_executable(animate_switch animate_switch.cpp)
target_link_libraries(animate_switch osg osgViewer osgDB)

add_executable(cessna_structure cessna_structure.cpp)
target_link_libraries(cessna_structure osg osgViewer osgDB)
