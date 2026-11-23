-- Configuração da saída
.headers on
.mode box
.nullvalue NULL

-- Configuração da saída
.tables

SELECT id_colaborador, cargo, salario,
CASE
WHEN salario < 3000 THEN 'Baixo'
WHEN salario BETWEEN 3000 AND 6000 THEN 'Médio'
ELSE 'Alto'
END AS categoria_salario
FROM CargosColaboradores;