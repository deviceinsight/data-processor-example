external-data-processor-example
=====================

This is an example data processor which is able to 
ignore events

Create config file:
    
    cp local.cmake.template local.cmake

Compile with:

    mkdir build
    cd build
    cmake .. -DCMAKE_BUILD_TYPE=Relase
    make
   
Testing

    {"ignoredEvents": ["eventKey-toBeIgnored1" , "eventKey-toBeIgnored2"]}
    {"asset":{"assetTypeUrn":null,"assetUrn":"urn:dummy"},"event":{"eventKey":"alarm","tsIso8601":"2015-04-27T08:41:52Z"}}
    {"asset":{"assetTypeUrn":null,"assetUrn":"urn:dummy"},"event":{"eventKey":"eventKey-toBeIgnored1","tsIso8601":"2015-04-27T08:41:52Z"}}