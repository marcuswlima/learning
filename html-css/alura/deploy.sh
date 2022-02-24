#!/bin/bash

PROJETO=/home/marcus/Developer/github/learning/html-css/alura/barbearia

echo $PROJETO

rm -rvf /opt/apache-tomcat-8.5.75/webapps/barbearia

cp -rv $PROJETO /opt/apache-tomcat-8.5.75/webapps


