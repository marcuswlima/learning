#!/bin/bash

PROJETO=/home/marcus/Developer/github/learning/vim/alura/topcasafina

rm -rvf /opt/apache-tomcat-8.5.75/webapps/topcasafina

cp -rv $PROJETO /opt/apache-tomcat-8.5.75/webapps
