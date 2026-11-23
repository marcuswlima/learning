#!/bin/bash

read -p "Informe o ID_PEDIDO: " ID_PEDIDO

DB=~/Developer/github/_dados/soranatto.db


sqlite3 "$DB" <<SQL
.parameter init
.parameter set :ID_PEDIDO '$ID_PEDIDO'
.read idpedido.sql
SQL