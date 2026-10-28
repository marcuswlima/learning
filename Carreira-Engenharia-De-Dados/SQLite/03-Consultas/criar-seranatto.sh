#!/bin/bash

DB="${1:-teste.db}"
DB=~/Developer/github/_dados/soranatto.db

SQL_FILE="${1:-script.sql}"

rm -rvf "$DB"

sqlite3 -echo -header "$DB" < "Aula01-preparando-o-ambiente/Criando-tabelas.sql" > Criando-tabelas.log

sqlite3 -echo -header "$DB" < "Aula01-preparando-o-ambiente/Inserindo-dados.sql" > inserindo_dados.log

sqlite3 -echo -header "$DB" < "Aula01-preparando-o-ambiente/imports-csv.sql" > imports-csv.log


