#!/bin/bash

DB=~/Developer/github/_dados/soranatto.db

rm -rvf "$DB"

#criar tabelas
sqlite3 -echo -header "$DB" < "Criando-tabelas.sql" > Criando-tabelas.log

#Views
sqlite3 -echo -header "$DB" < "Vw_ValorTotalPedido.sql" > Vw_ValorTotalPedido.log

#Triggers
sqlite3 -echo -header "$DB" < "trg_CalculaFaturamentoDiario.sql" > trg_CalculaFaturamentoDiario.log

#Novas Linhas
sqlite3 -echo -header "$DB" < "Inserindo-dados.sql" > inserindo_dados.log

#Import CSV
sqlite3 -echo -header "$DB" < "imports-csv.sql" > imports-csv.log

