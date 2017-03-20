SET(external_data_processor_SOURCES
    main.cpp
    CommunicationHandler.cpp
    Configuration.cpp
    EventProcessor.cpp
    util/JsonUtil.cpp
   )

SET(external_data_processor_HEADERS
    util/JsonUtil.h
    CommunicationHandler.h
    Configuration.h
    EventProcessor.h
   )

   
qt4_automoc(${external_data_processor_SOURCES})
QT4_WRAP_CPP(external_data_processor_HEADERS_MOC ${external_data_processor_HEADERS})

add_executable(external-data-processor-example ${external_data_processor_HEADERS_MOC} ${external_data_processor_SOURCES} )

SET(LIBRARIES
    ${QT_QTCORE_LIBRARY}
    ${QT_LIBRARIES}
    ${QJSON_LIB}
   )

target_link_libraries(external-data-processor-example ${LIBRARIES})
