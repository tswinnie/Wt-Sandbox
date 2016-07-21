SET(WT_PROJECT_SOURCE  main.cpp)

SET(WT_PROJECT_TARGET index.wt)

ADD_EXECUTABLE(${WT_PROJECT_TARGET} ${WT_PROJECT_SOURCE})

TARGET_LINK_LIBRARIES(${WT_PROJECT_TARGET} ${WT_CONNECTOR} wt)

INCLUDE_DIRECTORIES(/usr/local/include/Wt)

#COPY FILES FUNCTION
function    (cm_export_file FILE DEST)
    if    (NOT TARGET export-files)
        add_custom_target(export-files ALL COMMENT "Exporting files into build tree")
    endif (NOT TARGET export-files)
    get_filename_component(FILENAME "${FILE}" NAME)
    add_custom_command(TARGET export-files COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_CURRENT_SOURCE_DIR}/${FILE}" "${CMAKE_CURRENT_BINARY_DIR}/${DEST}/${FILENAME}")
    install(FILES "${FILE}" DESTINATION "${DEST}")
endfunction (cm_export_file)

#COPY ALL JS RESOURCE FILES
cm_export_file("../JS/jquery-2.2.3.min.js" "/")
cm_export_file("../JS/bootstrap.min.js" "/")
cm_export_file("../JS/mdb.min.js" "/")
cm_export_file("../JS/tether.min.js" "/")

#COPY ALL CSS RESOURCE FILES
cm_export_file("../CSS/bootstrap.min.css" "/")
cm_export_file("../CSS/mdb.min.css" "/")
cm_export_file("../CSS/moz-transitions.css" "/")
cm_export_file("../CSS/transitions.css" "/")
cm_export_file("../CSS/webkit-transitions.css" "/")
cm_export_file("../CSS/style.css" "/")

