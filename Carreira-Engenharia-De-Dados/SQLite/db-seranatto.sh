#!/bin/bash

DB="${1:-teste.db}"
DB=~/Developer/github/_dados/soranatto.db

SQL_FILE="${1:-script.sql}"

sqlite3 "$DB" < "$SQL_FILE"


