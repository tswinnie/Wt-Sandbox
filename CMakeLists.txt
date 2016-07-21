CMAKE_MINIMUM_REQUIRED(VERSION 3.4)

PROJECT(Project_Name)

SET (WT_CONNECTOR "wthttp" CACHE STRING "Connector used (wthttp or wtfcgi)")

ADD_SUBDIRECTORY(source)


