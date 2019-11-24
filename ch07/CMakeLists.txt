add_executable(hud_camera hud_camera.cpp)
target_link_libraries(hud_camera osg osgDB osgViewer)

add_executable(simulation_loop simulation_loop.cpp)
target_link_libraries(simulation_loop osg osgDB osgViewer osgGA)

add_executable(more_scenes more_scenes.cpp)
target_link_libraries(more_scenes osg osgDB osgViewer)

add_executable(global_multisampling global_multisampling.cpp)
target_link_libraries(global_multisampling osg osgDB osgViewer)

add_executable(stereo_scenes stereo_scenes.cpp)
target_link_libraries(stereo_scenes osg osgDB osgViewer)
