---------------------------
-- Consultas
---------------------------
SELECT * FROM tabelapedidos WHERE total_do_pedido > 200;

SELECT * FROM tabelaclientes WHERE nome_cliente > 'C' order by nome_cliente;

SELECT * FROM tabelapedidos WHERE data_do_pedido > '2023-09-19' order by data_do_pedido;

---------------------------
-- Filtros
---------------------------
SELECT * FROM tabelapedidos WHERE total_do_pedido >= 200 AND Status = 'Pendente';

SELECT * FROM tabelapedidos WHERE status = 'Pendente' OR status = 'Processando';

SELECT * FROM tabelapedidos WHERE NOT status = 'Pendente';

SELECT * FROM tabelapedidos WHERE data_de_envio_estimada BETWEEN '2023-08-01' and '2023-09-01';

---------------------------
-- Order BY 
---------------------------
SELECT * FROM tabelaprodutos WHERE preco_de_compra BETWEEN 200 AND 600;

SELECT * FROM tabelaprodutos WHERE preco_de_compra BETWEEN 200 AND 600 ORDER BY nome_do_produto;

SELECT * FROM tabelaprodutos WHERE preco_de_compra BETWEEN 200 AND 600 ORDER BY data_de_inclusao;

SELECT * FROM tabelaprodutos WHERE preco_de_compra BETWEEN 200 AND 600 ORDER BY fornecedor;

SELECT * FROM tabelaprodutos WHERE preco_de_compra BETWEEN 200 AND 600 ORDER BY fornecedor DESC;

---------------------------
-- 4.7 Alias
---------------------------

SELECT informacoes_de_contato AS email_cliente FROM tabelaclientes;


---------------------------
-- 5.1 - Atualizando
---------------------------

select status, count(*)
from tabelapedidos 
group by status;

UPDATE tabelapedidos 
SET status = 'Enviado' 
WHERE status = 'Processando';

UPDATE tabelaclientes 
SET informacoes_de_contato = 'j.santos@email.com', endereço_cliente = 'Rua dos paralelepipedos, 30 '
WHERE id_cliente = 2;


---------------------------
-- 5.3 - Delete
---------------------------
