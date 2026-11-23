
SELECT nome, rua, bairro, cidade, estado, cep FROM colaboradores 
UNION ALL
SELECT nome, rua, bairro, cidade, estado, cep FROM fornecedores;


select count(*) "colaboradores" from colaboradores;

select count(*) "fornecedores" from fornecedores;


select * from clientes;