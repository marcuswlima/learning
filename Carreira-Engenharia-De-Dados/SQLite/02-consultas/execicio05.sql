-- Configuração da saída
.headers on
.mode box
.nullvalue NULL

.tables

SELECT * FROM colaboradores ORDER BY nome ASC LIMIT 5;

SELECT * FROM produtos WHERE descricao IS NULL;