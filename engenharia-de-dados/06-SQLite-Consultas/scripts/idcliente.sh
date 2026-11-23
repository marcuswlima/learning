#!/bin/bash

read -p "Informe o ID_CLIENTE: " ID_CLIENTE

DB=~/Developer/github/_dados/soranatto.db


sqlite3 "$DB" <<SQL
.parameter init
.parameter set :ID_CLIENTE '$ID_CLIENTE'
.read idcliente.sql
SQL