#QT += core
#QT -= gui
#CONFIG += c++11
#TARGET = testmysql
#CONFIG += console
#CONFIG -= app_bundle
#TEMPLATE = app
#SOURCES += main.cpp

QT       += core sql
QT       -= gui
QT       += sql widgets
QT       += sql
TARGET = testmysql
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp
