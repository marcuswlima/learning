#!/bin/bash

rm -rf /opt/apache-tomcat-8.5.75


wget http://dlcdn.apache.org/tomcat/tomcat-8/v8.5.75/bin/apache-tomcat-8.5.75.tar.gz
tar -xvf apache-tomcat-8.5.75.tar.gz -C /opt

rm -v apache-tomcat-8.5.75.tar.gz


