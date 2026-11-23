select 
    p.datahorapedido "Data/hora", 
    p.status, 
    c.nome "Cliente"
from pedidos p
join clientes c on c.id = p.idcliente
where p.id = :ID_PEDIDO;


select 
    p.descricao "Produto", 
    ip.quantidade , 
    cast(p.preco as float) "Preço Produto",
    cast(ip.precounitario as float) "Valor Item"
from itenspedidos ip
join produtos p on p.id = ip.idproduto
where ip.idpedido = :ID_PEDIDO
order by p.descricao;

select 
    count(ip.idproduto) "Qdt Protudos",
    sum(ip.quantidade) "Qdt Itens",
    cast(sum(ip.precounitario) as float) "valor do pedido"
from itenspedidos ip
where ip.idpedido = :ID_PEDIDO
;