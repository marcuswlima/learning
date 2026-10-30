#!/bin/bash

DB=~/Developer/github/_dados/soranatto.db

rm -rvf "$DB"

#criar tabelas
sqlite3 -echo -header "$DB" < "Aula01-preparando-o-ambiente/Criando-tabelas.sql" > Criando-tabelas.log

#Views
sqlite3 -echo -header "$DB" < "Aula01-preparando-o-ambiente/Vw_ValorTotalPedido.sql" > Vw_ValorTotalPedido.log

#Triggers
sqlite3 -echo -header "$DB" < "Aula01-preparando-o-ambiente/trg_CalculaFaturamentoDiario.sql" > trg_CalculaFaturamentoDiario.log

#Novas Linhas
sqlite3 -echo -header "$DB" < "Aula01-preparando-o-ambiente/Inserindo-dados.sql" > inserindo_dados.log

#Import CSV
sqlite3 -echo -header "$DB" < "Aula01-preparando-o-ambiente/imports-csv.sql" > imports-csv.log

#Import CSV
#sqlite3 -echo -header "$DB" < "Aula01-preparando-o-ambiente/imports-csv.sql" > imports-csv.log

