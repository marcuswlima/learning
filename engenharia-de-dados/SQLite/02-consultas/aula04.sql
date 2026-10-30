-- Configuração da saída
.headers on
.mode box
.nullvalue NULL

-------------------------
-- Aula04
-------------------------
select '***********************' "Módulo"
union all
select 'Aula04 '    "Módulo"
union all
select '***********************' "Módulo"
;

SELECT nome, LENGTH(cpf) qtd
FROM Colaboradores
WHERE qtd = 11;

SELECT COUNT(*), LENGTH(cpf) qtd
FROM Colaboradores
WHERE qtd = 11;

--alterar o tamanho a primeira coluna para 100 e a segunda para 30
.width 200 30 

SELECT (' pessoa colaboradora ' || nome || ' de CPF ' || cpf || ' possui o seguinte endereço: '
            || endereco) AS texto
            FROM Colaboradores;

SELECT UPPER(' pessoa colaboradora ' || nome || ' de CPF ' || cpf || ' possui o seguinte endereço: '
            || endereco) AS texto
            FROM Colaboradores;

SELECT LOWER(' pessoa colaboradora ' || nome || ' de CPF ' || cpf || ' possui o seguinte endereço: '
            || endereco) AS texto
            FROM Colaboradores;                        

.width 14 30 

SELECT id_colaborador, STRFTIME('%Y/%m', datainicio) FROM Licencas;

select count(*), STRFTIME('%d-%e-%Y/%m',date()), time() from Licencas;

SELECT id_colaborador, JULIANDAY (datatermino) - JULIANDAY (datacontratacao)
FROM HistoricoEmprego
WHERE datatermino IS NOT NULL;

.width 30
SELECT CURRENT_TIMESTAMP;

select TIME('now'), date('now');