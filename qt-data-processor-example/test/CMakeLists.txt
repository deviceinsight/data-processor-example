SET(connector_SOURCES
    ../src/util/JsonUtil.cpp
   )

SET(connector_HEADERS
    ../src/util/JsonUtil.h
   )


SET(LIBRARIES
    ${QT_QTCORE_LIBRARY}
    ${QT_LIBRARIES}
   )


# copy test resource file to output folder
# file(GLOB TEST_RES
#      "resources/*.*"
#     )
# file(COPY ${TEST_RES} DESTINATION resources)
 
 
 
# SET(QT_USE_QTTEST TRUE)
# enable_testing()
 
 
# QT4_WRAP_CPP(dummy_HEADERS_MOC TestDummy.h )
# add_executable(dummytest TestDummy.cpp ${dummy_HEADERS_MOC} )
# target_link_libraries(dummytest ${LIBRARIES} ${QT_QTTEST_LIBRARY})
# add_test(dummytest dummytest)
