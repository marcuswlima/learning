select * from clientes
where id = :ID_CLIENTE;


-- Informações de Pedidos segregados por status
SELECT 
    p.status, 
    SUM(ip.precounitario) AS SomaTotalPedidos, 
    count(distinct p.id) "Pedidos"
FROM clientes     c
JOIN Pedidos      p  ON c.ID = p.idcliente
JOIN itensPedidos ip On P.id = ip.idpedido
where c.id = :ID_CLIENTE
group by p.status;

/*
-- Lista nominanl dos pedidos
select id "id_pedido", datahorapedido "Data/Hora", status
from pedidos
where idcliente = :ID_CLIENTE
order by datahorapedido desc;
*/



