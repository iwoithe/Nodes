add_executable(nodes
    nodes/addnode.cpp
    nodes/addnode.h
    nodes/groupnode.cpp
    nodes/groupnode.h
    nodes/numbernode.cpp
    nodes/numbernode.h
    nodes/outputnode.cpp
    nodes/outputnode.h
    main.cpp
    node.cpp
    node.h
    nodetree.cpp
    nodetree.h
    properties.cpp
    properties.h
    types.h
)

if (QT_SUPPORT)
    target_link_libraries(nodes PRIVATE ${QT_LIBRARIES})
endif (QT_SUPPORT)
