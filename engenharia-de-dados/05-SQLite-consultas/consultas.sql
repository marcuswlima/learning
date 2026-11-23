-- Configuração da saída
.headers on
.mode box
.nullvalue NULL

SELECT * FROM HistoricoEmprego
ORDER BY salario DESC
LIMIT 5;
--select '';

SELECT * FROM HistoricoEmprego
ORDER BY salario DESC
LIMIT 5;

SELECT * FROM HistoricoEmprego
WHERE cargo = 'Professor' AND
datatermino NOT NULL;

SELECT * FROM HistoricoEmprego
WHERE cargo = 'Oftalmologista' OR
cargo = 'Dermatologista';

SELECT * FROM HistoricoEmprego
WHERE cargo IN ('Oftalmologista', 'Dermatologista', 'Professor');

--#select cargo, count(*) 
--#from HistoricoEmprego
--#group by cargo

-------------------------
-- Consultas 4.5
-------------------------
with ds1 as (
    select * from Treinamento
)
select * from ds1;

SELECT * FROM Treinamento
WHERE (curso LIKE 'O direito%' AND instituicao = 'da Rocha');

SELECT * FROM Treinamento
WHERE (curso LIKE 'O direito%' AND instituicao = 'da Rocha')
OR (curso LIKE 'O conforto%' AND instituicao = 'das Neves');

-------------------------
-- Consultas 4.6
-------------------------
SELECT * FROM faturamento;

SELECT mes, MAX(faturamento_bruto)
FROM faturamento
;

SELECT mes, min(faturamento_bruto)
FROM faturamento
;


SELECT SUM(numero_novos_clientes) AS 'Novos clientes 2023' FROM faturamento;

SELECT SUM(numero_novos_clientes) AS 'Novos clientes 2023' FROM faturamento
WHERE mes LIKE '%2023';


SELECT COUNT(*) "Contrado Termiando" 
FROM HistoricoEmprego
WHERE datatermino NOT NULL;

SELECT COUNT(*) "ferias" FROM Licencas
WHERE tipolicenca = 'férias';

-------------------------
-- Consultas 3.5 e 3.6
-------------------------
select '***********************' "Módulo"
union all
select 'Consultas 3.5 e 3.6 '    "Módulo"
union all
select '***********************' "Módulo"
;

SELECT parentesco 
FROM Dependentes
GROUP BY parentesco;

with ds1 as (
    SELECT 
        parentesco, 
        COUNT(*) "Quantidade"
    FROM Dependentes
    GROUP BY parentesco
)
select * 
from ds1 
order by 2 desc;

with ds1 as (
    SELECT instituicao, COUNT(curso) "Quantidade"
    FROM Treinamento
    GROUP BY instituicao
    having COUNT(curso) > 2
)
select * 
from ds1 
order by 2 desc ;


SELECT instituicao, COUNT(curso)
FROM Treinamento
GROUP BY instituicao
HAVING COUNT(curso) > 2;

SELECT cargo, COUNT(*) qtd
FROM HistoricoEmprego
GROUP BY cargo
HAVING qtd >= 2
order by 2 desc;

