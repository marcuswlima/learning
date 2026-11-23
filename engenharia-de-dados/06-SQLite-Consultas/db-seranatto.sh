#!/bin/bash

DB=~/Developer/github/_dados/soranatto.db

SQL_FILE="${1:-script.sql}"

sqlite3 "$DB" < "$SQL_FILE" #> SQL_FILE.log 2>erro.log


